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
#include "nvic.h"

static TIRQHANDLER  IRQHandlers[NUM_IRQ_SOURCES];
static TEINTHANDLER EINTHandlers[NUM_EINT_SOURCES];

static TIRQHANDLER  AIRQHandlers[ADIE_NUM_IRQ_SOURCES];
static TEINTHANDLER AEINTHandlers[NUM_ADIE_EINT_SOURCES];

static uint32_t IRQMaskStore[2];
static uint16_t AIRQMaskStore;
static uint32_t EINTMaskStore;
static uint32_t EINTD0MaskStore;
static uint16_t AEINTMaskStore;
static uint16_t AEINTD0MaskStore;

static uint32_t NVIC_GetIRQStatus2(void)
{
    return IRQ_STA2;
}

static uint32_t NVIC_GetEINTStatus2(void)
{
    return CTZ(EINT_STATUS);
}

static uint32_t NVIC_GetAIRQStatus2(void)
{
    return ADIE_IRQ_STA2;
}

static uint32_t NVIC_GetAEINTStatus2(void)
{
    return CTZ(ADIE_EINT_STATUS & 0xFFFF);
}

static void NVIC_SetIRQ_EOI(uint32_t SourceIdx)
{
    if (SourceIdx < NUM_IRQ_SOURCES) IRQ_EOI2 = SourceIdx;
}

static void NVIC_SetAIRQ_EOI(uint32_t SourceIdx)
{
    if (SourceIdx < ADIE_NUM_IRQ_SOURCES) ADIE_IRQ_EOI2 = SourceIdx;
}

static void NVIC_SetEINT_EOI(uint32_t SourceIdx)
{
    if (SourceIdx < NUM_EINT_SOURCES) EINT_INTACK = (1 << SourceIdx);
}

static void NVIC_SetAEINT_EOI(uint32_t SourceIdx)
{
    if (SourceIdx < NUM_ADIE_EINT_SOURCES) ADIE_EINT_INTACK = (1 << SourceIdx);
}

// IRQ
static void NVIC_UnmaskIRQ2(uint32_t SourceIdx)
{
    if (SourceIdx < NUM_IRQ_SOURCES)
    {
        if (SourceIdx < 32)
        {
            IRQ_MASK_CLR0 = (1 << SourceIdx);
            return;
        }
        SourceIdx -= 32;
        IRQ_MASK_CLR1 = (1 << SourceIdx);
        return;
    }
    if ((SourceIdx >= TOTAL_IRQ_SOURCES) && (SourceIdx < GLB_IRQ_SOURCES))
    {
        SourceIdx -= TOTAL_IRQ_SOURCES;
        ADIE_IRQ_MASK_CLR = (1 << SourceIdx);
    }
}

static void NVIC_MaskIRQ2(uint32_t SourceIdx)
{
    if (SourceIdx < NUM_IRQ_SOURCES)
    {
        if (SourceIdx < 32)
        {
            IRQ_MASK_SET0 = (1 << SourceIdx);
            return;
        }
        SourceIdx -= 32;
        IRQ_MASK_SET1 = (1 << SourceIdx);
        return;
    }
    if ((SourceIdx >= TOTAL_IRQ_SOURCES) && (SourceIdx < GLB_IRQ_SOURCES))
    {
        SourceIdx -= TOTAL_IRQ_SOURCES;
        ADIE_IRQ_MASK_SET = (1 << SourceIdx);
    }
}

static void NVIC_SetIRQSenseEdge(uint32_t SourceIdx)
{
    if (SourceIdx < NUM_IRQ_SOURCES)
    {
        if (SourceIdx < 32)
        {
            IRQ_SENS_CLR0 = (1 << SourceIdx);
            return;
        }
        SourceIdx -= 32;
        IRQ_SENS_CLR1 = (1 << SourceIdx);
        return;
    }
    if ((SourceIdx >= TOTAL_IRQ_SOURCES) && (SourceIdx < GLB_IRQ_SOURCES))
    {
        SourceIdx -= TOTAL_IRQ_SOURCES;
        ADIE_IRQ_SENS_CLR = (1 << SourceIdx);
    }
}

static void NVIC_SetIRQSenseLevel(uint32_t SourceIdx)
{
    if (SourceIdx < NUM_IRQ_SOURCES)
    {
        if (SourceIdx < 32)
        {
            IRQ_SENS_SET0 = (1 << SourceIdx);
            return;
        }
        SourceIdx -= 32;
        IRQ_SENS_SET1 = (1 << SourceIdx);
        return;
    }
    if ((SourceIdx >= TOTAL_IRQ_SOURCES) && (SourceIdx < GLB_IRQ_SOURCES))
    {
        SourceIdx -= TOTAL_IRQ_SOURCES;
        ADIE_IRQ_SENS_SET = (1 << SourceIdx);
    }
}

