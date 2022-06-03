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

extern uintptr_t __ROMBase;

pDFCONFIG FlashConfig;
size_t    FlashCapacity;
boolean   (*SFI_DeviceCmdAddrWrite)(TSFI_CS, uint8_t, uint32_t, uint8_t*, size_t);

static void __ramfunc SF_DevWaitReady(TSFI_CS CS)
{
    uint8_t tmpSR;

    do
    {
        SFI_DeviceCommandRead(CS, DF_CMD_READ_SR, &tmpSR, 1);
    }
    while(tmpSR & DF_BUSY);
}

static boolean __ramfunc SF_BlankCheck(void *Address, size_t Count)
{
    uint8_t *pData = (uint8_t *)((uintptr_t)Address + (uintptr_t)&__ROMBase);
    uint8_t ns = (sizeof(int) - (uintptr_t)Address) & (sizeof(int) - 1);

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

static void __ramfunc SF_EraseBlock64K(TSFI_CS CS, void *Address)
{
    uint32_t intflags = __disable_interrupts();

    SFI_DeviceCommandWrite(CS, DF_CMD_WREN, NULL, 0);
    SFI_DeviceCmdAddrWrite(CS, DF_CMD_ERASE_BLOCK64, (uintptr_t)Address, NULL, 0);
    SF_DevWaitReady(CS);

    __restore_interrupts(intflags);
}

static void __ramfunc SF_EraseBlock32K(TSFI_CS CS, void *Address)
{
    uint32_t intflags = __disable_interrupts();

    SFI_DeviceCommandWrite(CS, DF_CMD_WREN, NULL, 0);
    SFI_DeviceCmdAddrWrite(CS, DF_CMD_ERASE_BLOCK32, (uintptr_t)Address, NULL, 0);
    SF_DevWaitReady(CS);

    __restore_interrupts(intflags);
}

static void __ramfunc SF_EraseBlock4K(TSFI_CS CS, void *Address)
{
    uint32_t intflags = __disable_interrupts();

    SFI_DeviceCommandWrite(CS, DF_CMD_WREN, NULL, 0);
    SFI_DeviceCmdAddrWrite(CS, DF_CMD_ERASE_SECTOR, (uintptr_t)Address, NULL, 0);
    SF_DevWaitReady(CS);

    __restore_interrupts(intflags);
}

static void __ramfunc SF_WriteBlock(TSFI_CS CS, void *Address, uint8_t *Data, size_t Count)
{
    uint32_t intflags = __disable_interrupts();

    SFI_DeviceCommandWrite(CS, DF_CMD_WREN, NULL, 0);
    SFI_DeviceCmdAddrWrite(CS, DF_CMD_PAGE_PROG, (uintptr_t)Address, Data, Count);
    SF_DevWaitReady(CS);
    __restore_interrupts(intflags);
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

    if ((FlashConfig != NULL) && (Data != NULL) && Count)
    {
        uint32_t intflags = __disable_interrupts();

        Result = SFI_DeviceCommandWrite(CS, DF_CMD_WREN, NULL, 0);
        Result &= SFI_DeviceCommandWrite(CS, DF_CMD_WRITE_SR, Data, Count);
        __restore_interrupts(intflags);
    }
    return Result;
}

size_t __ramfunc SF_Read(TSFI_CS CS, void *Address, uint8_t *Data, size_t Count)
{
    if ((CS < SFI_CSNUM) && (Data != NULL) && ((uintptr_t)Address < FlashCapacity))
    {
        uint8_t *pReadData = (uint8_t *)((uintptr_t)&__ROMBase + (uintptr_t)Address);

        Count = min(Count, FlashCapacity - (uintptr_t)Address);
        memcpy(Data, pReadData, Count);
    }
    else Count = 0;

    return Count;
}

size_t __ramfunc SF_Write(TSFI_CS CS, void *Address, uint8_t *Data, size_t Count)
{
    if ((CS < SFI_CSNUM) && (Data != NULL) && ((uintptr_t)Address < FlashCapacity))
    {
        uint8_t *bAddress = Address;

        Count = min(Count, FlashCapacity - (uintptr_t)bAddress);

        while(Count)
        {
            uint32_t nBytes = FlashConfig->PageSize - ((uintptr_t)bAddress & (FlashConfig->PageSize - 1));

            nBytes = min(min(nBytes, Count), SFI_MAXDATALOAD);

            SF_WriteBlock(CS, bAddress, Data, nBytes);

            bAddress += nBytes;
            Data += nBytes;
            Count -= nBytes;
        }
    }
    else Count = 0;

    return Count;
}

boolean __ramfunc SF_Erase(TSFI_CS CS, void *Address, size_t Count)
{
    boolean Result = false;

    if ((CS < SFI_CSNUM) && ((uintptr_t)Address < FlashCapacity) && FlashConfig->EraseSupport)
    {
        uint8_t  *bAddress = Address;
        uint32_t AlignMask = (FlashConfig->EraseSupport & BR_4K) ? BLOCK4K_MASK :
                             (FlashConfig->EraseSupport & BR_32K) ? BLOCK32K_MASK :
                             (FlashConfig->EraseSupport & BR_64K) ? BLOCK64K_MASK : 0;

        if (AlignMask)
        {
            size_t  nStart, nEnd, nBlocks;
            uint8_t *pStart = NULL, *pEnd = NULL;
            uint32_t blockGranularity = (FlashConfig->EraseSupport & BR_4K) ? 1 :
                                        (FlashConfig->EraseSupport & BR_32K) ? 8 :
                                        (FlashConfig->EraseSupport & BR_64K) ? 16 : 0;

            Count = min(Count, FlashCapacity - (uintptr_t)bAddress);
            nStart = (uintptr_t)bAddress & AlignMask;
            bAddress = (void *)((uintptr_t)bAddress & ~AlignMask);
            nBlocks = (nStart + Count + AlignMask) / (AlignMask + 1);
            nEnd = nBlocks * (AlignMask + 1) - (nStart + Count);

            nBlocks *= blockGranularity;

            if (nStart && !SF_BlankCheck(bAddress, nStart) &&
                    ((pStart = malloc(nStart)) != NULL))
                SF_Read(CS, bAddress, pStart, nStart);
            if (nEnd && !SF_BlankCheck((void *)((uintptr_t)bAddress + nStart + Count), nEnd) &&
                    ((pEnd = malloc(nEnd)) != NULL))
                SF_Read(CS, (void *)((uintptr_t)bAddress + nStart + Count), pEnd, nEnd);

            while(nBlocks)
            {
                if ((FlashConfig->EraseSupport & BR_64K) &&
                        !((uintptr_t)bAddress & BLOCK64K_MASK) && (nBlocks >= 16))
                {
                    /* Erase block of 64 KiB */
                    if (!SF_BlankCheck(bAddress, BLOCK64K_MASK + 1))
                        SF_EraseBlock64K(CS, bAddress);
                    nBlocks -= 16;
                    bAddress += BLOCK64K_MASK + 1;
                }
                else if ((FlashConfig->EraseSupport & BR_32K) &&
                         !((uintptr_t)bAddress & BLOCK32K_MASK) && (nBlocks >= 8))
                {
                    /* Erase block of 32 KiB */
                    if (!SF_BlankCheck(bAddress, BLOCK32K_MASK + 1))
                        SF_EraseBlock32K(CS, bAddress);
                    nBlocks -= 8;
                    bAddress += BLOCK32K_MASK + 1;
                }
                else
                {
                    /* Erase block of 4 KiB */
                    if (!SF_BlankCheck(bAddress, BLOCK4K_MASK + 1))
                        SF_EraseBlock4K(CS, bAddress);
                    nBlocks--;
                    bAddress += BLOCK4K_MASK + 1;
                }
            }

            bAddress = (void *)((uintptr_t)Address & ~AlignMask);
            if (pStart != NULL)
            {
                SF_Write(CS, bAddress, pStart, nStart);
                free(pStart);
            }
            if (pEnd != NULL)
            {
                SF_Write(CS, (void *)((uintptr_t)bAddress + nStart + Count), pEnd, nEnd);
                free(pEnd);
            }
            Result = true;
        }
    }
    return Result;
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
            DebugPrint(" Current interface mode: UNKNOWN!\r\n");
            break;
        }
        DebugPrint(" Current interface mode: %s\r\n", s);

        if (DeviceID && (DeviceID != 0xFFFFFFFF))
            DebugPrint(" Found device with ID: (0x%02X, 0x%02X, 0x%02X)\r\n",
                       DeviceID & 0xFF, (DeviceID >> 8) & 0xFF, (DeviceID >> 16) & 0xFF);
        else
        {
            DebugPrint(" Something went wrong, can not read device ID!\r\n");
            break;
        }

        FlashConfig = NULL;
        FlashCapacity = 0;
        SFI_DeviceCmdAddrWrite = NULL;
        while(pConfig->DeviceID != 0)
            if (pConfig->DeviceID == DeviceID)
            {
                FlashConfig = pConfig;
                DebugPrint(" Found supported device \"%s\"\r\n", FlashConfig->DeviceName);
                break;
            }
            else pConfig++;

        if (FlashConfig != NULL)
        {
            FlashCapacity = pConfig->PageSize * pConfig->TotalPages;
            SFI_DeviceCmdAddrWrite = (pConfig->Address4Bytes) ?
                                     SFI_DeviceCmdAddr4Write :
                                     SFI_DeviceCmdAddr3Write;

            DebugPrint(" Total capacity - %u KiB\r\n", FlashCapacity >> 10);

            DebugPrint(" Applying SF device configuration...");
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
