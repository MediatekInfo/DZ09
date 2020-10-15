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
#include "usb9.h"
#include "usb.h"

const uint8_t EPFIFOSize[USB_EPNUM] =
{
    USB_EP0_FIFOSIZE,
    USB_EP1_FIFOSIZE,
    USB_EP2_FIFOSIZE,
    USB_EP3_FIFOSIZE,
    USB_EP4_FIFOSIZE,
    USB_EP1_FIFOSIZE,
    USB_EP2_FIFOSIZE
};

TEPSTATE EPState[USB_EPNUM];
uint8_t  EP0Buffer[USB_EP0_FIFOSIZE] __attribute__ ((aligned (8)));

static void USB_EPFIFORead(TEP Endpoint, uint32_t Count, void *Data)
{
    uint8_t *DestPointer = (uint8_t *)Data;

    if (Endpoint >= USB_EP1OUT) Endpoint = Endpoint - USB_EP1OUT + USB_EP1IN;                       // Select USB_EP1_FIFO or USB_EP2_FIFO
    USB_INDEX = Endpoint;

    while(Count--)
        *DestPointer++ = USB_EPn_FIFO(Endpoint);
}

static void USB_EPFIFOWrite(TEP Endpoint, uint32_t Count, void *Data)
{
    uint8_t *SrcPointer = (uint8_t *)Data;

    USB_INDEX = Endpoint;

    while(Count--)
        USB_EPn_FIFO(Endpoint) = *SrcPointer++;
}

static void USB_EP0Handler(uint8_t EPAddress)
{
    if (EPState[USB_EP0].Stage == EPSTAGE_IDLE)
    {
        uint32_t Count = USB_GetOUTDataLength(USB_EP0);

        DebugPrint("COUT=%d\r\n", Count);
        if (Count)
        {
            USB_EPFIFORead(USB_EP0, Count, EP0Buffer);
            USB9_HandleSetupRequest((pUSBSETUP)EP0Buffer);
        }
    }
    else if (EPState[USB_EP0].Stage == EPSTAGE_OUT)
    {
//        USB_DataReceive(USB_EP0);
    }
    if (EPState[USB_EP0].Stage == EPSTAGE_IN)
    {
        USB_DataTransmit(USB_EP0);
    }
}

static void USB_ResetDevice(void)
{
    USB_POWER = USWRSTENAB;                                                                         // Enable software reset

    USB_RSTCTRL = USWRST;                                                                           // Reset device
    USB_RSTCTRL = 0;

    USB_FADDR = UUPD;
    USB_INTRINE = 0;
    USB_INTROUTE = 0;
    USB_INTRUSBE = UISUSP | UIRESUME | UIRESET;

    memset(EPState, 0x00, sizeof(EPState));

    USB_SetupEndpoint(USB_EP0, USB_DIR_IN, USB_EP0Handler, USB_EP0_FIFOSIZE);
    USB_SetEndpointEnabled(USB_EP0, true);

    USB_INTRINE |= UEP0;
}

static boolean USB_GetInterruptFlags(uint8_t *IntUSB, uint8_t *IntIN, uint8_t *IntOUT)
{
    *IntUSB = USB_INTRUSB & USB_INTRUSBE;
    *IntIN  = USB_INTRIN & USB_INTRINE;
    *IntOUT = USB_INTROUT & USB_INTROUTE;

    return *IntUSB || *IntIN || *IntOUT;
}

static void USB_EPDefaultHandler(uint8_t EPAddress)
{
    uint8_t EPIndex = EPAddress & ~USB_DIR_MASK;
    uint8_t tmpCSR;

    USB_INDEX = EPIndex;
    if (!EPIndex)
    {
        tmpCSR = USB_EP0_CSR;
        DebugPrint("DefH CSR%d, %02X\r\n", EPIndex, tmpCSR);
        if (tmpCSR & UE0SENTSTALL) USB_EP0_CSR = tmpCSR & ~UE0SENTSTALL;
        if (tmpCSR & UE0SETUPEND) USB_EP0_CSR = UE0SSETUPEND;
    }
    else if ((EPAddress & USB_DIR_MASK) == USB_DIR_IN)
    {
        tmpCSR = USB_EP_INCSR1;
        USB_EP_INCSR1 = tmpCSR & ~UISENTSTALL;
    }
    else
    {
        tmpCSR = USB_EP_OUTCSR1;
        USB_EP_OUTCSR1 = tmpCSR & ~UOSENTSTALL;
    }
}

