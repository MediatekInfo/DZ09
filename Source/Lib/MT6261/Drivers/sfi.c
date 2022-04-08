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
#include "sfi.h"

static void __ramfunc SFI_MaskAHBChannel(boolean Mask)
{
    if (Mask) RW_SFI_MISC_CTL3 = RW_SFI_MISC_CTL3 | SFI_CH2_TRANS_MASK;
    else      RW_SFI_MISC_CTL3 = RW_SFI_MISC_CTL3 & ~SFI_CH2_TRANS_MASK;
}

static void __ramfunc SFI_MACEnable(TSFI_CS CS)
{
    uint32_t Value;

    SFI_MaskAHBChannel(true);

    Value = RW_SFI_MAC_CTL;
    if (SFI_GetInterfaceMode(CS) == SFM_QPI)
        Value |= SFI_MAC_SIO_SEL;

    Value |= SFI_MAC_EN;

    while(!(RW_SFI_MISC_CTL3 & SFI_CH2_TRANS_IDLE)) {}
    while(!(RW_SFI_MISC_CTL & SFI_REQ_IDLE)) {}

    RW_SFI_MAC_CTL = Value;
}

static uint32_t __ramfunc SFI_MACTrigger(TSFI_CS CS)
{
    RW_SFI_MAC_CTL = RW_SFI_MAC_CTL | SFI_TRIG | SFI_MAC_EN;

    while(!(RW_SFI_MAC_CTL & SFI_WIP_READY)) {}
    while(RW_SFI_MAC_CTL & SFI_WIP) {}

    return 0;
}

static void __ramfunc SFI_MACLeave(void)
{
    RW_SFI_MAC_CTL &= ~(SFI_TRIG | SFI_MAC_SIO_SEL | SFI_MAC_SEL);
    while(RW_SFI_MAC_CTL & SFI_WIP_READY) {}

    RW_SFI_MAC_CTL &= ~SFI_MAC_EN;
    while(RW_SFI_MAC_CTL & SFI_MAC_EN) {}

    SFI_MaskAHBChannel(false);
}

static void __ramfunc SFI_MACWaitReady(TSFI_CS CS)
{
    SFI_MACTrigger(CS);
    SFI_MACLeave();
}

TSFIMODE __ramfunc SFI_GetInterfaceMode(TSFI_CS CS)
{
    if (CS == SFI_CS0) return (RW_SFI_DIRECT_CTL & SFI_QPI_EN) ? SFM_QPI : SFM_SPI;
    else return SFM_UNKNOWN;
}

void __ramfunc SFI_DeviceCommandRead(TSFI_CS CS, uint8_t Command, uint8_t *InData, uint32_t InCount)
{
    if (CS < SFI_CSNUM)
    {
        if (InData == NULL) InCount = 0;
        else if (InCount >= SFI_GPRAMSIZE - 1)
            InCount = SFI_GPRAMSIZE - 1;

        RW_SFI_GPRAM_DATA = Command;
        RW_SFI_MAC_OUTL = 1;
        RW_SFI_MAC_INL = InCount;
        SFI_MACEnable(CS);
        SFI_MACWaitReady(CS);

        if (InCount)
        {
            volatile uint32_t *pGPRAN = &RW_SFI_GPRAM_DATA;
            uint32_t i = 1, tmpData = *pGPRAN++ >> 8;                                                   // Skip command byte

            while(InCount)
            {
                for(; (i < 4) && InCount; i++, InCount--)
                {
                    *InData++ = tmpData;
                    tmpData >>= 8;
                }
                i = 0;
                tmpData = *pGPRAN++;
            }
        }
    }
}

void __ramfunc SFI_DeviceCommandWrite(TSFI_CS CS, uint8_t Command, uint8_t *OutData, uint32_t OutCount)
{
    if (CS < SFI_CSNUM)
    {
        uint32_t TotalLength = 1;

        if ((OutData != NULL) && OutCount)
        {
            volatile uint32_t *pGPRAN = &RW_SFI_GPRAM_DATA;
            uint32_t tmpData = Command;
            uint32_t i = 8;

            if (OutCount >= SFI_GPRAMSIZE - TotalLength)
                OutCount = SFI_GPRAMSIZE - TotalLength;

            TotalLength += OutCount;

            while(OutCount)
            {
                for(; (i < 32) && OutCount; i += 8, OutCount--)
                {
                    tmpData |= *OutData++ << i;
                }
                i = 0;
                *pGPRAN++ = tmpData;
                tmpData = 0;
            }
        }
        else RW_SFI_GPRAM_DATA = Command;

        SFI_MACEnable(CS);
        RW_SFI_MAC_OUTL = TotalLength;
        RW_SFI_MAC_INL = 0;
        SFI_MACWaitReady(CS);
    }
}

void __ramfunc SFI_DeviceCmdAddr3Write(TSFI_CS CS, uint8_t Command, uint32_t Address,
                                       uint8_t *OutData, uint32_t OutCount)
{
    if (CS < SFI_CSNUM)
    {
        volatile uint32_t *pGPRAN = &RW_SFI_GPRAM_DATA;
        uint32_t tmpData = swab32(Address) & ~0x000000FF | Command;
        uint32_t TotalLength = 4;

        *pGPRAN++ = tmpData;

        if ((OutData != NULL) && OutCount)
        {
            uint32_t i;

            if (OutCount >= SFI_GPRAMSIZE - TotalLength)
                OutCount = SFI_GPRAMSIZE - TotalLength;

            TotalLength += OutCount;

            while(OutCount)
            {
                tmpData = 0;
                for(i = 0; (i < 32) && OutCount; i += 8, OutCount--)
                {
                    tmpData |= *OutData++ << i;
                }
                *pGPRAN++ = tmpData;
            }
        }

        SFI_MACEnable(CS);
        RW_SFI_MAC_OUTL = TotalLength;
        RW_SFI_MAC_INL = 0;
        SFI_MACWaitReady(CS);
    }
}

void __ramfunc SFI_DeviceCmdAddr4Write(TSFI_CS CS, uint8_t Command, uint32_t Address,
                                       uint8_t *OutData, uint32_t OutCount)
{
    if (CS < SFI_CSNUM)
    {
        volatile uint32_t *pGPRAN = &RW_SFI_GPRAM_DATA;
        uint32_t tmpData = Address & 0x000000FF;
        uint32_t TotalLength = 5;

        Address = swab32(Address);
        *pGPRAN++ = (Address << 8) | Command;

        if ((OutData != NULL) && OutCount)
        {
            uint32_t i = 8;

            if (OutCount >= SFI_GPRAMSIZE - TotalLength)
                OutCount = SFI_GPRAMSIZE - TotalLength;

            TotalLength += OutCount;

            while(OutCount)
            {
                for(; (i < 32) && OutCount; i += 8, OutCount--)
                {
                    tmpData |= *OutData++ << i;
                }
                i = 0;
                *pGPRAN++ = tmpData;
                tmpData = 0;
            }
        }
        else *pGPRAN = tmpData;

        SFI_MACEnable(CS);
        RW_SFI_MAC_OUTL = TotalLength;
        RW_SFI_MAC_INL = 0;
        SFI_MACWaitReady(CS);
    }
}

