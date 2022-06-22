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
#include "usart.h"

TUSART_CONTEXT USARTINFO[USART_MODULES] =
{
    {USART1, PD_UART1},
    {USART2, PD_UART2},
    {USART3, PD_UART3}
};

int32_t USART_GetPDCode(TUSART Index)
{
    if (Index < USART_MODULES) return USARTINFO[Index].PD_Code;
    else return -1;
}

pUSART_CONTEXT USART_GetContext(TUSART Index)
{
    if (Index >= USART_MODULES) return NULL;
    else return &USARTINFO[Index];
}

boolean USART_Initialize(TUSART Index, uint32_t Speed, void (*Handler)(void), uint32_t Flags)
{
    uint32_t IRQ_CODE;
    volatile TUSARTREGS *USART;

    if      (Index == USART_MODULE1) IRQ_CODE = IRQ_UART1_CODE;
    else if (Index == USART_MODULE2) IRQ_CODE = IRQ_UART2_CODE;
    else if (Index == USART_MODULE3) IRQ_CODE = IRQ_UART3_CODE;
    else return false;

#ifdef USEINTERRUPTS
    NVIC_UnregisterIRQ(IRQ_CODE);                                                                   // Disable USART Interrupts
#endif
    PCTL_PowerUp(USARTINFO[Index].PD_Code);                                                         // Enable USART clock
    USART = USARTINFO[Index].USART;

    USART->LCR = U_WLS(WLS_8);                                                                      // DLAB = 0, LCR in default state

    // Set USART to default state
    USART->DMA_EN = 0x00;                                                                           // Disable DMA
    USART->AUTOBAUD_EN = 0x00;
    USART->IER = 0x00;                                                                              // Disable interrupts
    USART->MCR = 0x00;
    USART->FCR = CLRT | CLRR;                                                                       // Flash TX and RX, and disable FIFO
    USART->LSR = USART->LSR & ~U_DR;                                                                // Reading LSR for status update
    USART->HIGHSPEED = USPEED(USPEED_16);                                                           // 16 samples per bit
    USART->RATEFIX_AD = FREQ_SEL_26 | AUTOBAUDRATEFIX_52 | RATEFIX_52;                              // Set to default state

    if (Speed)
    {
        uint32_t BR = (USARTDEFCLOCK + (USARTDEFOVS * Speed) / 2) / (USARTDEFOVS * Speed);          // oversampling by 16, baud rate

        if (BR <= 1) return false;                                                                  // Divider can not be lower or equal 1

        USART->LCR |= U_DLAB;
        USART->DLM = (BR >> 8) & 0xFF;                                                              // Set baud rate
        USART->DLL = BR & 0xFF;
        USART->LCR &= ~U_DLAB;
    }
    else
    {
        PCTL_PowerDown(USARTINFO[Index].PD_Code);
        return false;
    }

    /* Enable HW flow control, if need */
//    if (Flags & USART_HWFlow_EnFlag) USART->CR3 |= (USART_CR3_RTSE | USART_CR3_CTSE);             // TO DO!!!!!!

#ifdef USEINTERRUPTS
    USART_EnableInterrupts(Index, Flags);                                                           // Check interrupt enable flags

    if (Flags & (USART_TXInt_EnFlag | USART_RXInt_EnFlag | USART_ERRInt_EnFlag))                    // Configure NVIC
    {
        if  (Handler != NULL)
        {
            NVIC_RegisterIRQ(IRQ_CODE, Handler, IRQ_SENS_EDGE, true, true);
        }
    }
#endif

    if (!(Flags & USART_EnFlag))
    {
        PCTL_PowerDown(USARTINFO[Index].PD_Code);                                                   // Disable USART clock
    }
    return true;
}

void USART_EnableInterrupts(TUSART Index, TUSART_FLAGS Flags)
{
    if (Index < USART_MODULES)
    {
#ifdef USEINTERRUPTS
        uint32_t intflags = __disable_interrupts();
        uint8_t  tmpLCR = USARTINFO[Index].USART->LCR;

        USARTINFO[Index].USART->LCR &= ~U_DLAB;

        if (Flags & USART_TXInt_EnFlag)  USARTINFO[Index].USART->IER |= ETBEI;                      // Enable transmitter interrupt
        if (Flags & USART_RXInt_EnFlag)  USARTINFO[Index].USART->IER |= ERBFI;                      // Enable receiver interrupt
        if (Flags & USART_ERRInt_EnFlag) USARTINFO[Index].USART->IER |= ELSI;                       // Enable errors interrupt
        USARTINFO[Index].USART->LCR = tmpLCR;

        __restore_interrupts(intflags);
#endif
    }
}

