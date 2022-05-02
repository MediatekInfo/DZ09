/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 AJScorp
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
#ifndef _FSCACHE_H_
#define _FSCACHE_H_

#define FSCACHEMAXBLOCKS            128

typedef enum tag_FSCCMD
{
    FSC_INVALIDATEALL,
    FSC_INVALIDATEBLOCK
} TFSCCMD;

typedef struct tag_FCACHE
{
    uint32_t BlockSize;
    uint32_t MaxBlocksCount;
    TDLIST   BlockList;
} TFSCACHE, *pFSCACHE;

typedef struct tag_FCBLOCK
{
    TDLITEM  ListHeader;
    uint32_t BlockIndex;
    uint8_t  BlockData[];
} TFCBLOCK, *pFCBLOCK;

extern pFSCACHE FSC_Create(uint32_t BlockSize, uint32_t MaxBlocksCount);
extern pFSCACHE FSC_Destroy(pFSCACHE Cache);
extern boolean FSC_Invalidate(pFSCACHE Cache, TFSCCMD Command, uint32_t Block);
extern boolean FSC_StoreDataBlock(pFSCACHE Cache, uint32_t BlockIndex, void *Data);
extern void *FSC_GetDataBlock(pFSCACHE Cache, uint32_t BlockIndex);

#endif /* _FSCACHE_H_ */
