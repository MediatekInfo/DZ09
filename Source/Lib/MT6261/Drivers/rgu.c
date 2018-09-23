// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "rgu.h"

void RGU_SetWDTInterval(uint8_t Interval, boolean Enable)                                           //Interval in seconds
{
    Interval = min(Interval, RGUINTERVAL_MAX);

    WDT_MODE = WDMKEY;
    WDT_LENGTH = WDLKEY | TIMEOUT(Interval);                                                        //Set timeout value
    RGU_RestartWDT();
    if (Enable) WDT_MODE = WDMKEY | ENABLE;                                                         //Enable WDT
}

void RGU_EnableWDT(void)
{
    if (WDT_MODE & ENABLE) return;
    WDT_MODE = WDMKEY;
    RGU_RestartWDT();
    WDT_MODE = WDMKEY | ENABLE;
}

void RGU_DisableWDT(void)
{
    WDT_MODE = WDMKEY;
}

TWDTREASON RGU_ReadWDTStatus(void)
{
    if      (WDT_STA & HW_WDT) return WDT_REASON_HW;
    else if (WDT_STA & SW_WDT) return WDT_REASON_SW;

    return WDT_REASON_NONE;
}

void RGU_RestartWDT(void)
{
    WDT_RESTART = WDTRKEY;
}

void RGU_RaiseWDTSWReset(void)
{
    WDT_SWRST = WDSWRKEY;
}
