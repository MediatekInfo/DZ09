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
// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "afe.h"

static void AFE_SwitchHSon(void) // +
{
    uint16_t restore;

    ABBA_AUDIODL_CON11 |= 0x0003;
    ABBA_AUDIODL_CON7  |= 0x0003;
    ABBA_AUDIODL_CON0  |= (RG_AUDDACRPWRUP | RG_AUDDACLPWRUP);
    ABBA_AUDIODL_CON1  &= (~0x6000);
    ABBA_AUDIODL_CON1  |= 0x6000;                                                                   // enable HS zcd
    restore = ABBA_AUDIODL_CON13;
    ABBA_AUDIODL_CON13 = (restore & ~0x7C00) | 0x2000;                                              // set to 0dB and enable zcd
    ABBA_AUDIODL_CON12 |= AUD_ZCD_ENABLE;
    ABBA_AUDIODL_CON13 = restore;
    ABBA_AUDIODL_CON1  &= (~0x1FF0);
    ABBA_AUDIODL_CON1  |= 0x0800;
    ABBA_AUDIODL_CON0  |= RG_AUDHSPWRUP;                                                            // HS buffer power on
}

static void AFE_SwitchHSoff(void) // +
{
    uint16_t OrgValue = ABBA_AUDIODL_CON13;

    ABBA_AUDIODL_CON12 &= ~AUD_ZCD_ENABLE;
    ABBA_AUDIODL_CON13  = (MINIMUM_VGAIN_SETTING << 10) | (OrgValue & 0x83FF);
    ABBA_AUDIODL_CON1  &= ~0x1C00;
    ABBA_AUDIODL_CON0  &= ~RG_AUDHSPWRUP;
}

static void AFE_SwitchHPon(void) // +
{
    uint16_t restore, tmp;

    ABBA_AUDIODL_CON11 |= 0x0003;
    ABBA_AUDIODL_CON7  |= 0x0003;
    ABBA_AUDIODL_CON0  |= (RG_AUDDACRPWRUP | RG_AUDDACLPWRUP);
    ABBA_AUDIODL_CON1  &= ~0x6000;
    ABBA_AUDIODL_CON1  |= 0x4000;                                                                   // enable HP zcd
    restore = ABBA_AUDIODL_CON13;
    ABBA_AUDIODL_CON13 = (restore & ~0x03FF) | 0x02F7;                                              // set to 0dB and enable zcd
    ABBA_AUDIODL_CON12 |= AUD_ZCD_ENABLE;

    ABBA_AUDIODL_CON0  |= RG_AUDHSPWRUP;                                                            // HS buffer power on [must]
    USC_Pause_us(10);
    ABBA_AUDIODL_CON5 |= 0x0001;
    USC_Pause_us(10);
    ABBA_AUDIODL_CON0 |= 0x0001;
    USC_Pause_us(10);
    ABBA_AUDIODL_CON2 |= 0x0001;
    ABBA_AUDIODL_CON0 |= 0x000C;
    ABBA_AUDIODL_CON2 &= (~0x0001);

    tmp  = ABBA_AUDIODL_CON1 & ~0x1FF0;                                                             // to avoid set path pop
    ABBA_AUDIODL_CON1 = tmp | 0x0120;
    ABBA_AUDIODL_CON5 &= ~0x0001;
    ABBA_AUDIODL_CON0 &= ~RG_AUDHSPWRUP;
    ABBA_AUDIODL_CON4 &= ~(RG_ADEPOP_EN | RG_DEPOP_VCM_EN);
    ABBA_AUDIODL_CON13 = restore;
}

static void AFE_SwitchHPoff(void) // +
{
    uint16_t OrgValue = ABBA_AUDIODL_CON13;

    ABBA_AUDIODL_CON4 |= RG_DEPOP_VCM_EN;
    USC_Pause_us(10);
    ABBA_AUDIODL_CON4 |= RG_ADEPOP_EN;
    USC_Pause_us(10);
    ABBA_AUDIODL_CON12 &= ~AUD_ZCD_ENABLE;
    ABBA_AUDIODL_CON13  = (MINIMUM_AGAIN_SETTING << 1) | (MINIMUM_AGAIN_SETTING << 6) | (OrgValue & 0xFC21);
    ABBA_AUDIODL_CON0  &= ~(RG_AUDIBIASPWRUP | RG_AUDHPRPWRUP | RG_AUDHPLPWRUP);
    ABBA_AUDIODL_CON1  &= ~0x03F0;
}

