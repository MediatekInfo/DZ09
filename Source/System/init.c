// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "appinit.h"
#include "init.h"

void Init(void)
{
    DBG_Initialize();                                                                               // Setup debug interface
    DebugPrint("\r\n--System initialization--\r\n");
    MPU_Initialize();                                                                               // Setup system cache
    PCTL_Initialize();                                                                              // Power down peripherals by default
    GPIO_Initialize();                                                                              // Set GPIO to default state

    DebugPrint("Initialize serial flash interface:\r\n");
    SF_Initialize();

    DebugPrint("Initialize real time clock...");
    RTC_Initialize();

    USC_StartCounter();

    DebugPrint("Initialize system memory pool - ");
    {
        size_t MemSize = InitializeMemoryPool();

        if (MemSize != -1) DebugPrint("%u KiB available\r\n", MemSize / 1024);
        else DebugPrint("failed!\r\n");
    }

    DebugPrint("Initialize event manager...");
    DebugPrint((EM_Initialize()) ? "Complete.\r\n" : "Failed\r\n");

    DebugPrint("Initialize NVICs...");
    NVIC_Initialize();
    DebugPrint("Complete.\r\n");

    DebugPrint("Initialize low resolution timers pool...");
    DebugPrint((LRT_Initialize()) ? "Complete.\r\n" : "Failed\r\n");

    PMU_Initialize();

//
//
////////////////////////////////////////////////////////////
//    PMU_DisableUSBDownloaderWDT();
////    PMU_SetVibrationOutput(true);
//    PMU_SetISINKMode(false);
//    PMU_SetISINKParameters(ISINK_CH0, IC_8mA, true);
////////////////////////////////////////////////////////////
//
//    PMU_SetChargingEnable(true);

    __enable_interrupts();
    APP_Initialize();

}
