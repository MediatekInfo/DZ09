// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "utils.h"

extern uint32_t FreqLoopsCycles;

uint32_t GetCPUFrequency(void)
{
    uint32_t CPUTicks = GetCPUFreqTicks();
    uint32_t CPUFrequency;

    CPUFrequency = (((FREERUNFREQ / 500000) * FreqLoopsCycles) / CPUTicks + 1) >> 1;

    return CPUFrequency;
}
