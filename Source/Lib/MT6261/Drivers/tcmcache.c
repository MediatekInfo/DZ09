// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "tcmcache.h"

extern uint32_t ROM_Image_Base;
extern uint32_t ROM_Image_Limit;

static TMPUINFO MpuInfo;

void MPU_Initialize(void)
{
    uint8_t i;

#ifdef SysCacheSize
    CACHE_CON = CACHESIZE(SysCacheSize);
#else
    CACHESIZE(CACHE_NO);                                                                            //Disable cache
#endif
    CACHE_OP = OP(OP_INVALL) | CMDEN;                                                               //Invalidate cache
    CACHE_EN = 0;                                                                                   //Disable regions

    for(i = 0; i < MPU_REGIONS_MAX; i++)                                                            //Clear regions in MPU
    {
        MPU_RSTART(i) = 0;
        MPU_REND(i) = 0;
    }

    memset(&MpuInfo, 0x00, sizeof(TMPUINFO));

    MPU_AddRegion(ROM_Image_Base, ROM_Image_Limit, true, PRIV_RW_USER_RW);
}

// TODO (scorp#1#): Need to come up with a more intelligent cache management algorithm
boolean MPU_AddRegion(uint32_t RegionStart, uint32_t RegionEnd, boolean Cacheable, uint8_t AccessRights)
{
    uint32_t i, Attr;
    int32_t  FreeRegionIdx = -1;

    RegionStart &= ~MPU_ADDR_MASK;
    if (RegionEnd & MPU_ADDR_MASK)
        RegionEnd = (RegionEnd & ~MPU_ADDR_MASK) + MPU_ADDR_MASK + 1;

    if (RegionStart < RegionEnd)
    {
        for(i = 0; i < MPU_REGIONS_MAX; i++)
        {
            if (!MpuInfo.MPURegions[i].Used)
            {
                FreeRegionIdx = i;
                break;
            }
        }

        if (FreeRegionIdx != -1)
        {
            CACHE_EN &= ~(1 << FreeRegionIdx);                                                      //Disable region
            Attr = ((Cacheable) ? MPU_CACHEABLE : 0) | MPU_ATTR(AccessRights);
            MPU_RSTART(FreeRegionIdx) = RegionStart | Attr;                                         //Set attributes
            MPU_REND(FreeRegionIdx)   = RegionEnd;
            CACHE_OP = OP(OP_INVALL) | CMDEN;                                                       //Invalidate cache
            CACHE_EN |= (1 << FreeRegionIdx);                                                       //Enable region
            CACHE_CON |= MPEN | MCEN;                                                               //Enable memory protection and cache
            MpuInfo.MPURegions[FreeRegionIdx].RegionStart = RegionStart;
            MpuInfo.MPURegions[FreeRegionIdx].RegionEnd = RegionEnd;
            MpuInfo.MPURegions[FreeRegionIdx].Used = true;
            MpuInfo.RegionsUsed++;
            return true;
        }
    }
    return false;
}

boolean MPU_DisableCache(void)
{
    boolean IsCacheEnabled = CACHE_CON & MCEN;

    CACHE_CON &= ~MCEN;

    return IsCacheEnabled;
}

void MPU_EnableCache(void)
{
    CACHE_CON |= MCEN;
}

void MPU_RestoreCacheEnState(boolean State)
{
    uint16_t tmpCACHE_EN = CACHE_EN;

    CACHE_EN = 0x0000;
    CACHE_OP = OP(OP_INVALL) | CMDEN;
    CACHE_CON = (CACHE_CON & ~MCEN) | ((State) ? MCEN : 0);
    CACHE_EN = tmpCACHE_EN;
}
