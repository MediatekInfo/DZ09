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
#include "rgu.h"

void RGU_SetWDTInterval(uint8_t Interval, boolean Enable)                                           //Interval in seconds
{
    Interval = min(Interval, RGUINTERVAL_MAX);

    WDT_MODE = WDMKEY;
    WDT_LENGTH = WDLKEY | TIMEOUT(Interval);                                                        //Set timeout value
    RGU_RestartWDT();
    if (Enable) WDT_MODE = WDMKEY | ENABLE;                                                         //Enable WDT
}

void RGU_EnableWDT(void)
{
    if (WDT_MODE & ENABLE) return;
    WDT_MODE = WDMKEY;
    RGU_RestartWDT();
    WDT_MODE = WDMKEY | ENABLE;
}

void RGU_DisableWDT(void)
{
    WDT_MODE = WDMKEY;
}

TWDTREASON RGU_ReadWDTStatus(void)
{
    if      (WDT_STA & HW_WDT) return WDT_REASON_HW;
    else if (WDT_STA & SW_WDT) return WDT_REASON_SW;

    return WDT_REASON_NONE;
}

void RGU_RestartWDT(void)
{
    WDT_RESTART = WDTRKEY;
}

void RGU_RaiseWDTSWReset(void)
{
    WDT_SWRST = WDSWRKEY;
}
