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

    CACHE_CON = CACHESIZE(SysCacheSize);                                                            //Disable cache
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
