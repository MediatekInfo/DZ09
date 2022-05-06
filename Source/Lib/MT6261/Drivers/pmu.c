// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 - 2019 AJScorp
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; version 2 of the License.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/
#include "systemconfig.h"
#include "pmu.h"

#define BATPARAMAVERAGESIZE         128
#define CHARGERONDEBOUNCE           (3 * 2)                                                         // 3 sec
#define RECHARGEVOLTAGE             3800                                                            // mV
#define RECHARGETIMEOUT             (10 * 2)                                                        // 10 sec

typedef struct
{
    uint16_t Limit;
    uint8_t  BitValue;
    uint8_t  USBDLMaxCurrent;
} TCURRLIMIT;

const TCURRLIMIT BatCurrentLimits[] =
{
    {  70,   CS_VTH_70mA, 0x12},
    { 200,  CS_VTH_200mA, 0x18},
    { 300,  CS_VTH_300mA, 0x28},                                                                    // Need correction
    { 450,  CS_VTH_450mA, 0x59},
    { 550,  CS_VTH_550mA, 0x59},
    { 650,  CS_VTH_650mA, 0x59},
    { 700,  CS_VTH_700mA, 0x59},
    { 800,  CS_VTH_800mA, 0x59},
    { 900,  CS_VTH_900mA, 0x59},
    {1000, CS_VTH_1000mA, 0x59},
    {1100, CS_VTH_1100mA, 0x59},
    {1200, CS_VTH_1200mA, 0x59},
    {1300, CS_VTH_1300mA, 0x59},
    {1400, CS_VTH_1400mA, 0x59},
    {1500, CS_VTH_1500mA, 0x59},
    {1600, CS_VTH_1600mA, 0x59}
};

static boolean  PrevChargerState, BatteryCharging;
static pTIMER   ChargerTimer;
static uint16_t VBat, ISense;
static uint32_t ChargeOnDebounce;
static uint32_t RechargeTimeout;
static uint16_t *pDataArrayPrev, *pDataArrayNew;

static void PMU_PrintDebugInfo(void)
{
    uint16_t ChCON1 = CHR_CON1, i, j;
    TDATETIME DTime;

    DTime = RTC_GetDateTime();
    CHR_CON8 = RG_PCHR_FLAG_SEL(0x1F) | RG_PCHR_FLAG_EN;

    DebugPrint("VBAT (%u), ISEN (%umA), CHR_CON8 %04X CHR_CON0 %04X CHR_CON1 %04X CHR_CON9 %04X CHR_CON5 %04X ",
               VBat,
               ISense,
               CHR_CON8,
               CHR_CON0,
               CHR_CON1,
               CHR_CON9,
               CHR_CON5);
    DebugPrint("%s %s ", (ChCON1 & RGS_VBAT_CC_DET) ? "CC" : "", (ChCON1 & RGS_VBAT_CV_DET) ? "CV" : "");
    DebugPrint("%02d:%02d:%02d\r\n", DTime.Time.Hour, DTime.Time.Min, DTime.Time.Sec);

    if ((pDataArrayPrev == NULL) || (pDataArrayNew == NULL))
    {
        if (pDataArrayPrev == NULL) pDataArrayPrev = malloc(4096);
        if (pDataArrayNew == NULL) pDataArrayNew = malloc(4096);

        memcpy(pDataArrayNew, (void *)(PMU_BASE), 4096);
    }
    else
    {
        uint16_t *tmpPtr = pDataArrayPrev, i;

        pDataArrayPrev = pDataArrayNew;
        pDataArrayNew = tmpPtr;

        tmpPtr = (void *)(PMU_BASE);
        for(i = 0; i < 2048; i++)
            pDataArrayNew[i] = tmpPtr[i];

        for(i = 0; i < 2048; i++)
        {
            if (pDataArrayPrev[i] != pDataArrayNew[i])
                DebugPrint("0x%04X: %04X->%04X\r\n", 2 * i, pDataArrayPrev[i], pDataArrayNew[i]);
        }
    }
}

static int8_t PMU_GetChargingParams(uint16_t TestValue)
{
    int8_t i = sizeof(BatCurrentLimits) / sizeof(BatCurrentLimits[0]) - 1;

    for(; i >= 0; i--)
        if (TestValue >= BatCurrentLimits[i].Limit)
            return i;

    return -1;
}

static boolean PMU_IsChargerEnabled(void)
{
    return !!(CHR_CON0 & CHR_EN);
}

