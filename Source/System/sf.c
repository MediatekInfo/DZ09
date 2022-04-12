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
#include "sf.h"

extern uintptr_t __ROMBase, __ROMLimit;

static TDFCONTEXT DFContext[SFI_CSNUM];

static uint8_t __ramfunc SF_DevReadStatus(pDFCONTEXT DF)
{
    uint8_t tmpSR;

    SFI_DeviceCommandRead(DF->CS, DF_CMD_READ_SR, &tmpSR, 1);

    return tmpSR;
}

static void __ramfunc SF_DevWaitReady(pDFCONTEXT DF)
{
    while(SF_DevReadStatus(DF) & DF_BUSY) {}
}

static void __ramfunc SF_WriteEnable(pDFCONTEXT DF)
{
    SFI_DeviceCommandWrite(DF->CS, DF_CMD_WREN, NULL, 0);
}

static void __ramfunc SF_WriteDisable(pDFCONTEXT DF)
{
    SFI_DeviceCommandWrite(DF->CS, DF_CMD_WRDIS, NULL, 0);
}

static boolean __ramfunc SF_BlankCheck(uint32_t Address, size_t Count)
{
    uint8_t *pData = (uint8_t *)Address, ns = -Address & 0x03;

    for (; ns && (Count > 0); Count--, ns--)
        if (*pData++ != 0xFF)
            return false;
    for (; Count >= 4; Count -= 4, pData += 4)
        if (*(uint32_t *)pData != 0xFFFFFFFF)
            return false;
    for (; Count > 0; Count--)
        if (*pData++ != 0xFF)
            return false;

    return true;
}

uint32_t __ramfunc SF_DevReadID(pDFCONTEXT DF)
{
    uint32_t tmpDevixeID, intflags = __disable_interrupts();

    SFI_DeviceCommandRead(DF->CS, DF_CMD_READ_ID, (uint8_t *)&tmpDevixeID, 3);
    __restore_interrupts(intflags);

    return tmpDevixeID;
}

void __ramfunc SF_WriteStatus(pDFCONTEXT DF, uint8_t *Data, uint32_t Count)
{
    if ((Data != NULL) && Count)
    {
        uint32_t intflags = __disable_interrupts();

        SFI_DeviceCommandWrite(DF->CS, DF_CMD_WRDIS, Data, Count);
        __restore_interrupts(intflags);
    }
}

size_t __ramfunc SF_Read(pDFCONTEXT DF, uint32_t Address, uint8_t *Data, size_t Count)
{
    size_t AbsROMSize = (uintptr_t)&__ROMLimit - (uintptr_t)&__ROMBase + 1;

    if ((Data != 0) && (Address < AbsROMSize))
    {
        uint8_t *pReadData = (uint8_t *)((uintptr_t)&__ROMBase + Address);

        Count = min(Count, AbsROMSize - Address);
        memcpy(Data, pReadData, Count);
    }
    else Count = 0;

    return Count;
}
