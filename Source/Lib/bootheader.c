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
#include <stdint.h>
#include "mtktypes.h"

typedef struct tag_APP_HEADER
{
    FILE_INFO_v1        file_info;
    GFH_BROM_CFG_v3     brom_cfg;
    GFH_BL_INFO_v1      bl_info;
    GFH_ARM_BL_INFO_v1  arm_bl_info;
} APP_HEADER;

extern uint32_t __boot_header_base;
extern uint32_t __boot_header_size;

volatile const APP_HEADER boot_header __attribute__ ((section (".boot_header"))) =
{
    {
        {GFH_HDR_MAGIC, sizeof(FILE_INFO_v1), GFH_FILE_INFO},
        "FILE_INFO",
        1,
        ARM_BL,
        F_SF,
        1,
        (uint32_t)(&__boot_header_base),
        0xffffffff,
        0xffffffff,
        (uint32_t)(&__boot_header_size),
        0x00000020,
        (uint32_t)(&__boot_header_size),
        1
    },
    {   {GFH_HDR_MAGIC, sizeof(GFH_BROM_CFG_v3), GFH_BROM_CFG},
        0x02, 0x00, 0x00, 0x00, 0xB8, 0x0B
    },
    {
        {GFH_HDR_MAGIC, sizeof(GFH_BL_INFO_v1), GFH_BL_INFO},
        1
    },
    {
        {GFH_HDR_MAGIC, sizeof(GFH_ARM_BL_INFO_v1), GFH_ARM_BL_INFO},
        0x00000001,
        0x00000560,
        0x00000000,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }
};
