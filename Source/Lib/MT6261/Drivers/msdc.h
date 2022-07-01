/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 AJScorp
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
#ifndef _MSDC_H_
#define _MSDC_H_

typedef enum tag_MSDC
{
    MSDC_ITF0,
    MSDC_ITF1,
    MSDC_ITFNUM
} TMSDC;

typedef struct tag_MSDCREGS
{
    uint32_t MSDC_CFG;
    uint32_t MSDC_STA;
    uint32_t MSDC_INT;
    uint32_t MSDC_PS;
    uint32_t MSDC_DAT;
    uint32_t MSDC_IOCON;
    uint32_t MSDC_IOCON1;
    uint32_t RSVD0;
    uint32_t SDC_CFG;
    uint32_t SDC_CMD;
    uint32_t SDC_ARG;
    uint32_t SDC_STA;
    uint32_t SDC_RESP0;
    uint32_t SDC_RESP1;
    uint32_t SDC_RESP2;
    uint32_t SDC_RESP3;
    uint32_t SDC_CMDSTA;
    uint32_t SDC_DATSTA;
    uint32_t SDC_CSTA;
    uint32_t SDC_IRQMASK0;
    uint32_t SDC_IRQMASK1;
    uint32_t SDIO_CFG;
    uint32_t SDIO_STA;
    uint32_t RSVD1[9];
    uint32_t CLK_RED;
    uint32_t CLK_STA;
    uint32_t CLK_CRCSTA1;
    uint32_t CLK_CRCSTA2;
    uint32_t RSVD2[2];
    uint32_t DAT_CHECKSUM;
} TMSDCREGS, *pMSDCREGS;

typedef struct tag_MSDC_CONTEXT
{
    volatile TMSDCREGS *MSDC;
    uint8_t            PD_Code;
} TMSDCCONTEXT,  *pMSDCCONTEXT;

