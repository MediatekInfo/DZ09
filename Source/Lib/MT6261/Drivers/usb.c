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

void             (*USB_OnDeviceActive)(boolean Active);
TEPSTATE         EPState[USB_EPNUM];
static TUSBSTATE USBDeviceState;
static TUSBSETUP SetupBuffer;

static void USB_EPFIFORead(TEP Endpoint, uint32_t Count, void *Data)
{
    uint8_t *DestPointer = (uint8_t *)Data;

    if (Endpoint >= USB_EP1OUT) Endpoint = Endpoint - USB_EP1OUT + USB_EP1IN;                       // Select USB_EP1_FIFO or USB_EP2_FIFO
    USB_INDEX = Endpoint;

    while(Count--)
        if (DestPointer != NULL) *DestPointer++ = USB_EPn_FIFO(Endpoint);
        else if (USB_EPn_FIFO(Endpoint)) {};
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

        if (Count >= sizeof(TUSBSETUP))
        {
            USB_EPFIFORead(USB_EP0, sizeof(TUSBSETUP), &SetupBuffer);
            USB9_HandleSetupRequest(&SetupBuffer);
        }
        else if (Count) USB_UpdateEPState(USB_EP0, USB_DIR_OUT, true, true);                        // Invalid Setup request -> send Stall
    }
    else if (EPState[USB_EP0].Stage == EPSTAGE_OUT)
    {
        if (USB_DataReceive(USB_EP0))
        {
            USB9_HandleSetupRequest(&SetupBuffer);
            EPState[USB_EP0].Stage = EPSTAGE_IDLE;
        }
    }
    if (EPState[USB_EP0].Stage == EPSTAGE_IN)
    {
        if (USB_DataTransmit(USB_EP0))
            EPState[USB_EP0].Stage = EPSTAGE_IDLE;
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

    USB_SetDeviceState(USB_DEVICE_IDLE);

    memset(EPState, 0x00, sizeof(EPState));

    if (!USB9_InterfaceInitialize())
    {
        DebugPrint("Can not initialize USB device interface.\r\n");
        USB_DisableDevice();
    }
    else
    {
        USB_SetupEndpoint(USB_EP0, USB_EP0Handler, USB_EP0_FIFOSIZE);
        USB_SetEndpointEnabled(USB_EP0, true);
    }
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
            uint8_t EPIndex = USB_INDEX = EPIndex = USB_EPENUM2INDEX(i);

            if ((i < USB_EP1OUT) && (IntFlagsIN & (1 << EPIndex)))
            {
                IntFlagsIN  &= ~(1 << EPIndex);
                USB_EPDefaultHandler(EPIndex | USB_DIR_IN);
                if (EPState[i].EventHandler != NULL) EPState[i].EventHandler(EPIndex | USB_DIR_IN);
            }
            if ((i >= USB_EP1OUT) && (IntFlagsOUT & (1 << EPIndex)))
            {
                IntFlagsOUT &= ~(1 << EPIndex);
                USB_EPDefaultHandler(EPIndex | USB_DIR_OUT);
                if (EPState[i].EventHandler != NULL) EPState[i].EventHandler(EPIndex | USB_DIR_OUT);
            }
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
#if !defined(_NO_USB_DRIVER_)
    DebugPrint("USB driver initialization.\r\n");
    memset(&EPState, 0x00, sizeof(EPState));

    USB_DisableDevice();

    NVIC_RegisterIRQ(IRQ_USB_CODE, USB_InterruptHandler, IRQ_SENS_LEVEL, true);
#else
    USB_DisableDevice();
#endif
}

