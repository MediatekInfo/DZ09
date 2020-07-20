/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2020 AJScorp
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
#ifndef _AFE_H_
#define _AFE_H_

#define AFE_VMCU_CON0               (*(volatile uint16_t*)(AFE_base + 0x0000))
#define VIRQON                      (1 << 0)
#define AFE_VMCU_CON1               (*(volatile uint16_t*)(AFE_base + 0x000C))
#define VRSDON                      (1 << 7)
#define VMODE4K                     (1 << 9)
#define VMODE32K                    (1 << 10)
#define DUAL_MIC                    (! << 12)
#define AFE_VMCU_CON2               (*(volatile uint16_t*)(AFE_base + 0x0010))
#define VSDM_GAIN(v)                (((v) & 0x3F) << 0)
#define VTX_CK_PHASE                (1 << 11)
#define VDC_COMP_EN                 (1 << 15)
#define AFE_VDB_CON                 (*(volatile uint16_t*)(AFE_base + 0x0014))
#define VBTSLEN(v)                  (((v) & 0x07) << 0)
#define VBTSYNC                     (1 << 3)
#define VBTON                       (1 << 4)
#define VDAION                      (1 << 5)
#define VBT_LOOP                    (1 << 10)
#define VBT_LOOP_BACK               (1 << 12)
#define PCM_CK_MODE_256K            (0 << 14)
#define PCM_CK_MODE_512K            (1 << 14)
#define PCM_CK_MODE_1024K           (2 << 14)
#define PCM_CK_MODE_2048K           (3 << 14)
#define AFE_VLB_CON                 (*(volatile uint16_t*)(AFE_base + 0x0018))
#define VDECINMODE                  (1 << 0)
#define VINTINMODE                  (! << 1)
#define VDAPIN_CH0                  (1 << 2)
#define VDAPIN_CH1                  (1 << 3)
#define VDSPCSMODE                  (1 << 4)
#define VDSPBYPASS                  (! << 5)
#define VININSEL                    (1 << 6)
#define ENGEN_OPT                   (1 << 7)
#define AFE_VMCU_CON3               (*(volatile uint16_t*)(AFE_base + 0x001C))
#define SDM_CK_PHASE                (1 << 0)
#define SDMLP_DLTOUL                (1 << 4)
#define VSDN_DATA_MONO              (1 << 5)
#define VSDMLP_ULTODL               (1 << 8)