// MSDC_CFG
#define MSDC_EN                     (1 << 0)
#define MSDC_RST                    (1 << 1)
#define MSDC_NOCRC                  (1 << 2)
#define MSDC_CLKSRC(v)              (((v) & 0x03) << 3)
#define MSDC_STDBY                  (1 << 5)
#define MSDC_CRED                   (1 << 6)
#define MSDC_SCLKON                 (1 >> 7)
#define MSDC_SCLKF(v)               (((v) & 0xFF) << 8)
#define MSDC_INTEN                  (1 << 16)
#define MSDC_DMAEN                  (1 << 17)
#define MSDC_PINEN                  (1 << 18)
#define MSDC_DIRQEN                 (1 << 19)
#define MSDC_RCDEN                  (1 << 20)
#define MSDC_VDDPD                  (1 << 21)
#define MSDC_FIFOTHD(v)             (((v) & 0x0F) << 24)
// MSDC_STA
#define MSDC_BF                     (1 << 0)
#define MSDC_BE                     (1 << 1)
#define MSDC_DRQ                    (1 << 2)
#define MSDC_INT                    (1 >> 3)
#define MSDC_FIFOCNT(v)             (((v) >> 4) & 0x0F)
#define MSDC_FIFOCLR                (1 << 14)
#define MSDC_BUSY                   (1 << 15)
// MSDC_INT
#define MSDC_DIRQ                   (1 << 0)
#define MSDC_PINIRQ                 (1 << 1)
#define SD_CMDIRQ                   (1 << 2)
#define SD_DATIRQ                   (1 << 3)
#define SD_MCIRQ                    (1 << 4)
#define SD_R1BIRQ                   (1 << 6)
#define SD_IOIRQ                    (1 << 7)
// MSDC_PS
#define MSDC_CDEN                   (1 << 0)
#define NSDC_PIEN0                  (1 << 1)
#define MSDC_POEN0                  (1 << 2)
#define MSDC_PIN0                   (1 << 3)
#define MSDC_PINCHG                 (1 << 4)
#define MSDC_CDDEB(v)               (((v) & 0x0F) << 12)
#define MSDC_DATALINES(v)           (((v) >> 16) & 0xFF)
#define MSDC_CMDLINE                (1 << 24)
// MSDC_IOCON
#define MSDC_ODCCFG0(v)             (((v) & 0x07) << 0)
#define MSDC_ODC0_4MA               0
#define MSDC_ODC0_8MA               1
#define MSDC_ODC0_12MA              2
#define MSDC_ODC0_16MA              3
#define MSDC_ODCCFG1(v)             (((v) & 0x07) << 3)
#define MSDC_ODC1_4MA               0
#define MSDC_ODC1_8MA               1
#define MSDC_ODC1_12MA              2
#define MSDC_ODC1_16MA              3
#define MSDC_SRCFG0                 (1 << 6)
#define MSDC_SRCFG1                 (1 << 7)
#define MSDC_DMABURST(v)            (((v) & 0x03) << 8)
#define MSDC_DB_SM                  0
#define MSDC_DB_4B                  1
#define MSDC_DB_8B                  2
#define MSDC_HSPEED                 (1 << 10)
#define MSDC_CMDRE                  (1 << 15)
#define MSDC_DSW                    (1 << 16)
#define MSDC_INTLH(v)               (((v) & 0x03) << 17)
#define MSDC_CMDSEL                 (1 << 19)
#define SD_CRCDIS                   (1 << 20)
#define MSDC_SAMPON                 (1 << 21)
#define MSDC_FIXDLY(v)              (((v) & 0x03) << 22)
#define MSDC_SAMPDLY(v)             (((v) & 0x03) << 24)
// MSDC_IOCON1
#define MSDC_PRVAL_INS(v)           (((v) & 0x03) << 0)
#define MSDC_PRVAL_INS_DIS          0
#define MSDC_PRVAL_INS_47K          2
#define MSDC_PRVAL_INS_23K          3
#define MSDC_PRCFG_INS_PU           (0 << 2)
#define MSDC_PRCFG_INS_PD           (1 << 2)
#define MSDC_PRVAL_DA(v)            (((v) & 0x03) << 4)
#define MSDC_PRVAL_DA_DIS           0
#define MSDC_PRVAL_DA_47K           2
#define MSDC_PRVAL_DA_23K           3
#define MSDC_PRCFG_DA_PU            (0 << 6)
#define MSDC_PRCFG_DA_PD            (1 << 6)
#define MSDC_PRVAL_CM(v)            (((v) & 0x03) << 8)
#define MSDC_PRVAL_CM_DIS           0
#define MSDC_PRVAL_CM_47K           2
#define MSDC_PRVAL_CM_23K           3
#define MSDC_PRCFG_CM_PU            (0 << 10)
#define MSDC_PRCFG_CM_PD            (1 << 10)
#define MSDC_PRVAL_CK(v)            (((v) & 0x03) << 12)
#define MSDC_PRVAL_CK_DIS           0
#define MSDC_PRVAL_CK_47K           2
#define MSDC_PRVAL_CK_23K           3
#define MSDC_PRCFG_CK_PU            (0 << 14)
#define MSDC_PRCFG_CK_PD            (1 << 14)
#define MSDC_PRVAL_RSWP(v)          (((v) & 0x03) << 16)
#define MSDC_PRVAL_RSWP_DIS         0
#define MSDC_PRVAL_RSWP_47K         2
#define MSDC_PRVAL_RSWP_23K         3
#define MSDC_PRCFG_RSWP_PU          (0 << 18)
#define MSDC_PRCFG_RSWP_PD          (1 << 18)
// SDC_CFG
#define SDC_BLKLEN(v)               (((v) & 0x0FFF) << 0)
#define SDC_BSYDLY(v)               (((v) & 0x0F) << 12)
#define SDC_SIEN                    (1 << 16)
#define SDC_MDLEN                   (1 << 17)
#define SDC_SDIO                    (1 << 19)
#define SDC_WDOD(v)                 (((v) & 0x0F) << 20)
#define SDC_DTOC(v)                 (((v) & 0xFF) << 24)
// SDC_CMD
#define SDC_CMD(v)                  (((v) & 0xFF) << 0)
#define SDC_BREAK                   (1 << 6)
#define SDC_RSPTYP(v)               (((v) & 0x07) << 7)
#define SDC_NO_RSP                  0
#define SDC_RSP_R1                  1
#define SDC_RSP_R2                  2
#define SDC_RSP_R3                  3
#define SDC_RSP_R4                  4
#define SDC_RSP_R5                  5
#define SDC_RSP_R6                  6
#define SDC_RSP_R1B                 7
#define SDC_IDRT                    (1 << 10)
#define SDC_DTYPE(v)                (((v) & 0x03) << 11)
#define SDC_DTYPE_NODATA            0
#define SDC_DTYPE_SINGLE            1
#define SDC_DTYPE_MULTIPLE          2
#define SDC_DTYPE_STREAM            3
#define SDC_CMD_READ                (0 << 13)
#define SDC_CMD_WRITE               (1 << 13)
#define SDC_CMD_STOP                (1 << 14)
#define SDC_INTC                    (1 << 15)
#define SDC_CMDFAIL                 (1 << 16)
// SDC_STA
#define SDC_BESDCBUSY               (1 << 0)
#define SDC_BECMDBUSY               (1 << 1)
#define SDC_BEDATBUSY               (1 << 2)
#define SDC_FECMDBUSY               (1 << 3)
#define SDC_FEDATBUSY               (1 << 4)
#define SDC_WP                      (1 << 15)
// SDC_CMDSTA
#define SDC_CMDRDY                  (1 << 0)
#define SDC_CMDTO                   (1 << 1)
#define SDC_RSPCRCERR               (1 << 2)
// SDC_DATSTA
#define SDC_BLKDONE                 (1 << 0)
#define SDC_DATTO                   (1 << 1)
#define SDC_DATCRCERR               (1 << 2)
// SDC_CSTA
#define SDC_AKE_SEQ_ERROR           (1 << 3)
#define SDC_CID_CSD_OVERWRITE       (1 << 16)
#define SDC_OVERRUN                 (1 << 17)
#define SDC_UNDERRUN                (1 << 18)
#define SDC_ERROR                   (1 << 19)
#define SDC_CC_ERROR                (1 << 20)
#define SDC_CARD_ECC_FAILED         (1 << 21)
#define SDC_ILLEGAL_COMMAND         (1 << 22)
#define SDC_COM_CRC_ERROR           (1 << 23)
#define SDC_LOCK_UNLOCK_FAILED      (1 << 24)
#define SDC_WP_VIOLATION            (1 << 26)
#define SDC_ERASE_PARAM             (1 << 27)
#define SDC_ERASE_SEQ_ERROR         (1 << 28)
#define SDC_BLOCK_LEN_ERROR         (1 << 29)
#define SDC_ADDRESS_ERROR           (1 << 30)
#define SDC_OUT_OF_RANGE            (1UL << 31)
// SDC_IRQMASK0
// SDC_IRQMASK1
// SDC_CFG
#define SDC_INTEN                   (1 << 0)
#define SDC_DSBSEL                  (1 << 2)
#define SDC_INTCSEL                 (1 << 3)
#define SDC_DISSEL                  (1 << 5)
// DIO_STA
#define SDIO_IRQ                    (1 << 0)
// CLK_RED
#define MSDC_CLK_CLKTUN_ON          (1 << 0)
#define MSDC_CLK_COARSE_EN          (1 << 1)
#define MSDC_CLK FINE_EN            (3 << 1)
#define MSDC_CLK_SCANMODE           (1 << 3)
#define MSDC_CLK_SAMPLE_PERIOD(v)   (((v) & 0x03) << 4)
#define MSDC_CLK_LATCH              (1 << 6)
#define MSDC_CLKPAD_RED             (1 << 7)
#define MSDC_CLK_DAT_PHASE(v)       (((v) & 0x1F) << 8)
#define MSDC_DAT_PHASE_RED          (1 << 13)
#define MSDC_CLK_TUN_BLOCK_NUM(v)   (((v) & 0xFF) << 16)
#define MSDC_CLK_CMD_PHASE(v)       (((v) & 0x1F) << 24)
#define MSDC_CMD_RED_PHASE          (1 << 29)
#define MSDC_CLK_ACB_MODE           (1UL << 31)
// CLK_STA
#define MSDC_CLK_CLKTUN_DONE        (1 << 0)
#define MSDC_CLK_DET_DONE           (1 << 1)
#define MSDC_CLK_COARSE_DONE        (1 << 2)
#define MSDC_CLK_FINE_DONE          (1 << 3)
#define MSDC_CLK_ACB_TO             (1 << 4)
#define MSDC_CLK_DET_CLK_PHASE(v)   (((v) & 0x0F) << 8)
// CLK_CRCSTA1
#define MSDC_CLK_CRC_STA_ENABLE     0xFFFF0000
#define MSDC_CLK_CRC_STA_CRC        0x0000FFFF
// CLK_CRCSTA2

#include "sdcmd.h"

#define MSDC0                       ((volatile TMSDCREGS*)MSDC0_BASE)
#define MSDC1                       ((volatile TMSDCREGS*)MSDC1_BASE)                               // Note: Only the serial interface is available for MSDC1.

extern boolean MSDC_IsMultiLineSupported(TMSDC Index);

#endif /* _MSDC_H_ */
