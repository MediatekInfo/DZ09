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
#ifndef _PMU_H_
#define _PMU_H_

#define WR_PATH_CON0                (*(volatile uint16_t *)(PMU_BASE + 0x0000))
#define CCI_ACD_MODE                (1 << 0)
#define CCI_ABIST_MODE              (1 << 1)
#define CCI_PRST_MODE               (1 << 2)
#define CCI_SEL_26M                 (1 << 5)
#define AUX_PWDB                    (1 << 8)

#define AFUNC_XOSC_CON0             (*(volatile uint32_t *)(PMU_BASE + 0x0010))

#define ABIST_CON0                  (*(volatile uint32_t *)(PMU_BASE + 0x0020))
#define ABIST_MON_CFG               (1 << 8)
#define ABIST_PASS                  (1 << 14)
#define ABIST_FINISH                (1 << 15)
#define ABIST_CON1                  (*(volatile uint32_t *)(PMU_BASE + 0x0024))
#define ABIST_LMON_SEL(v)           (((v) & 0xFF) << 0)
#define ABIST_HMON_SEL(v)           (((v) & 0xFF) << 8)
#define ABIST_CON2                  (*(volatile uint32_t *)(PMU_BASE + 0x0028))
#define ABIST_LMON_OUT(v)           (((v) << 0) & 0x0F)
#define ABIST_HMON_OUT(v)           (((v) << 4) & 0x0F)
#define ABIST_MON_CHG               (1 << 15)
#define ABIST_CON3                  (*(volatile uint32_t *)(PMU_BASE + 0x002C))
#define ABIST_LMON_DATA(v)          (((v) << 0 & 0x0F)
#define ABIST_HMON_DATA(v)          (((v) << 4 & 0x0F)


#define APB_CON0                    (*(volatile uint16_t *)(PMU_BASE + 0x0050))
#define CCI_C2A_SIM1_VOSEL          (1 << 8)                                                        // 0 - 1.8V/1 - 3.0V
#define C2A_SIM1SEL_SEL             (1 << 9)
#define CCI_C2A_SIM2_VOSEL          (1 << 12)                                                       // 0 - 1.8V/1 - 3.0V
#define C2A_SIM2SEL_SEL             (1 << 13)
#define ACCDET_CON0                 (*(volatile uint16_t *)(PMU_BASE + 0x0060))                     // Not defined in datasheet

#define ABBA_AUX_CON0               (*(volatile uint16_t *)(PMU_BASE + 0x0080))                     // Not defined in datasheet
#define ABBA_AUX_CON1               (*(volatile uint16_t *)(PMU_BASE + 0x0084))                     // Not defined in datasheet
#define ABBA_AUX_CON2               (*(volatile uint16_t *)(PMU_BASE + 0x0088))                     // Not defined in datasheet
#define ABBA_AUX_CON3               (*(volatile uint16_t *)(PMU_BASE + 0x008C))                     // Not defined in datasheet
#define ABBA_AUX_CON4               (*(volatile uint16_t *)(PMU_BASE + 0x0090))                     // Not defined in datasheet
#define ABBA_AUX_CON5               (*(volatile uint16_t *)(PMU_BASE + 0x0094))                     // Not defined in datasheet
#define AUXADC_SPL_NUM(v)           (((v) & 0xFF) << 8)                                             // adc_hw_h
#define ABBA_AUX_CON6               (*(volatile uint16_t *)(PMU_BASE + 0x0098))                     // Not defined in datasheet

#define LDO_CON0                    (*(volatile uint16_t *)(PMU_BASE + 0x00C0))
#define CCI_SRCCLKEN                (1 << 0)
#define VSF_SRCLKENA_SEL(v)         (((v) & 0x03) << 2)
#define VRF_SRCLKENA_SEL(v)         (((v) & 0x03) << 4)
#define VA_SRCLKENA_SEL(v)          (((v) & 0x03) << 8)
#define VCORE_SRCLKENA_SEL(v)       (((v) & 0x03) << 10)
#define VMC_SRCLKENA_SEL(v)         (((v) & 0x03) << 12)
#define VUSB_SRCLKENA_SEL(v)        (((v) & 0x03) << 14)
#define LDO_CON1                    (*(volatile uint16_t *)(PMU_BASE + 0x00C4))
#define RG_DLDO_RESERVE             0xFF00
#define RG_ALDOS_RESER              0x00FF
#define LDO_CON2                    (*(volatile uint16_t *)(PMU_BASE + 0x00C8))
#define VIBR_SRCLKENA_SEL(v)        (((v) & 0x03) << 2)
#define VCAMA_SRCLKENA_SEL(v)       (((v) & 0x03) << 4)
#define VSIM2_SRCLKENA_SEL(v)       (((v) & 0x03) << 8)
#define VSIM1_SRCLKENA_SEL(v)       (((v) & 0x03) << 10)
#define VIO28_SRCLKENA_SEL(v)       (((v) & 0x03) << 12)
#define VIO18_SRCLKENA_SEL(v)       (((v) & 0x03) << 14)

#define VRF_CON0                    (*(volatile uint16_t *)(PMU_BASE + 0x0100))
#define RG_VRF_EN                   (1 << 0)
#define VRF_ON_SEL                  (1 << 1)
#define RG_VRF_NDIS_EN              (1 << 10)
#define QI_VRF_STATAUS              (1 << 15)
#define VRF_CON1                    (*(volatile uint16_t *)(PMU_BASE + 0x0104))
#define QI_VRF_LP_EN                (1 << 0)
#define VRF_MODE_SEL                (1 << 4)
#define RG_VRF_CAL(v)               (((v) & 0x0F) << 4)

#define VA_CON0                     (*(volatile uint16_t *)(PMU_BASE + 0x0120))
#define RG_VA_EN                    (1 << 0)
#define RG_VA_NDIS_EN               (1 << 10)
#define QI_VA_STATUS                (1 << 15)
#define VA_CON1                     (*(volatile uint16_t *)(PMU_BASE + 0x0124))
#define QI_VA_LP_EN                 (1 << 0)
#define VA_MODE_SEL                 (1 << 4)
#define RG_VA_CAL(v)                (((v) & 0x0F) << 4)