#define AFE_AMCU_CON0               (*(volatile uint16_t*)(AFE_base + 0x0020))
#define AIRQON                      (1 << 0)
#define AFE_AMCU_CON1               (*(volatile uint16_t*)(AFE_base + 0x0024))
#define AMUTEL                      (1 << 2)
#define AMUTER                      (1 << 3)
#define ARAMPSP(v)                  (((v) & 0x03) << 4)
#define AFS(v)                      (((v) & 0x0F) << 6)
#define I2S_1XOUT_SEL               (1 << 12)
#define MONO_SEL                    (1 << 14)
#define AFE_EDI_CON                 (*(volatile uint16_t*)(AFE_base + 0x0028))
#define EDI_EN                      (1 << 0)
#define EDI_FMT                     (1 << 1)
#define EDI_WCYCLE(v)               (((v) & 0x1F) << 2)
#define EDI_DIR                     (1 << 8)
#define EDI_LPBK_MODE               (1 << 9)
#define ULTOEDI                     (1 << 10)
#define I2S_OUT_MODE_1X             (0 << 12)
#define I2S_OUT_MODE_2X             (1 << 12)
#define I2S_OUT_MODE_4X             (2 << 12)
#define UL_TOI2SDSP                 (1 << 14)
#define EDI_PAD_EN                  (1 << 15)
#define AFE_AMCU_CON2               (*(volatile uint16_t*)(AFE_base + 0x002C))
#define ASDM_GAIN(v)                (((v) & 0x3F) << 0)
#define EDI_SEL                     (1 << 6)
#define PREDIT_EN                   (! << 10)
#define EDI_WS_OPTION               (1 << 14)                                                       // Optional setting for I2S. Do not touch the bit!
#define ADC_COMP_EN                 (! << 15)
#define AFE_DAC_TEST                (*(volatile uint16_t*)(AFE_base + 0x0030))
#define FREQ_DIV(v)                 (((v) & 0x00FF) << 0)
#define AMP_DIV(v)                  (((v) & 0x07) << 8)
#define SIN_OUT_MUTE                (1 << 13)
#define ADAC_AUDIO                  (0 << 14)
#define ADAC_SINUS                  (1 << 14)
#define VDAC_VOICE                  (0 << 15)
#define VDAC_SINUS                  (1 << 15)
#define AFE_VAM_SET                 (*(volatile uint16_t*)(AFE_base + 0x0034))
#define PER_VAL(v)                  (((v) & 0x07) << 0)
#define AIRQ2VIRQ                   (1 << 15)                                                       // 0: Voice interrupt/audio interrupt, 1: Audio interrupt/no interrupt
#define AFE_AMCU_CON3               (*(volatile uint16_t*)(AFE_base + 0x0038))
#define ARE_A2(v)                   (((v) & 0x0FFF) << 0)
#define AFE_AMCU_CON4               (*(volatile uint16_t*)(AFE_base + 0x003C))
#define ARE_A3(v)                   (((v) & 0x0FFF) << 0)
#define AFE_DC_DBG_1                (*(volatile uint16_t*)(AFE_base + 0x0040))
#define AFE_DC_DBG_2                (*(volatile uint16_t*)(AFE_base + 0x0044))
#define AFE_DC_DBG_3                (*(volatile uint16_t*)(AFE_base + 0x0048))
#define AFE_ACHECK_SUM_R            (*(volatile uint16_t*)(AFE_base + 0x0140))
#define AFE_ACHECK_SUM_L            (*(volatile uint16_t*)(AFE_base + 0x0144))
#define AFE_MUTE_STA                (*(volatile uint16_t*)(AFE_base + 0x0148))
#define MUTE_DONE_R                 (1 << 0)
#define MUTE_DONE_L                 (1 << 1)
#define UNMUTE_DONE_R               (1 << 2)
#define UNMUTE_DONE_L               (1 << 3)
#define AFE_AMCU_CON5               (*(volatile uint16_t*)(AFE_base + 0x0180))
#define SDM_CK_PHASE                (1 << 0)
#define ASDMLP_ULTODL               (1 << 4)
#define ASDM_DATA_MONO              (1 << 5)
#define SDMLP_ULTODL                (1 << 8)
#define AFE_AMCU_CON6               (*(volatile uint16_t*)(AFE_base + 0x0184))
#define RCH_AUDIO_DCOFFSET_VALUE(v) (v)
#define AFE_AMCU_CON7               (*(volatile uint16_t*)(AFE_base + 0x0188))
#define LCH_AUDIO_DCOFFSET_VALUE(v) (v)
#define AFE_DBG_RD_PRE              (*(volatile uint16_t*)(AFE_base + 0x0190))
#define AFE_DBG_MD_CON0             (*(volatile uint16_t*)(AFE_base + 0x0194))
#define AFE_DBG_MD_CON1             (*(volatile uint16_t*)(AFE_base + 0x0198))
#define AFE_DBG_APB_STATUS          (*(volatile uint16_t*)(AFE_base + 0x019C))
#define AFE_VMCU_CON4               (*(volatile uint16_t*)(AFE_base + 0x01A0))
#define DC_OFFSET_VALUE(v)          (v)
#define AFE_VMCU_CON6               (*(volatile uint16_t*)(AFE_base + 0x01A8)) //(?)
#define AFE_VMCU_CON5               (*(volatile uint16_t*)(AFE_base + 0x01AC))
#define D3P25M_SEL                  (1 << 0)
#define DIG_MIC_EN                  (1 << 4)
#define CK_PHASE                    (1 << 9)
#define RCH_PHASE(v)                (((v) & 0x07) << 10)
#define LCH_PHASE(v)                (((v) & 0x07) << 13)
#define AFE_CMPR_CNTR               (*(volatile uint16_t*)(AFE_base + 0x01CC))
#define AFE_APBMEM_RD_DAT           (*(volatile uint16_t*)(AFE_base + 0x01E4))
#define AFE_APBMEM_RD               (*(volatile uint16_t*)(AFE_base + 0x01E8))
#define AFE_PC_1X_IDX               (*(volatile uint16_t*)(AFE_base + 0x01EC))
#define AFE_DBG_SIG                 (*(volatile uint16_t*)(AFE_base + 0x01F0))
#define AFE_PC_OUT_DBG              (*(volatile uint16_t*)(AFE_base + 0x01F4))
#define AFE_DBG_1XDAT               (*(volatile uint16_t*)(AFE_base + 0x01F8))
#define AFE_COSIM_RG                (*(volatile uint16_t*)(AFE_base + 0x0200))
#define UL_SINE_OUT                 (1 << 0)
#define FPGA_DL2UL_LPBK             (1 << 1)
#define AFE_MCU_CON0                (*(volatile uint16_t*)(AFE_base + 0x0210))
#define AFE_ON                      (1 << 0)
#define AFE_MCU_CON1                (*(volatile uint16_t*)(AFE_base + 0x0214))
#define A_IF_UL_ON                  (1 << 0)
#define UDSP_UL_ON                  (1 << 1)
#define A_IF_DL_ON                  (1 << 2)
#define UDSP_DL_ON                  (1 << 3)
#define AFE_SLV_I2S_CON             (*(volatile uint32_t*)(AFE_base + 0x0300))

