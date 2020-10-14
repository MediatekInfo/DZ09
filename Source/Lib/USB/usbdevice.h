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
#ifndef _USB_DEVICE_H_
#define _USB_DEVICE_H_

#define USB_CDCCONTROL_EP           (USB_EP3 | USB_DIR_IN)
#define USB_DATAIN_EP               (USB_EP1 | USB_DIR_IN)
#define USB_DATAOUT_EP              (USB_EP2 | USB_DIR_OUT)

#define USB_EPDEVICE_MAXP           USB_EP1_FIFOSIZE                                                // The same for EP2
#define USB_EPCDCCTL_MAXP           USB_EP3_FIFOSIZE

#define CDC_CTL_INTERFACE_INDEX     0x00
#define CDC_DATA_INTERFACE_INDEX    0x01

#include "usb9.h"

#define _USB_STRING_(name, str)\
const struct name\
{\
    uint8_t  bLength;\
    uint8_t  bDescriptorType;\
    uint16_t bString[(sizeof(str) - 2) / 2];\
}\
name = {sizeof(name), USB_STRING, str};

extern pUSB_DEV_DESCR USBDevDescriptor;
extern uint8_t        *USBCfgDescriptor;
extern const uint8_t DEV_DESC_CDC[];
extern const uint8_t CFG_DESC_CDC[];

extern uint8_t USB_GetStringCount(void);
extern uint8_t *USB_GetString(uint8_t Index);
extern uint8_t USB_DevConfigSize(void);
extern void USB_ITF_Reset(void);
extern void USB_ITF_Initialization(void);
extern boolean USB_ITF_ReqHandler(pUSBSETUP Setup);
extern boolean USB_ITF_VendorReqHandler(pUSBSETUP Setup);

#endif /* _USB_DEVICE_H_ */