#define VCAMA_CON0                  (*(volatile uint16_t *)(PMU_BASE + 0x0130))
#define RG_VCAMA_EN                 (1 << 0)
#define RG_VCAMA_ON_SEL             (1 << 1)
#define VCAMA_18V                   (0 << 4)
#define VCAMA_28V                   (1 << 4)                                                        // Also used for integrated FM radio !?!?
#define RG_VCAMA_NDIS_EN            (1 << 10)
#define QI_VCAMA_STATUS             (1 << 15)
#define VCAMA_CON1                  (*(volatile uint16_t *)(PMU_BASE + 0x0134))
#define QI_VCAMA_LP_EN              (1 << 0)
#define RG_VCAMA_CAL(v)             (((v) & 0x0F) << 4)
#define VCAMA_CON2                  (*(volatile uint16_t *)(PMU_BASE + 0x0138))
#define VCAMA_STB_TD(v)             (((v) & 0x03) << 6)

#define VIO28_CON0                  (*(volatile uint16_t *)(PMU_BASE + 0x0150))
#define RG_VIO28_EN                 (1 << 0)
#define RG_VIO28_NDIS_EN            (1 << 10)
#define QI_VIO28_STATUS             (1 << 15)
#define VIO28_CON1                  (*(volatile uint16_t *)(PMU_BASE + 0x0154))
#define RG_VIO28_CAL(v)             (((v) & 0x0F) << 4)

#define VUSB_CON0                   (*(volatile uint16_t *)(PMU_BASE + 0x0160))
#define RG_VUSB_EN                  (1 << 0)
#define RG_VUSB_NDIS_EN             (1 << 10)
#define QI_VUSB_STATUS              (1 << 15)
#define VUSB_CON1                   (*(volatile uint16_t *)(PMU_BASE + 0x0164))
#define RG_VUSB_CAL(v)              (((v) & 0x0F) << 4)

#define VSIM1_CON0                  (*(volatile uint16_t *)(PMU_BASE + 0x0180))
#define RG_VSIM1_EN                 (1 << 0)
#define RG_VSIM1_VOSEL              (1 << 4)
#define RG_VSIM1_NDIS_EN            (1 << 10)
#define QI_VSIM1_STATUS             (1 << 15)
#define VSIM1_CON1                  (*(volatile uint16_t *)(PMU_BASE + 0x0184))
#define QI_VSIM1_LP_EN              (1 << 0)
#define VSIM1_MODE_SEL              (1 << 1)
#define RG_VSIM1_CAL(v)             (((v) & 0x0F) << 4)
#define VSIM1_CON2                  (*(volatile uint16_t *)(PMU_BASE + 0x0188))
#define VSIM1_GPLDO_EN              (1 << 1)
#define VSIM1_STB_TD(v)             (((v) & 0x03) << 6)

#define VSIM2_CON0                  (*(volatile uint16_t *)(PMU_BASE + 0x0190))
#define RG_VSIM2_EN                 (1 << 0)
#define RG_VSIM2_VOSEL              (1 << 4)
#define RG_VSIM2_NDIS_EN            (1 << 10)
#define QI_VSIM2_STATUS             (1 << 15)
#define VSIM2_CON1                  (*(volatile uint16_t *)(PMU_BASE + 0x0194))
#define QI_VSIM2_LP_EN              (1 << 0)
#define VSIM2_MODE_SEL              (1 << 1)
#define RG_VSIM2_CAL(v)             (((v) & 0x0F) << 4)
#define VSIM2_CON2                  (*(volatile uint16_t *)(PMU_BASE + 0x0198))
#define VSIM2_GPLDO_EN              (1 << 1)
#define VSIM2_STB_TD(v)             (((v) & 0x03) << 6)

#define VRTC_CON0                   (*(volatile uint16_t *)(PMU_BASE + 0x01A0))
#define RG_VRTC_EN                  (1 << 0)
#define RG_VRTC_VO28                (0 << 4)
#define RG_VRTC_VO33                (1 << 4)

#define VIBR_CON0                   (*(volatile uint16_t *)(PMU_BASE + 0x01B0))
#define RG_VIBR_EN                  (1 << 0)
#define VIBR_ON_SEL                 (1 << 1)                                                        /* 0 - Enable with EXT_SRCLKENA or BT_SRCLKENA or TOPSM_SRCLKENA
/                                                                                                      1 - Enable with RG_VIBR_EN */
#define RG_VIBR_VOSEL(v)            (((v) & 0x03) << 4)
#define VIBR_VO18V                  0
#define VIBR_VO28V                  2
#define VIBR_VO30V                  3
#define RG_VIBR_NDIS_EN             (1 << 10)                                                       // VIBR POWER DOWN NMOS Enable
#define RG_VIBR_SS_BYPASS           (1 << 11)
#define QI_VIBR_STATUS              (1 << 15)
#define VIBR_CON1                   (*(volatile uint16_t *)(PMU_BASE + 0x01B4))
#define QI_VIBR_LP_EN               (1 << 0)
#define RG_VIBR_CAL(v)              (((v) & 0x0F) << 4)
#define VIBR_CON2                   (*(volatile uint16_t *)(PMU_BASE + 0x01B8))
#define VIBR_STB_TD(v)              (((v) & 0x03) << 6)

#define VMC_CON0                    (*(volatile uint16_t *)(PMU_BASE + 0x01C0))
#define RG_VMC_EN                   (1 << 0)
#define VMC_ON_SEL                  (1 << 1)
#define RG_VMC_VOSEL_MASK_OFFSET    4
#define RG_VMC_VOSEL(v)             (((v) & 0x07) << RG_VMC_VOSEL_MASK_OFFSET)
typedef enum tag_VMC
{
    VMC_VO18V = 0,
    VMC_VO28V = 2,
    VMC_VO30V = 3,
    VMC_VO33V = 4
} TVMC;
#define RG_VMC_NDIS_EN              (1 << 10)
#define RG_VMC_SS_BYPASS            (1 << 11)
#define QI_VMC_STATUS               (1 << 15)
#define VMC_CON1                    (*(volatile uint16_t *)(PMU_BASE + 0x01C4))
#define QI_VMC_LP_EN                (1 << 0)
#define RG_VMC_CAL(v)               (((v) & 0x0F) << 4)
#define VMC_CON2                    (*(volatile uint16_t *)(PMU_BASE + 0x01C8))
#define RG_VMC_IL_CAL               (1 << 0)
#define RG_VMC_COMP_EN              (1 << 2)
#define RG_VMC_AWL_EN               (1 << 3)
#define VMC_STB_TD(v)               (((v) & 0x03) << 6)
#define VMC_CON3                    (*(volatile uint16_t *)(PMU_BASE + 0x01CC))
#define VMC_VOSEL_SEL               (1 << 2)

