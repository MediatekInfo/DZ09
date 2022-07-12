// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "spi.h"

#define SPIMAXSPEED                 32000000
#define SPIMAXPACKETLENGTH          1024

static boolean SPI_WaitBusy(void)
{
    while(!(SPI_STATUS2 & SPI_STAT2_BUSY)) {}

    return true;
}

static void SPI_Reset(void)
{
    if (PCTL_GetPeripheralPowerStatus(PD_SPI))
    {
        SPI_CMD |= SPI_CMD_RST;
        SPI_CMD &= ~SPI_CMD_RST;
    }
}

static boolean SPI_SetupRXTX_DMA(void *RX_Dst, void *TX_Src)
{
    boolean Result = false;

    if (RX_Dst != NULL)
    {
        SPI_RX_DST = (uint32_t)RX_Dst;
        SPI_CMD |= SPI_RX_DMA_EN;
        Result = true;
    }
    else SPI_CMD &= ~SPI_RX_DMA_EN;

    if (TX_Src != NULL)
    {
        SPI_TX_SRC = (uint32_t)TX_Src;
        SPI_CMD |= SPI_TX_DMA_EN;
        Result = true;
    }
    else SPI_CMD &= ~SPI_TX_DMA_EN;

    return Result;
}

void SPI_EnableInterface(void)
{
    PCTL_PowerUp(PD_SPI);
    SPI_Reset();
}

void SPI_DisableInterface(void)
{
    SPI_Reset();
    PCTL_PowerDown(PD_SPI);
}

void SPI_SetupCS(uint8_t CSSetTime, uint8_t CSHoldTime, uint8_t CSIdleTime)
{
    if (PCTL_GetPeripheralPowerStatus(PD_SPI) && SPI_WaitBusy())
        SPI_CON0 = (SPI_CON0 & ~(SPI_CON0_SETTIME(-1) | SPI_CON0_HOLDTIME(-1)) | SPI_CON1_CSIDLE(-1)) |
                   SPI_CON0_SETTIME(CSSetTime) | SPI_CON0_HOLDTIME(CSHoldTime) | SPI_CON1_CSIDLE(CSIdleTime);
}

void SPI_SetupSpeed(uint32_t Speed)
{
    if (PCTL_GetPeripheralPowerStatus(PD_SPI) && SPI_WaitBusy())
    {
        uint32_t nTicks;

        Speed = min(Speed, SPIMAXSPEED);
        nTicks = min(255, ((2 * SPIMAXSPEED + Speed / 2) / Speed) - 2);                             // 125kHz min frequency
        SPI_CON0 = (SPI_CON0 & ~(SPI_CON0_HIGHTIME(-1) | SPI_CON0_LOWTIME(-1))) |
                   SPI_CON0_HIGHTIME(nTicks / 2) | SPI_CON0_LOWTIME(nTicks / 2 + (nTicks & 1));
    }
}

void SPI_SetupEndian(boolean RXReverse, boolean TXReverse, boolean RXMSB, boolean TXMSB)
{
    if (PCTL_GetPeripheralPowerStatus(PD_SPI) && SPI_WaitBusy())
    {
        uint32_t tmpCMD = SPI_CMD & ~(SPI_CMD_RX_ENDIAM | SPI_CMD_TX_ENDIAM |
                                      SPI_CMD_RXMSBF | SPI_CMD_TXMSBF);

        if (RXReverse) tmpCMD |= SPI_CMD_RX_ENDIAM;
        if (TXReverse) tmpCMD |= SPI_CMD_TX_ENDIAM;
        if (RXMSB) tmpCMD |= SPI_CMD_RXMSBF;
        if (TXMSB) tmpCMD |= SPI_CMD_TXMSBF;
        SPI_CMD = tmpCMD;
    }
}

void SPI_SetupInterface(TSCPOL CPOL, TSCPHA CPHA, boolean CSDeassertEn)
{
    if (PCTL_GetPeripheralPowerStatus(PD_SPI) && SPI_WaitBusy())
    {
        uint32_t tmpCMD = SPI_CMD & ~(SPI_CMD_CPHA_1 | SPI_CMD_CPOL_1 |
                                      SPI_CMD_CS_DEASSERT_EN);

        if (CPOL == CPOL_1) tmpCMD |= SPI_CMD_CPOL_1;
        if (CPHA == CPHA_1) tmpCMD |= SPI_CMD_CPHA_1;
        if (CSDeassertEn) tmpCMD |= SPI_CMD_CS_DEASSERT_EN;
        SPI_CMD = tmpCMD;
    }
}

boolean SPI_RXTXDataBufferDMA(void *RXData, void *TXData, uint32_t Count)
{
    if (!Count) return true;
    if (PCTL_GetPeripheralPowerStatus(PD_SPI) && SPI_WaitBusy())
    {
        uint32_t Status;
        uint32_t nBytes = min(Count, SPIMAXPACKETLENGTH);

        if (SPI_SetupRXTX_DMA(RXData, TXData))
        {
            if (Count > SPIMAXPACKETLENGTH) SPI_CMD |= SPI_CMD_PAUSE_EN;
            else SPI_CMD &= ~SPI_CMD_PAUSE_EN;

            SPI_CON1 = (SPI_CON1 & ~SPI_CON1_PACKLENGTH(-1)) | SPI_CON1_PACKLENGTH(nBytes - 1);
            SPI_CMD |= SPI_CMD_ACT;

            do
            {
                Status = SPI_STATUS1;
                if (Status & SPI_STAT1_PAUSE_IF)
                {
                    Count -= nBytes;
                    nBytes = min(Count, SPIMAXPACKETLENGTH);
                    if (Count <= SPIMAXPACKETLENGTH)
                    {
                        SPI_CON1 = (SPI_CON1 & ~SPI_CON1_PACKLENGTH(-1)) | SPI_CON1_PACKLENGTH(nBytes - 1);
                        SPI_CMD &= ~SPI_CMD_PAUSE_EN;
                    }
                    SPI_CMD |= SPI_CMD_RESUME;
                }
            }
            while(!(Status & SPI_STAT1_FINISH_IF));

            return true;
        }
    }
    return false;
}