static void USB_InterruptHandler(void)
{
    uint8_t IntFlagsUSB, IntFlagsIN, IntFlagsOUT;
    uint8_t i;

    while(USB_GetInterruptFlags(&IntFlagsUSB, &IntFlagsIN, &IntFlagsOUT))
    {
        DebugPrint("\r\nINT %02X %02X %02X\r\n", IntFlagsUSB, IntFlagsIN, IntFlagsOUT);
        if (IntFlagsUSB & UIRESET)
        {
            /* Reset the device */
            USB_ResetDevice();
            return;
        }
        if (IntFlagsUSB & UIRESUME)
        {
            /* Enter to normal power mode */
            USB_INTRUSBE = UISUSP | UIRESET;
            USB_POWER = URESUME | USWRSTENAB;
        }
        /* Process endpoint requests */
        for(i = 0; (i < USB_EPNUM) && (IntFlagsIN || IntFlagsOUT); i++)
        {
            uint8_t EPIndex = (i < USB_EP1OUT) ? i : i - USB_EP1OUT + USB_EP1IN;

            USB_INDEX = EPIndex;

            if (IntFlagsIN & (1 << EPIndex))
            {
                USB_EPDefaultHandler(EPIndex | USB_DIR_IN);
                if (EPState[i].EventHandler != NULL) EPState[i].EventHandler(EPIndex | USB_DIR_IN);
            }
            if (IntFlagsOUT & (1 << EPIndex))
            {
                USB_EPDefaultHandler(EPIndex | USB_DIR_OUT);
                if (EPState[i].EventHandler != NULL) EPState[i].EventHandler(EPIndex | USB_DIR_OUT);
            }
            IntFlagsIN  &= ~(1 << EPIndex);
            IntFlagsOUT &= ~(1 << EPIndex);
        }

        if (IntFlagsUSB & UISUSPEND)
        {
            /* Enter to suspend power mode */
            USB_INTRUSBE = UIRESUME | UIRESET;
            USB_POWER = USUSPENAB | USWRSTENAB;
        }
    }
}

void USB_Initialize(void)
{
    memset(&EPState, 0x00, sizeof(EPState));

    USB_DisableDevice();

    NVIC_RegisterIRQ(IRQ_USB_CODE, USB_InterruptHandler, IRQ_SENS_LEVEL, true);
}

void USB_EnableDevice(void)
{
    /* Turn on VUSB */
    PMU_TurnOnVUSB(true);
    /* USB AHB clock */
    PCTL_PowerUp(PD_USB);
    /* USB internal 48MHz */
//    PLL_SetUPLLEnabled(true);
    /* Wait while power stable */
    USC_Pause_us(50);
    /* Turn on PHY bias control */
    USB_U1PHYCR0 |= U1PHYCR0_USB11_FSLS_ENBGRI;
    USC_Pause_us(10);
    /* Set up D+ pull up resistor */
    USB_PHY_CONTROL = UPHY_CONTROL_PUDP;
}

void USB_DisableDevice(void)
{
    /* Release D+ pull up resistor */
    USB_PHY_CONTROL = UPHY_CONTROL_PUDP;
    /* Turn off PHY bias control */
    USB_U1PHYCR0 |= U1PHYCR0_USB11_FSLS_ENBGRI;
    /* Turn off VUSB */
    PMU_TurnOnVUSB(false);
    /* Disable USB internal 48MHz */
//    PLL_SetUPLLEnabled(false);
    /* USB AHB clock */
    PCTL_PowerDown(PD_USB);

    NVIC_UnregisterIRQ(IRQ_USB_CODE);
}

void USB_SetDeviceAddress(uint8_t Address)
{
    USB_FADDR = Address;
    DebugPrint("FADDR = %02X %02X\r\n", Address, USB_FADDR);
}