#define VSF_CON0                    (*(volatile uint16_t *)(PMU_BASE + 0x01D0))
#define RG_VSF_EN                   (1 << 0)
#define RG_VSF_VOSEL(v)             (((v) & 0x07) << 4)
#define VSF_VO186V                  1
#define VSF_VO28V                   2
#define VSF_VO30V                   3
#define VSF_VO33V                   4
#define RG_VSF_NDIS_EN              (1 << 10)
#define QI_VSF_STATUS               (1 << 15)
#define VSF_CON1                    (*(volatile uint16_t *)(PMU_BASE + 0x01D4))
#define QI_VSF_LP_EN                (1 << 0)
#define VSF_MODE_SEL                (1 << 1)
#define RG_VSF_CAL(v)               (((v) & 0x0F) << 4)
#define VSF_CON2                    (*(volatile uint16_t *)(PMU_BASE + 0x01D8))
#define RG_VSF_COMP_EN              (1 << 0)
#define RG_VSF_AWL_EN               (1 << 1)
#define RG_VSF_IL_CAL(v)            (((v) & 0x03) << 2)
#define VSF_STB_TD(v)               (((v) & 0x03) << 6)
#define VSF_CON3                    (*(volatile uint16_t *)(PMU_BASE + 0x01DC))
#define VSF_AUTOFF_EN               (1 << 0)
#define VSF_VOSEL_SEL               (1 << 2)
#define VSF_AUTOFF_DLY_SEL(v)       (((v) & 0x0F) << 4)

#define VIO18_CON0                  (*(volatile uint16_t *)(PMU_BASE + 0x0200))
#define RG_VIO18_EN                 (1 << 0)
#define RG_VIO18_NDIS_EN            (1 << 10)
#define QI_VIO18_STATUS             (1 << 15)
#define VIO18_CON1                  (*(volatile uint16_t *)(PMU_BASE + 0x0204))
#define RG_VIO18_CAL(v)             (((v) & 0x0F) << 4)

#define VCORE_CON0                  (*(volatile uint16_t *)(PMU_BASE + 0x0230))
#define RG_VCORE_EN                 (1 << 0)
#define RG_VCORE_VOSEL(v)           (((v) & 0x1F) << 4)
#define VCORE_VO11V                 0x00
#define VCORE_VO1125V               0x01
#define VCORE_VO115V                0x02
#define VCORE_VO1175V               0x03
#define VCORE_VO12V                 0x04
#define VCORE_VO1225V               0x05
#define VCORE_VO125V                0x06
#define VCORE_VO1275V               0x07
#define VCORE_VO13V                 0x08
#define VCORE_VO1325V               0x09
#define VCORE_VO135V                0x0A
#define VCORE_VO1375V               0x0B
#define VCORE_VO14V                 0x0C
#define VCORE_VO1425V               0x0D
#define VCORE_VO145V                0x0E
#define VCORE_VO1475V               0x0F
#define VCORE_VO07V                 0x10
#define VCORE_VO0725V               0x11
#define VCORE_VO075V                0x12
#define VCORE_VO0775V               0x13
#define VCORE_VO08V                 0x14
#define VCORE_VO0825V               0x15
#define VCORE_VO085V                0x16
#define VCORE_VO0875V               0x17
#define VCORE_VO09V                 0x18
#define VCORE_VO0925V               0x19
#define VCORE_VO095V                0x1A
#define VCORE_VO0975V               0x1B
#define VCORE_VO1V                  0x1C
#define VCORE_VO1025V               0x1D
#define VCORE_VO105V                0x1E
#define VCORE_VO1075V               0x1F
#define RG_VCORE_NDIS_EN            (1 << 10)
#define VCORE_OC_FLAG               (1 << 14)
#define QI_VCORE_STATUS             (1 << 15)
#define VCORE_CON1                  (*(volatile uint16_t *)(PMU_BASE + 0x0234))
#define RG_VCORE_CAL(v)             (((v) & 0x0F) << 4)
//#define VCORE_CON2                  (*(volatile uint16_t *)(PMU_base + 0x0234))
#define VCORE_CON3                  (*(volatile uint16_t *)(PMU_BASE + 0x023C))
#define VCORE_OC_CTRL               (1 << 0)
#define VCORE_SOFTCH_EN             (1 << 3)
#define VCORE_VO_SLEEP(v)           (((v) & 0x1F) << 4)
#define VCORE_VOS11V                0x00
#define VCORE_VOS1125V              0x01
#define VCORE_VOS115V               0x02
#define VCORE_VOS1175V              0x03
#define VCORE_VOS12V                0x04
#define VCORE_VOS1225V              0x05
#define VCORE_VOS125V               0x06
#define VCORE_VOS1275V              0x07
#define VCORE_VOS13V                0x08
#define VCORE_VOS1325V              0x09
#define VCORE_VOS135V               0x0A
#define VCORE_VOS1375V              0x0B
#define VCORE_VOS14V                0x0C
#define VCORE_VOS1425V              0x0D
#define VCORE_VOS145V               0x0E
#define VCORE_VOS1475V              0x0F
#define VCORE_VOS07V                0x10
#define VCORE_VOS0725V              0x11
#define VCORE_VOS075V               0x12
#define VCORE_VOS0775V              0x13
#define VCORE_VOS08V                0x14
#define VCORE_VOS0825V              0x15
#define VCORE_VOS085V               0x16
#define VCORE_VOS0875V              0x17
#define VCORE_VOS09V                0x18
#define VCORE_VOS0925V              0x19
#define VCORE_VOS095V               0x1A
#define VCORE_VOS0975V              0x1B
#define VCORE_VOS1V                 0x1C
#define VCORE_VOS1025V              0x1D
#define VCORE_VOS105V               0x1E
#define VCORE_VOS1075V              0x1F

