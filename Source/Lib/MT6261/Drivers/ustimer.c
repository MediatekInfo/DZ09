// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "ustimer.h"

void USC_StartCounter(void)
{
  USCNT_CON = USCNT_START_CODE;
}

void USC_StopCounter(void)
{
  USCNT_CON = USCNT_STOP_CODE;
}

int32_t USC_GetCurrentTicks(void)
{
    return USCNTI_VAL;
}

void USC_Pause_us(uint32_t us)
{
    if (USCNT_CON & USC_START)
    {
        int32_t PrevTime = USC_GetCurrentTicks();

        while(USC_GetCurrentTicks() - PrevTime < us);
    }
}
