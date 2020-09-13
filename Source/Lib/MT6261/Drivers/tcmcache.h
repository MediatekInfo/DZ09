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
#ifndef _TCMCACHE_H_
#define _TCMCACHE_H_

#define MPU_REGIONS_MAX             16

#define CACHE_CON                   (*(volatile uint16_t *)(CACHE_BASE + 0x0000))
#define MCEN                        (1 << 0)
#define MPEN                        (1 << 1)
#define MPDEFEN                     (1 << 2)                                                        // MT76x7_Reference_Manual.pdf, page 53
#define CNTEN0                      (1 << 3)
#define CNTEN1                      (1 << 4)
#define MDRF                        (1 << 7)
#define CACHESIZE(v)                (((v) & 0x0003) << 8)                                           // MT76x7_Reference_Manual.pdf, page 53
#define CACHE_NO                    0
#define CACHE_8kB                   1
#define CACHE_16kB                  2
#define CACHE_32kB                  3
#define CACHE_OP                    (*(volatile uint32_t *)(CACHE_BASE + 0x0004))
#define CMDEN                       (1 << 0)
#define OP(v)                       (((v) & 0x000F) << 1)
#define OP_INVALL                   0x01                                                            // MT76x7_Reference_Manual.pdf, page 54
#define OP_INVUSADDR                0x02
#define OP_INVUSWAY                 0x04
#define OP_FLSALL                   0x09
#define OP_FLSUSADDR                0x0A
#define OP_FLSUSWAY                 0x0C
#define TADDR(v)                    ((v) & 0xFFFFFFE0)

#define CACHE_HCNT0L                (*(volatile uint32_t *)(CACHE_BASE + 0x0008))
#define CACHE_HCNT0U                (*(volatile uint32_t *)(CACHE_BASE + 0x000C))
#define CACHE_CCNT0L                (*(volatile uint32_t *)(CACHE_BASE + 0x0010))
#define CACHE_CCNT0U                (*(volatile uint32_t *)(CACHE_BASE + 0x0014))
#define CACHE_HCNT1L                (*(volatile uint32_t *)(CACHE_BASE + 0x0018))
#define CACHE_HCNT1U                (*(volatile uint32_t *)(CACHE_BASE + 0x001C))
#define CACHE_CCNT1L                (*(volatile uint32_t *)(CACHE_BASE + 0x0020))
#define CACHE_CCNT1U                (*(volatile uint32_t *)(CACHE_BASE + 0x0024))
#define CACHE_WAYPOLICY             (*(volatile uint32_t *)(CACHE_BASE + 0x0028))
#define PLC_RANDOM                  (0 << 0)
#define PLC_LOWER                   (1 << 0)
#define CACHE_EN                    (*(volatile uint16_t *)(CACHE_BASE + 0x002C))
#define CACHE_R00                   (1UL << 0)
#define CACHE_R01                   (1UL << 1)
#define CACHE_R02                   (1UL << 2)
#define CACHE_R03                   (1UL << 3)
#define CACHE_R04                   (1UL << 4)
#define CACHE_R05                   (1UL << 5)
#define CACHE_R06                   (1UL << 6)
#define CACHE_R07                   (1UL << 7)
#define CACHE_R08                   (1UL << 8)
#define CACHE_R09                   (1UL << 9)
#define CACHE_R10                   (1UL << 10)
#define CACHE_R11                   (1UL << 11)
#define CACHE_R12                   (1UL << 12)
#define CACHE_R13                   (1UL << 13)
#define CACHE_R14                   (1UL << 14)
#define CACHE_R15                   (1UL << 15)

#define REMAP_ADDR_MASK             0x1FF
#define NCREMAP_HI0                 (*(volatile uint32_t *)(CACHE_BASE + 0x1000))                   // Virtual address
#define NCREMAP_EN                  (1 << 0)
#define NCREMAP_SIZE(v)             (((v) & 0x3F) << 1)                                             // 2^(size + 9) bytes
#define NCREMAP_ADDR(v)             ((v) & ~REMAP_ADDR_MASK)
#define NCREMAP_LO0                 (*(volatile uint32_t *)(CACHE_BASE + 0x1004))                   // Physical address
#define NCREMAP_ADDR(v)             ((v) & ~REMAP_ADDR_MASK)
#define NCREMAP_HI1                 (*(volatile uint32_t *)(CACHE_BASE + 0x1008))
#define NCREMAP_LO1                 (*(volatile uint32_t *)(CACHE_BASE + 0x100C))
#define NCREMAP_HI2                 (*(volatile uint32_t *)(CACHE_BASE + 0x1010))                   // MT6261
#define NCREMAP_LO2                 (*(volatile uint32_t *)(CACHE_BASE + 0x1014))                   // MT6261

// MPU defines
#define MPU_ADDR_MASK               0x00000FFF