#define CHR_CON0                    (*(volatile uint16_t *)(PMU_BASE + 0x0A00))
#define RG_VCDT_HV_EN               (1 << 0)
#define RGS_CHR_LDO_DET             (1 << 1)
#define RG_CSDAC_EN                 (1 << 3)
#define CHR_EN                      (1 << 4)
#define RGS_CHRDET                  (1 << 5)
#define RGS_VCDT_LV_DET             (1 << 6)
#define RGS_VCDT_HV_DET             (1 << 7)

#define RG_VCDT_LV_VTH(v)           (((v) & 0x0F) << 8)
#define LV_VTH_420V                 0x00
#define LV_VTH_425V                 0x01
#define LV_VTH_430V                 0x02
#define LV_VTH_435V                 0x03
#define LV_VTH_440V                 0x04
#define LV_VTH_445V                 0x05
#define LV_VTH_450V                 0x06
#define LV_VTH_455V                 0x07
#define LV_VTH_460V                 0x08
#define LV_VTH_600V                 0x09
#define LV_VTH_650V                 0x0A
#define LV_VTH_700V                 0x0B
#define LV_VTH_750V                 0x0C
#define LV_VTH_850V                 0x0D
#define LV_VTH_950V                 0x0E
#define LV_VTH_1050V                0x0F
#define RG_VCDT_HV_VTH(v)           (((v) & 0x0F) << 12)
#define HV_VTH_420V                 0x00
#define HV_VTH_425V                 0x01
#define HV_VTH_430V                 0x02
#define HV_VTH_435V                 0x03
#define HV_VTH_440V                 0x04
#define HV_VTH_445V                 0x05
#define HV_VTH_450V                 0x06
#define HV_VTH_455V                 0x07
#define HV_VTH_460V                 0x08
#define HV_VTH_600V                 0x09
#define HV_VTH_650V                 0x0A
#define HV_VTH_700V                 0x0B
#define HV_VTH_750V                 0x0C
#define HV_VTH_850V                 0x0D
#define HV_VTH_950V                 0x0E
#define HV_VTH_1050V                0x0F
#define CHR_CON1                    (*(volatile uint16_t *)(PMU_BASE + 0x0A04))
#define RG_VBAT_CV_EN               (1 << 0)
#define RG_VBAT_CC_EN               (1 << 1)
#define RGS_VBAT_CV_DET             (1 << 2)
#define RGS_VBAT_CC_DET             (1 << 3)
#define RG_VBAT_CC_VTH(v)           (((v) & 0x03) << 4)
#define CC_VTH_3300V                0x00
#define CC_VTH_3350V                0x01
#define CC_VTH_3400V                0x02
#define CC_VTH_3450V                0x03
#define RG_VBAT_CV_VTH(v)           (((v) & 0x1F) << 8)
#define CV_VTH_4200V                0x00
#define CV_VTH_37750V               0x03
#define CV_VTH_38000V               0x04
#define CV_VTH_38500V               0x05
#define CV_VTH_39000V               0x06
#define CV_VTH_40000V               0x07
#define CV_VTH_40500V               0x08
#define CV_VTH_41000V               0x09
#define CV_VTH_41250V               0x0A
#define CV_VTH_41375V               0x0B
#define CV_VTH_41500V               0x0C
#define CV_VTH_41625V               0x0D
#define CV_VTH_41750V               0x0E
#define CV_VTH_41875V               0x0F
#define CV_VTH_42000V               0x10
#define CV_VTH_42125V               0x11
#define CV_VTH_42250V               0x12
#define CV_VTH_42375V               0x13
#define CV_VTH_42500V               0x14
#define CV_VTH_42625V               0x15
#define CV_VTH_42750V               0x16
#define CV_VTH_43000V               0x17
#define CV_VTH_43250V               0x18
#define CV_VTH_43750V               0x1A
#define CV_VTH_44000V               0x1B
#define CV_VTH_44250V               0x1C
#define CV_VTH_22000V               0x1F
#define CHR_CON2                    (*(volatile uint16_t *)(PMU_BASE + 0x0A08))
#define RG_CS_VTH(v)                (((v) & 0x0F) << 0)
#define CS_VTH_1600mA               0x00
#define CS_VTH_1500mA               0x01
#define CS_VTH_1400mA               0x02
#define CS_VTH_1300mA               0x03
#define CS_VTH_1200mA               0x04
#define CS_VTH_1100mA               0x05
#define CS_VTH_1000mA               0x06
#define CS_VTH_900mA                0x07
#define CS_VTH_800mA                0x08
#define CS_VTH_700mA                0x09
#define CS_VTH_650mA                0x0A
#define CS_VTH_550mA                0x0B
#define CS_VTH_450mA                0x0C
#define CS_VTH_300mA                0x0D
#define CS_VTH_200mA                0x0E
#define CS_VTH_70mA                 0x0F
#define RG_CS_EN                    (1 << 8)
#define RGS_CS_DET                  (1 << 15)
//#define CHR_CON3                    (*(volatile uint16_t *)(PMU_base + 0x0A0C))
#define CHR_CON4                    (*(volatile uint16_t *)(PMU_BASE + 0x0A10))
#define RG_CSDAC_STP_INC(v)         (((v) & 0x07) << 0)
#define STP_INC_1_0cpS              0
#define STP_INC_1cpS                1
#define STP_INC_2cpS                2
#define STP_INC_3cpS                3
#define STP_INC_4cpS                4
#define STP_INC_5cpS                5
#define STP_INC_6cpS                6
#define STP_INC_7cpS                7
#define RG_CSDAC_STP_DEC(v)         (((v) & 0x07) << 4)
#define STP_DEC_1_0cpS              0
#define STP_DEC_1cpS                1
#define STP_DEC_2cpS                2
#define STP_DEC_3cpS                3
#define STP_DEC_4cpS                4
#define STP_DEC_5cpS                5
#define STP_DEC_6cpS                6
#define STP_DEC_7cpS                7
#define RG_CSDAC_STP(v)             (((v) & 0x07) << 8)
#define CSDAC_STP_1_0cpS            0
#define CSDAC_STP_1cpS              1
#define CSDAC_STP_2cpS              2
#define CSDAC_STP_3cpS              3
#define CSDAC_STP_4cpS              4
#define CSDAC_STP_5cpS              5
#define CSDAC_STP_6cpS              6
#define CSDAC_STP_7cpS              7
#define RG_CSDAC_DLY(v)             (((v) & 0x07) << 12)
#define STP_DLY16us                 0
#define STP_DLY32us                 1
#define STP_DLY64us                 2
#define STP_DLY128us                3
#define STP_DLY256us                4
#define STP_DLY512us                5
#define STP_DLY1024us               6
//#define STP_DLY256us                7                                                             // !!!!!!!!!!!!!!!!!
#define CHR_CON5                    (*(volatile uint16_t *)(PMU_BASE + 0x0A14))
#define RG_VBAT_OV_EN               (1 << 0)                                                        // Battery over-voltage for driving protection
#define RG_VBAT_OV_DEG              (1 << 1)                                                        // OV voltage detection deglitch enable
#define RGS_VBAT_OV_DET             (1 << 3)
#define RG_VBAT_OV_VTH(v)           (((v) & 0x07) << 4)
#define OV_VTH_415V                 0                                                               // 4.15...4.2
#define OV_VTH_425V                 1                                                               // 4.25...4.3
#define OV_VTH_435V                 2                                                               // 4.35...4.4
#define OV_VTH_440V                 3                                                               // 4.4 ...4.45
#define OV_VTH_3825V                4                                                               // 3.825...3.825
#define OV_VTH_425V_0               5                                                               // 4.25...4.3
#define OV_VTH_425V_1               6
#define OV_VTH_425V_2               7
#define RG_BATON_EN                 (1 << 8)
#define RG_BATON_HT_EN              (1 << 9)
#define RGS_BATON_UNDET             (1 << 10)                                                       // 1 - Not detected
#define RG_BATON_TDET_EN            (1 << 12)                                                       // Enable BATON Temperature detection
#define CHR_CON6                    (*(volatile uint16_t *)(PMU_BASE + 0x0A18))                     // ?????????? dcl_mixedsys6260_reg.h
#define RG_CSDAC_DATA(v)            (((v) & 0x03FF) << 0)                                           // RW????????
#define CHR_CON7                    (*(volatile uint16_t *)(PMU_BASE + 0x0A1C))                     // ?????????? dcl_mixedsys6260_reg.h
#define RG_PCHR_TESTMODE            (1 << 4)
#define RG_CSDAC_TESTMODE           (1 << 5)
#define RG_PCHR_RST                 (1 << 6)
#define RG_PCHR_FT_CTRL(v)          (((v) & 0x07) << 8)                                             // ??????????
#define CHR_CON8                    (*(volatile uint16_t *)(PMU_BASE + 0x0A20))
#define RGS_PCHR_FLAG_OUT           0x000F                                                          // Mask
#define RG_PCHR_FLAG_EN             (1 << 7)
#define RG_PCHR_FLAG_SEL(v)         (((v) & 0x3F) << 8)
#define CHR_CON9                    (*(volatile uint16_t *)(PMU_BASE + 0x0A24))
#define RG_CHRWDT_TD(v)             (((v) & 0x0F) << 0)
#define CHRWDT_4SEC                 0x00
#define CHRWDT_8SEC                 0x01
#define CHRWDT_16SEC                0x02
#define CHRWDT_32SEC                0x03
#define CHRWDT_128SEC               0x04
#define CHRWDT_256SEC               0x05
#define CHRWDT_512SEC               0x06
#define CHRWDT_1024SEC              0x07
#define CHRWDT_3000SEC              0x08
#define RG_CHRWDT_DIS               (0 << 4)
#define RG_CHRWDT_EN                (1 << 4)
#define RG_CHRWDT_WR                (1 << 5)
#define CHRWDT_INT_EN               (1 << 8)
#define CHRWDT_FLAG_WR              (1 << 9)
#define RGS_CHRWDT_OUT              (1 << 15)
#define CHR_CON10                   (*(volatile uint16_t *)(PMU_BASE + 0x0A28))
#define RG_UVLO_VTHL(v)             (((v) & 0x03) << 0)
#define RG_ADCIN_VBAT_EN            (1 << 4)
#define RG_ADCIN_VSEN_EN            (1 << 5)
#define RG_ADCIN_CHR_EN             (1 << 6)
#define RG_BGR_RSEL(v)              (((v) & 0x07) << 8)                                             // ??????????
#define RG_BGR_UNCHOP_PH            (1 << 12)                                                       // ??????????
#define RG_BGR_UNCHOP               (1 << 13)                                                       // ??????????
#define RG_USBDL_RST                (1 << 14)                                                       // Force leave USBDL_MODE
#define RG_USBDL_SET                (1 << 15)                                                       // Force enter USBDL_MODE
#define CHR_CON11                   (*(volatile uint16_t *)(PMU_BASE + 0x0A2C))                     // ?????????? dcl_mixedsys6260_reg.h
//#define RG_BC11_CMP_EN(v)           (((v) & 0x03) << 0)
#define COMP_EN_ON_DM               (1 << 0)
#define COMP_EN_ON_DP               (1 << 1)
//#define RG_BC11_VSRC_EN(v)          (((v) & 0x03) << 2)
#define VSRC_EN_ON_DM               (1 << 2)
#define VSRC_EN_ON_DP               (1 << 3)
//#define RG_BC11_IPD_EN(v)           (((v) & 0x03) << 4)
#define IPD_EN_ON_DM                (1 << 4)
#define IPD_EN_ON_DP                (1 << 5)
//#define RG_BC11_IPU_EN(v)         (((v) & 0x03) << 6)
#define IPU_EN_ON_DM                (1 << 6)
#define IPU_EN_ON_DP                (1 << 7)
//#define RG_BC11_VREF_VTH            (1 << 8)
#define COMP_VTH_00_325000          (0 << 8)
#define COMP_VTH_01_200000          (1 << 8)
#define RG_BC11_BIAS_EN             (1 << 9)
#define RG_BC11_BB_CTRL             (1 << 10)
#define RG_BC11_RST                 (1 << 11)
#define RGS_BC11_CMP_OUT            (1 << 15)
#define CHR_CON12                   (*(volatile uint16_t *)(PMU_BASE + 0x0A30))
#define RG_CSDAC_MODE               (1 << 2)
#define RG_TRACKING_EN              (1 << 4)
#define RG_HWCV_EN                  (1 << 6)
#define RG_ULC_DET_EN               (1 << 7)                                                        // Enables charger plug-out auto detection
#define RG_LOW_ICH_DB(v)            (((v) & 0x3F) << 8)                                             // Plug out HW detection de-bounce time (base = 16ms)
#define CHR_CON13                   (*(volatile uint16_t *)(PMU_BASE + 0x0A34))                     // ?????????? dcl_mixedsys6260_reg.h
#define RG_OVP_TRIM(v)              (((v) & 0x0F) << 0)
#define CHR_CON14                   (*(volatile uint16_t *)(PMU_BASE + 0x0A38))
#define RG_PCHR_RV2(v)              (((v) & 0xFF) << 0)
#define RG_PCHR_RV1(v)              (((v) & 0xFF) << 8)
#define CHR_CON15                   (*(volatile uint16_t *)(PMU_BASE + 0x0A3C))                     // ?????????? dcl_mixedsys6260_reg.h
#define RG_DAC_USBDL_MAX(v)         (((v) & 0x3FF) << 0)

