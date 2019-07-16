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
#ifndef _SYSTYPES_H_
#define _SYSTYPES_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false = 0, true = !false}     boolean;
typedef volatile uint8_t __attribute__((aligned(4))) uint8x32_t;
typedef void* pHANDLE;                                                                              //A temporary definition, may not be necessary in the future.

#endif /* _SYSTYPES_H_ */
