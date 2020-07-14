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

#define AFE_MCU_CON0                (*(volatile uint16_t*)(AFE_base + 0x0210))
#define AFE_MCU_CON1                (*(volatile uint16_t*)(AFE_base + 0x0214))
#define AFE_VMCU_CON0               (*(volatile uint16_t*)(AFE_base + 0x0000))
#define AFE_VMCU_CON1               (*(volatile uint16_t*)(AFE_base + 0x000C))
#define AFE_VMCU_CON2               (*(volatile uint16_t*)(AFE_base + 0x0010))
#define AFE_VMCU_CON3               (*(volatile uint16_t*)(AFE_base + 0x001C))
#define AFE_VMCU_CON4               (*(volatile uint16_t*)(AFE_base + 0x01A0))
#define AFE_VMCU_CON6               (*(volatile uint16_t*)(AFE_base + 0x01A8))
#define AFE_VDB_CON                 (*(volatile uint16_t*)(AFE_base + 0x0014))
#define AFE_VLB_CON                 (*(volatile uint16_t*)(AFE_base + 0x0018))
#define AFE_AMCU_CON0               (*(volatile uint16_t*)(AFE_base + 0x0020))
#define AFE_AMCU_CON1               (*(volatile uint16_t*)(AFE_base + 0x0024))
#define AFE_AMCU_CON2               (*(volatile uint16_t*)(AFE_base + 0x002C))
#define AFE_AMCU_CON3               (*(volatile uint16_t*)(AFE_base + 0x0038))
#define AFE_AMCU_CON4               (*(volatile uint16_t*)(AFE_base + 0x003C))
#define AFE_AMCU_CON5               (*(volatile uint16_t*)(AFE_base + 0x0180))
#define AFE_AMCU_CON6               (*(volatile uint16_t*)(AFE_base + 0x0184))
#define AFE_AMCU_CON7               (*(volatile uint16_t*)(AFE_base + 0x0188))
#define AFE_EDI_CON                 (*(volatile uint16_t*)(AFE_base + 0x0028))
#define AFE_DAC_TEST                (*(volatile uint16_t*)(AFE_base + 0x0030))
#define AFE_VAM_SET                 (*(volatile uint16_t*)(AFE_base + 0x0034))

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

#endif /* _AFE_H_ */