#define STRUP_CON0                  (*(volatile uint16_t *)(PMU_BASE + 0x0A80))
#define RG_THR_SEL(v)               (((v) & 0x03) << 0)
#define RG_THERMAL_DIS              (1 << 2)
#define THR_HWPDN_EN                (1 << 3)
#define RG_USBDL_EN                 (1 << 4)
#define QI_PMU_THR_STATUS           (1 << 8)
#define PMU_THR_PWROFF              (1 << 11)
#define QI_USBDL_MODE               (1 << 12)
#define QI_TEST_MODE_POR            (1 << 13)
#define QI_PWRKEY_VCORE             (1 << 14)
#define QI_PWRKEY_DEB               (1 << 15)

#define STRUP_CON1                  (*(volatile uint16_t *)(PMU_BASE + 0x0A84))
#define RG_VREF_BG(v)               (((v) & 0x07) << 0)
#define RG_PMU_PGDET_DIS            (1 << 3)
#define RG_STRUP_TEST               (1 << 4)
#define RG_RST_DRVSEL               (1 << 5)
#define RG_PMU_LEV_UNIGATE          (1 << 8)
#define RG_BIAS_GEN_FORCE           (1<14)

#define STRUP_CON2                  (*(volatile uint16_t *)(PMU_BASE + 0x0A88))
#define RG_STRUP_FLAG_SEL(v)        (((v) & 0xFF) << 0)
#define RG_STRUP_FLAG_EN            (1 << 8)
#define QI_STRUP_FLAG_OUT(v)        (((v) >> 9) & 0x0F)