static void PMU_ChargerEnable(boolean Enable)
{
    int8_t ParamIndex = PMU_GetChargingParams(BATMAXCURRENT);

    CHR_CON15 = (ParamIndex != -1) ? BatCurrentLimits[ParamIndex].USBDLMaxCurrent : 0;
    CHR_CON0 = RG_VCDT_HV_VTH(HV_VTH_600V) | RG_VCDT_LV_VTH(LV_VTH_430V);
    CHR_CON1 = RG_VBAT_CV_VTH(CV_VTH_42000V) | RG_VBAT_CC_VTH(CC_VTH_3300V);
    CHR_CON5 = (CHR_CON5 & ~RG_VBAT_OV_VTH(-1)) | RG_VBAT_OV_VTH(OV_VTH_425V) | RG_VBAT_OV_DEG | RG_VBAT_OV_EN;
    CHR_CON10 = RG_ADCIN_VBAT_EN;
    CHR_CON12 = RG_LOW_ICH_DB(4) | RG_ULC_DET_EN | RG_HWCV_EN | RG_CSDAC_MODE;

    CHR_CON11 = RG_BC11_RST;

    PMU_SetChargerWDTEnabled(false);

    if (Enable && (ParamIndex != -1) && PMU_IsChargerConnected())
    {
        CHR_CON1 |= RG_VBAT_CC_EN | RG_VBAT_CV_EN;
        CHR_CON2 = RG_CS_EN | RG_CS_VTH(BatCurrentLimits[ParamIndex].BitValue);
        CHR_CON4 = RG_CSDAC_DLY(STP_DLY128us) | RG_CSDAC_STP(CSDAC_STP_1_0cpS) |
                   RG_CSDAC_STP_DEC(STP_DEC_1_0cpS) | RG_CSDAC_STP_INC(STP_INC_1_0cpS);
        CHR_CON10 |= RG_ADCIN_CHR_EN | RG_ADCIN_VSEN_EN;
        CHR_CON0 |= CHR_EN | RG_CSDAC_EN;
    }
    else
    {
        CHR_CON0 &= ~(RG_CSDAC_EN | CHR_EN);
        CHR_CON1 &= ~(RG_VBAT_CC_EN | RG_VBAT_CV_EN);
        CHR_CON2 &= RG_CS_EN;
        CHR_CON10 &= ~(RG_ADCIN_CHR_EN | RG_ADCIN_VSEN_EN);
    }
}

static void PMU_MeasureChargeParams(void)
{
    uint16_t tmpADCValues[2], i, j;
    uint32_t MathChargerADC[2] = {0}, tmpIValue;

    for(i = 0; i < BATPARAMAVERAGESIZE; i++)
    {
        AUXADC_MeasureMultiple(tmpADCValues, ADC_ISENSE | ADC_VBAT);
        for(j = 0; j < sizeof(tmpADCValues) / sizeof(tmpADCValues[0]); j++)
            MathChargerADC[j] += tmpADCValues[j];
    }
    for(j = 0; j < sizeof(tmpADCValues) / sizeof(tmpADCValues[0]); j++)
        tmpADCValues[j] = (MathChargerADC[j] + BATPARAMAVERAGESIZE / 2) / BATPARAMAVERAGESIZE;

    VBat = (5600 * tmpADCValues[0]) / 0x03FF;
    tmpIValue = (5600 * tmpADCValues[1]) / 0x03FF;
    ISense = (tmpIValue >= VBat) ? 5 * (tmpIValue - VBat) : 0;
}