static void NVIC_StoreAndMaskIRQ(void)
{
    uint32_t intflags = DisableInterrupts();

    IRQMaskStore[0] = IRQ_MASK0;
    IRQ_MASK_SET0 = 0xFFFFFFFF & ~(1 << IRQ_EINT_CODE);
    IRQMaskStore[1] = IRQ_MASK1;
    IRQ_MASK_SET1 = 0xFFFFFFFF;
    AIRQMaskStore   = ADIE_IRQ_MASK;
    ADIE_IRQ_MASK_SET = 0xFFFF & ~(1 << (IRQ_ADIE_EINT_CODE - TOTAL_IRQ_SOURCES));

    RestoreInterrupts(intflags);
}

static void NVIC_RestoreMaskedIRQ(void)
{
    uint32_t intflags = DisableInterrupts();

    IRQ_MASK_CLR0 = ~IRQMaskStore[0];
    IRQ_MASK_CLR1 = ~IRQMaskStore[1];
    ADIE_IRQ_MASK_CLR = ~AIRQMaskStore;

    RestoreInterrupts(intflags);
}

// EINT
static void NVIC_UnmaskEINT2(uint32_t SourceIdx)
{
    if      (SourceIdx < NUM_EINT_SOURCES) EINT_MASK_CLR = (1 << SourceIdx);
    else if (SourceIdx < GLB_EINT_SOURCES)
    {
        SourceIdx -= NUM_EINT_SOURCES;
        ADIE_EINT_MASK_CLR = (1 << SourceIdx);
    }
}

static void NVIC_MaskEINT2(uint32_t SourceIdx)
{
    if      (SourceIdx < NUM_EINT_SOURCES) EINT_MASK_SET = (1 << SourceIdx);
    else if (SourceIdx < GLB_EINT_SOURCES)
    {
        SourceIdx -= NUM_EINT_SOURCES;
        ADIE_EINT_MASK_SET = (1 << SourceIdx);
    }
}

static void NVIC_SetEINTSenseEdge(uint32_t SourceIdx)
{
    if      (SourceIdx < NUM_EINT_SOURCES) EINT_SENS_CLR = (1 << SourceIdx);
    else if (SourceIdx < GLB_EINT_SOURCES)
    {
        SourceIdx -= NUM_EINT_SOURCES;
        ADIE_EINT_SENS_CLR = (1 << SourceIdx);
    }
}

static void NVIC_SetEINTSenseLevel(uint32_t SourceIdx)
{
    if      (SourceIdx < NUM_EINT_SOURCES) EINT_SENS_SET = (1 << SourceIdx);
    else if (SourceIdx < GLB_EINT_SOURCES)
    {
        SourceIdx -= NUM_EINT_SOURCES;
        ADIE_EINT_SENS_SET = (1 << SourceIdx);
    }
}

static void NVIC_EnableEINT_D0Event2(uint32_t SourceIdx)
{
    if      (SourceIdx < NUM_EINT_SOURCES) EINT_D0EN |= (1 << SourceIdx);
    else if (SourceIdx < GLB_EINT_SOURCES)
    {
        SourceIdx -= NUM_EINT_SOURCES;
        ADIE_EINT_D0EN |= (1 << SourceIdx);
    }
}

static void NVIC_DisableEINT_D0Event2(uint32_t SourceIdx)
{
    if      (SourceIdx < NUM_EINT_SOURCES) EINT_D0EN &= ~(1 << SourceIdx);
    else if (SourceIdx < GLB_EINT_SOURCES)
    {
        SourceIdx -= NUM_EINT_SOURCES;
        ADIE_EINT_D0EN &= ~(1 << SourceIdx);
    }
}

