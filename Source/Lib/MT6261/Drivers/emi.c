// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "gpio.h"

void EMI_MemoryRemap(MREMAP Mode)
{
    boolean CacheState;

#ifdef USEINTERRUPTS
    uint32_t intflags = DisableInterrupts();
#endif
    CacheState = MPU_DisableCache();
    EMI_REMAP = Mode & 0x03;
    MPU_RestoreCacheEnState(CacheState);
#ifdef USEINTERRUPTS
    RestoreInterrupts(intflags);
#endif
}