void USB_EnableDevice(void)
{
#if !defined(_NO_USB_DRIVER_)
    if (USBDeviceState == USB_DEVICE_OFF)
    {
        /* Turn on VUSB */
        PMU_TurnOnVUSB(true);
        /* USB AHB clock */
        PCTL_PowerUp(PD_USB);
        /* USB internal 48MHz */
//        PLL_SetUPLLEnabled(true);
        /* Wait while power stable */
        USC_Pause_us(50);
        /* Turn on PHY bias control */
        USB_U1PHYCR1 &= ~U1PHYCR1_RG_USB11_PHY_REV_7;
        USB_U1PHYCR0 |= U1PHYCR0_USB11_FSLS_ENBGRI;
        USC_Pause_us(10);
        /* Set up D+ pull up resistor */
        USB_PHY_CONTROL = UPHY_CONTROL_PUDP;
        USB_SetDeviceState(USB_DEVICE_IDLE);
        /* Enable USB interrupts */
        NVIC_EnableIRQ(IRQ_USB_CODE);
        DebugPrint("USB device enabled.\r\n");
    }
#endif
}

void USB_DisableDevice(void)
{
    if (USBDeviceState != USB_DEVICE_OFF)
    {
        /* Disable USB interrupts */
        NVIC_DisableIRQ(IRQ_USB_CODE);

        /* Disable interface */
        USB_SetDeviceState(USB_DEVICE_OFF);
        USB9_InterfaceInitialize();

        /* Release D+ pull up resistor */
        USB_PHY_CONTROL &= ~UPHY_CONTROL_PUDP;
        /* Turn off PHY bias control */
        USB_U1PHYCR0 &= ~U1PHYCR0_USB11_FSLS_ENBGRI;
        USB_U1PHYCR1 |= U1PHYCR1_RG_USB11_PHY_REV_7;
        /* Turn off VUSB */
        PMU_TurnOnVUSB(false);
        /* Disable USB internal 48MHz */
//        PLL_SetUPLLEnabled(false);
        /* USB AHB clock */
        PCTL_PowerDown(PD_USB);
        DebugPrint("USB device disabled.\r\n");
    }
}

void USB_OnCableDisconnect(void)
{
#if !defined(_NO_USB_DRIVER_)
    if (USB_IsDeviceActive()) USB_ResetDevice();
#endif
}

void USB_SetDeviceAddress(uint8_t Address)
{
    USB_FADDR = Address;
    USB_SetDeviceState(USB_DEVICE_ADDRESSED);
}

void USB_SetDeviceState(TUSBSTATE State)
{
    if (USBDeviceState != State)
    {
        boolean PrevActive = USB_IsDeviceActive();
        boolean NowActive;

        USBDeviceState = State;
        NowActive = USB_IsDeviceActive();
        if ((USB_OnDeviceActive != NULL) && (PrevActive != NowActive))
            USB_OnDeviceActive(NowActive);
    }
}

TUSBSTATE USB_GetDeviceState(void)
{
    return USBDeviceState;
}

boolean USB_IsDeviceActive(void)
{
    return (USBDeviceState == USB_DEVICE_CONFIGURED);
}

void USB_SetOnStateChangeHandler(void (*Handler)(boolean Active))
{
#if !defined(_NO_USB_DRIVER_)
    USB_OnDeviceActive = Handler;
#endif
}