static void NVIC_SetEINTDebounce(uint32_t SourceIdx, uint16_t Debounce)
{
    boolean Masked;

    if (SourceIdx < NUM_EINT_SOURCES)
    {
        Masked = (EINT_MASK & (1 << SourceIdx)) ? true : false;                                     // Get the masked status
        if (!Masked) NVIC_MaskEINT2(SourceIdx);                                                     // 1. Mask EINT
        EINT_CON(SourceIdx) = Debounce & ~EINT_DEBEN;                                               // 2. Disable debounce
        USC_Pause_us(50);                                                                           // 3. Delay at least 5 32K cycles
        EINT_CON(SourceIdx) = Debounce;                                                             // 4. Enable the debounce (EN = 1) and change the debounce setting
        if (!Masked) NVIC_UnmaskEINT2(SourceIdx);                                                   // 5. Unmask EINT
    }
    else if (SourceIdx < GLB_EINT_SOURCES)
    {
        SourceIdx -= NUM_EINT_SOURCES;

        Masked = (ADIE_EINT_MASK & (1 << SourceIdx)) ? true : false;                                // Get the masked status
        if (!Masked) NVIC_MaskEINT2(SourceIdx + NUM_EINT_SOURCES);                                  // 1. Mask EINT
        ADIE_EINT_CON(SourceIdx) &= ~(ADIE_EINT_PSMASK | ADIE_EINT_DEBEN);                          // 2. Clear original prescaler and disable debounce
        USC_Pause_us(50);                                                                           // 3. Delay at least 5 32K cycles
        ADIE_EINT_CON(SourceIdx) = Debounce;                                                        // 4. Enable the debounce (EN = 1) and change the debounce setting
        USC_Pause_us(50);                                                                           // 5. Delay at least 5 32K cycles
        ADIE_EINT_DBCRST |= 1 << SourceIdx;                                                         // 6. Reset debounce counter
        USC_Pause_us(50);                                                                           // 7. Delay at least 5 32K cycles
        NVIC_SetAEINT_EOI(SourceIdx);                                                               // 8. Ack spurious interrupt
        if (!Masked) NVIC_UnmaskEINT2(SourceIdx + NUM_EINT_SOURCES);                                // 9. Unmask EINT
    }
}

void NVIC_C_IRQ_Handler(void)
{
    uint32_t IRQSrcIdx;

    while((IRQSrcIdx = NVIC_GetIRQStatus2()) != NOIRQ)
    {
        IRQSrcIdx &= IRQMASK;
        if (IRQHandlers[IRQSrcIdx].Handler != NULL)
            IRQHandlers[IRQSrcIdx].Handler();
        else
        {
            DebugPrint("\r\nUnhandled IRQ 0x%02X", IRQSrcIdx);
        }
        NVIC_SetIRQ_EOI(IRQSrcIdx);
    }
}

void NVIC_ADIE_C_IRQ_Handler(void)
{
    uint32_t AIRQSrcIdx;

    while((AIRQSrcIdx = NVIC_GetAIRQStatus2()) != NOIRQ)
    {
        AIRQSrcIdx &= AIRQMASK;
        if (AIRQHandlers[AIRQSrcIdx].Handler != NULL)
            AIRQHandlers[AIRQSrcIdx].Handler();
        else
        {
            DebugPrint("\r\nUnhandled AIRQ 0x%02X", AIRQSrcIdx);
        }
        NVIC_SetAIRQ_EOI(AIRQSrcIdx);
    }
}

void NVIC_EINTCHandler(void)
{
    uint32_t EINTSrcIdx = NVIC_GetEINTStatus2();

    if ((EINTSrcIdx < NUM_EINT_SOURCES) && (EINTHandlers[EINTSrcIdx].Handler != NULL))
        EINTHandlers[EINTSrcIdx].Handler();
    else
    {
        DebugPrint("\r\nUnhandled EINT 0x%02X", EINTSrcIdx);
    }
    NVIC_SetEINT_EOI(EINTSrcIdx);
}

void NVIC_AEINTCHandler(void)
{
    uint32_t AEINTSrcIdx = NVIC_GetAEINTStatus2();

    if ((AEINTSrcIdx < NUM_ADIE_EINT_SOURCES) && (AEINTHandlers[AEINTSrcIdx].Handler != NULL))
        AEINTHandlers[AEINTSrcIdx].Handler();
    else
    {
        DebugPrint("\r\nUnhandled AEINT 0x%02X", AEINTSrcIdx);
    }
    NVIC_SetAEINT_EOI(AEINTSrcIdx);
}

