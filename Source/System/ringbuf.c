// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2024 - 2020 AJScorp
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

pRINGBUF RB_Create(uint32_t BufferSize)
{
    pRINGBUF tmpRingBuf = NULL;

    if (BufferSize)
    {
        tmpRingBuf = malloc(sizeof(TRINGBUF) + BufferSize);

        if (tmpRingBuf == NULL) return NULL;

        tmpRingBuf->Head = tmpRingBuf->Buffer;
        tmpRingBuf->Tail = NULL;                                                                    // NULL == Zero data size
        tmpRingBuf->BufferSize = BufferSize;
    }
    return tmpRingBuf;
}

pRINGBUF RB_Destroy(pRINGBUF RingBuffer)
{
    if (RingBuffer != NULL)
    {
        uint32_t intflags = __disable_interrupts();

        if (IsDynamicMemory(RingBuffer)) free(RingBuffer);
        __restore_interrupts(intflags);
    }
    return NULL;
}

uint32_t RB_WriteByte(pRINGBUF RingBuffer, uint8_t Data)
{
    uint32_t WCount = 0;

    if (RingBuffer != NULL)
    {
        uint32_t  intflags = __disable_interrupts();
        uintptr_t Buflimit = (uintptr_t)RingBuffer->Buffer + RingBuffer->BufferSize;

        *RingBuffer->Head++ = Data;

        if (RingBuffer->Tail == RingBuffer->Head - 1) RingBuffer->Tail++;                           // Buffer overflow
        else if (RingBuffer->Tail == NULL) RingBuffer->Tail = RingBuffer->Head - 1;                 // 1st byte placed into buffer

        if ((uintptr_t)RingBuffer->Head >= Buflimit) RingBuffer->Head -= RingBuffer->BufferSize;
        if ((uintptr_t)RingBuffer->Tail >= Buflimit) RingBuffer->Tail -= RingBuffer->BufferSize;

        WCount++;

        __restore_interrupts(intflags);
    }
    return WCount;
}

uint32_t RB_WriteData(pRINGBUF RingBuffer, uint8_t *Data, uint32_t Count)
{
    uint32_t WCount = 0;

    if ((RingBuffer != NULL) && (Data != NULL) && Count)
    {
        uint32_t  intflags = __disable_interrupts();
        uintptr_t Buflimit = (uintptr_t)RingBuffer->Buffer + RingBuffer->BufferSize;

        if (Count >= RingBuffer->BufferSize)
        {
            Data = &Data[Count - RingBuffer->BufferSize];
            Count = RingBuffer->BufferSize;
            RingBuffer->Head = RingBuffer->Buffer;
            RingBuffer->Tail = NULL;
        }
        if (RingBuffer->Tail == NULL) RingBuffer->Tail = RingBuffer->Head;

        WCount = Count;
        while(Count)
        {
            uint32_t NWrite = min(Count, Buflimit - (uintptr_t)RingBuffer->Head);

            memcpy(RingBuffer->Head, Data, NWrite);
            Data += NWrite;
            Count -= NWrite;
            RingBuffer->Head += NWrite;
            if ((uintptr_t)RingBuffer->Head >= Buflimit) RingBuffer->Head -= RingBuffer->BufferSize;
        }
        __restore_interrupts(intflags);
    }
    return WCount;
}

uint32_t RB_ReadByte(pRINGBUF RingBuffer, uint8_t *Data)
{
    uint32_t RCount = 0;

    if ((RingBuffer != NULL) && (Data != NULL))
    {
        uint32_t  intflags = __disable_interrupts();

        if (RingBuffer->Tail != NULL)
        {
            uintptr_t Buflimit = (uintptr_t)RingBuffer->Buffer + RingBuffer->BufferSize;

            *Data = *RingBuffer->Tail++;

            if ((uintptr_t)RingBuffer->Tail >= Buflimit) RingBuffer->Tail -= RingBuffer->BufferSize;
            if (RingBuffer->Tail == RingBuffer->Head) RingBuffer->Tail = NULL;

            RCount++;
        }
        __restore_interrupts(intflags);
    }
    return RCount;
}

uint32_t RB_ReadData(pRINGBUF RingBuffer, uint8_t *Data, uint32_t Count)
{
    uint32_t RCount = 0;

    if ((RingBuffer != NULL) && (Data != NULL) && Count)
    {
        uint32_t  intflags = __disable_interrupts();
        uint32_t  RCount = min(Count, RB_GetCurrentDataCount(RingBuffer));
        uintptr_t Buflimit = (uintptr_t)RingBuffer->Buffer + RingBuffer->BufferSize;

        Count = RCount;
        while(Count)
        {
            uint32_t NRead = min(Count, Buflimit - (uintptr_t)RingBuffer->Tail);

            memcpy(Data, RingBuffer->Tail, NRead);
            Data += NRead;
            Count -= NRead;
            RingBuffer->Tail += NRead;
            if ((uintptr_t)RingBuffer->Tail >= Buflimit) RingBuffer->Tail -= RingBuffer->BufferSize;
        }
        if (RingBuffer->Tail == RingBuffer->Head) RingBuffer->Tail = NULL;

        __restore_interrupts(intflags);
    }
    return RCount;
}

uint32_t RB_GetCurrentDataCount(pRINGBUF RingBuffer)
{
    int32_t DSize = 0;

    if (RingBuffer != NULL)
    {
        uint32_t intflags = __disable_interrupts();

        if (RingBuffer->Tail == NULL) DSize = 0;
        else if (RingBuffer->Head == RingBuffer->Tail) DSize = RingBuffer->BufferSize;
        else
        {
            DSize = (uintptr_t)RingBuffer->Head - (uintptr_t)RingBuffer->Tail;

            if (DSize < 0) DSize = RingBuffer->BufferSize + DSize;
        }
        __restore_interrupts(intflags);
    }
    return DSize;
}

uint32_t RB_GetCurrentFreeSpace(pRINGBUF RingBuffer)
{
    uint32_t n;

    if (RingBuffer != NULL)
    {
        uint32_t intflags = __disable_interrupts();

        n = RingBuffer->BufferSize - RB_GetCurrentDataCount(RingBuffer);
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

        RingBuffer->Head = RingBuffer->Buffer;
        RingBuffer->Tail = NULL;
        __restore_interrupts(intflags);
    }
}
