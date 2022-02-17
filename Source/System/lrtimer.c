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
#include "lrtimer.h"

#define LRTMININTERVAL              (1000000 / LRTMR_FREQUENCY)

pDLIST TimersList;

void LRT_GPTHandler(void)
{
    if (TimersList != NULL)
    {
        pDLITEM tmrItem = DL_GetFirstItem(TimersList);

        while(tmrItem != NULL)
        {
            pTIMER tmpLRT = tmrItem->Data;

            if (tmpLRT != NULL)
            {
                if (tmpLRT->Flags & TF_ENABLED)
                {
                    uint32_t CurrTicks = USC_GetCurrentTicks();
                    uint32_t DeltaTicks = CurrTicks - tmpLRT->StartTicks;

                    if (DeltaTicks >= tmpLRT->Interval)
                    {
                        if (tmpLRT->Handler != NULL)
                        {
                            if (tmpLRT->Flags & TF_DIRECT)
                            {
                                tmpLRT->Handler(tmpLRT);
                                /* The tmrItem->Data value could have been changed from LRT_Destroy(), called in handler */
                                if ((volatile void *)tmrItem->Data == NULL)
                                {
                                    pDLITEM tmpItem = tmrItem;

                                    tmrItem = DL_GetNextItem(tmpItem);
                                    DL_DeleteItem(TimersList, tmpItem);
                                    continue;
                                }
                            }
                            else EM_PostEvent(ET_ONTIMER, NULL, &tmpLRT, sizeof(pTIMER));
                        }
                        if (tmpLRT->Flags & TF_AUTOREPEAT) tmpLRT->StartTicks = CurrTicks;
                        else tmpLRT->Flags &= ~TF_ENABLED;
                    }
                }
            }
            else
            {
                pDLITEM tmpItem = tmrItem;

                tmrItem = DL_GetNextItem(tmpItem);
                DL_DeleteItem(TimersList, tmpItem);
                continue;
            }
            tmrItem = DL_GetNextItem(tmrItem);
        }
    }
}

boolean LRT_Initialize(void)
{
    GPT_InitializeTimers();

    if (TimersList == NULL) TimersList = DL_Create();
    if (TimersList != NULL)
    {
        if (GPT_SetupTimer(LRTMRHWTIMER, LRTMR_FREQUENCY, true, LRT_GPTHandler, true) &&
                GPT_StartTimer(LRTMRHWTIMER))
            return true;
        GPT_SetupTimer(LRTMRHWTIMER, 0, false, NULL, false);
    }
    TimersList = DL_Delete(TimersList, false);

    return false;
}

pTIMER LRT_Create(uint32_t Interval, void (*Handler)(pTIMER), TMRFLAGS Flags)
{
    pTIMER tmpTimer = NULL;

    if (Interval && (TimersList != NULL))
    {
        Interval *= 1000;                                                                           // Set interval to us

        if (Interval < LRTMININTERVAL) Interval = LRTMININTERVAL;
        tmpTimer = malloc(sizeof(TTIMER));
        if (tmpTimer != NULL)
        {
            tmpTimer->Flags = Flags;
            tmpTimer->Interval = Interval;
            tmpTimer->StartTicks = USC_GetCurrentTicks();
            tmpTimer->Handler = Handler;
            if (DL_AddItem(TimersList, tmpTimer) == NULL)
            {
                free(tmpTimer);
                tmpTimer = NULL;
            }
        }
    }
    return tmpTimer;
}

boolean LRT_Destroy(pTIMER Timer)
{
    if (Timer != NULL)
    {
        pDLITEM tmpItem = DL_FindItemByData(TimersList, Timer, NULL);

        if (tmpItem != NULL)
        {
            uint32_t intflags = __disable_interrupts();
            pTIMER   tmpTimer = tmpItem->Data;

            if (__is_in_isr_mode()) tmpItem->Data = NULL;                                           // This node will be removed when returning to LRT_GPTHandler()
            else DL_DeleteItem(TimersList, tmpItem);                                                // Direct node deletion

            __restore_interrupts(intflags);

            __secure_memset(tmpTimer, 0x00, sizeof(TTIMER));
            free(tmpTimer);
            return true;
        }
    }
    return false;
}

boolean LRT_Start(pTIMER Timer)
{
    if (Timer != NULL)
    {
        if (Timer->Flags & TF_ENABLED)
        {
            uint32_t iflags = __disable_interrupts();

            Timer->Flags &= ~TF_ENABLED;
            __restore_interrupts(iflags);
        }
        Timer->StartTicks = USC_GetCurrentTicks();
        Timer->Flags |= TF_ENABLED;
        return true;
    }
    return false;
}

boolean LRT_Stop(pTIMER Timer)
{
    if (Timer != NULL)
    {
        if (Timer->Flags & TF_ENABLED)
        {
            uint32_t iflags = __disable_interrupts();

            Timer->Flags &= ~TF_ENABLED;
            __restore_interrupts(iflags);
        }
        return true;
    }
    return false;
}

boolean LRT_SetMode(pTIMER Timer, TMRFLAGS Flags)
{
    if (Timer != NULL)
    {
        uint32_t iflags = __disable_interrupts();

        Timer->Flags = Flags;
        if (Flags & TF_ENABLED) Timer->StartTicks = USC_GetCurrentTicks();
        __restore_interrupts(iflags);

        return true;
    }
    return false;
}

boolean LRT_SetInterval(pTIMER Timer, uint32_t Interval)
{
    if (Timer != NULL)
    {
        uint32_t iflags = __disable_interrupts();

        Timer->Interval = 1000 * Interval;                                                          // Set interval to us
        if (Timer->Flags & TF_ENABLED) Timer->StartTicks = USC_GetCurrentTicks();
        __restore_interrupts(iflags);

        return true;
    }
    return false;
}