static void AFE_DCLKCtrlSeq(boolean TurnOn, boolean Audio, TAV_PATH Path) // +
{
    uint32_t savedMask = __disable_interrupts();

    if (TurnOn)
    {
        *(volatile uint16_t *)(0xA001022C) = *(volatile uint16_t *)(0xA001022C) | 0x0013;

        ABBA_AUDIODL_CON8 |= RG_LCLDO_TBST_EN;
        ABBA_AUDIODL_CON10 = RG_AUDHSBIAS | 0x0406;                                                 // LDO:2.4v
        ABBA_AUDIODL_CON9 |= 0x0001;
        ABBA_AUDIODL_CON11 |= 0x0003;
        USC_Pause_us(1);

        if (Audio) ABBA_AUDIODL_CON7 |= 0x0003;
        else       ABBA_AUDIODL_CON7 = (ABBA_AUDIODL_CON7 & ~0x0003) | 0x0002;

        ABBA_AUDIODL_CON0 |= (RG_AUDDACRPWRUP | RG_AUDDACLPWRUP);
        ABBA_AUDIODL_CON15 = 0x11A1;
        ABBA_AUDIODL_CON14 |= 0x0001;

        MD2GSYS_CG_CLR2 = PDN_VAFE;

        if (Audio)
        {
            AFE_MCU_CON1 = (AFE_MCU_CON1 & ~AFE_PATH_MASK) | UDSP_DL_ON | A_IF_DL_ON;
            AFE_AMCU_CON0 |= AIRQON;
        }
        else
        {
            if (Path == DL_PATH)
                AFE_MCU_CON1 = (AFE_MCU_CON1 & ~AFE_PATH_MASK) | UDSP_DL_ON | A_IF_DL_ON;
            else if (Path == UL_PATH)
                AFE_MCU_CON1 = (AFE_MCU_CON1 & ~AFE_PATH_MASK) | UDSP_UL_ON | A_IF_UL_ON;
            else AFE_MCU_CON1 |= AFE_PATH_MASK;

            AFE_VMCU_CON0 |= VIRQON;                                                                // Turns on 8k interrupt
        }
        AFE_MCU_CON0 = AFE_ON;                                                                      // Turns on the audio front end
    }
    else
    {
        ABBA_AUDIODL_CON0 &= ~(RG_AUDDACRPWRUP | RG_AUDDACLPWRUP); //-V525
        ABBA_AUDIODL_CON7 &= ~0x0003;
        ABBA_AUDIODL_CON11 &= ~0x0003;
        AFE_MCU_CON0 &= ~AFE_ON;                                                                    // Turns off the audio front end

        if (Audio) AFE_AMCU_CON0 &= ~AIRQON;
        else       AFE_VMCU_CON0 &= ~VIRQON;

        AFE_MCU_CON1 &= ~AFE_PATH_MASK;

        MD2GSYS_CG_SET2 = PDN_VAFE;

        ABBA_AUDIODL_CON14 &= ~0x0001;
        ABBA_AUDIODL_CON15 = 0x1021;
        ABBA_AUDIODL_CON9 &= ~0x0001;

        *(volatile uint16_t *)(0xA001022C) = *(volatile uint16_t *)(0xA001022C) &= (~0x0010);
    }
    __restore_interrupts(savedMask);
}

static void AFE_SwitchIntAmp(boolean On) // +
{
    if (On)
    {
        uint16_t restore;

        SPK_CON3 = 0x4800;
        SPK_CON6 = 0x0988; // bypass mode
        SPK_CON7 = 0x0180; // vcm fast startup
        USC_Pause_us(2000); // wait 2 ms
        SPK_CON7 = 0x0100;


        ABBA_AUDIODL_CON0 |= RG_AUDHSPWRUP;                                                         // HS buffer power on
        USC_Pause_us(10);
        ABBA_AUDIODL_CON1 |= 0x0004;                                                                // spk mode
        /* for adjust gain with ramp */
        ABBA_AUDIODL_CON12 &= ~AUD_ZCD_ENABLE;

        //set to 0dB
        restore =  ABBA_AUDIODL_CON13;
        ABBA_AUDIODL_CON13 = (restore & ~0x7C00) | 0x2000;                                          // Default 0dB => [14:10] = 01000

        SPK_CON7 |= RG_SPK_VCM_SEL;                                                                 // fast VCM track
        AFE_TurnOnSpeaker(true);
        USC_Pause_us(2000);
        SPK_CON3 |= RG_SPK_IN_FLOAT_B;
        SPK_CON7 &= ~RG_SPK_VCM_SEL;                                                                // vcm high PSRR mode

        {
            int16_t targ_gain = restore & 0x7C00;
            int16_t curr_gain = ABBA_AUDIODL_CON13 & 0x7C00;
            int16_t gain_step = targ_gain >= curr_gain ? 0x0400 : -0x0400;

            while (curr_gain != targ_gain)
            {
                curr_gain += gain_step;
                ABBA_AUDIODL_CON13 = curr_gain | (restore & ~0x7C00);
                USC_Pause_us(500);
            }
        }
        ABBA_AUDIODL_CON13 = restore;

        ABBA_AUDIODL_CON1  |= 0x6000;                                                                // ZCD: handset mode
        ABBA_AUDIODL_CON12 |= AUD_ZCD_ENABLE;
    }
    else
    {
        ABBA_AUDIODL_CON1 &= ~0x0004;
        SPK_CON3 |= RG_SPK_OUT_FLOAT_B;
        AFE_TurnOnSpeaker(false);
        SPK_CON3 &= ~RG_SPK_IN_FLOAT_B;
        SPK_CON7 &= ~RG_SPK_PBIAS;
    }
}

