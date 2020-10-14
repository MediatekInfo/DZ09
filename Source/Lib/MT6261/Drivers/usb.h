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
#ifndef _USB_H_
#define _USB_H_

typedef enum tag_USBDIR
{
    USB_DIR_OUT  = 0x00,
    USB_DIR_IN   = 0x80,
    USB_DIR_MASK = 0x80
} TUSBDIR;

typedef enum tag_EPSTAGE
{
    EPSTAGE_IDLE,
    EPSTAGE_RX,
    EPSTAGE_TX
} TEPSTAGE;

typedef enum tag_EP
{
    USB_EP0,
    USB_EP1IN,
    USB_EP2IN,
    USB_EP3IN,
    USB_EP4IN,
    USB_EP1OUT,
    USB_EP2OUT,
    USB_EPNUM
} TEP;

typedef struct tag_EPSTATE
{
    TUSBDIR  EPType;
    TEPSTAGE Stage;
    uint16_t PacketSize;
    void     *TXBuffer;                                                                             // transmit buffer located in main memory
    void     *TXPosition;                                                                           // next transmit position in the buffer or NULL if done
    uint16_t TXLength;                                                                              // transmit buffer length
    void     *RXBuffer;                                                                             // receive buffer located in main memory
    void     *RXPosition;                                                                           // next transmit position in the buffer or NULL if done
    uint16_t RXLength;                                                                              // receive buffer length
    void     (*EventHandler)(uint8_t EPAddress);
} TEPSTATE;

#define USB_EP0_FIFOSIZE            64
#define USB_EP1_FIFOSIZE            64
#define USB_EP2_FIFOSIZE            64
#define USB_EP3_FIFOSIZE            16
#define USB_EP4_FIFOSIZE            16

#define USB_EP0                     USB_EP0
#define USB_EP1                     USB_EP1IN
#define USB_EP2                     USB_EP2IN
#define USB_EP3                     USB_EP3IN
#define USB_EP4                     USB_EP4IN