#define STRUP_CON3                  (*(volatile uint16_t *)(PMU_BASE + 0x0A8C))
#define RG_ESDDEG_EN                (1 << 0)
#define RG_ESDDEG_DLYSEL(v)         (((v) & 0x07) << 1)
#define RG_EOSC_CALI_TD(v)          (((v) & 0x07) << 5)
#define RG_EOSC_CALI_TD_SET         (1 << 8)
#define RG_EOSC_CALI_TEST(v)        (((v) & 0x0F) << 9)

#define STRUP_CON4                  (*(volatile uint16_t *)(PMU_BASE + 0x0A90))
#define RG_STRUP_RSV                0x00FF
#define RG_FRC_VRF_ON               (1 << 8)
#define RG_FRC_VRF_ON_SET           (1 << 9)
#define RG_EOSC_CALI_RSV_SET        (1 << 10)
#define RG_EOSC_CALI_RSV            0x7800

#define ISINKS_CON0                 (*(volatile uint16_t *)(PMU_BASE + 0x0C00))
#define ISINKS_MODE_PWM             (0 << 0)
#define ISINKS_MODE_SINK            (1 << 0)
#define ISINK0_CON0                 (*(volatile uint16_t *)(PMU_BASE + 0x0C10))
#define NI_ISINKS_CH0_EN            (1 << 0)
#define NI_ISINKS_BIAS0_EN          (1 << 3)
#define RG_ISINKS_CH0(v)            (((v) & 0x07) << 4)
#define ISINKS_CH0_4mA              0
#define ISINKS_CH0_8mA              1
#define ISINKS_CH0_12mA             2
#define ISINKS_CH0_16mA             3
#define ISINKS_CH0_20mA             6
#define ISINKS_CH0_24mA             7
#define RG_ISINK0_DOUBLE            (1 << 8)
#define NI_ISINK0_STATUS            (1 << 15)
#define ISINK1_CON0                 (*(volatile uint16_t *)(PMU_BASE + 0x0C20))
#define NI_ISINKS_CH1_EN            (1 << 0)
#define NI_ISINKS_BIAS1_EN          (1 << 3)
#define RG_ISINKS_CH1(v)            (((v) & 0x07) << 4)
#define ISINKS_CH1_4mA              0
#define ISINKS_CH1_8mA              1
#define ISINKS_CH1_12mA             2
#define ISINKS_CH1_16mA             3
#define ISINKS_CH1_20mA             6
#define ISINKS_CH1_24mA             7
#define RG_ISINK1_DOUBLE            (1 << 8)
#define NI_ISINK1_STATUS            (1 << 15)
typedef enum tag_ISINKCHNL
{
    ISINK_CH0,
    ISINK_CH1,
    ISINK_CHTOTAL
} ISINKCHNL;

typedef enum tag_ICVAL
{
    IC_4mA,
    IC_8mA,
    IC_12mA,
    IC_16mA,
    IC_20mA,
    IC_24mA,
    IC_32mA,
    IC_40mA,
    IC_48mA
} ICVAL;

#define KPLED_CON0                  (*(volatile uint16_t *)(PMU_BASE + 0x0C80))
#define NI_KPLED_EN                 (1 << 0)
#define KPLED_MODE_PWM              (0 << 1)
#define KPLED_MODE_SINK             (1 << 1)
#define NI_KPLED_STATUS             (1 << 15)

