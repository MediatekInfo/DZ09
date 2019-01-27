// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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

            if ((tmpLRT != NULL) && (tmpLRT->Type == SO_TIMER))
            {
                if (tmpLRT->Flags & TF_ENABLED)
                {
                    int32_t CurrTicks = USC_GetCurrentTicks();
                    int32_t DeltaTicks = CurrTicks - tmpLRT->StartTicks;

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

                if (tmpLRT != NULL) free(tmpLRT);
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

pTIMER LRT_Create(uint32_t Interval, pHANDLE Parent, void (*Handler)(pHANDLE), TMRFLAGS Flags)
{
    pTIMER tmpTimer = NULL;

    if (Interval)
    {
        Interval *= 1000;                                                                           //Set interval to us

        if (Interval < LRTMININTERVAL) Interval = LRTMININTERVAL;
        tmpTimer = malloc(sizeof(TTIMER));
        if (tmpTimer != NULL)
        {
            tmpTimer->Flags = Flags;
            tmpTimer->Interval = Interval;
            tmpTimer->StartTicks = USC_GetCurrentTicks();
            tmpTimer->Parent = Parent;
            tmpTimer->Handler = Handler;
            tmpTimer->Type = SO_TIMER;
            if (!DL_AddItem(TimersList, tmpTimer))
            {
                free(tmpTimer);
                tmpTimer = NULL;
            }
        }
    }
    return tmpTimer;
}