boolean USB_SetupEndpoint(TEP Endpoint, TUSBDIR Direction, void (*Handler)(uint8_t), uint8_t MaxPacketSize)
{
    if ((Endpoint >= USB_EPNUM) || (Handler == NULL)) return false;

    MaxPacketSize = min(MaxPacketSize, EPFIFOSize[Endpoint]);
    USB_INDEX = (Endpoint < USB_EP1OUT) ? Endpoint : Endpoint - USB_EP1OUT + USB_EP1IN;

    if (Endpoint > USB_EP0)
    {
        if (((Direction & USB_DIR_MASK) == USB_DIR_IN) && (Endpoint < USB_EP1OUT))
        {
            USB_EP_INCSR1 = UICLRDATATOG;
            if (USB_EP_INCSR1 & UINPKTRDY) USB_EP_INCSR1 = UABORTPKTEN | UIFLUSHFIFO;
            if (USB_EP_INCSR1 & UINPKTRDY) USB_EP_INCSR1 = UABORTPKTEN | UIFLUSHFIFO;
            USB_EP_INCSR1 &= ~UABORTPKTEN;
            USB_EP_INMAXP = MaxPacketSize;
        }
        else if ((Endpoint == USB_EP1OUT) || (Endpoint == USB_EP2OUT))
        {
            USB_EP_OUTCSR1 = UOCLRDATATOG;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = UOFLUSHFIFO;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = UOFLUSHFIFO;
            USB_EP_OUTMAXP = MaxPacketSize;
        }
        else return false;
    }

    memset(&EPState[Endpoint], 0x00, sizeof(TEPSTATE));

    EPState[Endpoint].Stage = EPSTAGE_IDLE;
    EPState[Endpoint].EPType = Direction;
    EPState[Endpoint].EventHandler = Handler;
    EPState[Endpoint].PacketSize = MaxPacketSize;
    return true;
}

