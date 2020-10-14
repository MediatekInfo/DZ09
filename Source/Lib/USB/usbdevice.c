// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "usb9.h"
#include "usbdevice.h"

_USB_STRING_(sd000, 0x0409);
_USB_STRING_(sd001, u"Prolific Technology Inc. ");
_USB_STRING_(sd002, u"USB-Serial Controller D");

const uint8_t *STR_DATA[] = {(const uint8_t *)&sd000, (const uint8_t *)&sd001, (const uint8_t *)&sd002};

const uint8_t DEV_DESC_CDC[] =
{
    DEV_LENGTH,                                                                                     // Size of this descriptor in bytes
    USB_DEVICE,                                                                                     // DEVICE Descriptor
    0x10, 0x01,                                                                                     // USB version 1.1
    0x00,                                                                                           // Devise Class Code
    0x00,                                                                                           // Device Subclass Code
    0x00,                                                                                           // Protocol Code
    USB_EP0_FIFOSIZE,                                                                               // EP0 packet max size
    0x7B, 0x06,                                                                                     // Vendor ID
    0x03, 0x23,                                                                                     // Product ID
    0x00, 0x04,                                                                                     // Revision ID in BCD
    0x01,                                                                                           // Index of string descriptor describing manufacturer
    0x02,                                                                                           // Index of Product description string in String Descriptor
    0x00,                                                                                           // Index of string descriptor describing the device's serial number
    0x01                                                                                            // Number of possible configurations
};

const uint8_t CFG_DESC_CDC[] =
{
    CFG_LENGTH,                                                                                     // Size of this descriptor in bytes
    USB_CONFIG,                                                                                     // CONFIGURATION Descriptor
    0x27, 0x00,                                                                                     // Total size of descriptor, including Interface and Endpoint descriptors
    0x01,                                                                                           // Number of interfaces supported by this configuration
    0x01,                                                                                           // Index of configuration
    0x00,                                                                                           // Index of string descriptor describing this configuration
    0x80,                                                                                           // Powered from USB
    0x64,                                                                                           // Max power consumption 200 mA

// CDC control interface
    /*Interface Descriptor */
    INT_LENGTH,                                                                                     // Size of this descriptor in bytes
    USB_INTERFACE,                                                                                  // INTERFACE Descriptor
    CDC_CTL_INTERFACE_INDEX,                                                                        // Index of interface in this Configuration
    0x00,                                                                                           // Alternative interface ('0' - None)
    0x03,                                                                                           // Number of endpoints, used by this interface
    0xFF,                                                                                           // Class Code: Communication Interface Class
    0x00,                                                                                           // Subclass Code: Abstract Control Model
    0x00,                                                                                           // Protocol Code: Common AT commands
    0x00,                                                                                           // Index of string descriptor describing this interface

    // Pipe 1 (endpoint 1)
    END_LENGTH,                                                                                     // Size of this descriptor in bytes
    USB_ENDPOINT,                                                                                   // ENDPOINT Descriptor
    USB_CDCCONTROL_EP,                                                                              // IN Endpoint with address 0x03
    USB_EPTYPE_INTR,                                                                                // Data transfer type - Interrupt
    USB_EPCDCCTL_MAXP, 0x00,                                                                        // Max packet size = 16
    0x01,                                                                                           // Endpoint polling interval - 1 ms

    // Pipe 2 (endpoint 2)
    END_LENGTH,                                                                                     // Size of this descriptor in bytes
    USB_ENDPOINT,                                                                                   // ENDPOINT Descriptor
    USB_DATAIN_EP,                                                                                  // IN Endpoint with address 0x01
    0x02,                                                                                           // Data transfer Type - Bulk
    USB_EPDEVICE_MAXP, 0x00,                                                                        // Max packet size = 64
    0x00,                                                                                           // '0' - endpoint never NAKs

    // Pipe 2 (endpoint 3)
    END_LENGTH,                                                                                     // Size of this descriptor in bytes
    USB_ENDPOINT,                                                                                   // ENDPOINT Descriptor
    USB_DATAOUT_EP,                                                                                 // OUT Endpoint with address 0x02
    0x02,                                                                                           // Data transfer Type - Bulk
    USB_EPDEVICE_MAXP, 0x00,                                                                        // Max packet size = 64
    0x00                                                                                            // '0' - endpoint never NAKs
};

pUSB_DEV_DESCR USBDevDescriptor = (pUSB_DEV_DESCR)&DEV_DESC_CDC;
uint8_t        *USBCfgDescriptor = (uint8_t *)&CFG_DESC_CDC;
uint8_t        USBCfgDescriptorSz = sizeof(CFG_DESC_CDC);

//bool USB_SetUSBMode(TUSBMODE Mode)
//{
//    switch (Mode)
//    {
//    case UM_MSC:
//        USBDevDescriptor = (pUSB_DEV_DESCR)&DEV_DESC_MSC;
//        USBCfgDescriptor = (uint8_t *)&CFG_DESC_MSC;
//        USBCfgDescriptorSz = sizeof(CFG_DESC_MSC);
//        break;
//    case UM_CDC:
//        USBDevDescriptor = (pUSB_DEV_DESCR)&DEV_DESC_CDC;
//        USBCfgDescriptor = (uint8_t *)&CFG_DESC_CDC;
//        USBCfgDescriptorSz = sizeof(CFG_DESC_CDC);
//        break;
//    default:
//        USBDevDescriptor = NULL;
//        USBCfgDescriptor = NULL;
//        USBCfgDescriptorSz = 0;
//        return false;
//    }
//    return true;
//}
//
uint8_t USB_GetStringCount(void)
{
    return sizeof(STR_DATA) / sizeof(const uint8_t *);
}

uint8_t *USB_GetString(uint8_t Index)
{
    return (Index < USB_GetStringCount()) ? (uint8_t *)STR_DATA[Index] : NULL;
}

uint8_t USB_DevConfigSize(void)
{
    return USBCfgDescriptorSz;
}

void USB_ITF_Reset(void)
{
//    if (CFG.USBMode == UM_MSC) USB_MSC_Reset();
//    else if (CFG.USBMode == UM_CDC) USB_CDC_Reset();
}

void USB_ITF_Initialization(void)
{
//    if (CFG.USBMode == UM_MSC) USB_MSC_Initialize();
//    else if (CFG.USBMode == UM_CDC) USB_CDC_Initialize();
}

boolean USB_ITF_ReqHandler(pUSBSETUP Setup)
{
    boolean Error;
//
//    if (CFG.USBMode == UM_MSC)
//        /* Here already checked for interface request */
//        switch (Setup->wIndex & 0xFF)
//        {
//        case MSC_INTERFACE_INDEX:
//            bError = USB_MSC_ReqHandler(Setup);
//            break;
//        default:
//            bError = true;
//            break;
//        }
//    else if (CFG.USBMode == UM_CDC)
//        /* Here already checked for interface request */
//        switch (Setup->wIndex & 0xFF)
//        {
//        case CDC_CTL_INTERFACE_INDEX:
//            bError = USB_CDC_ReqHandler(Setup);
//            break;
//        case CDC_DATA_INTERFACE_INDEX:
//            bError = true;
//            break;
//        default:
//            bError = true;
//            break;
//        }
//    else bError = true;

    return Error;
}

boolean USB_ITF_VendorReqHandler(pUSBSETUP Setup)
{
    boolean Error;

//    if (CFG.USBMode == UM_MSC) bError = true;
//    else if (CFG.USBMode == UM_CDC)
//        bError = USB_CDC_VendorReqHandler(Setup);
//    else bError = true;

    return Error;
}
