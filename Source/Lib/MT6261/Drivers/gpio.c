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

void GPIO_Initialize(void)
{
    GPIO_DIR0_CLR = GPIO_DIR0_MASK;                                                                 //Set all GPIO input
    GPIO_DIR1_CLR = GPIO_DIR1_MASK;

    GPIO_PULLEN0_CLR  = PULLEN0_MASK;                                                               //Disable Pullup/PullDown
    GPIO_PULLEN1_CLR  = PULLEN1_MASK;
    GPIO_RESEN0_0_CLR = RESEN0_0_MASK;
    GPIO_RESEN0_1_CLR = RESEN0_1_MASK;
    GPIO_RESEN1_0_CLR = RESEN1_0_MASK;
    GPIO_RESEN1_1_CLR = RESEN1_1_MASK;

    GPIO_MODE0_CLR = GPIO_MODE0MASK;                                                                //Set pins mode
    GPIO_MODE1_CLR = GPIO_MODE1MASK;
    GPIO_MODE2_CLR = GPIO_MODE2MASK;
    GPIO_MODE3_CLR = GPIO_MODE3MASK;
    GPIO_MODE4_CLR = GPIO_MODE4MASK;
    GPIO_MODE5_CLR = GPIO_MODE5MASK;
    GPIO_MODE6_CLR = GPIO_MODE6MASK;

    GPIO_SetupMode(GPIO51, GPMODE(GPIO51_MODE_RESETB));
#if _DEBUG_
    GPIO_SetupMode(DBG_RXPIN, GPMODE(DBG_RXPIN_MODE));
    GPIO_SetupMode(DBG_TXPIN, GPMODE(DBG_TXPIN_MODE));
#endif
}

void GPIO_SetupMode(uint32_t Pin, uint32_t Flags)
{
    if (Pin <= GPIOMAX)
    {
        if (Flags & GPDO) GPIO_SETDIROUT(Pin);
        else GPIO_SETDIRIN(Pin);

        if (Flags & GPDIEN) GPIO_SETINPUTEN(Pin);
        else GPIO_SETINPUTDIS(Pin);

        if (Flags & GPPDN) GPIO_SETPULLDOWN(Pin);
        else GPIO_SETPULLUP(Pin);

        if (Flags & GPPULLEN) GPIO_PULLENABLE(Pin);
        else GPIO_PULLDISABLE(Pin);

        if (Flags & GPSMT) GPIO_SMTENABLE(Pin);
        else GPIO_SMTDISABLE(Pin);

        GPIO_SETMODE(Pin, (Flags >> 8) & GPIO_MODEMASK);
    }
}
