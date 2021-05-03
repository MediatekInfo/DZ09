// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2021 - 2020 AJScorp
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
#include "ringbuf.h"

static uint8_t *RB_ShiftPointer(pRINGBUF RingBuffer, uint8_t *BufPtr, uint32_t Value)
{
    uint8_t *BufLimit = &RingBuffer->Buffer[RingBuffer->BufferSize];
    uint8_t *Pointer = BufPtr;

    Value %= RingBuffer->BufferSize;
    Pointer += Value;
    if ((uintptr_t)Pointer >= (uintptr_t)BufLimit)
        Pointer -= RingBuffer->BufferSize;

    return Pointer;
}

pRINGBUF RB_Create(uint32_t BufferSize)
{
    pRINGBUF tmpRingBuf = NULL;
    uint8_t  *tmpBuffer;

    if (BufferSize)
    {
        tmpRingBuf = malloc(sizeof(TRINGBUF));
        tmpBuffer  = malloc(BufferSize);

        if ((tmpRingBuf == NULL) || (tmpBuffer == NULL))
        {
            free(tmpRingBuf);
            free(tmpBuffer);
            return NULL;
        }
        tmpRingBuf->Buffer = tmpRingBuf->Tail = tmpBuffer;
        tmpRingBuf->DataCount = 0;
        tmpRingBuf->BufferSize = BufferSize;
    }
    return tmpRingBuf;
}

pRINGBUF RB_Destroy(pRINGBUF RingBuffer)
{
    if (RingBuffer != NULL)
    {
        uint32_t intflags = __disable_interrupts();

        if ((RingBuffer->Buffer != NULL) &&
                IsDynamicMemory(RingBuffer->Buffer)) free(RingBuffer->Buffer);
        if (IsDynamicMemory(RingBuffer)) free(RingBuffer);
        __restore_interrupts(intflags);
    }
    return NULL;
}

uint32_t RB_WriteData(pRINGBUF RingBuffer, uint8_t *Data, uint32_t Count)
{
    uint32_t WCount = 0;

    if ((RingBuffer != NULL) && (Data != NULL) && Count)
    {
        uint32_t intflags = __disable_interrupts();

        if ((RingBuffer->Buffer != NULL) && (RingBuffer->Tail != NULL))
        {
            uint8_t *BufLimit = &RingBuffer->Buffer[RingBuffer->BufferSize];
            uint8_t *BufHead;

            WCount = Count;
            if (Count >= RingBuffer->BufferSize)
            {
                Data = &Data[Count - RingBuffer->BufferSize];
                Count = RingBuffer->BufferSize;
            }
            BufHead = RB_ShiftPointer(RingBuffer, RingBuffer->Tail, RingBuffer->DataCount);
            if (RingBuffer->BufferSize - RingBuffer->DataCount < Count)
                RingBuffer->Tail = RB_ShiftPointer(RingBuffer, RingBuffer->Tail,
                                                   Count - RingBuffer->BufferSize + RingBuffer->DataCount);

            while(Count)
            {
                uint32_t NWrite = min(Count, (uintptr_t)BufLimit - (uintptr_t)BufHead);

                memcpy(BufHead, Data, NWrite);
                Data += NWrite;
                Count -= NWrite;
                BufHead = RB_ShiftPointer(RingBuffer, BufHead, NWrite);
                RingBuffer->DataCount = min(RingBuffer->DataCount + NWrite, RingBuffer->BufferSize);
            }
        }
        __restore_interrupts(intflags);
    }
    return WCount;
}

uint32_t RB_ReadData(pRINGBUF RingBuffer, uint8_t *Data, uint32_t Count)
{
    uint32_t RCount = 0;

    if ((RingBuffer != NULL) && (Data != NULL) && Count)
    {
        uint32_t intflags = __disable_interrupts();

        if ((RingBuffer->Buffer != NULL) && (RingBuffer->Tail != NULL))
        {
            uint8_t *BufLimit = &RingBuffer->Buffer[RingBuffer->BufferSize];
            uint32_t RBytes = RCount = min(RingBuffer->DataCount, Count);

            while(RBytes)
            {
                uint32_t NRead = min(RBytes, (uintptr_t)BufLimit - (uintptr_t)RingBuffer->Tail);

                memcpy(Data, RingBuffer->Tail, NRead);
                Data += NRead;
                RBytes -= NRead;
                RingBuffer->Tail = RB_ShiftPointer(RingBuffer, RingBuffer->Tail, NRead);
            }
            RingBuffer->DataCount -= RCount;
            __restore_interrupts(intflags);
        }
    }
    return RCount;
}

uint32_t RB_GetCurrentDataCount(pRINGBUF RingBuffer)
{
    uint32_t n;

    if (RingBuffer != NULL)
    {
        uint32_t intflags = __disable_interrupts();

        n = RingBuffer->DataCount;
        __restore_interrupts(intflags);
    }
    else n = 0;

    return n;
}

uint32_t RB_GetCurrentFreeSpace(pRINGBUF RingBuffer)
{
    uint32_t n;

    if (RingBuffer != NULL)
    {
        uint32_t intflags = __disable_interrupts();

        n = RingBuffer->BufferSize - RingBuffer->DataCount;
        __restore_interrupts(intflags);
    }
    else n = 0;

    return n;
}

void RB_FlashBuffer(pRINGBUF RingBuffer)
{
    if (RingBuffer != NULL)
    {
        uint32_t intflags = __disable_interrupts();

        RingBuffer->Tail = RingBuffer->Buffer;
        RingBuffer->DataCount = 0;
        __restore_interrupts(intflags);
    }
}