#define SPK_CON0                    (*(volatile uint16_t *)(PMU_BASE + 0x0D00))                     // Defined in afe_def.h
#define RG_SPK_EN                   (1 << 0)                                                        // afe_6261.h
#define SPK_GAIN(v)                 (((v) & 0x03) << 4)                                             // 0: -6db, 1: 3db, 2: 6db, 3: 12db
#define SPK_OC_AUTOFF               (1 << 12)
#define SPK_OC_FLAG                 (1 << 14)
#define SPK_CON3                    (*(volatile uint16_t *)(PMU_BASE + 0x0D0C))                     // Defined in afe_def.h
#define SPK_OC_CTRL(v)              (((v) & 0x03) << 2)
#define RG_SPK_OUT_FLOAT_B          (1 << 11)
#define RG_SPK_IN_TIE_HIGH          (1 << 12)
#define RG_SPK_IN_FLOAT_B           (1 << 14)
#define SPK_CON6                    (*(volatile uint16_t *)(PMU_BASE + 0x0D18))
#define RG_SPK_IN_CM_CTRL_EN        (1 << 2)
#define RG_SPK_VCM_DIV_SEL          (1 << 3)
#define RG_SPK_ISENSE_PD_RESET      (1 << 4)
#define RG_SPK_SPK_OCP_ABIST        (1 << 5)
#define RG_SPK_SPK_OCN_ABIST        (1 << 6)
#define RG_SPK_DAMPING_EN           (1 << 7)
#define RG_SPK_RSV(v)               (((v) & 0x0F) << 8)
#define SPK_CON7                    (*(volatile uint16_t *)(PMU_BASE + 0x0D1C))                     // Defined in afe_def.h
#define RG_SPK_OBIAS(v)             (((v) & 0x03) << 4)
#define RG_VCM_IBSEL                (1 << 6)
#define RG_SPK_VCM_SEL              (1 << 7)
#define SPK_CLASSAB_OC_EN           (1 << 8)
#define RG_SPK_PBIAS                (1 << 10)
#define SPK_CON8                    (*(volatile uint16_t *)(PMU_BASE + 0x0D20))                     // Calibration
#define RG_SPK_CHANNELSEL(v)        (((v) & 0x03) << 2)
#define SPK_DC_CALIB_EN             (1 << 6)
#define SPK_SPKP                    (1 << 9)
#define SPK_SPKN                    (0 << 9)
#define SPK_CON9                    (*(volatile uint16_t *)(PMU_BASE + 0x0D24))                     // Current sensor register
#define RG_SPK_ISENSE_TEST_EN       (1 << 4)
#define RG_SPK_ISENSE_REFSEL(v)     (((v) & 0x07) << 8)
#define RG_SPK_ISENSE_GAINSEL(v)    (((v) & 0x07) << 11)
#define RG_SPK_ISENSE_EN            (1 << 15)

#define VSBST_CON0                  (*(volatile uint16_t *)(PMU_BASE + 0x0D28))
#define QI_VSBST_EN                 (1 << 0)
#define RG_VSBST_BP                 (1 << 1)
#define NI_VSBST_MODESET            (1 << 2)
#define NI_VSBST_SSBST              (1 << 3)
#define NI_VSBST_SSV2P5             (1 << 4)
#define NI_VSBST_SSBP               (1 << 5)
#define VSBST_CTRL_EN               (1 << 6)
#define VSBST_VIO28_PG_CTRL         (1 << 7)
#define VSBST_VIO28_PG_STATUS_TD(v) (((v) & 0x03) << 8)
#define VSBST_VIO28_PG_STATUS       (1 << 10)
#define VSBST_EN_SEL                (1 << 11)
#define VSBST_MODESET_SEL           (1 << 12)
#define VSBST_SS_SEL                (1 << 13)
#define VSBST_SSV2P5_DLY_SEL_R      (1 << 14)
#define VSBST_SSV2P5_DLY_SEL_F      (1 << 15)
#define VSBST_CON1                  (*(volatile uint16_t *)(PMU_BASE + 0x0D2C))                     // From afe_def.h
#define RG_VSBST_CSL(v)             (((v) & 0x0F) << 0)
#define RG_VSBST_CSM(v)             (((v) & 0x07) << 4)
#define RG_VSBST_CSR(v)             (((v) & 0x03) << 7)
#define RG_VSBST_CC(v)              (((v) & 0x07) << 9)
#define RG_VSBST_RC                 (1 << 12)
#define VSBST_CON2                  (*(volatile uint16_t *)(PMU_BASE + 0x0D30))
#define RG_VSBST_RSV(v)             (((v) & 0xFF) << 0)
#define RG_VSBST_SLP(v)             (((v) & 0x03) << 8)
#define VSBST_SLEW_NMOS(v)          (((v) & 0x03) << 10)
#define SLEW_NMOS1_0                0
#define SLEW_NMOS3_4                1
#define SLEW_NMOS2_4                2
#define SLEW_NMOS1_4                3
#define VSBST_SLEW(v)               (((v) & 0x03) << 12)
#define VSBST_SLEW1_0               0
#define VSBST_SLEW3_4               1
#define VSBST_SLEW2_4               2
#define VSBST_SLEW1_4               3
#define RG_VSBST_OVP_SEL            (1 << 14)
#define VSBST_CON3                  (*(volatile uint16_t *)(PMU_BASE + 0x0D34))
#define RG_VSBST_FASYNC             (1 << 0)
#define RG_VSBST_ZX_OS(v)           (((v) & 0x0F) << 1)
#define RG_VSBST_BURSTL(v)          (((v) & 0x03) << 5)
#define RG_VSBST_BURSTH(v)          (((v) & 0x03) << 7)
#define RG_VSBST_TRIM(v)            (((v) & 0x1F) << 9)
#define RG_VSBST_VOSEL(v)           (((v) & 0x03) << 14)
#define RG_VSBST_VO53               0
#define RG_VSBST_VO525              1
#define RG_VSBST_VO52               2
#define RG_VSBST_VO535              3
#define VSBST_CON4                  (*(volatile uint16_t *)(PMU_BASE + 0x0D38))
#define RG_VSBST_OVP_ENB            (1 << 0)
#define RG_VSBST_FPWM_CKDIVB        (1 << 1)
#define RG_VSBST_FB_SOURCE          (1 << 2)
#define RG_VSBST_VPGNND_SEL(v)      (((v) & 0x03) << 3)
#define RGS_VSBST_ENPWM_STATUS      (1 << 8)
#define QI_VSBST_PG_STATUS          (1 << 9)
#define QI_VSBST_DIG_MON(v)         (((v) & 0x0F) << 10)
#define QI_VSBST_OC_STATUS          (1 << 14)
#define VSBST_CON5                  (*(volatile uint16_t *)(PMU_BASE + 0x0D3C))                     // From afe-def.h
#define VSBST_CKS_PRG(v)            (((v) & 0xFF) << 0)
#define VSBST_CKS_CHG               (1 << 15)
#define VSBST_CON6                  (*(volatile uint16_t *)(PMU_BASE + 0x0D40))
#define VSBST_OC_CKS_PRG(v)         (((v) & 0xFF) << 0)
#define VSBST_CTRL_STATUS           (1 << 8)
#define VSBST_THERMAL_AUTOFF        (1 << 9)
#define VSBST_OC_AUTOFF             (1 << 10)
#define VSBST_OC_FLAG               (1 << 11)
#define VSBST_OC_CTRL               (1 << 12)
#define VSBST_OC_CKS_CHG            (1 << 15)

