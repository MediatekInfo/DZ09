// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "afe.h"

static void AFE_SwitchHSon(void)
{
    uint16_t restore;

    ABBA_AUDIODL_CON11 |= 0x0003;
    ABBA_AUDIODL_CON7  |= 0x0003;
    ABBA_AUDIODL_CON0  |= (RG_AUDDACRPWRUP | RG_AUDDACLPWRUP);
    ABBA_AUDIODL_CON1  &= (~0x6000);
    ABBA_AUDIODL_CON1  |= 0x6000;                       // enable HS zcd
    restore = ABBA_AUDIODL_CON13;
    ABBA_AUDIODL_CON13 = (restore & ~0x7C00) | 0x2000;  // set to 0dB and enable zcd
    ABBA_AUDIODL_CON12 |= AUD_ZCD_ENABLE;
    ABBA_AUDIODL_CON13 = restore;
    ABBA_AUDIODL_CON1  &= (~0x1FF0);
    ABBA_AUDIODL_CON1  |= 0x0800;
    ABBA_AUDIODL_CON0  |= RG_AUDHSPWRUP;                // HS buffer power on
//#if HP_EN_UNDERSPK
//    if(afe.dc_calibrate_finish)
//        // force to turn on earphone under spk
//    {
//        *ABBA_AUDIODL_CON0 |= 0x000D;
//        *ABBA_AUDIODL_CON1 |= 0x0090;
//    }
//#endif
}

void _AFE_DCLK_CtrlSeq(boolean turnon, boolean audio)
{
    if( turnon )
    {
        *(volatile uint16_t *)(0xA001022C) = (*(volatile uint16_t *)(0xA001022C) | 0x0013);
        ABBA_AUDIODL_CON8  |= RG_LCLDO_TBST_EN;
        ABBA_AUDIODL_CON10 = 0x1406; //LDO:2.4v
        ABBA_AUDIODL_CON9  |= 0x0001;
        ABBA_AUDIODL_CON11 |= 0x0003;
        USC_Pause_us(1);
        if(audio)
        {
            ABBA_AUDIODL_CON7 |= 0x0003;
        }
        else
        {
            ABBA_AUDIODL_CON7 |= 0x0002;
        }
        ABBA_AUDIODL_CON0 |= (RG_AUDDACRPWRUP | RG_AUDDACLPWRUP);
        ABBA_AUDIODL_CON15  = 0x11A1;
        ABBA_AUDIODL_CON14 |= 0x0001;
        MD2GSYS_CG_CLR2     = PDN_CON2_AAFE; //equal PDN_CON2_VAFE

        if(audio)
        {
            if(0)//AFE_IsKaraok())  //dl + ul
            {
                AFE_MCU_CON1 |= 0x000F;
            }
            else
            {
                AFE_MCU_CON1   |= 0x000C;
            }
            AFE_AMCU_CON0  |= 0x0001;

        }
        else
        {
            if(0)//AFE_IsKaraok() || (AM_GetDLULPath() == DL_UL_BOTH_PATH) || afe.loopback) //dl + ul
            {
                AFE_MCU_CON1 |= 0x000F;
            }
            else if(1)//AM_GetDLULPath() == DL_PATH)
            {
                AFE_MCU_CON1   |= 0x000C;
            }
            else //ul only
            {
                AFE_MCU_CON1 |= 0x0003;
            }
            AFE_VMCU_CON0 |= 0x0001;
        }
        AFE_MCU_CON0 = 0x0001;
    }
    else
    {
        ABBA_AUDIODL_CON0  &= (~(RG_AUDDACRPWRUP | RG_AUDDACLPWRUP));
        ABBA_AUDIODL_CON7  &= (~0x0003);
        ABBA_AUDIODL_CON11 &= (~0x0003);
        AFE_MCU_CON0 &= (~0x0001);
        if(audio)
        {
            AFE_AMCU_CON0  &= (~0x0001);
        }
        else
        {
            AFE_VMCU_CON0  &= (~0x0001);
        }
        AFE_MCU_CON1 &= (~0x000F);
        MD2GSYS_CG_SET2     = PDN_CON2_VAFE;   //equal PDN_CON2_AAFE
        ABBA_AUDIODL_CON14 &= (~0x0001);
        ABBA_AUDIODL_CON15  = 0x1021;
        ABBA_AUDIODL_CON9  &= (~0x0001);
        *(volatile uint16_t *)(0xA001022C) = (*(volatile uint16_t *)(0xA001022C) & (~0x0010));
    }
}