#define ABBA_WR_PATH0               (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0000))
#define ABBA_VBITX_CON0             (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0050))
#define RG_VCFG_1                   (1 << 10)
#define RG_VPWDB_PGA                (1 << 5)
#define ABBA_VBITX_CON1             (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0054))
#define RG_VPWDB_ADC                (1 << 6)
#define RG_VREF24_EN                (1 << 2)
#define RG_VCM14_EN                 (1 << 1)
#define ABBA_VBITX_CON2             (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0058))
#define ABBA_VBITX_CON3             (*(volatile uint16_t*)(ABBSYS_SD_base + 0x005C))
#define ABBA_VBITX_CON4             (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0060))
#define RG_VPWDB_MBIAS              (1 << 1)
#define ABBA_VBITX_CON5             (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0064))
#define ABBA_AUDIODL_CON0           (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0080))
#define RG_AUDIBIASPWRUP            (1)
#define RG_AUDHPRPWRUP              (1 << 2)
#define RG_AUDHPLPWRUP              (1 << 3)
#define RG_AUDHSPWRUP               (1 << 4)
#define RG_AUDDACRPWRUP             (1 << 5)
#define RG_AUDDACLPWRUP             (1 << 6)
#define ABBA_AUDIODL_CON1           (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0084))
#define ABBA_AUDIODL_CON2           (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0088))
#define ABBA_AUDIODL_CON3           (*(volatile uint16_t*)(ABBSYS_SD_base + 0x008C))
#define ABBA_AUDIODL_CON4           (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0090))
#define RG_DEPOP_VCM_EN             (1)
#define RG_DEPOP_CHARGEOPTION       (1 << 5)
#define RG_ADEPOP_EN                (1 << 6)
#define ABBA_AUDIODL_CON5           (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0094))
#define ABBA_AUDIODL_CON6           (*(volatile uint16_t*)(ABBSYS_SD_base + 0x0098))
#define ABBA_AUDIODL_CON7           (*(volatile uint16_t*)(ABBSYS_SD_base + 0x009C))
#define ABBA_AUDIODL_CON8           (*(volatile uint16_t*)(ABBSYS_SD_base + 0x00A0))
#define RG_LCLDO_TBST_EN            (1 << 1)                                                        // Audio/Voice TOP bias current from ABB TOP
#define ABBA_AUDIODL_CON9           (*(volatile uint16_t*)(ABBSYS_SD_base + 0x00A4))
#define ABBA_AUDIODL_CON10          (*(volatile uint16_t*)(ABBSYS_SD_base + 0x00A8))
#define RG_AUDHSBIAS                (1 << 12)
#define ABBA_AUDIODL_CON11          (*(volatile uint16_t*)(ABBSYS_SD_base + 0x00AC))
#define ABBA_AUDIODL_CON12          (*(volatile uint16_t*)(ABBSYS_SD_base + 0x00B0))
#define AUD_ZCD_ENABLE              (1)
#define ABBA_AUDIODL_CON13          (*(volatile uint16_t*)(ABBSYS_SD_base + 0x00B4))
#define ABBA_AUDIODL_CON14          (*(volatile uint16_t*)(ABBSYS_SD_base + 0x00B8))
#define ABBA_AUDIODL_CON15          (*(volatile uint16_t*)(ABBSYS_SD_base + 0x00BC))
#define ABBA_AUDIODL_CON16          (*(volatile uint16_t*)(ABBSYS_SD_base + 0x00C0))
#define RG_AMUTER                   (1 << 1)
#define RG_AMUTEL                   (1)
#define ABBA_AUDIODL_CON17          (*(volatile uint16_t*)(ABBSYS_SD_base + 0x00C4))
#define ABBA_AUDIODL_CON18          (*(volatile uint16_t*)(ABBSYS_SD_base + 0x00C8))