static void ChargerTimerHandler(pTIMER Timer)
{
    boolean ChargerState = PMU_IsChargerConnected();

    if (PrevChargerState != ChargerState)
    {
        DebugPrint("PMU charger %s!\r\n", (ChargerState) ? "connected" : "disconnected");
        PrevChargerState = ChargerState;
        PMU_ChargerEnable(ChargerState);
    }
    PMU_MeasureChargeParams();

    if (ChargerState)
    {
        if (CHR_CON1 & RGS_VBAT_CV_DET)
        {
            if (CHR_CON1 & RG_VBAT_CC_EN)
                CHR_CON1 &= ~RG_VBAT_CC_EN;
        }
        if (ISense)
        {
            if (ISense <= BATMINCURRENT)
            {
                ChargeOnDebounce = 0;
                PMU_ChargerEnable(false);
                if (BatteryCharging)
                    DebugPrint("PMU charging complete!\r\n");
            }
            else if (ChargeOnDebounce < CHARGERONDEBOUNCE) ChargeOnDebounce++;
        }
        else
        {
            if (ChargeOnDebounce) ChargeOnDebounce--;
            if (VBat < RECHARGEVOLTAGE)
            {
                if (RechargeTimeout) RechargeTimeout--;
                else
                {
                    DebugPrint("PMU restart charging!\r\n");
                    if (PMU_IsChargerEnabled()) PMU_ChargerEnable(false);
                    PMU_ChargerEnable(true);
                    RechargeTimeout = RECHARGETIMEOUT;
                }
            }
            else RechargeTimeout = 0;
        }
    }
    else ChargeOnDebounce = RechargeTimeout = 0;

    if (BatteryCharging != (ChargeOnDebounce == CHARGERONDEBOUNCE))
    {
        if (!BatteryCharging && (ChargeOnDebounce == CHARGERONDEBOUNCE))
        {
            BatteryCharging = true;
            DebugPrint("PMU charging started!\r\n");
        }
        else if (ChargeOnDebounce == 0) BatteryCharging = false;
    }

    PMU_PrintDebugInfo();
}

static void PMU_InterruptHandler(void)
{
    ChargeOnDebounce = 0;
    BatteryCharging = false;
    USB_OnCableDisconnect();
}

void PMU_SetChargerWDTEnabled(boolean Enabled)
{
    CHR_CON9 |= RG_CHRWDT_WR;
    if (Enabled) CHR_CON9 |= RG_CHRWDT_EN;
    else CHR_CON9 &= ~RG_CHRWDT_EN;

    while(CHR_CON9 & RGS_CHRWDT_OUT) {}

    CHR_CON9 |= CHRWDT_FLAG_WR;
}

void PMU_SetChargerWDTInterval(uint8_t Interval)
{
    CHR_CON9 = (CHR_CON9 & ~RG_CHRWDT_TD(-1)) | RG_CHRWDT_TD(Interval) | RG_CHRWDT_WR;

    while(CHR_CON9 & RGS_CHRWDT_OUT) {}

    CHR_CON9 |= CHRWDT_FLAG_WR;
}

boolean PMU_IsChargerConnected(void)
{
    return (CHR_CON0 & RGS_CHRDET) ? true : false;
}

boolean PMU_IsBatteryCharging(void)
{
#if (APPUSEBATTERY != 0)
    return BatteryCharging;
#else
    return false;
#endif
}

void PMU_EnableUSBDLMode(void)
{
    CHR_CON10 &= ~(RG_USBDL_SET | RG_USBDL_RST);
    STRUP_CON0 |= RG_USBDL_EN;
}

void PMU_DisableUSBDLMode(void)
{
    STRUP_CON0 &= ~RG_USBDL_EN;
    CHR_CON10 = (CHR_CON10 & ~RG_USBDL_SET) | RG_USBDL_RST;
}

boolean PMU_IsPowerKeyPressed(void)
{
    return (STRUP_CON0 & QI_PWRKEY_DEB) ? false : true;
}

void PMU_SetVibrationOutput(boolean Enable)
{
#ifdef VIBRVOLTAGE
    uint16_t En = (Enable) ? RG_VIBR_EN : 0;

#if VIBRVOLTAGE == VIBR_VO18V
    VIBR_CON0 = RG_VIBR_VOSEL(VIBR_VO18V) | VIBR_ON_SEL | En;
#elif VIBRVOLTAGE == VIBR_VO28V
    VIBR_CON0 = RG_VIBR_VOSEL(VIBR_VO28V) | VIBR_ON_SEL | En;
#elif VIBRVOLTAGE == VIBR_VO30V
    VIBR_CON0 = RG_VIBR_VOSEL(VIBR_VO30V) | VIBR_ON_SEL | En;
#endif
#endif
}

void PMU_DisableISINKs(void)
{
    PMU_SetISINKOutput(ISINK_CH0, false);
    PMU_SetISINKOutput(ISINK_CH1, false);
}

void PMU_SetISINKMode(boolean UsePWM)
{
    if (UsePWM) ISINKS_CON0 = ISINKS_MODE_PWM;
    else ISINKS_CON0 = ISINKS_MODE_SINK;
}

