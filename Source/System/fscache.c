// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "fscache.h"

static pFCBLOCK FSC_FindBlock(pFSCACHE Cache, uint32_t BlockIndex)
{
    pDLITEM tmpBlockItem = DL_GetFirstItem(&Cache->BlockList);

    while(tmpBlockItem != NULL)
    {
        if (((pFCBLOCK)tmpBlockItem)->BlockIndex == BlockIndex) break;
        tmpBlockItem = DL_GetNextItem(tmpBlockItem);
    }
    return (pFCBLOCK)tmpBlockItem;
}

pFSCACHE FSC_Create(uint32_t BlockSize, uint32_t MaxBlocksCount)
{
    pFSCACHE NewFSCache = NULL;

    if (BlockSize)
    {
        NewFSCache = malloc(sizeof(TFSCACHE));
        if (NewFSCache != NULL)
        {
            memset(NewFSCache, 0x00, sizeof(TFSCACHE));

            NewFSCache->BlockSize = BlockSize;
            NewFSCache->MaxBlocksCount = min(FSCACHEMAXBLOCKS, MaxBlocksCount);
        }
    }
    return NewFSCache;
}

pFSCACHE FSC_Destroy(pFSCACHE Cache)
{
    if (Cache != NULL)
    {
        if (DL_GetItemsCount(&Cache->BlockList))
            DL_Delete(&Cache->BlockList, false);
        if (IsDynamicMemory(Cache)) free(Cache);
    }
    return NULL;
}

boolean FSC_Invalidate(pFSCACHE Cache, TFSCCMD Command, uint32_t BlockIndex)
{
    boolean Result = false;

    if (Cache != NULL)
    {
        switch (Command)
        {
        case FSC_INVALIDATEALL:
            while(DL_GetItemsCount(&Cache->BlockList))
                DL_DeleteFirstItem(&Cache->BlockList);
            Result = true;
            break;
        case FSC_INVALIDATEBLOCK:
        {
            pFCBLOCK tmpBlock = FSC_FindBlock(Cache, BlockIndex);

            if (tmpBlock != NULL)
            {
                Result = DL_ExcludeItem(&Cache->BlockList, &tmpBlock->ListHeader);
                free(tmpBlock);
            }
        }
        break;
        }
    }
    return Result;
}

boolean FSC_StoreDataBlock(pFSCACHE Cache, uint32_t BlockIndex, void *Data)
{
    boolean Result = false;

    if ((Cache != NULL) && (Data != NULL))
    {
        pFCBLOCK DataBlock = FSC_FindBlock(Cache, BlockIndex);

        if (DataBlock != NULL)
        {
            memcpy(DataBlock->BlockData, Data, Cache->BlockSize);
            Result = DL_MoveItemToIndex(&Cache->BlockList, 0, &DataBlock->ListHeader);
        }
        else
        {
            DataBlock = malloc(sizeof(TFCBLOCK) + Cache->BlockSize);
            if (DataBlock != NULL)
            {
                while(DL_GetItemsCount(&Cache->BlockList) >= Cache->MaxBlocksCount)
                {
                    pDLITEM tmpItem = DL_GetLastItem(&Cache->BlockList);

                    if (tmpItem == NULL) break;
                    DL_DeleteItem(&Cache->BlockList, tmpItem);
                }
                memcpy(DataBlock->BlockData, Data, Cache->BlockSize);
                DataBlock->BlockIndex = BlockIndex;
                Result = DL_AddItemAtIndexPtr(&Cache->BlockList, 0, &DataBlock->ListHeader);
            }
        }
    }
    return Result;
}

void *FSC_GetDataBlock(pFSCACHE Cache, uint32_t BlockIndex)
{
    pFCBLOCK DataBlock;

    if ((Cache != NULL) &&
            ((DataBlock = FSC_FindBlock(Cache, BlockIndex)) != NULL))
        return DataBlock->BlockData;
    else return NULL;
}