boolean USB_SetEndpointEnabled(TEP Endpoint, boolean Enable)
{
    uint8_t EPIndex;

    if ((Endpoint >= USB_EPNUM) || (EPState[Endpoint].EventHandler == NULL)) return false;

    EPIndex = (Endpoint < USB_EP1OUT) ? Endpoint : Endpoint - USB_EP1OUT + USB_EP1IN;
    USB_INDEX = EPIndex;

    if ((EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_IN)
    {
        if (Enable)
        {
            USB_EP_INCSR1 = UICLRDATATOG;
            if (USB_EP_INCSR1 & UINPKTRDY) USB_EP_INCSR1 = UABORTPKTEN | UIFLUSHFIFO;
            if (USB_EP_INCSR1 & UINPKTRDY) USB_EP_INCSR1 = UABORTPKTEN | UIFLUSHFIFO;
            USB_EP_INCSR1 &= ~UABORTPKTEN;
            USB_EP_INCSR2 = 0;
            USB_INTRINE |= 1 << EPIndex;
        }
        else
        {
            USB_INTRINE &= ~(1 << EPIndex);
            USB_EP_INCSR2 = 0;
        }
        return true;
    }
    else if ((Endpoint == USB_EP1OUT) || (Endpoint == USB_EP2OUT))
    {
        if (Enable)
        {
            USB_EP_OUTCSR1 = UOCLRDATATOG;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = UOFLUSHFIFO;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = UOFLUSHFIFO;
            USB_EP_OUTCSR2 = 0;
            USB_INTROUTE |= 1 << EPIndex;
        }
        else
        {
            USB_INTROUTE &= ~(1 << EPIndex);
            USB_EP_OUTCSR2 = 0;
        }
        return true;
    }
    return false;
}

uint32_t USB_GetOUTDataLength(TEP Endpoint)
{
    uint32_t DataLength = 0;
    uint8_t  tmpCSR;

    if (Endpoint == USB_EP0)
    {
        USB_INDEX = Endpoint;
        tmpCSR = USB_EP0_CSR;
        if (tmpCSR & UE0OUTPKTRDY) DataLength = USB_EP0_COUNT;
    }
    else if ((Endpoint == USB_EP1OUT) || (Endpoint == USB_EP2OUT))
    {
        uint32_t EPIndex = Endpoint - USB_EP1OUT + USB_EP1IN;

        USB_INDEX = EPIndex;
        tmpCSR = USB_EP_OUTCSR1;
        if (tmpCSR & UE0OUTPKTRDY) DataLength = (UCOUNTH(USB_EP_COUNTH) << 8) | USB_EP_COUNTL;
    }
    return DataLength;
}

void USB_UpdateEPState(TEP Endpoint, boolean ReadStage, boolean SendStall, boolean DataEnd)
{
    uint8_t tmpCSR;

    if (Endpoint == USB_EP0)
    {
        tmpCSR = (ReadStage) ? UE0SOUTPKTRDY : UE0INPKTRDY;

        USB_INDEX = Endpoint;
        if (SendStall) tmpCSR |= UE0SENDSTALL;
        if (DataEnd) tmpCSR |= UE0DATAEND;

        USB_EP0_CSR = tmpCSR;
    }
    else if (Endpoint < USB_EPNUM)
    {
        USB_INDEX = (Endpoint < USB_EP1OUT) ? Endpoint : Endpoint - USB_EP1OUT + USB_EP1IN;
        if ((EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_IN)
        {
            tmpCSR = (ReadStage) ? 0 : UINPKTRDY;
            if (SendStall) tmpCSR |= UISENDSTALL;

            USB_EP_INCSR1 = tmpCSR;
        }
        else if ((Endpoint == USB_EP1OUT) || (Endpoint == USB_EP2OUT))
        {
            tmpCSR = USB_EP_OUTCSR1 & UOUTPKTRDY;
            if (ReadStage) tmpCSR &= ~UOUTPKTRDY;
            if (SendStall) tmpCSR |= UISENDSTALL;

            USB_EP_OUTCSR1 = tmpCSR;
        }
    }
}

void USB_ControlEPStall(TEP Endpoint, boolean Enable)
{
    uint8_t tmpCSR;

    if (Endpoint == USB_EP0) return;

    USB_INDEX = (Endpoint < USB_EP1OUT) ? Endpoint : Endpoint - USB_EP1OUT + USB_EP1IN;
    if (Enable)
    {
        if ((EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_IN)
        {
            tmpCSR = USB_EP_INCSR1;
            tmpCSR |= UISENDSTALL;
            USB_EP_INCSR1 = tmpCSR;
            if (USB_EP_INCSR1 & UINPKTRDY) USB_EP_INCSR1 = tmpCSR | UABORTPKTEN | UIFLUSHFIFO;
            if (USB_EP_INCSR1 & UINPKTRDY) USB_EP_INCSR1 = tmpCSR | UABORTPKTEN | UIFLUSHFIFO;
        }
        else if ((Endpoint == USB_EP1OUT) || (Endpoint == USB_EP2OUT))
        {
            tmpCSR = USB_EP_OUTCSR1;
            tmpCSR |= UOSENDSTALL;
            USB_EP_OUTCSR1 = tmpCSR;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = tmpCSR | UOFLUSHFIFO;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = tmpCSR | UOFLUSHFIFO;
        }
    }
    else
    {
        if ((EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_IN)
        {
            tmpCSR = USB_EP_INCSR1;
            tmpCSR &= ~UISENDSTALL;
            USB_EP_INCSR1 = tmpCSR;
            if (USB_EP_INCSR1 & UINPKTRDY) USB_EP_INCSR1 = tmpCSR | UABORTPKTEN | UIFLUSHFIFO;
            if (USB_EP_INCSR1 & UINPKTRDY) USB_EP_INCSR1 = tmpCSR | UABORTPKTEN | UIFLUSHFIFO;
        }
        else if ((Endpoint == USB_EP1OUT) || (Endpoint == USB_EP2OUT))
        {
            tmpCSR = USB_EP_OUTCSR1;
            tmpCSR &= ~UOSENDSTALL;
            USB_EP_OUTCSR1 = tmpCSR;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = tmpCSR | UOFLUSHFIFO;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = tmpCSR | UOFLUSHFIFO;
        }
    }
}

void USB_PrepareDataReceive(TEP Endpoint, void *DataBuffer)
{
    if ((Endpoint < USB_EPNUM) &&
            ((Endpoint == USB_EP0) || (EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_OUT))
    {
        EPState[Endpoint].DataBuffer = DataBuffer;
        EPState[Endpoint].DataPosition = DataBuffer;
        EPState[Endpoint].DataLength = 0;

        USB_SetEndpointEnabled(Endpoint, true);
    }
}

void USB_PrepareDataTransmit(TEP Endpoint, void *DataBuffer, uint32_t DataLength)
{
    if ((Endpoint < USB_EPNUM) &&
            ((Endpoint == USB_EP0) || (EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_OUT))
    {
        EPState[Endpoint].DataBuffer = DataBuffer;
        EPState[Endpoint].DataPosition = DataBuffer;
        EPState[Endpoint].DataLength = DataLength;
        EPState[Endpoint].Stage = EPSTAGE_IN;
    }
}

void USB_DataTransmit(TEP Endpoint)
{
    if ((Endpoint < USB_EPNUM) &&
            ((Endpoint == USB_EP0) || (EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_OUT))
    {
        uint32_t Count = min(EPState[Endpoint].DataLength, EPState[Endpoint].PacketSize);

        EPState[Endpoint].DataLength -= Count;

        USB_EPFIFOWrite(Endpoint, Count, EPState[Endpoint].DataPosition);

        DebugPrint("TX size: %d\r\n", Count);

        if (Count < EPState[Endpoint].PacketSize)
        {
            EPState[Endpoint].Stage = EPSTAGE_IDLE;
            USB_UpdateEPState(Endpoint, false, false, true);
        }
        else USB_UpdateEPState(Endpoint, false, false, false);
    }
}
