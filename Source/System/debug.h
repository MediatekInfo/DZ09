/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 - 2019 AJScorp
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
#ifndef _DEBUG_H_
#define _DEBUG_H_

#if _DEBUG_
#include <stdio.h>
#define DebugPrint(fmt, args...)    do\
                                    {\
                                        printf(fmt, ## args);\
                                        fflush(stdout);\
                                    }\
                                    while(0)
extern void DBG_Initialize(void);
extern void DBG_DumpMem32(uint32_t *Address, uint32_t Count);
extern void DBG_DumpMem16(uint16_t *Address, uint32_t Count);
#else
#if !defined(DebugPrint)
#define DebugPrint(fmt, args...)
#endif /* DebugPrint */

#define DBG_Initialize()
#define DBG_DumpMem32(x, y)
#define DBG_DumpMem16(x, y)
#endif /* _DEBUG_ */

#endif /* _DEBUG_H_ */