void NVIC_Initialize(void)
{
    uint32_t i, intflags = DisableInterrupts();

    IRQ_MASK_SET0 = IRQ_MASK0_ALL;                                                                  // Disable All interrupt sources
    IRQ_MASK_SET1 = IRQ_MASK1_ALL;
    EINT_MASK_SET = EINT_MASK_ALL;
    EINT_D0EN = 0;

    ADIE_IRQ_MASK_SET = ADIE_IRQ_MASK_ALL;                                                          // Disable All ADIE interrupt sources
    ADIE_EINT_MASK_SET = ADIE_EINT_MASK_ALL;
    ADIE_EINT_D0EN = 0;

    for(i = 0; i < MAX_IRQ_SELECTIONS; i++)
        IRQ_SEL(i, i);

    memset(IRQHandlers, 0x00, sizeof(IRQHandlers));
    memset(EINTHandlers, 0x00, sizeof(EINTHandlers));

    for(i = 0; i < MAX_ADIE_IRQ_SELECTIONS; i++)
        ADIE_IRQ_SEL(i, i);

    memset(AIRQHandlers, 0x00, sizeof(AIRQHandlers));
    memset(AEINTHandlers, 0x00, sizeof(AEINTHandlers));

    while((i = NVIC_GetIRQStatus2()) != NOIRQ) NVIC_SetIRQ_EOI(i);                                  // Release IRQ interrupts
    while((i = NVIC_GetAIRQStatus2()) != NOIRQ) NVIC_SetAIRQ_EOI(i);                                // Release AIRQ interrupts

    EINT_INTACK = EINT_MASK_ALL;                                                                    // Release EINT interrupts
    ADIE_EINT_INTACK = ADIE_EINT_MASK_ALL;                                                          // Release AEINT interrupts
    NVIC_RegisterIRQ(IRQ_EINT_CODE, NVIC_EINTCHandler, IRQ_SENS_EDGE, true);                        // Register EINT interrupt
    NVIC_RegisterIRQ(IRQ_ADIE_EINT_CODE, NVIC_AEINTCHandler, IRQ_SENS_EDGE, true);                  // Register ADIE EINT interrupt
    NVIC_RegisterIRQ(IRQ_DIE2DIE_CODE, NVIC_ADIE_C_IRQ_Handler, IRQ_SENS_LEVEL, true);              // Register ADIE NVIC interrupt

    RestoreInterrupts(intflags);
}

boolean NVIC_RegisterIRQ(uint32_t SourceIdx, void (*Handler)(void), uint8_t Sense, boolean Enable)
{
    if (SourceIdx < NUM_IRQ_SOURCES)
    {
        if (Handler == NULL)  NVIC_UnregisterIRQ(SourceIdx);
        else
        {
            uint32_t intflags = DisableInterrupts();

            IRQHandlers[SourceIdx].Handler = Handler;
            if (Sense == IRQ_SENS_EDGE) NVIC_SetIRQSenseEdge(SourceIdx);
            else NVIC_SetIRQSenseLevel(SourceIdx);
            (Enable) ? NVIC_UnmaskIRQ2(SourceIdx) : NVIC_MaskIRQ2(SourceIdx);

            RestoreInterrupts(intflags);
        }
        return true;
    }
    else if ((SourceIdx >= TOTAL_IRQ_SOURCES) && (SourceIdx < GLB_IRQ_SOURCES))
    {
        if (Handler == NULL) NVIC_UnregisterIRQ(SourceIdx);
        else
        {
            uint32_t intflags = DisableInterrupts();

            SourceIdx -= TOTAL_IRQ_SOURCES;
            AIRQHandlers[SourceIdx].Handler = Handler;

            SourceIdx += TOTAL_IRQ_SOURCES;
            if (Sense == IRQ_SENS_EDGE) NVIC_SetIRQSenseEdge(SourceIdx);
            else NVIC_SetIRQSenseLevel(SourceIdx);
            (Enable) ? NVIC_UnmaskIRQ2(SourceIdx) : NVIC_MaskIRQ2(SourceIdx);

            RestoreInterrupts(intflags);
        }
        return true;
    }
    return false;
}

boolean NVIC_UnregisterIRQ(uint32_t SourceIdx)
{
    uint32_t intflags;

    if (SourceIdx < NUM_IRQ_SOURCES)
    {
        intflags = DisableInterrupts();
        NVIC_MaskIRQ2(SourceIdx);
        IRQHandlers[SourceIdx].Handler = NULL;
        RestoreInterrupts(intflags);
        return true;
    }
    if ((SourceIdx >= TOTAL_IRQ_SOURCES) && (SourceIdx < GLB_IRQ_SOURCES))
    {
        intflags = DisableInterrupts();
        NVIC_MaskIRQ2(SourceIdx);
        AIRQHandlers[SourceIdx - TOTAL_IRQ_SOURCES].Handler = NULL;
        RestoreInterrupts(intflags);
        return true;
    }
    return false;
}

