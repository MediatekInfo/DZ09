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
#ifndef _SFI_H_
#define _SFI_H_

#define SFI_GPRAMSIZE               0x00A0
#define SFI_MAXDATALOAD             0x0080                                                          // To ensure multiplicity with the page size.

#define RW_SFI_MAC_CTL              (*(volatile uint32_t *)(SFI_BASE + 0x0000))
#define SFI_WIP                     (1 << 0)
#define SFI_WIP_READY               (1 << 1)
#define SFI_TRIG                    (1 << 2)
#define SFI_MAC_EN                  (1 << 3)
#define SFI_MAC_SIO_SEL             (1 << 4)
#define SFI_RELEASE_MAC             (1 << 16
#define SFI_MAC_SEL                 (1 << 28)

#define RW_SFI_DIRECT_CTL           (*(volatile uint32_t *)(SFI_BASE + 0x0004))
#define SFI_QPI_EN                  (1 << 0)
#define SFI_CMD1_EXTADDR_EN         (1 << 1)
#define SFI_CMD2_EN                 (1 << 2)
#define SFI_CMD2_EXTADDR_EN         (1 << 3)
#define SFI_DR_SPI_NORMAL_READ_MODE (0 << 4)
#define SFI_DR_SPI_FAST_READ_MODE   (1 << 4)
#define SFI_DR_QPI_FAST_READ_MODE   (7 << 4)
#define SFI_DR_CMD2_DUMMY_CYC_MASK  (0x0F << 8)
#define SFI_DR_CMD1_DUMMY_CYC_MASK  (0x0F << 12)
#define SFI_DR_CMD2_MASK            (0xFF << 16)
#define SFI_DR_CMD1_MASK            (0xFF << 24)

#define RW_SFI_MISC_CTL             (*(volatile uint32_t *)(SFI_BASE + 0x0008))
#define SFI_DEL_LATCH_MASK          (3 << 0)
#define SFI_REQ_IDLE                (1 << 8)
#define SFI_BOOT_REMAP              (1 << 9)
#define SFI_SYNC_EN                 (1 << 17)
#define SFI_NO_RELOAD               (1 << 23)
#define SFI_CS_EXT_MASK             (0x0F << 28)

#define RW_SFI_MISC_CTL2            (*(volatile uint32_t *)(SFI_BASE + 0x000C))
#define SFI_WRAP_ACC_EN             (1 << 0)
#define SFI_DDR                     (1 << 1)

#define RW_SFI_MAC_OUTL             (*(volatile uint32_t *)(SFI_BASE + 0x0010))
#define RW_SFI_MAC_INL              (*(volatile uint32_t *)(SFI_BASE + 0x0014))
#define RW_SFI_RESET_CTL            (*(volatile uint32_t *)(SFI_BASE + 0x0018))

#define RW_SFI_STA2_CTL             (*(volatile uint32_t *)(SFI_BASE + 0x001C))
#define SFI_KEEP_READ_SETTING       (1UL << 31)

#define RW_SFI_DLY_CTL1             (*(volatile uint32_t *)(SFI_BASE + 0x0020))
#define RW_SFI_DLY_CTL2             (*(volatile uint32_t *)(SFI_BASE + 0x0024))
#define RW_SFI_DLY_CTL3             (*(volatile uint32_t *)(SFI_BASE + 0x0028))
#define RW_SFI_DLY_CTL4             (*(volatile uint32_t *)(SFI_BASE + 0x0030))
#define RW_SFI_DLY_CTL5             (*(volatile uint32_t *)(SFI_BASE + 0x0034))
#define RW_SFI_DLY_CTL6             (*(volatile uint32_t *)(SFI_BASE + 0x0038))
#define RW_SFI_DIRECT_CTL2          (*(volatile uint32_t *)(SFI_BASE + 0x0040))

#define RW_SFI_MISC_CTL3            (*(volatile uint32_t *)(SFI_BASE + 0x0044))
#define SFI_SF2_EN                  (1 << 0)
#define SFI_SF1_SIZE_MASK           (7 << 4)
#define SFI_CH1_TRANS_MASK          (1 << 8)
#define SFI_CH2_TRANS_MASK          (1 << 9)
#define SFI_CH3_TRANS_MASK          (1 << 10)
#define SFI_CH1_TRANS_IDLE          (1 << 12)
#define SFI_CH2_TRANS_IDLE          (1 << 13)
#define SFI_CH3_TRANS_IDLE          (1 << 14)
#define SFI_DEL_LATCH_MASK2         (3 << 16)

#define RW_SFI_GPRAM_DATA(x)        (*(volatile uint32_t *)(SFI_BASE + 0x0800 + 4 * (x)))