static void AFE_ChipInitialization(void) // +
{
    /* Digital part initialization */
    AFE_AMCU_CON1 = 0x0C00 | AFS(0x08) | ARAMPSP(0);
    AFE_AMCU_CON5 = 0x0002;
    AFE_VMCU_CON3 = 0x0002;
    AFE_VMCU_CON2 = VTX_CK_PHASE | VSDM_GAIN(0x3C);
    AFE_AMCU_CON2 = ASDM_GAIN(0x3C);
    AFE_VMCU_CON1 = VRSDON;

    ABBA_VBITX_CON0 |= RG_ULPGA_GAIN(0x2);                                                          // Uplink PGA Gain : 6dB

    /* Analog part initialization and power-on control sequence */
    ABBA_AUDIODL_CON8 |= (RG_LCLDO_TBST_EN);
    ABBA_AUDIODL_CON4  = 0x198 | RG_DEPOP_CHARGEOPTION | RG_DEPOP_VCM_EN;
    USC_Pause_us(10);
    ABBA_AUDIODL_CON4 |= 0x0040;
    // should wait 2s~3s to charge cap
    ABBA_AUDIODL_CON10 = RG_AUDHSBIAS | 0x0406;                                                     // LDO:2.4v
    ABBA_AUDIODL_CON9 |= 0x0001;

    /* Speaker amp setting */
    AFE_SetSpeakerVolume(SPK_GAIN_M6DB);

//    /* main microphone settings */
//    if      (mic0_type_sel == 0) ABBA_VBITX_CON4 &= 0xA7FF;                                         // acc
//    else if (mic0_type_sel == 1) ABBA_VBITX_CON4 = (ABBA_VBITX_CON4 & 0xA7FF) | 0x4000;             // dcc mems
//    else ABBA_VBITX_CON4 = (ABBA_VBITX_CON4 & 0xA7FF) | 0x4800;                                     // dcc ecm
//
//    /* earphone microphone settings */
//    if      (mic1_type_sel == 0) ABBA_VBITX_CON4 &= 0xD9FF;                                         // acc
//    else if (mic1_type_sel == 1) ABBA_VBITX_CON4 = (ABBA_VBITX_CON4 & 0xD9FF) | 0x2000;             // dcc mems
//    else ABBA_VBITX_CON4 = (ABBA_VBITX_CON4 & 0xD9FF) | 0x2400;                                     // dcc ecm

//    *DP_VOL_IN_PCM    = DG_Microphone;
//    *DP_VOL_OUT_PCM   = DG_DL_Speech;
//    PcmSink_SetGain(DG_DAF);
//    PcmSink_InitDigitalGain();
//
//    *DP_AUDIO_16K_TX_VOL = DG_Microphone;
//    *DP_AUDIO_16K_RX_VOL = DG_DL_Speech;   // 16K WB DownLink path digital gain
}

void AFE_SetSpeakerVolume(uint8_t Volume)
{
    SPK_CON0 = (SPK_CON0 & ~SPK_GAIN(-1)) | SPK_GAIN(Volume);
}

void AFE_TurnOnSpeaker(boolean On)
{
    if (On) SPK_CON0 |= RG_SPK_EN;
    else    SPK_CON0 &= ~RG_SPK_EN;
}

boolean AFE_SetAudioSampleRate(TASR Rate)
{
    switch (Rate)
    {
    case ASR_8KHZ:
    case ASR_11KHZ:
    case ASR_12KHZ:
    case ASR_16KHZ:
    case ASR_22KHZ:
    case ASR_24KHZ:
    case ASR_32KHZ:
    case ASR_44KHZ:
    case ASR_48KHZ:
        AFE_AMCU_CON1 = (AFE_AMCU_CON1 & ~AFS(-1)) | AFS(Rate);
        return true;
    default:
        return false;
    }
}

void AFE_initialize(void)
{
    AFE_ChipInitialization();
    AFE_DCLKCtrlSeq(true, true, DL_PATH);

    AFE_SetAudioSampleRate(ASR_8KHZ);

    AFE_SwitchHSon();

    AFE_SwitchIntAmp(true);

    SPK_CON0 = SPK_GAIN(3) | RG_SPK_EN;

    ABBA_AUDIODL_CON13 = RG_GAINS(0x10) | RG_GAINL(0x1F) | RG_GAINR(0x1F);
    USC_Pause_us(5000);
}

void Beep(void)
{
    AFE_DAC_TEST = VDAC_SINUS | ADAC_SINUS | AMP_DIV(7) | FREQ_DIV(22);
    USC_Pause_us(50000);
    AFE_DAC_TEST &= ~(VDAC_SINUS | ADAC_SINUS);
}
