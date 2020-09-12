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
#ifndef _SFI_H_
#define _SFI_H_

#define RW_SFI_MAC_CTL              (*(volatile uint32_t *)(SFI_base + 0x0000))
#define SFI_WIP                     (1 << 0)    //(0x00000001)   // b0
#define SFI_WIP_READY               (1 << 1)    //(0x00000002)   // b1
#define SFI_TRIG                    (1 << 2)    //(0x00000004)   // b2
#define SFI_MAC_EN                  (1 << 3)    //(0x00000008)   // b3
#define SFI_MAC_SIO_SEL             (1 << 4)    //(0x00000010)   // b4
#define SFI_RELEASE_MAC             (1 << 16)   //(0x00010000)   // b16
#define SFI_MAC_SEL                 (1 << 28)   //(0x10000000)   // b28
#define RW_SFI_DIRECT_CTL           (*(volatile uint32_t *)(SFI_base + 0x0004))
// RW_SF_DIRECT_CTL
#define SFI_QPI_EN                  (1 << 0)    //(0x00000001)  // b0
#define SFI_CMD1_EXTADDR_EN         (1 << 1)    //(0x00000002)  // b1
#define SFI_CMD2_EN                 (1 << 2)    //(0x00000004)  // b2
#define SFI_CMD2_EXTADDR_EN         (1 << 3)    //(0x00000008)  // b3
#define SFI_DR_MODE_MASK            (0x00000070)  // b4~b6
#define SFI_DR_CMD2_DUMMY_CYC_MASK  (0x00000F00)  // b8~b11
#define SFI_DR_CMD1_DUMMY_CYC_MASK  (0x0000F000)  // b12~b15
#define SFI_DR_CMD2_DUMMY_CYC_OFFSET         (8)
#define SFI_DR_CMD1_DUMMY_CYC_OFFSET        (12)
#define SFI_DR_CMD2_MASK            (0x00FF0000)  // b16~b23
#define SFI_DR_CMD1_MASK            (0xFF000000)  // b24~b31
#define SFI_DR_CMD2_OFFSET                  (16)
#define SFI_DR_CMD1_OFFSET                  (24)
// RW_SF_DIRECT_CTL: Serial flash direct read mode
#define SFI_DR_SPI_NORMAL_READ_MODE (0x00000000)
#define SFI_DR_SPI_FAST_READ_MODE   (0x00000010)
#define SFI_DR_QPI_FAST_READ_MODE   (0x00000070)