boolean USB_SetupEndpoint(TEP Endpoint, void (*Handler)(uint8_t), uint8_t MaxPacketSize)
{
    TUSBDIR Direction = USB_DIR_IN;

    if ((Endpoint >= USB_EPNUM) || (Handler == NULL)) return false;

    MaxPacketSize = min(MaxPacketSize, EPFIFOSize[Endpoint]);

    USB_INDEX = USB_EPENUM2INDEX(Endpoint);
    if (Endpoint > USB_EP0)
    {
        if (Endpoint < USB_EP1OUT)
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
            Direction = USB_DIR_OUT;
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

    USB_INDEX = EPIndex = USB_EPENUM2INDEX(Endpoint);
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

void USB_UpdateEPState(TEP Endpoint, TUSBDIR Transaction, boolean SendStall, boolean DataEnd)
{
    uint8_t tmpCSR;

    if (Endpoint == USB_EP0)
    {
        tmpCSR = ((Transaction & USB_DIR_MASK) == USB_DIR_OUT) ? UE0SOUTPKTRDY : UE0INPKTRDY;

        USB_INDEX = Endpoint;
        if (SendStall) tmpCSR |= UE0SENDSTALL;
        if (DataEnd) tmpCSR |= UE0DATAEND;

        USB_EP0_CSR = tmpCSR;
    }
    else if (Endpoint < USB_EPNUM)
    {
        USB_INDEX = USB_EPENUM2INDEX(Endpoint);
        if ((EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_IN)
        {
            tmpCSR = USB_EP_INCSR1;
            if ((Transaction & USB_DIR_MASK) == USB_DIR_IN) tmpCSR |= UINPKTRDY;
            if (SendStall) tmpCSR |= UISENDSTALL;

            USB_EP_INCSR1 = tmpCSR;
        }
        else if ((Endpoint == USB_EP1OUT) || (Endpoint == USB_EP2OUT))
        {
            tmpCSR = USB_EP_OUTCSR1;
            if ((Transaction & USB_DIR_MASK) == USB_DIR_OUT) tmpCSR &= ~UOUTPKTRDY;
            if (SendStall) tmpCSR |= UISENDSTALL;

            USB_EP_OUTCSR1 = tmpCSR;
        }
    }
}

void USB_ControlEPStall(TEP Endpoint, boolean Enable)
{
    uint8_t tmpCSR;

    if (Endpoint == USB_EP0) return;

    USB_INDEX = USB_EPENUM2INDEX(Endpoint);
    if (Enable)
    {
        if ((EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_IN)
        {
            tmpCSR = USB_EP_INCSR1;
            tmpCSR |= UISENDSTALL;
            USB_EP_INCSR1 = tmpCSR;
            if (USB_EP_INCSR1 & UINPKTRDY) USB_EP_INCSR1 = tmpCSR | UABORTPKTEN | UIFLUSHFIFO;
            if (USB_EP_INCSR1 & UINPKTRDY) USB_EP_INCSR1 = tmpCSR | UABORTPKTEN | UIFLUSHFIFO;
            EPState[Endpoint].Stalled = false;
        }
        else if ((Endpoint == USB_EP1OUT) || (Endpoint == USB_EP2OUT))
        {
            tmpCSR = USB_EP_OUTCSR1;
            tmpCSR |= UOSENDSTALL;
            USB_EP_OUTCSR1 = tmpCSR;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = tmpCSR | UOFLUSHFIFO;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = tmpCSR | UOFLUSHFIFO;
            EPState[Endpoint].Stalled = false;
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
            EPState[Endpoint].Stalled = true;
        }
        else if ((Endpoint == USB_EP1OUT) || (Endpoint == USB_EP2OUT))
        {
            tmpCSR = USB_EP_OUTCSR1;
            tmpCSR &= ~UOSENDSTALL;
            USB_EP_OUTCSR1 = tmpCSR;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = tmpCSR | UOFLUSHFIFO;
            if (USB_EP_OUTCSR1 & UOUTPKTRDY) USB_EP_OUTCSR1 = tmpCSR | UOFLUSHFIFO;
            EPState[Endpoint].Stalled = true;
        }
    }
}

void USB_PrepareDataReceive(TEP Endpoint, void *DataBuffer, uint32_t MaxDataLength)
{
    if ((Endpoint < USB_EPNUM) &&
            ((Endpoint == USB_EP0) || (EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_OUT))
    {
        EPState[Endpoint].DataBuffer = DataBuffer;
        EPState[Endpoint].DataPosition = DataBuffer;
        EPState[Endpoint].DataLength = MaxDataLength;
        EPState[Endpoint].Stage = ((DataBuffer != NULL) && MaxDataLength) ? EPSTAGE_OUT : EPSTAGE_IDLE;
    }
}

boolean USB_DataReceive(TEP Endpoint)
{
    boolean LastPacket = false;

    if ((Endpoint < USB_EPNUM) &&
            ((Endpoint == USB_EP0) || (EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_OUT) &&
            (EPState[Endpoint].DataBuffer != NULL) && (EPState[Endpoint].DataPosition != NULL))
    {
        pEPSTATE EPInfo = &EPState[Endpoint];
        uint32_t Count = USB_GetOUTDataLength(Endpoint);
        uint32_t TotalReceived = (uintptr_t)EPInfo->DataPosition - (uintptr_t)EPInfo->DataBuffer;

        LastPacket = (Count < EPInfo->PacketSize);

        if (TotalReceived < EPInfo->DataLength)
        {
            uint32_t ReadCount = min(Count, EPInfo->DataLength - TotalReceived);

            USB_EPFIFORead(Endpoint, ReadCount, EPInfo->DataPosition);
            EPInfo->DataPosition += ReadCount;
            Count -= ReadCount;
        }
        if (Count) USB_EPFIFORead(Endpoint, Count, NULL);

        USB_UpdateEPState(Endpoint, USB_DIR_OUT, false, LastPacket);
    }
    return LastPacket;
}

void USB_PrepareDataTransmit(TEP Endpoint, void *DataBuffer, uint32_t DataLength)
{
    if ((Endpoint < USB_EPNUM) &&
            ((Endpoint == USB_EP0) || (EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_IN))
    {
        EPState[Endpoint].DataBuffer = DataBuffer;
        EPState[Endpoint].DataPosition = DataBuffer;
        EPState[Endpoint].DataLength = DataLength;
        EPState[Endpoint].Stage = ((DataBuffer != NULL) && DataLength) ? EPSTAGE_IN : EPSTAGE_IDLE;
    }
}

boolean USB_DataTransmit(TEP Endpoint)
{
    boolean LastPacket = false;

    if ((Endpoint < USB_EPNUM) &&
            ((Endpoint == USB_EP0) || (EPState[Endpoint].EPType & USB_DIR_MASK) == USB_DIR_IN))
    {
        pEPSTATE EPInfo = &EPState[Endpoint];
        uint32_t Count = min(EPInfo->DataLength, EPInfo->PacketSize);

        LastPacket = (Count < EPInfo->PacketSize);
        if (Count && (EPInfo->DataPosition != NULL))
        {
            USB_EPFIFOWrite(Endpoint, Count, EPInfo->DataPosition);

            EPInfo->DataLength -= Count;
            EPInfo->DataPosition += Count;
        }
        USB_UpdateEPState(Endpoint, USB_DIR_IN, false, LastPacket);
    }
    return LastPacket;
}

uint32_t USB_GetDataAmount(TEP Endpoint)
{
    if ((Endpoint < USB_EPNUM) &&
            (EPState[Endpoint].DataBuffer != NULL) && (EPState[Endpoint].DataPosition != NULL) &&
            ((uintptr_t)EPState[Endpoint].DataPosition > (uintptr_t)EPState[Endpoint].DataBuffer))
    {
        return ((uintptr_t)EPState[Endpoint].DataPosition - (uintptr_t)EPState[Endpoint].DataBuffer);
    }
    return 0;
}

TEPSTAGE USB_GetEPStage(TEP Endpoint)
{
    uint32_t intflags = __disable_interrupts();
    TEPSTAGE Stage = (Endpoint < USB_EPNUM) ? EPState[Endpoint].Stage : EPSTAGE_IDLE;

    __restore_interrupts(intflags);

    return Stage;
}

boolean USB_SetEPStage(TEP Endpoint, TEPSTAGE Stage)
{
    if ((Endpoint < USB_EPNUM) && (Stage <= EPSTAGE_IN))
    {
        uint32_t intflags = __disable_interrupts();

        EPState[Endpoint].Stage = Stage;
        __restore_interrupts(intflags);
        return true;
    }
    return false;
}
