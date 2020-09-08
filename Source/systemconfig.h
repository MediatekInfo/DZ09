/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2020, 2019 AJScorp
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
#ifndef _SYSTEMCONFIG_H_
#define _SYSTEMCONFIG_H_

#include "systypes.h"

//Debug USART interface
#define DBG_USARTn          USART_MODULE1
#define DBG_BAUDRATE        115200
#define DBG_RXPIN           GPIO10
#define DBG_RXPIN_MODE      GPIO10_MODE_U1RXD
#define DBG_TXPIN           GPIO11
#define DBG_TXPIN_MODE      GPIO11_MODE_U1TXD

#if defined(TARGET_SYSTEM)

#define _DEBUG_             (1)
#define _USEBATTERY_        (0)
#define USEINTERRUPTS
#define VIBRVoltage         VIBR_VO18V

#define SystemMemorySize    (3 * 1024 * 1024)
#define SysCacheSize        CACHE_32kB
#define LRTMRHWTIMER        GP_TIMER1
#define LRTMRFrequency      100
#include "systemlib.h"
#include "guilib.h"

#include "appconfig.h"

#elif defined(TARGET_BOOTLOADER)

#define _DEBUG_             (1)
#include "mt6261.h"
#include "debug.h"
#endif

#endif /* _SYSTEMCONFIG_H_ */
