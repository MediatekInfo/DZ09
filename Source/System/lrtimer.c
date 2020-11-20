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
#include "lrtimer.h"

#define LRTMININTERVAL  (1000000 / LRTMRFrequency)

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
                            if (tmpLRT->Flags & TF_DIRECT) tmpLRT->Handler(tmpLRT);
                            else EM_PostEvent(ET_ONTIMER, tmpLRT->Parent, &tmpLRT, sizeof(pTIMER));
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

    if (TimersList == NULL) TimersList = DL_Create(0);
    if (TimersList != NULL)
    {
        if (GPT_SetupTimer(LRTMRHWTIMER, LRTMRFrequency, true, LRT_GPTHandler, true) &&
                GPT_StartTimer(LRTMRHWTIMER))
            return true;
        GPT_SetupTimer(LRTMRHWTIMER, 0, false, NULL, false);
    }
    return false;
}

pTIMER LRT_Create(uint32_t Interval, pHANDLE Parent, void (*Handler)(pTIMER), TMRFLAGS Flags)
{
    pTIMER tmpTimer = NULL;

    if (Interval)
    {
        Interval *= 1000;                                                                           // Set interval to us

        if (Interval < LRTMININTERVAL) Interval = LRTMININTERVAL;
        tmpTimer = malloc(sizeof(TTIMER));
        if (tmpTimer != NULL)
        {
            tmpTimer->Flags = Flags;
            tmpTimer->Interval = Interval;
            tmpTimer->StartTicks = USC_GetCurrentTicks();
            tmpTimer->Parent = Parent;
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

boolean LRT_Destroy(pTIMER Timer)                                                                   // Do not use this method in the timer handler in TFDIRECT mode!!!
{
    if (Timer != NULL)
    {
        pDLITEM tmpItem = DL_FindItemByData(TimersList, Timer, NULL);

        if (tmpItem != NULL)
        {
            free(tmpItem->Data);
            DL_DeleteItem(TimersList, tmpItem);
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
            uint32_t iflags = DisableInterrupts();

            Timer->Flags &= ~TF_ENABLED;
            RestoreInterrupts(iflags);
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
            uint32_t iflags = DisableInterrupts();

            Timer->Flags &= ~TF_ENABLED;
            RestoreInterrupts(iflags);
        }
        return true;
    }
    return false;
}

boolean LRT_SetMode(pTIMER Timer, TMRFLAGS Flags)
{
    if (Timer != NULL)
    {
        uint32_t iflags = DisableInterrupts();

        Timer->Flags = Flags;
        if (Flags & TF_ENABLED) Timer->StartTicks = USC_GetCurrentTicks();
        RestoreInterrupts(iflags);

        return true;
    }
    return false;
}

boolean LRT_SetInterval(pTIMER Timer, uint32_t Interval)
{
    if (Timer != NULL)
    {
        uint32_t iflags = DisableInterrupts();

        Timer->Interval = 1000 * Interval;                                                          // Set interval to us
        if (Timer->Flags & TF_ENABLED) Timer->StartTicks = USC_GetCurrentTicks();
        RestoreInterrupts(iflags);

        return true;
    }
    return false;
}
