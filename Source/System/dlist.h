/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 - 2019 AJScorp
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
#ifndef _DLIST_H_
#define _DLIST_H_

// Internal type definitions
typedef struct tag_ListItem TDLITEM, *pDLITEM;
typedef struct tag_ListItem
{
    pDLITEM Prev;
    pDLITEM Next;
    void    *Data;
} TDLITEM, *pDLITEM;

typedef struct tag_DList
{
    pDLITEM  First;
    pDLITEM  Last;
    uint32_t Count;
} TDLIST, *pDLIST;

extern pDLIST DL_Create(void);
extern pDLIST DL_Delete(pDLIST List, boolean FreeData);
extern uint32_t DL_GetItemsCount(pDLIST DList);
extern pDLITEM DL_GetFirstItem(pDLIST DList);
extern pDLITEM DL_GetLastItem(pDLIST DList);
extern pDLITEM DL_GetPrevItem(pDLITEM DLItem);
extern pDLITEM DL_GetNextItem(pDLITEM DLItem);
extern int32_t DL_GetItemIndex(pDLIST DList, pDLITEM Item);
extern pDLITEM DL_FindItemByData(pDLIST DList, void *Data, int32_t *Index);
extern pDLITEM DL_FindItemByDataReverse(pDLIST DList, void *Data, int32_t *Index);
extern pDLITEM DL_FindItemByIndex(pDLIST List, uint32_t Index);
extern pDLITEM DL_AddItem(pDLIST List, void *Data);
extern boolean DL_AddItemPtr(pDLIST DList, pDLITEM Item);
extern pDLITEM DL_AddItemAtIndex(pDLIST DList, uint32_t Index, void *Data);
extern pDLITEM DL_InsertItemBefore(pDLIST DList, pDLITEM Item, void *Data);
extern pDLITEM DL_InsertItemAfter(pDLIST DList, pDLITEM Item, void *Data);
extern boolean DL_DeleteItem(pDLIST DList, pDLITEM Item);
extern boolean DL_DeleteItemByData(pDLIST List, void *Data);
extern boolean DL_DeleteItemByIndex(pDLIST List, uint32_t Index);
extern boolean DL_DeleteFirstItem(pDLIST DList);
extern boolean DL_DeleteLastItem(pDLIST DList);
extern boolean DL_MoveItemToIndex(pDLIST List, uint32_t OldIndex, uint32_t NewIndex);
extern boolean DL_ReplaceItemData(pDLIST DList, void *OldData, void *NewData);

#endif /* _DLIST_H_ */
