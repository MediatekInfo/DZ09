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
#include "gpio.h"

void EMI_MemoryRemap(MREMAP Mode)
{
    boolean CacheState;

#ifdef USEINTERRUPTS
    uint32_t intflags = DisableInterrupts();
#endif
    CacheState = MPU_DisableCache();
    EMI_REMAP = Mode & EMI_REMAP_MODE_MASK;
    MPU_RestoreCacheEnState(CacheState);
#ifdef USEINTERRUPTS
    RestoreInterrupts(intflags);
#endif
}
