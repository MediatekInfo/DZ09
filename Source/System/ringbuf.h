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
#ifndef _RINGBUF_H_
#define _RINGBUF_H_

typedef struct tag_RINGBUF
{
    uint8_t  *Head;
    uint8_t  *Tail;
    uint32_t BufferSize;
    uint8_t  Buffer[];
} TRINGBUF, *pRINGBUF;

extern pRINGBUF RB_Create(uint32_t BufferSize);
extern pRINGBUF RB_Destroy(pRINGBUF RingBuffer);
extern uint32_t RB_WriteByte(pRINGBUF RingBuffer, uint8_t Data);
extern uint32_t RB_WriteData(pRINGBUF RingBuffer, uint8_t *Data, uint32_t Count);
extern uint32_t RB_ReadByte(pRINGBUF RingBuffer, uint8_t *Data);
extern uint32_t RB_ReadData(pRINGBUF RingBuffer, uint8_t *Data, uint32_t Count);
extern uint32_t RB_GetCurrentDataCount(pRINGBUF RingBuffer);
extern uint32_t RB_GetCurrentFreeSpace(pRINGBUF RingBuffer);
extern void RB_FlashBuffer(pRINGBUF RingBuffer);

#endif /* _RINGBUF_H_ */