#define MPU_RSTART(idx)             (*(volatile uint32_t *)(MPU_BASE + 0x0000 + 4 * (idx)))
#define MPU_R00START                (*(volatile uint32_t *)(MPU_BASE + 0x0000))
#define MPU_R01START                (*(volatile uint32_t *)(MPU_BASE + 0x0004))
#define MPU_R02START                (*(volatile uint32_t *)(MPU_BASE + 0x0008))
#define MPU_R03START                (*(volatile uint32_t *)(MPU_BASE + 0x000C))
#define MPU_R04START                (*(volatile uint32_t *)(MPU_BASE + 0x0010))
#define MPU_R05START                (*(volatile uint32_t *)(MPU_BASE + 0x0014))
#define MPU_R06START                (*(volatile uint32_t *)(MPU_BASE + 0x0018))
#define MPU_R07START                (*(volatile uint32_t *)(MPU_BASE + 0x001C))
#define MPU_R08START                (*(volatile uint32_t *)(MPU_BASE + 0x0020))
#define MPU_R09START                (*(volatile uint32_t *)(MPU_BASE + 0x0024))
#define MPU_R10START                (*(volatile uint32_t *)(MPU_BASE + 0x0028))
#define MPU_R11START                (*(volatile uint32_t *)(MPU_BASE + 0x002C))
#define MPU_R12START                (*(volatile uint32_t *)(MPU_BASE + 0x0030))
#define MPU_R13START                (*(volatile uint32_t *)(MPU_BASE + 0x0034))
#define MPU_R14START                (*(volatile uint32_t *)(MPU_BASE + 0x0038))
#define MPU_R15START                (*(volatile uint32_t *)(MPU_BASE + 0x003C))
// #define Bits 4-0 unknown

#define MPU_ATTR_MASK               0x07
#define MPU_ATTR(v)                 (((v) & MPU_ATTR_MASK) << 5)
#define PRIV_RW_USER_RW             0 // = 0x00,
#define PRIV_RW                     1 // = 0x20,
#define PRIV_RW_USER_RO             2 // = 0x40,
#define PRIV_RW_USER_WO             3 // = 0x60,
#define PRIV_RO_USER_RO             4 // = 0x80,
#define NO_ACCESS                   5 // = 0xA0
#define PRIV_RO                     6 // = 0xC0                                                     // MT76x7_Reference_Manual.pdf, page 61
#define MPU_CACHEABLE               (1 << 8)
#define MPU_ADDR(v)                 ((v) & ~MPU_ADDR_MASK)

#define MPU_REND(idx)               (*(volatile uint32_t *)(MPU_BASE + 0x0040 + 4 * (idx)))
#define MPU_R00END                  (*(volatile uint32_t *)(MPU_BASE + 0x0040))
#define MPU_R01END                  (*(volatile uint32_t *)(MPU_BASE + 0x0044))
#define MPU_R02END                  (*(volatile uint32_t *)(MPU_BASE + 0x0048))
#define MPU_R03END                  (*(volatile uint32_t *)(MPU_BASE + 0x004C))
#define MPU_R04END                  (*(volatile uint32_t *)(MPU_BASE + 0x0050))
#define MPU_R05END                  (*(volatile uint32_t *)(MPU_BASE + 0x0054))
#define MPU_R06END                  (*(volatile uint32_t *)(MPU_BASE + 0x0058))
#define MPU_R07END                  (*(volatile uint32_t *)(MPU_BASE + 0x005C))
#define MPU_R08END                  (*(volatile uint32_t *)(MPU_BASE + 0x0060))
#define MPU_R09END                  (*(volatile uint32_t *)(MPU_BASE + 0x0064))
#define MPU_R10END                  (*(volatile uint32_t *)(MPU_BASE + 0x0068))
#define MPU_R11END                  (*(volatile uint32_t *)(MPU_BASE + 0x006C))
#define MPU_R12END                  (*(volatile uint32_t *)(MPU_BASE + 0x0070))
#define MPU_R13END                  (*(volatile uint32_t *)(MPU_BASE + 0x0074))
#define MPU_R14END                  (*(volatile uint32_t *)(MPU_BASE + 0x0078))
#define MPU_R15END                  (*(volatile uint32_t *)(MPU_BASE + 0x007C))
#define MPU_ADDR(v)                 ((v) & ~MPU_ADDR_MASK)

typedef struct tag_MPUREGION
{
    boolean  Used;
    uint32_t RegionStart;
    uint32_t RegionEnd;
} TMPUREGION;

typedef struct tag_MPUINFO
{
    uint32_t   RegionsUsed;
    TMPUREGION MPURegions[MPU_REGIONS_MAX];
} TMPUINFO, *pMPUINFO;

extern void MPU_Initialize(void);
extern boolean MPU_AddRegion(uint32_t RegionStart, uint32_t RegionEnd, boolean Cacheable, uint8_t AccessRights);
extern boolean MPU_DisableCache(void);
extern void MPU_EnableCache(void);
extern void MPU_RestoreCacheEnState(boolean State);

#endif /* _TCMCACHE_H_ */
