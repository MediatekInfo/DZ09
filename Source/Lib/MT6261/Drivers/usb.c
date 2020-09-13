// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "usb.h"

const uint8_t EP_FIFO[USB_EPNUM] = {64, 64, 64, 16, 16};

TEPSTATE EPState[USB_EPNUM];
uint8_t  SetupPacket[USB_EP0_MAXLENGTH];

void USB_ISR(void)
{
    uint8_t IntFlagsUSB, IntFlagsIN, IntFlagsOUT;

    IntFlagsUSB = USB_INTRUSB;
    IntFlagsIN  = USB_INTRIN;
    IntFlagsOUT = USB_INTROUT;

    DebugPrint("USB %02X %02X %02X\r\n", IntFlagsUSB, IntFlagsIN, IntFlagsOUT);
}

void USB_Initialize(void)
{
    memset(&EPState, 0x00, sizeof(EPState));

    /* Turn on VUSB */
    PMU_TurnOnVUSB(true);
    /* USB AHB clock */
    PCTL_PowerUp(PD_USB);
    /* USB internal 48MHz */
    /* Wait while power stable */
    USC_Pause_us(50);
    /* Turn on PHY bias control */
    USB_U1PHYCR0 |= U1PHYCR0_USB11_FSLS_ENBGRI;
    USC_Pause_us(10);

    NVIC_RegisterIRQ(IRQ_USB_CODE, USB_ISR, IRQ_SENS_LEVEL, true);

    USB_PHY_CONTROL = UPHY_CONTROL_PUDP;
}
