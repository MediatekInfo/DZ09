// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2020, 2019 AJScorp
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

void PMU_DisablePCHR_WDT(void)
{
    CHR_CON9 = CHRWDT_FLAG_WR | RG_CHRWDT_WR | RG_CHRWDT_DIS;
}

void PMU_EnablePCHR_WDT(uint8_t Interval)
{
    CHR_CON9 = RG_CHRWDT_WR | RG_CHRWDT_EN | RG_CHRWDT_TD(Interval);
}

void PMU_EnableUSBDownloaderWDT(void)                                                               // ~30 sec WDT after power on
{
    CHR_CON10 &= ~(RG_USBDL_RST | RG_USBDL_SET);
}

void PMU_DisableUSBDownloaderWDT(void)
{
#if (_USEBATTERY_ != 0)
    CHR_CON10 = (CHR_CON10 & ~RG_USBDL_SET) | RG_USBDL_RST;
#else
    CHR_CON10 = (CHR_CON10 | RG_USBDL_SET) | RG_USBDL_RST;
#endif
}

boolean PMU_IsChargerDetected(void)
{
    return (CHR_CON0 & RGS_CHRDET) ? true : false;
}

boolean PMU_IsPowerKeyPressed(void)
{
    return (STRUP_CON0 & QI_PWRKEY_DEB) ? false : true;
}

void PMU_SetVibrationOutput(boolean Enable)
{
#ifdef VIBRVoltage
    uint16_t En = (Enable) ? RG_VIBR_EN : 0;

#if VIBRVoltage == VIBR_VO18V
    VIBR_CON0 = RG_VIBR_VOSEL(VIBR_VO18V) | VIBR_ON_SEL | En;
#elif VIBRVoltage == VIBR_VO28V
    VIBR_CON0 = RG_VIBR_VOSEL(VIBR_VO28V) | VIBR_ON_SEL | En;
#elif VIBRVoltage == VIBR_VO30V
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