#define RW_SFI_MISC_CTL             (*(volatile uint32_t *)(SFI_base + 0x0008))
// RW_SF_MISC_CTL
#define SFI_DEL_LATCH_MASK          (0x00000003)  // b0~01
#define SFI_DEL_LATCH_OFFSET        (0)
#define SFI_REQ_IDLE                (0x00000100)  // b8
#define SFI_BOOT_REMAP              (0x00000200)  // b9
#define SFI_SYNC_EN                 (0x00020000)  // b17
#define SFI_NO_RELOAD               (0x00800000)  // b23
#define SFI_CS_EXT_MASK             (0xF0000000)  // b28~b31
#define RW_SFI_MISC_CTL2            (*(volatile uint32_t *)(SFI_base + 0x000C))
// RW_SF_MISC_CTL2
#define SFI_WRAP_ACC_EN             (0x00000001)  // b0
#define SFI_DDR                     (0x00000002)  // b1
#define RW_SFI_MAC_OUTL             (*(volatile uint32_t *)(SFI_base + 0x0010))
#define RW_SFI_MAC_INL              (*(volatile uint32_t *)(SFI_base + 0x0014))
#define RW_SFI_RESET_CTL            (*(volatile uint32_t *)(SFI_base + 0x0018))
#define RW_SFI_STA2_CTL             (*(volatile uint32_t *)(SFI_base + 0x001C))
// RW_SF_STA2_CTL
#define SFI_KEEP_READ_SETTING       (0x80000000)  // b31
#define RW_SFI_DLY_CTL1             (*(volatile uint32_t *)(SFI_base + 0x0020))
#define RW_SFI_DLY_CTL2             (*(volatile uint32_t *)(SFI_base + 0x0024))
#define RW_SFI_DLY_CTL3             (*(volatile uint32_t *)(SFI_base + 0x0028))
#define RW_SFI_DLY_CTL4             (*(volatile uint32_t *)(SFI_base + 0x0030))
#define RW_SFI_DLY_CTL5             (*(volatile uint32_t *)(SFI_base + 0x0034))
#define RW_SFI_DLY_CTL6             (*(volatile uint32_t *)(SFI_base + 0x0038))
#define RW_SFI_DIRECT_CTL2          (*(volatile uint32_t *)(SFI_base + 0x0040))
#define RW_SFI_MISC_CTL3            (*(volatile uint32_t *)(SFI_base + 0x0044))
// RW_SF_MISC_CTL3
#define SFI_DEL_LATCH_MASK2         (0x00030000)  // b16~017
#define SFI_DEL_LATCH_OFFSET2       (16)
#define SFI_SF2_EN                  (0x00000001)    // b0
#define SFI_SF1_SIZE_MASK           (0x00000070)    // b4~6
#define SFI_SF1_SIZE_OFFSET         (4)             // b4~6
#define SFI_CH1_TRANS_MASK          (0x00000100)    // b8
#define SFI_CH2_TRANS_MASK          (0x00000200)    // b9
#define SFI_CH3_TRANS_MASK          (0x00000400)    // b10
#define SFI_CH1_TRANS_IDLE          (0x00001000)    // b12
#define SFI_CH2_TRANS_IDLE          (0x00002000)    // b13
#define SFI_CH3_TRANS_IDLE          (0x00004000)    // b14
#define RW_SFI_GPRAM_DATA           (*(volatile uint32_t *)(SFI_base + 0x0800))
// Performance Monitor
#define SF_PERF_MON1                (*(volatile uint32_t *)(SFI_base + 0x0080))
#define SF_PERF_MON2                (*(volatile uint32_t *)(SFI_base + 0x0084))
#define SF_PERF_MON3                (*(volatile uint32_t *)(SFI_base + 0x0088))
#define SF_PERF_MON4                (*(volatile uint32_t *)(SFI_base + 0x008C))
#define SF_PERF_MON5                (*(volatile uint32_t *)(SFI_base + 0x0090))
#define SF_PERF_MON6                (*(volatile uint32_t *)(SFI_base + 0x0094))
#define SF_PERF_MON7                (*(volatile uint32_t *)(SFI_base + 0x0098))
#define SF_PERF_MON8                (*(volatile uint32_t *)(SFI_base + 0x009C))
#define SF_PERF_MON9                (*(volatile uint32_t *)(SFI_base + 0x00A0))
#define SF_PERF_MON10               (*(volatile uint32_t *)(SFI_base + 0x00A4))
#define SF_PERF_MON11               (*(volatile uint32_t *)(SFI_base + 0x00A8))
#define SF_PERF_MON12               (*(volatile uint32_t *)(SFI_base + 0x00AC))
#define SF_PERF_MON13               (*(volatile uint32_t *)(SFI_base + 0x00B0))
///////////////////////////////////////////////////////////////////////
/* SF GPIO registers*/
#define SFIO_CFG0           (CONFIG_base + 0x600)
#define SFIO_CFG1           (CONFIG_base + 0x604)
#define SFIO_CFG2           (CONFIG_base + 0x608)
#define SF_NORMAL_HIGHZ     (0xFFCFFFCF)
//#define GPIO_RESEN0_1       (GPIO_base + 0xb10)
//#define GPIO_RESEN1_1       (GPIO_base + 0xb30)
#define SF_SLT_HIGHZ        (0xFFF81FFF)
//#define GPIO_DRV1           (GPIO_base + 0x810)
#define SF_SLT_DRIVING_CLR  (0xFF3FFFFF)
#define SF_SLT_DRIVING_12mA (0xFF8FFFFF)

/* SFC Driving registers */
#define SFIO_CFG0_DRV       ((volatile UINT32P)(CONFIG_base+0x600))
#define SFIO_CFG1_DRV       ((volatile UINT32P)(CONFIG_base+0x604))
#define SFIO_CFG2_DRV       ((volatile UINT32P)(CONFIG_base+0x608))


/* SFC SLT registers */
#define SF_NORMAL_MODE      (0x00000001)
#define SF_SLT_MODE         (0x00000002)
#define SF_SLT_MODE_MASK    (0x00000007)


#endif /* _SFI_H_ */
