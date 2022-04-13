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

static uint8_t __ramfunc SF_DevReadStatus(TSFI_CS CS)
{
    uint8_t tmpSR;

    SFI_DeviceCommandRead(CS, DF_CMD_READ_SR, &tmpSR, 1);

    return tmpSR;
}

static void __ramfunc SF_DevWaitReady(TSFI_CS CS)
{
    while(SF_DevReadStatus(CS) & DF_BUSY) {}
}

static void __ramfunc SF_WriteEnable(TSFI_CS CS)
{
    SFI_DeviceCommandWrite(CS, DF_CMD_WREN, NULL, 0);
}

static void __ramfunc SF_WriteDisable(TSFI_CS CS)
{
    SFI_DeviceCommandWrite(CS, DF_CMD_WRDIS, NULL, 0);
}

static boolean __ramfunc SF_BlankCheck(uint32_t Address, size_t Count)
{
    uint8_t *pData = (uint8_t *)Address, ns = -Address & 0x03;

    for(; ns && (Count > 0); Count--, ns--)
        if (*pData++ != 0xFF)
            return false;
    for(; Count >= 4; Count -= 4, pData += 4)
        if (*(uint32_t *)pData != 0xFFFFFFFF)
            return false;
    for(; Count > 0; Count--)
        if (*pData++ != 0xFF)
            return false;

    return true;
}

uint32_t __ramfunc SF_DevReadID(TSFI_CS CS)
{
    uint32_t tmpDevixeID = 0, intflags = __disable_interrupts();

    SFI_DeviceCommandRead(CS, DF_CMD_READ_ID, (uint8_t *)&tmpDevixeID, 3);
    __restore_interrupts(intflags);

    return tmpDevixeID;
}

boolean __ramfunc SF_WriteStatus(TSFI_CS CS, uint8_t *Data, uint32_t Count)
{
    boolean Result = false;

    if ((Data != NULL) && Count)
    {
        uint32_t intflags = __disable_interrupts();

        Result = SFI_DeviceCommandWrite(CS, DF_CMD_WRDIS, Data, Count);
        __restore_interrupts(intflags);
    }
    return Result;
}

size_t __ramfunc SF_Read(TSFI_CS CS, uint32_t Address, uint8_t *Data, size_t Count)
{
    size_t AbsROMSize = (uintptr_t)&__ROMLimit - (uintptr_t)&__ROMBase + 1;

    if ((Data != 0) && (Address < AbsROMSize) && (CS < SFI_CSNUM))
    {
        uint8_t *pReadData = (uint8_t *)((uintptr_t)&__ROMBase + Address);

        Count = min(Count, AbsROMSize - Address);
        memcpy(Data, pReadData, Count);
    }
    else Count = 0;

    return Count;
}

boolean SF_Initialize(void)
{
    boolean Result = false;

    do
    {
        uint32_t  DeviceID = SF_DevReadID(SFI_CS0);
        TSFIMODE  ItfMode = SFI_GetInterfaceMode(SFI_CS0);
        pDFCONFIG pConfig = (pDFCONFIG)DFConfigList;
        char      *s;

        if      (ItfMode == SFM_SPI) s = "SPI";
        else if (ItfMode == SFM_QPI) s = "QPI";
        else
        {
            DebugPrint(" Interface mode: UNKNOWN!\r\n");
            break;
        }
        DebugPrint(" Interface mode: %s\r\n", s);

        if (DeviceID && (DeviceID != 0xFFFFFFFF))
            DebugPrint(" Found device with ID: (0x%02X, 0x%02X, 0x%02X)\r\n",
                       DeviceID & 0xFF, (DeviceID >> 8) & 0xFF, (DeviceID >> 16) & 0xFF);
        else
        {
            DebugPrint(" Something went wrong, can not read device ID!\r\n");
            break;
        }

        s = NULL;
        while(pConfig->DeviceID != 0)
            if (pConfig->DeviceID == DeviceID)
            {
                s = pConfig->DeviceName;
                DebugPrint(" Found supported device \"%s\"\r\n", s);
                break;
            }
            else pConfig++;

        if (s != NULL)
        {
            DebugPrint(" Total capacity - %u KiB\r\n",
                       (pConfig->PageSize * pConfig->TotalPages) >> 10);

            DebugPrint(" Applying the configuration...");
            SFI_ConfigureInterface(SFI_CS0, pConfig);
            DebugPrint("Complete.\r\n");
        }
        else
        {
            DebugPrint(" No configuration found for device (0x%02X, 0x%02X, 0x%02X)\r\n",
                       DeviceID & 0xFF, (DeviceID >> 8) & 0xFF, (DeviceID >> 16) & 0xFF);
            break;
        }
        Result = true;
    }
    while(0);

    if (!Result) DebugPrint(" SFI initialization failed.\r\n");

    return Result;
}