void _AFE_Switch_IntAmp(boolean on)  // 1: turn on, 0: turn off
{
    uint16_t restore;

    if(on)
    {
//#if !defined(__CLASSK_CP_SUPPORT__)
//        //off -> bypass
//        //spk initial setting
//        *SPK_CON3  = 0x4800;
//        *SPK_CON6  = 0x0988; //bypass mode
//        *SPK_CON7  = 0x0180; //vcm fast startup
//        AFE_DELAY(2000);     //wait 2ms
//        *SPK_CON7  = 0x0100;
//#endif
        ABBA_AUDIODL_CON0  |= RG_AUDHSPWRUP;    // HS buffer power on
        USC_Pause_us(10);
        ABBA_AUDIODL_CON1  |= 0x0004;           // spk mode
        // for adjust gain with ramp
        ABBA_AUDIODL_CON12 &= ~AUD_ZCD_ENABLE;

        //set to 0dB
        restore =  ABBA_AUDIODL_CON13;
        ABBA_AUDIODL_CON13 = (restore & ~0x7C00) | 0x2000;  // Default 0dB => [14:10] = 01000

//#if __SPK_DC_COMPENSATION__
//        //enable compensation
//        {
//            *AFE_AMCU_CON2 |= 0x8000;
//            *AFE_VMCU_CON2 |= 0x8000;
//            *AFE_AMCU_CON6 = afe.spk_dc_compensate_value;
//            *AFE_AMCU_CON7 = afe.spk_dc_compensate_value;
//            *AFE_VMCU_CON4 = afe.spk_dc_compensate_value;
//        }
//#endif
        SPK_CON7 |= 0x0080;    // fast VCM track
        SPK_CON0 |= 0x0001;    // enable spk
        USC_Pause_us(2000);
        SPK_CON3 |= 0x4000;
        SPK_CON7 &= (~0x0080); // vcm high PSRR mode

        {
            uint16_t targ_gain = (uint16_t)(restore & 0x7C00);
            uint16_t curr_gain = (uint16_t)(ABBA_AUDIODL_CON13 & 0x7C00);
            uint16_t gain_step = targ_gain >= curr_gain ? 0x0400 : -0x0400;

            while (curr_gain != targ_gain)
            {
                curr_gain += gain_step;
                ABBA_AUDIODL_CON13 = (uint16_t)curr_gain | (restore & ~0x7C00);
                USC_Pause_us(500);
            }
        }
        ABBA_AUDIODL_CON1  |= 0x6000; // ZCD: handset mode
        ABBA_AUDIODL_CON12 |= AUD_ZCD_ENABLE;
    }
    else
    {
        ABBA_AUDIODL_CON1 &= (~0x0004);
        SPK_CON3 |= 0x0800;
        SPK_CON0 &= (~0x0001);
        SPK_CON3 &= (~0x4000);
        SPK_CON7 &= (~0x0400);
//#if __SPK_DC_COMPENSATION__
//        //disable compensation
//        {
//            AFE_AMCU_CON2 &= ~0x8000;
//            AFE_VMCU_CON2 &= ~0x8000;
//        }
//#endif
    }
//#if __AFE_CLASSK_SUPPORT_INTERNAL__
//    if(L1Audio_IsInitiated())
//        audio_send_vbat_detect_rate(on);
//#endif
}