#define AC_ODS_CON                  (*(volatile uint16_t*)(MIXED_base + 0x0000))                    // Analog Chip Output Driving Strength Control Register
#define ACIF_AC_HW_VER              (*(volatile uint16_t*)(MIXED_base + 0x0004))                    // Mix-signal Chip Version Control
#define AFE_VAG_CON                 (*(volatile uint16_t*)(MIXED_base + 0x0100))                    // AFE Voice Analog Gain Control Register
#define AFE_VAC_CON0                (*(volatile uint16_t*)(MIXED_base + 0x0104))                    // AFE Voice Analog-Circuit Control Register 0
#define AFE_VAC_CON1                (*(volatile uint16_t*)(MIXED_base + 0x0108))                    // AFE Voice Analog-Circuit Control Register 1
#define AFE_VAPDN_CON               (*(volatile uint16_t*)(MIXED_base + 0x010C))                    // AFE Voice Analog Power Down Control Register
#define VAPDN_BIAS_DAC_ON           0x024
#define VAPDN_BIAS_LNA_ON           0x030
#define VAPDN_BIAS_LNA_ADC_ON       0x038
#define AFE_AAG_CON                 (*(volatile uint16_t*)(MIXED_base + 0x0200))                    // AFE Audio Analog Gain Control Register
#define AFE_AAC_CON                 (*(volatile uint16_t*)(MIXED_base + 0x0204))                    // AFE Audio Analog-Circuit Control Register
#define AFE_AAPDN_CON               (*(volatile uint16_t*)(MIXED_base + 0x0208))                    // AFE Audio Analog Power Down Control Register
#define AAPDN_POWER_DOWN            0x000
#define AAPDN_BIAS_DAC_ON           0x01C
#define AAPDN_BIAS_BUF_ON           0x013
#define AAPDN_ALL_ON                0x0FF
#define AAPDN_MASK                  0x0FF
#define APC_AC_CON                  (*(volatile uint16_t*)(PLL_base + 0x0600))                      // APC DAC Analog-Circuit Control Register
#define AUX_AC_CON                  (*(volatile uint16_t*)(PLL_base + 0x0700))                      // Auxiliary ADC Analog-Circuit Control Register

#define MD2GSYS_CG_CON0             (*(volatile uint16_t*)(MD2GCONFG_base + 0x000))                 // Power Down Control 0 Register
#define MD2GSYS_CG_CON2             (*(volatile uint16_t*)(MD2GCONFG_base + 0x008))                 // Power Down Control 2 Register
#define PDN_CON2_VAFE               (1 << 8)
#define PDN_CON2_AAFE               (1 << 12)                                                       // or == PDN_CON2_VAFE
#define MD2GSYS_CG_CON4             (*(volatile uint16_t*)(MD2GCONFG_base + 0x030))                 // Power Down Control 4 Register
#define MD2GSYS_CG_SET0             (*(volatile uint16_t*)(MD2GCONFG_base + 0x010))                 // Power Down Disable 0 Register
#define MD2GSYS_CG_SET2             (*(volatile uint16_t*)(MD2GCONFG_base + 0x018))                 // Power Down Disable 2 Register
#define MD2GSYS_CG_SET4             (*(volatile uint16_t*)(MD2GCONFG_base + 0x034))                 // Power Down Disable 4 Register
#define MD2GSYS_CG_CLR0             (*(volatile uint16_t*)(MD2GCONFG_base + 0x020))                 // Power Down Enable 0 Register
#define MD2GSYS_CG_CLR2             (*(volatile uint16_t*)(MD2GCONFG_base + 0x028))                 // Power Down Enable 2 Register
#define MD2GSYS_CG_CLR4             (*(volatile uint16_t*)(MD2GCONFG_base + 0x038))                 // Power Down Enable 4 Register

extern void AFE_Chip_Init(void);
extern void AFE_TurnOnAudioClock(uint8_t clock);
extern void AFE_SwitchHPon(void);
extern void AFE_SwitchHSon(void);

#endif /* _AFE_H_ */