#define SF_PERF_MON1                (*(volatile uint32_t *)(SFI_BASE + 0x0080))
#define SF_PERF_MON2                (*(volatile uint32_t *)(SFI_BASE + 0x0084))
#define SF_PERF_MON3                (*(volatile uint32_t *)(SFI_BASE + 0x0088))
#define SF_PERF_MON4                (*(volatile uint32_t *)(SFI_BASE + 0x008C))
#define SF_PERF_MON5                (*(volatile uint32_t *)(SFI_BASE + 0x0090))
#define SF_PERF_MON6                (*(volatile uint32_t *)(SFI_BASE + 0x0094))
#define SF_PERF_MON7                (*(volatile uint32_t *)(SFI_BASE + 0x0098))
#define SF_PERF_MON8                (*(volatile uint32_t *)(SFI_BASE + 0x009C))
#define SF_PERF_MON9                (*(volatile uint32_t *)(SFI_BASE + 0x00A0))
#define SF_PERF_MON10               (*(volatile uint32_t *)(SFI_BASE + 0x00A4))
#define SF_PERF_MON11               (*(volatile uint32_t *)(SFI_BASE + 0x00A8))
#define SF_PERF_MON12               (*(volatile uint32_t *)(SFI_BASE + 0x00AC))
#define SF_PERF_MON13               (*(volatile uint32_t *)(SFI_BASE + 0x00B0))
///////////////////////////////////////////////////////////////////////
/* SF GPIO registers*/
#define SFIO_CFG0                   (*(volatile uint32_t *)(CONFIG_BASE + 0x0600))
#define SFIO_CFG1                   (*(volatile uint32_t *)(CONFIG_BASE + 0x0604))
#define SFIO_CFG2                   (*(volatile uint32_t *)(CONFIG_BASE + 0x0608))
#define SF_NORMAL_HIGHZ             0xFFCFFFCF
//#define GPIO_RESEN0_1       (GPIO_base + 0xb10)
//#define GPIO_RESEN1_1       (GPIO_base + 0xb30)
#define SF_SLT_HIGHZ                0xFFF81FFF
//#define GPIO_DRV1           (GPIO_base + 0x810)
#define SF_SLT_DRIVING_CLR          0xFF3FFFFF
#define SF_SLT_DRIVING_12mA         0xFF8FFFFF

/* SFC SLT registers */
#define SF_NORMAL_MODE              (0x00000001)
#define SF_SLT_MODE                 (0x00000002)
#define SF_SLT_MODE_MASK            (0x00000007)

typedef enum tag_SFI_CS
{
    SFI_CS0,
    SFI_CSNUM
} TSFI_CS;

typedef enum tag_SFIMODE
{
    SFM_UNKNOWN,
    SFM_SPI,
    SFM_QPI
} TSFIMODE;

typedef enum tag_BSRANGE
{
    BR_4K   = (1 << 0),
    BR_32K  = (1 << 1),
    BR_64K  = (1 << 2)
} TBSRANGE;

typedef struct tag_DFCONFIG TDFCONFIG, *pDFCONFIG;
typedef struct tag_DFCONFIG
{
    uint32_t DeviceID;
    char     *DeviceName;
    boolean  Address4Bytes;
    uint16_t PageSize;
    uint32_t TotalPages;
    TBSRANGE EraseSupport;
    uint8_t  *PreInitSequence;
    uint8_t  *PostInitSequence;
    uint32_t SFI_MAC_CTL;
    uint32_t SFI_DIRECT_CTL;
    uint32_t SFI_MISC_CTL;
    uint32_t SFI_MISC_CTL2;
    uint32_t SFI_DLY_CTL_2;
    uint32_t SFI_DLY_CTL_3;
    uint32_t DRIVING;
} TDFCONFIG, *pDFCONFIG;

extern TSFIMODE SFI_GetInterfaceMode(TSFI_CS CS);
extern boolean SFI_DeviceCommandRead(TSFI_CS CS, uint8_t Command, uint8_t *InData, size_t InCount);
extern boolean SFI_DeviceCommandWrite(TSFI_CS CS, uint8_t Command, uint8_t *OutData, size_t OutCount);
extern boolean SFI_DeviceCmdAddr3Write(TSFI_CS CS, uint8_t Command, uint32_t Address,
                                       uint8_t *OutData, size_t OutCount);
extern boolean SFI_DeviceCmdAddr4Write(TSFI_CS CS, uint8_t Command, uint32_t Address,
                                       uint8_t *OutData, size_t OutCount);
extern boolean SFI_ConfigureInterface(TSFI_CS CS, pDFCONFIG Config);
#endif /* _SFI_H_ */