boolean NVIC_RegisterEINT(uint32_t SourceIdx, void (*Handler)(void), uint8_t Sense, uint16_t Debounce, boolean Enable)
{
    uint32_t intflags;

    if (SourceIdx < NUM_EINT_SOURCES)
    {
        if (Handler == NULL)
        {
            NVIC_UnregisterEINT(SourceIdx);
            return true;
        }

        if (EINTHandlers[SourceIdx].Handler == Handler) return true;

        intflags = DisableInterrupts();
        EINTHandlers[SourceIdx].Handler = Handler;
        if (Sense == EINT_SENS_EDGE) NVIC_SetEINTSenseEdge(SourceIdx);
        else NVIC_SetEINTSenseLevel(SourceIdx);
        NVIC_SetEINTDebounce(SourceIdx, Debounce);

        (Enable) ? NVIC_EnableEINT_D0Event2(SourceIdx) : NVIC_DisableEINT_D0Event2(SourceIdx);
        (Enable) ?         NVIC_UnmaskEINT2(SourceIdx) :            NVIC_MaskEINT2(SourceIdx);

        RestoreInterrupts(intflags);
        return true;
    }
    if (SourceIdx < GLB_EINT_SOURCES)
    {
        if (Handler == NULL)
        {
            NVIC_UnregisterEINT(SourceIdx);
            return true;
        }

        if (AEINTHandlers[SourceIdx - NUM_EINT_SOURCES].Handler == Handler) return true;

        intflags = DisableInterrupts();
        AEINTHandlers[SourceIdx - NUM_EINT_SOURCES].Handler = Handler;

        if (Sense == EINT_SENS_EDGE) NVIC_SetEINTSenseEdge(SourceIdx);
        else NVIC_SetEINTSenseLevel(SourceIdx);
        NVIC_SetEINTDebounce(SourceIdx, Debounce);
        ADIE_EINT_DBCRST = (1 << (SourceIdx - NUM_EINT_SOURCES));

        (Enable) ? NVIC_EnableEINT_D0Event2(SourceIdx) : NVIC_DisableEINT_D0Event2(SourceIdx);
        (Enable) ?         NVIC_UnmaskEINT2(SourceIdx) :            NVIC_MaskEINT2(SourceIdx);

        RestoreInterrupts(intflags);
        return true;
    }
    return false;
}

boolean NVIC_UnregisterEINT(uint32_t SourceIdx)
{
    uint32_t intflags;

    if (SourceIdx < NUM_EINT_SOURCES)
    {
        intflags = DisableInterrupts();
        NVIC_MaskEINT2(SourceIdx);
        EINTHandlers[SourceIdx].Handler = NULL;
        NVIC_SetEINTDebounce(SourceIdx, 0x0000);
        RestoreInterrupts(intflags);
        return true;
    }
    if (SourceIdx < GLB_EINT_SOURCES)
    {
        intflags = DisableInterrupts();
        NVIC_MaskEINT2(SourceIdx);
        AEINTHandlers[SourceIdx - NUM_EINT_SOURCES].Handler = NULL;
        NVIC_SetEINTDebounce(SourceIdx, 0x0000);
        RestoreInterrupts(intflags);
        return true;
    }
    return false;
}

boolean NVIC_EnableEINT(uint32_t SourceIdx)
{
    if (SourceIdx < GLB_EINT_SOURCES)
    {
        uint32_t intflags = DisableInterrupts();

        NVIC_EnableEINT_D0Event2(SourceIdx);
        NVIC_UnmaskEINT2(SourceIdx);

        RestoreInterrupts(intflags);
        return true;
    }
    return false;
}

boolean NVIC_DisableEINT(uint32_t SourceIdx)
{
    if (SourceIdx < GLB_EINT_SOURCES)
    {
        uint32_t intflags = DisableInterrupts();

        NVIC_DisableEINT_D0Event2(SourceIdx);
        NVIC_MaskEINT2(SourceIdx);

        RestoreInterrupts(intflags);
        return true;
    }
    return false;
}

boolean NVIC_EnableIRQ(uint32_t SourceIdx)
{
    if ((SourceIdx < NUM_IRQ_SOURCES) || ((SourceIdx >= TOTAL_IRQ_SOURCES) && (SourceIdx < GLB_IRQ_SOURCES)))
    {
        uint32_t intflags = DisableInterrupts();

        NVIC_UnmaskIRQ2(SourceIdx);

        RestoreInterrupts(intflags);
        return true;
    }
    return false;
}

boolean NVIC_DisableIRQ(uint32_t SourceIdx)
{
    if ((SourceIdx < NUM_IRQ_SOURCES) || ((SourceIdx >= TOTAL_IRQ_SOURCES) && (SourceIdx < GLB_IRQ_SOURCES)))
    {
        uint32_t intflags = DisableInterrupts();

        NVIC_MaskIRQ2(SourceIdx);

        RestoreInterrupts(intflags);
        return true;
    }
    return false;
}