#define USB_FADDR                   (*(volatile uint8_t *)(USB_BASE + 0x0000))
#define UUPD                        (1 << 7)
#define UFADDR(v)                   (((v) & 0x7F) << 0)
#define USB_POWER                   (*(volatile uint8_t *)(USB_BASE + 0x0001))
#define USUSPENAB                   (1 << 0)
#define USUSPMODE                   (1 << 1)
#define URESUME                     (1 << 2)
#define URESET                      (1 << 3)
#define USWRSTENAB                  (1 << 4)
#define UISO_UP                     (1 << 7)
#define USB_INTRIN                  (*(volatile uint8_t *)(USB_BASE + 0x0002))
#define UEP0                        (1 << 0)
#define UEP1                        (1 << 1)
#define UEP2                        (1 << 2)
#define UEP3                        (1 << 3)
#define UEP4                        (1 << 4)
#define USB_INTROUT                 (*(volatile uint8_t *)(USB_BASE + 0x0004))
#define UEP1                        (1 << 1)
#define UEP2                        (1 << 2)
#define USB_INTRUSB                 (*(volatile uint8_t *)(USB_BASE + 0x0006))
#define UISUSP                      (1 << 0)
#define UIRESUME                    (1 << 1)
#define UIRESET                     (1 << 2)
#define UISOF                       (1 << 3)
#define UPOWERDWN                   (1 << 4)
#define USB_INTRINE                 (*(volatile uint8_t *)(USB_BASE + 0x0007))
#define UEP0                        (1 << 0)
#define UEP1                        (1 << 1)
#define UEP2                        (1 << 2)
#define UEP3                        (1 << 3)
#define UEP4                        (1 << 4)
#define USB_INTROUTE                (*(volatile uint8_t *)(USB_BASE + 0x0009))
#define UEP1                        (1 << 1)
#define UEP2                        (1 << 2)
#define USB_INTRUSBE                (*(volatile uint8_t *)(USB_BASE + 0x000B))
#define UISUSPEND                   (1 << 0)
#define UIRESUME                    (1 << 1)
#define UIRESET                     (1 << 2)
#define UISOF                       (1 << 3)
#define UPOWERDWN                   (1 << 4)
#define USB_FRAME1                  (*(volatile uint8_t *)(USB_BASE + 0x000C))
#define USB_FRAME2                  (*(volatile uint8_t *)(USB_BASE + 0x000D))
#define USB_INDEX                   (*(volatile uint8_t *)(USB_BASE + 0x000E))
#define USB_RSTCTRL                 (*(volatile uint8_t *)(USB_BASE + 0x000F))
#define URSTCNTR(v)                 (((v) & 0x0F) << 0)
#define USWRST                      (1 << 7)
#define USB_EP_INMAXP               (*(volatile uint8_t *)(USB_BASE + 0x0010))
#define USB_EP0_CSR                 (*(volatile uint8_t *)(USB_BASE + 0x0011))
#define UE0OUTPKTRDY                (1 << 0)
#define UE0INPKTRDY                 (1 << 1)
#define UE0SENTSTALL                (1 << 2)
#define UE0DATAEND                  (1 << 3)
#define UE0SETUPEND                 (1 << 4)
#define UE0SENDSTALL                (1 << 5)
#define UE0SOUTPKTRDY               (1 << 6)
#define UE0SSETUPEND                (1 << 7)
#define USB_EP_INCSR1               (*(volatile uint8_t *)(USB_BASE + 0x0011))
#define UINPKTRDY                   (1 << 0)
#define UFIFONOTEMPTY               (1 << 1)
#define UUNDERRUN                   (1 << 2)
#define UIFLUSHFIFO                 (1 << 3)
#define UISENDSTALL                 (1 << 4)
#define UISENTSTALL                 (1 << 5)
#define UICLRDATATOG                (1 << 6)
#define UABORTPKTEN                 (1 << 7)
#define USB_EP_INCSR2               (*(volatile uint8_t *)(USB_BASE + 0x0012))
#define UFRCDATATOG                 (1 << 3)
#define UIDMAENAB                   (1 << 4)
#define UMODE                       (1 << 5)
#define UISO                        (1 << 6)
#define UAUTOSET                    (1 << 7)
#define USB_EP_OUTMAXP              (*(volatile uint8_t *)(USB_BASE + 0x0013))
#define USB_EP_OUTCSR1              (*(volatile uint8_t *)(USB_BASE + 0x0014))
#define UOUTPKTRDY                  (1 << 0)
#define UFIFOFULL                   (1 << 1)
#define UOVERRUN                    (1 << 2)
#define UDATAERROR                  (1 << 3)
#define UOFLUSHFIFO                 (1 << 4)
#define UOSENDSTALL                 (1 << 5)
#define UOSENTSTALL                 (1 << 6)
#define UOCLRDATATOG                (1 << 7)
#define USB_EP_OUTCSR2              (*(volatile uint8_t *)(USB_BASE + 0x0015))
#define UDMAMODE                    (1 << 4)
#define UODMAENAB                   (1 << 5)
#define UISO                        (1 << 6)
#define UAUTOCLEAR                  (1 << 7)
#define USB_EP0_COUNT               (*(volatile uint8_t *)(USB_BASE + 0x0016))
#define USB_EP_COUNTL               (*(volatile uint8_t *)(USB_BASE + 0x0016))
#define USB_EP_COUNTH               (*(volatile uint8_t *)(USB_BASE + 0x0017))
#define UCOUNTH(v)                  ((v) & 0x07)
#define USB_EPn_FIFO(v)             (*(volatile uint8_t *)(USB_BASE + 0x0020 + 4 * (v)))
#define USB_EP0_FIFO                (*(volatile uint8_t *)(USB_BASE + 0x0020))
#define USB_EP1_FIFO                (*(volatile uint8_t *)(USB_BASE + 0x0024))
#define USB_EP2_FIFO                (*(volatile uint8_t *)(USB_BASE + 0x0028))
#define USB_EP3_FIFO                (*(volatile uint8_t *)(USB_BASE + 0x002C))
#define USB_EP4_FIFO                (*(volatile uint8_t *)(USB_BASE + 0x0030))
#define USB_ENABLE                  (*(volatile uint8_t *)(USB_BASE + 0x0230))
#define UENABLE                     (1 << 0)
#define UDISABLE                    (0 << 0)
#define USB_PHY_CONTROL             (*(volatile uint8_t *)(USB_BASE + 0x0240))
#define UPHY_CONTROL_PUDP           (1 << 0)
#define UPHY_CONTROL_PUDM           (1 << 1)
#define UPHY_NULLPKT_FIX            (1 << 5)
#define USB_DUMMY                   (*(volatile uint8_t *)(USB_BASE + 0x0244))

#define USB_U1PHYCR0                (*(volatile uint32_t *)(USB_SIFSLV_BASE + 0x08C0))               // USB1.1 PHY Control Registers
#define U1PHYCR0_USB11_FSLS_ENBGRI  (1 << 11)
#define U1PHYCR0_USB11_RST          (1 << 23)
#define USB_U1PHYCR1                (*(volatile uint32_t *)(USB_SIFSLV_BASE + 0x08C4))               // USB1.1 PHY Control Registers
#define U1PHYCR1_RG_USB11_PHY_REV_7 (1 << 15)
#define USB_U1PHYCR2                (*(volatile uint32_t *)(USB_SIFSLV_BASE + 0x08C8))               // USB1.1 PHY Control Registers

extern TEPSTATE EPState[USB_EPNUM];

extern void USB_Initialize(void);
extern void USB_EnableDevice(void);
extern void USB_DisableDevice(void);
extern void USB_SetDeviceAddress(uint8_t Address);
extern boolean USB_SetupEndpoint(TEP Endpoint, TUSBDIR Direction, void (*Handler)(uint8_t), uint8_t MaxPacketSize);
extern boolean USB_SetEndpointEnabled(TEP Endpoint, boolean Enabled);
extern uint32_t USB_GetOUTDataLength(TEP Endpoint);
extern void USB_UpdateEPState(TEP Endpoint, boolean ReadStage, boolean SendStall, boolean DataEnd);
extern void USB_ControlEPStall(TEP Endpoint, boolean Enable);
extern void USB_PrepareDataReceive(TEP Endpoint, uint8_t *DataBuffer);
extern void USB_PrepareDataTransmit(TEP Endpoint, uint8_t *DataBuffer, uint32_t DataLength);
extern void USB_DataTransmit(TEP Endpoint);

#endif /* _USB_H_ */
