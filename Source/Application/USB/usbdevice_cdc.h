/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2020 AJScorp
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
#ifndef _USBDEVICE_CDC_H_
#define _USBDEVICE_CDC_H_

#define SEND_ENCAPSULATED_COMMAND   0x00
#define GET_ENCAPSULATED_RESPONSE   0x01
#define SET_COMM_FEATURE            0x02
#define GET_COMM_FEATURE            0x03
#define CLEAR_COMM_FEATURE          0x04
#define SET_AUX_LINE_STATE          0x10
#define SET_HOOK_STATE              0x11
#define PULSE_SETUP                 0x12
#define SEND_PULSE                  0x13
#define SET_PULSE_TIME              0x14
#define RING_AUX_JACK               0x15
#define SET_LINE_CODING             0x20
#define LINE_DTR                    (1 << 0)
#define LINE_RTS                    (1 << 1)
#define GET_LINE_CODING             0x21
#define SET_CONTROL_LINE_STATE      0x22
#define SEND_BREAK                  0x23
#define SET_RINGING_PARMS           0x30
#define GET_RINGING_PARMS           0x31
#define SET_OPERATION_PARMS         0x32
#define GET_OPERATION_PARMS         0x33
#define SET_LINE_PARMS              0x34
#define GET_LINE_PARMS              0x35
#define DIAL_DIGITS                 0x36
#define SET_UNIT_PARAMETER          0x37
#define GET_UNIT_PARAMETER          0x38
#define CLEAR_UNIT_PARAMETER        0x39
#define GET_PROFILE                 0x3A

extern void *USB_CDC_Initialize(void);

#endif /* _USBDEVICE_CDC_H_ */
