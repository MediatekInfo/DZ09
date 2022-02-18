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
#include "crc.h"

static void AddByteToCRC16(uint16_t *pCRC16, uint8_t Data)
{
    static const uint16_t CRCTable[] =
    {
        0x0000, 0xCC01, 0xD801, 0x1400, 0xF001, 0x3C00, 0x2800, 0xE401,
        0xA001, 0x6C00, 0x7800, 0xB401, 0x5000, 0x9C01, 0x8801, 0x4400
    };

    *pCRC16 ^= Data;
    *pCRC16 = (*pCRC16 >> 4) ^ CRCTable[*pCRC16 & 0x000F];
    *pCRC16 = (*pCRC16 >> 4) ^ CRCTable[*pCRC16 & 0x000F];
}

uint16_t CalculateCRC16(void *Data, size_t Count)
{
    uint16_t wCRC16 = 0xFFFF;

    if (Data != NULL)
    {
        uint8_t *bData = Data;

        while(Count--)
            AddByteToCRC16(&wCRC16, *bData++);
    }
    return wCRC16;
}
