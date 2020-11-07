// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2020 AJScorp
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
    uint8_t  tmpBuffer;

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
        uint32_t intflags = DisableInterrupts();

        if ((RingBuffer->Buffer != NULL) &&
                IsDynamicMemory(RingBuffer->Buffer)) free(RingBuffer->Buffer);
        if (IsDynamicMemory(RingBuffer)) free(RingBuffer);
        RestoreInterrupts(intflags);
    }
    return NULL;
}

uint32_t RB_WriteData(pRINGBUF RingBuffer, uint8_t *Data, uint32_t Count)
{
    uint32_t Written = 0;

    if ((RingBuffer != NULL) && (RingBuffer->Buffer != NULL) &&
            (Data != NULL) && Count)
    {

    }
    return Written;
}
