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

typedef enum tag_CDCSTATUS
{
    CDC_OK,
    CDC_FAILED,
    CDC_CONNECTED,
    CDC_DISCONNECTED,
    CDC_TXTIMEOUT,
} TCDCSTATUS;

typedef struct tag_CDCEVENTER
{
    volatile uint32_t OutBufferSize;
    void (*OnStatusChange)(TCDCSTATUS Status);                                                      // These handlers will be called from the interrupt.
    void (*OnDataReceived)(uint32_t ReceivedCount);                                                 // -
    void (*OnDataTransmitted)(uint32_t TransmittedCount);                                           // -
} TCDCEVENTER, *pCDCEVENTER;

extern void *USB_CDC_Initialize(void);

extern TCDCSTATUS USB_CDC_Open(pCDCEVENTER EventerInfo);
extern TCDCSTATUS USB_CDC_Close(pCDCEVENTER EventerInfo);
extern uint32_t USB_CDC_Read(pCDCEVENTER EventerInfo, uint8_t *DataPtr, uint32_t Count);
extern uint32_t USB_CDC_Write(pCDCEVENTER EventerInfo, uint8_t *DataPtr, uint32_t Count);
extern TCDCSTATUS USB_CDC_FlashRXBuffer(pCDCEVENTER EventerInfo);
extern TCDCSTATUS USB_CDC_FlashTXBuffer(pCDCEVENTER EventerInfo);

#endif /* _USBDEVICE_CDC_H_ */