#define OC_CON0                     (*(volatile uint16_t *)(PMU_BASE + 0x0E00))
#define OC_CON7                     (*(volatile uint16_t *)(PMU_BASE + 0x0E1C))
#define OC_CON8                     (*(volatile uint16_t *)(PMU_BASE + 0x0E20))
#define QI_VRF_OC_STATUS            (1 << 0)
#define QI_VA_OC_STATUS             (1 << 2)
#define QI_VCAMA_OC_STATUS          (1 << 3)
#define QI_VIO28_OC_STATUS          (1 << 5)
#define QI_VUSB_OC_STATUS           (1 << 6)
#define QI_VSIM1_OC_STATUS          (1 << 8)
#define QI_VSIM2_OC_STATUS          (1 << 9)
#define QI_VIBR_OC_STATUS           (1 << 11)
#define QI_VMC_OC_STATUS            (1 << 12)
#define QI_VSF_OC_STATUS            (1 << 13)
#define OC_CON9                     (*(volatile uint16_t *)(PMU_BASE + 0x0E24))
#define QI_VCORE_OC_STATUS          (1 << 0)
#define QI_VIO18_OC_STATUS          (1 << 1)
#define OC_CON11                    (*(volatile uint16_t *)(PMU_BASE + 0x0E2C))                     // Not defined in datasheet

#define TEST_CON0                   (*(volatile uint16_t *)(PMU_BASE + 0x0F00))
#define RG_PWRKEY_RST_EN            (1 << 0)
#define RG_PWRKEY_TMR_DIS           (1 << 1)
#define RG_PWRKEY_RST_TD            (1 << 2)
#define RG_PWRKEY_RST_FUNC_SET      (1 << 4)
#define RG_CLR_JUST_RST             (1 << 5)
#define RG_LNGP_SHUTDOWN_SEL        (1 << 6)
#define TESTMODE_RSV                0xFF80
#define TEST_CON1                   (*(volatile uint16_t *)(PMU_BASE + 0x0F04))
#define RG_TP_LED(v)                (((v) & 0x0F) << 0)
#define RG_IBIAS_TRIM(v)            (((v) & 0x0F << 8)
#define TEST_CON2                   (*(volatile uint16_t *)(PMU_BASE + 0x0F08))
#define RG_THERMAL_TEST(v)          (((v & 0x07) << 0)
#define RG_IBIAS_TRIM_EN            (1 << 5)
#define RG_THR_TMODE                (1 << 8)
#define RG_SV12_TMODE               (1 << 9)
#define TEST_CON3                   (*(volatile uint16_t *)(PMU_BASE + 0x0F0C))
#define BP_OLT_CTRL                 (1 << 1)
#define BP_OLT_CTRL_VSBST           (1 << 2)
#define BP_OLT_CTRL_ISINKS          (1 << 3)
#define RG_TS_G                     (1 << 15)

/* Frequency meter registers */
#define FQMTR_CON0                  (*(volatile uint16_t *)(PMU_BASE + 0x0FF0))
#define FQMTR_MODE                  (1 << 12)
#define FQMTR_RST                   (1 << 13)
#define FQMTR_EN                    (1 << 14)
#define FQMTR_BUSY                  (1 << 15)
#define FQMTR_CON1                  (*(volatile uint16_t *)(PMU_BASE + 0x0FF4))
#define FQMTR_TCKSEL(v)             (((v) & 0x07) << 0)
#define FQMTR_FCKSEL(v)             (((v) & 0x03) << 8)
#define FQMTR_CON2                  (*(volatile uint16_t *)(PMU_BASE + 0x0FF8))                     // FQMTR_DATA mask 0xFFFF
#define FQMTR_CON3                  (*(volatile uint16_t *)(PMU_BASE + 0x0FFC))                     // FQMTR_WINSET mask 0xFFFF

extern void PMU_SetChargerWDTEnabled(boolean Enabled);
extern void PMU_SetChargerWDTInterval(uint8_t Interval);
extern boolean PMU_IsChargerConnected(void);
extern boolean PMU_IsBatteryCharging(void);
extern void PMU_SetChargingEnable(boolean Enabled);
extern void PMU_EnterUSBDLMode(void);
extern void PMU_LeaveUSBDLMode(void);
extern boolean PMU_IsPowerKeyPressed(void);
extern void PMU_SetVibrationOutput(boolean Enable);
extern void PMU_DisableISINKs(void);
extern void PMU_SetISINKMode(boolean UsePWM);
extern void PMU_SetISINKOutput(ISINKCHNL Channel, boolean Enable);
extern void PMU_SetISINKParameters(ISINKCHNL Channel, ICVAL Value, boolean Enable);
extern void PMU_TurnOnVUSB(boolean Enable);
extern void PMU_TurnOnVMC(boolean Enable);
extern boolean PMU_SetVoltageVMC(TVMC Voltage);
extern TVMC PMU_GetSelectedVoltageVMC(void);
extern void PMU_Initialize(void);

#endif /* _PMU_H_ */
