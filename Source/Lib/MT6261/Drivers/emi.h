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
#ifndef _EMI_H_
#define _EMI_H_

typedef enum
{
    MR_BOOTCODE = 0,                                                                                //Boot jump code
    MR_FB0RB1   = 2,                                                                                //Flash - Bank0, RAM - Bank1
    MR_FB1RB0   = 3                                                                                 //Flash - Bank1, RAM - Bank0
} MREMAP;


#define EMI_REMAP                   (*(volatile uint16_t*)(BOOT_ENG_base))
#define EMI_REMAP_MODE_MASK         0x03


extern void EMI_MemoryRemap(MREMAP Mode);

#endif /* _EMI_H_ */