void PMU_SetISINKOutput(ISINKCHNL Channel, boolean Enable)
{
    volatile uint16_t *ISINK_CON;

    if      (Channel == ISINK_CH0) ISINK_CON = &ISINK0_CON0;
    else if (Channel == ISINK_CH1) ISINK_CON = &ISINK1_CON0;
    else return;

    if (Enable) *ISINK_CON |= NI_ISINKS_CH0_EN;
    else *ISINK_CON &= ~NI_ISINKS_CH0_EN;

    *ISINK_CON &= ~NI_ISINKS_CH0_EN;
}

void PMU_SetISINKParameters(ISINKCHNL Channel, ICVAL Value, boolean Enable)
{
    volatile uint16_t *ISINK_CON;
    uint16_t En;

    if      (Channel == ISINK_CH0) ISINK_CON = &ISINK0_CON0;
    else if (Channel == ISINK_CH1) ISINK_CON = &ISINK1_CON0;
    else return;

    En = (Enable) ? NI_ISINKS_CH0_EN : 0;

    switch (Value)
    {
    case IC_4mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_4mA)  | En;
        break;
    case IC_8mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_8mA)  | En;
        break;
    case IC_12mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_12mA) | En;
        break;
    case IC_16mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_16mA) | En;
        break;
    case IC_20mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_20mA) | En;
        break;
    case IC_24mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_24mA) | En;
        break;
    case IC_32mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_16mA) | RG_ISINK0_DOUBLE | En;
        break;
    case IC_40mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_20mA) | RG_ISINK0_DOUBLE | En;
        break;
    case IC_48mA:
        *ISINK_CON = RG_ISINKS_CH0(ISINKS_CH0_24mA) | RG_ISINK0_DOUBLE | En;
        break;
    }
}

void PMU_TurnOnVUSB(boolean Enable)
{
    if (Enable) VUSB_CON0 |= RG_VUSB_EN;
    else VUSB_CON0 &= ~RG_VUSB_EN;
}

void PMU_TurnOnVMC(boolean Enable)
{
    uint16_t En = (Enable) ? RG_VMC_EN : 0;

    VMC_CON0 = (VMC_CON0 & ~RG_VMC_EN) | VMC_ON_SEL | En;
    if (En)
    {
// NOTE (ajscorp#1#): Need to add a check for the QI_VMC_STATUS flag at least when turning voltage on.
    }
}

boolean PMU_SetVoltageVMC(TVMC Voltage)
{
    switch (Voltage)
    {
    case VMC_VO18V:
    case VMC_VO28V:
    case VMC_VO30V:
    case VMC_VO33V:
        VMC_CON0 = (VMC_CON0 & ~RG_VMC_VOSEL(-1)) | RG_VMC_VOSEL(Voltage);
// NOTE (ajscorp#1#): Need to add a check for the QI_VMC_STATUS flag.
        return true;
    default:
        return false;
    }
}

TVMC PMU_GetSelectedVoltageVMC(void)
{
    TVMC VMC = (VMC_CON0 & RG_VMC_VOSEL(-1)) >> RG_VMC_VOSEL_MASK_OFFSET;

    return VMC;
}

void PMU_Initialize(void)
{
    boolean Result = false;

    PMU_DisableUSBDLMode();

    do
    {
#if (APPUSEBATTERY != 0)
        DebugPrint(":\r\n Battery charger...");

        if (!AUXADC_Enable())
        {
            DebugPrint("Failed! Can not enable AUXADC.\r\n");
            break;
        }
        if (ChargerTimer == NULL)
        {
            ChargerTimer = LRT_Create(500, ChargerTimerHandler, TF_AUTOREPEAT | TF_ENABLED);
            if (ChargerTimer == NULL)
            {
                DebugPrint("Failed! Can not create timer.\r\n");
                break;
            }
        }
        if (!NVIC_RegisterEINT(ADIE_EINT_CHRDET, PMU_InterruptHandler,
                               ADIE_EINT_SENS_EDGE, ADIE_EINT_POLHIGH, 0, false) ||
                !NVIC_EnableEINT(ADIE_EINT_CHRDET))
        {
            DebugPrint("Failed! Can not register interrupt.\r\n");
            break;
        }
#endif
        Result = true;
    }
    while(0);

    if (Result) DebugPrint("...Complete.\r\n");
    else
    {
        NVIC_UnregisterEINT(ADIE_EINT_CHRDET);
        AUXADC_Disable();
        if (ChargerTimer != NULL)
        {
            LRT_Destroy(ChargerTimer);
            ChargerTimer = NULL;
        }
        DebugPrint("PMU initialization failed!\r\n");
    }
}
