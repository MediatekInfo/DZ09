// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2019 AJScorp
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
#include "debug.h"

#if _DEBUG_

void DBG_Initialize(void)
{
    GPIO_Setup(DBG_RXPIN, GPMODE(DBG_RXPIN_MODE));
    GPIO_Setup(DBG_TXPIN, GPMODE(DBG_TXPIN_MODE));

    USART_Initialize(DBG_USARTINF.USART, DBG_BAUDRATE, NULL, USART_EnFlag);
}

int _write(int file, char *ptr, int len)
{
    int32_t Count = len;

    if (Count && (file == 1))                                                                       // stdout
    {
        DBG_USARTINF.USART_TX_Buffer = ptr;
        DBG_USARTINF.USART_TX_Count  = Count;
        DBG_USARTINF.USART_TX_Index = 0;
        USART_SendBufferPoll(&DBG_USARTINF);
    }
    return len;
}

void DBG_DumpMem32(uint32_t *Address, uint32_t Count)
{
    uint32_t x, y;

    Address = (uint32_t *)((uint32_t)Address & ~(sizeof(uint32_t) - 1));

    for(y = 0; y < Count; y += 16)
    {
        DebugPrint("%08X  ", (uint32_t)Address);
        for(x = 0; x < 16; x += 4)
            DebugPrint("%08X ", *Address++);
        DebugPrint("\r\n");
    }
}

#endif /* _DEBUG_ */