void DC_Calibration(void)
{
    // AFE related control flow
    // Turn on digital afe
    _AFE_DCLK_CtrlSeq(true, true);

    // Disable mono mode
    AFE_AMCU_CON1 &= ~0x4000;

    // Generate silence
//    AFE_AMCU_CON1 |= 0x003c;   // Mute
//    AFE_DAC_TEST  |= 0x6000;   // Audio sine tone gen
    AFE_AMCU_CON1 = 0x0030;//0x003c;   // Mute off
    AFE_DAC_TEST  |= ADAC_SINUS;//0x6000;   // Audio sine tone gen

    // Turn on hs DAC & buffer
    AFE_SwitchHSon();

    ABBA_AUDIODL_CON13 = (ABBA_AUDIODL_CON13 & ~0x7C00) | 0x2000 | (3 << 1) | (3 << 6);  // Default 0dB => [14:10] = 01000b
//#if defined(__CLASSK_CP_SUPPORT__)

    DBG_DumpMem32((uint32_t *)PMU_base, 0x1000);

    //change to bypass mode
    while(1) //polling power good state
    {
        if((VSBST_CON0 & VSBST_VIO28_PG_STATUS))
            break;
    }

    VSBST_CON0 |= QI_VSBST_EN;
    USC_Pause_us(1000); //delay 1ms

    DBG_DumpMem32((uint32_t *)PMU_base, 0x1000);

    while(1)
    {
        if((VSBST_CON4 & QI_VSBST_PG_STATUS))
            break;
    }
//#endif
    SPK_CON3 = 0x4800;
//#if defined(__CLASSK_CP_SUPPORT__)
    VSBST_CON0 |= RG_VSBST_BP;
//#endif
    USC_Pause_us(1000);
    SPK_CON6  = 0x0988;     //bypass mode
    SPK_CON7  = 0x0180;     //vcm fast startup
    USC_Pause_us(2000);     //wait 2ms
    SPK_CON7  = 0x0100;

    _AFE_Switch_IntAmp(true);
    SPK_CON0 = ((SPK_CON0 & 0xFFCF) | (3 << 4) | RG_SPK_EN);
    USC_Pause_us(1000);

//    // Enable DC compensation
//    AFE_AMCU_CON2 |= 0x8000;
//    AFE_AMCU_CON7 = afe.spk_dc_compensate_value;
}



void Init_sound(void)
{
    MD2GSYS_CG_CLR2 = PDN_CON2_AAFE;

    AFE_Chip_Init();
    DC_Calibration();

//    AFE_SwitchHSon();
//    AFE_TurnOn8K(); // voice dac
//    AFE_DAC_TEST = VDAC_SINUS | ADAC_SINUS | AMP_DIV(3) | FREQ_DIV(8);
//
//    _AFE_Switch_IntAmp(true);
//    SPK_CON0 = SPK_GAIN(3) | RG_SPK_EN;
}

void AFE_Chip_Init(void)
{
    //Digital part Initialization
    AFE_AMCU_CON1   = 0x0E00;
    AFE_AMCU_CON5   = 0x0002;
    AFE_VMCU_CON3   = 0x0002;
    AFE_VMCU_CON2   = 0x083C;
    AFE_AMCU_CON2   = 0x003C;
    AFE_VMCU_CON1   = 0x0080;

    //Uplink PGA Gain : 6dB
    ABBA_VBITX_CON0 |=  (0x2 << 6);

    //Analog part Initialization and power-on control sequence
    ABBA_AUDIODL_CON8 |= (RG_LCLDO_TBST_EN);
    ABBA_AUDIODL_CON4  = 0x01B9;
    USC_Pause_us(10);
    ABBA_AUDIODL_CON4 |= 0x0040;
    // should wait 2s~3s to charge cap
    ABBA_AUDIODL_CON10 = 0x1406;    //LDO:2.4v

    //Speaker Amp setting
    SPK_CON0 = ( (SPK_CON0 & 0xFFCF) | (0 << 4) );

//    {
//        //main mic
//        if(mic0_type_sel == 0) //acc
//            *ABBA_VBITX_CON4 &= 0xA7FF;
//        else if(mic0_type_sel == 1) //dcc mems
//            *ABBA_VBITX_CON4 = (*ABBA_VBITX_CON4 & 0xA7FF) | 0x4000;
//        else  //dcc ecm
//            *ABBA_VBITX_CON4 = (*ABBA_VBITX_CON4 & 0xA7FF) | 0x4800;
//
//        //ear-mic
//        if(mic1_type_sel == 0) //acc
//            *ABBA_VBITX_CON4 &= 0xD9FF;
//        else if(mic1_type_sel == 1) //dcc mems
//            *ABBA_VBITX_CON4 = (*ABBA_VBITX_CON4 & 0xD9FF) | 0x2000;
//        else //dcc ecm
//            *ABBA_VBITX_CON4 = (*ABBA_VBITX_CON4 & 0xD9FF) | 0x2400;
//    }
//    afe.class_d_gain  = SpkAmpGain;
//    *DP_VOL_IN_PCM    = DG_Microphone;
//    *DP_VOL_OUT_PCM   = DG_DL_Speech;
//    PcmSink_SetGain(DG_DAF);
//    PcmSink_InitDigitalGain();
//
//    *DP_AUDIO_16K_TX_VOL = DG_Microphone;
//    *DP_AUDIO_16K_RX_VOL = DG_DL_Speech;   // 16K WB DownLink path digital gain
}