void USART_DisableInterrupts(TUSART Index, TUSART_FLAGS Flags)
{
    if (Index < USART_MODULES)
    {
#ifdef USEINTERRUPTS
        uint32_t intflags = __disable_interrupts();
        uint8_t  tmpLCR = USARTINFO[Index].USART->LCR;

        USARTINFO[Index].USART->LCR &= ~U_DLAB;

        if (Flags & USART_TXInt_EnFlag) USARTINFO[Index].USART->IER &= ~ETBEI;                      // Disable transmitter interrupt
        if (Flags & USART_RXInt_EnFlag) USARTINFO[Index].USART->IER &= ~ERBFI;                      // Disable receiver interrupt
        if (Flags & USART_ERRInt_EnFlag) USARTINFO[Index].USART->IER &= ~ELSI;                      // Disable errors interrupt
        USARTINFO[Index].USART->LCR = tmpLCR;

        __restore_interrupts(intflags);
#endif
    }
}

void USART_FlashRX(TUSART Index)
{
    if ((Index < USART_MODULES) && (USARTINFO[Index].USART->FCR_RD & FIFOEN))
        USARTINFO[Index].USART->FCR = CLRR | FIFOEN;
}

void USART_FlashTX(TUSART Index)
{
    if ((Index < USART_MODULES) && (USARTINFO[Index].USART->FCR_RD & FIFOEN))
        USARTINFO[Index].USART->FCR = CLRT | FIFOEN;
}

void USART_SendChar(TUSART Index, char c)
{
    if (Index < USART_MODULES)
    {
        volatile TUSARTREGS *tmpUSART = USARTINFO[Index].USART;

        while(!(tmpUSART->LSR & U_TEMT));
        tmpUSART->TXB = c;
    }
}

void USART_SendString(TUSART Index, char *Str)
{
    if (Str != NULL)
        while (*Str != '\0') USART_SendChar(Index, *Str++);
}

void USART_SendBufferPoll(TUSART Index)
{
    pUSART_CONTEXT USARTInf;

    if (Index >= USART_MODULES) return;
    USARTInf = &USARTINFO[Index];

    if (USARTInf->USART_TX_Buffer != NULL)
    {
        volatile TUSARTREGS *tmpUSART = USARTInf->USART;
        uint8_t  *Data;

        USART_DisableInterrupts(Index, USART_TXInt_EnFlag);                                         // Disable USART TX interrupts

        Data = USARTInf->USART_TX_Buffer + USARTInf->USART_TX_Index;

        while(USARTInf->USART_TX_Index < USARTInf->USART_TX_Count)
        {
            while (!(tmpUSART->LSR & U_TEMT));
            tmpUSART->TXB = *Data++;
            USARTInf->USART_TX_Index++;
        }
        USARTInf->USART_TX_Index = 0;
        USARTInf->USART_TX_Count = 0;
    }
}

void USART_SendBufferInt(TUSART Index)
{
    pUSART_CONTEXT USARTInf;

    if (Index >= USART_MODULES) return;
    USARTInf = &USARTINFO[Index];

    if (USARTInf->USART_TX_Buffer != NULL)
    {
        uint32_t Sent = 0;
        uint8_t  *Data;

        USART_DisableInterrupts(Index, USART_TXInt_EnFlag);                                         // Disable USART TX interrupts

        Data = USARTInf->USART_TX_Buffer + USARTInf->USART_TX_Index;

        while((USARTInf->USART->LSR & U_TEMT) &&
                (Sent < (USARTInf->USART_TX_Count - USARTInf->USART_TX_Index)))
        {
            USARTInf->USART->TXB = *Data++;
            USARTInf->USART_TX_Index++;
            Sent++;
        }
        USART_EnableInterrupts(Index, USART_TXInt_EnFlag);                                          // Enable USART TX interrupts
    }
}
