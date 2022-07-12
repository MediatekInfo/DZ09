/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022AJScorp
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
#ifndef _SPI_H_
#define _SPI_H_

#define SPI_CON0                    (*(volatile uint32_t *)(SPI_BASE + 0x0000))
#define SPI_CON0_HIGHTIME(v)        (((v) & 0xFF) << 0)                                             // (COUNT + 1) * CLK_PERIOD
#define SPI_CON0_LOWTIME(v)         (((v) & 0xFF) << 8)
#define SPI_CON0_HOLDTIME(v)        (((v) & 0xFF) << 16)
#define SPI_CON0_SETTIME(v)         (((v) & 0xFF) << 24)
#define SPI_CON1                    (*(volatile uint32_t *)(SPI_BASE + 0x0004))
#define SPI_CON1_CSIDLE(v)          (((v) & 0xFF) << 0)
#define SPI_CON1_PACKLOOP(v)        (((v) & 0xFF) << 8)
#define SPI_CON1_PACKLENGTH(v)      (((v) & 0x03FF) << 16)
#define SPI_CON1_TICK_DLY(v)        (((v) & 0x07) << 29)
#define SPI_TX_SRC                  (*(volatile uint32_t *)(SPI_BASE + 0x0008))
#define SPI_RX_DST                  (*(volatile uint32_t *)(SPI_BASE + 0x000C))
#define SPI_TX_FIFO                 (*(volatile uint32_t *)(SPI_BASE + 0x0010))
#define SPI_RX_FIFO                 (*(volatile uint32_t *)(SPI_BASE + 0x0014))
#define SPI_CMD                     (*(volatile uint32_t *)(SPI_BASE + 0x0018))
#define SPI_CMD_ACT                 (1 << 0)
#define SPI_CMD_RESUME              (1 << 1)
#define SPI_CMD_RST                 (1 << 2)
#define SPI_CMD_PAUSE_EN            (1 << 4)
#define SPI_CMD_CS_DEASSERT_EN      (1 << 5)
#define SPI_CMD_CPHA_0              (0 << 8)
#define SPI_CMD_CPHA_1              (1 << 8)
#define SPI_CMD_CPOL_0              (0 << 9)
#define SPI_CMD_CPOL_1              (1 << 9)
#define SPI_RX_DMA_EN               (1 << 10)
#define SPI_TX_DMA_EN               (1 << 11)
#define SPI_CMD_TXMSBF              (1 << 12)
#define SPI_CMD_RXMSBF              (1 << 13)
#define SPI_CMD_RX_ENDIAM           (1 << 14)                                                       // 0 - not reversed
#define SPI_CMD_TX_ENDIAM           (1 << 15)
#define SPI_CMD_FINISH_IE           (1 << 16)
#define SPI_CMD_PAUSE_IE            (1 << 17)
#define SPI_STATUS1                 (*(volatile uint32_t *)(SPI_BASE + 0x001C))
#define SPI_STAT1_FINISH_IF         (1 << 0)
#define SPI_STAT1_PAUSE_IF          (1 << 1)
#define SPI_STATUS2                 (*(volatile uint32_t *)(SPI_BASE + 0x0020))
#define SPI_STAT2_BUSY              (1 << 0)                                                        // 0 - busy state
#define SPI_PAD_MACRO_SEL           (*(volatile uint32_t *)(SPI_BASE + 0x002C))

typedef enum tag_SCPOL
{
    CPOL_0,
    CPOL_1
} TSCPOL;

typedef enum tag_SCPHA
{
    CPHA_0,
    CPHA_1
} TSCPHA;

extern void SPI_EnableInterface(void);
extern void SPI_DisableInterface(void);
extern void SPI_SetupCS(uint8_t CSSetTime, uint8_t CSHoldTime, uint8_t CSIdleTime);
extern void SPI_SetupSpeed(uint32_t Speed);
extern void SPI_SetupEndian(boolean RXReverse, boolean TXReverse, boolean RXMSB, boolean TXMSB);
extern void SPI_SetupInterface(TSCPOL CPOL, TSCPHA CPHA, boolean CSDeassertEn);
extern boolean SPI_RXTXDataBufferDMA(void *RXData, void *TXData, uint32_t Count);

#endif /* _SPI_H_ */
