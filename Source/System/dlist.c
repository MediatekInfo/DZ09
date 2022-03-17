// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "memory.h"
#include "dlist.h"

static pDLITEM DL_FirstItem(pDLIST DList)
{
    return (DList == NULL) ? NULL : DList->First;
}

static pDLITEM DL_LastItem(pDLIST DList)
{
    return (DList == NULL) ? NULL : DList->Last;
}

static pDLITEM DL_PrevItem(pDLITEM LItem)
{
    return (LItem == NULL) ? NULL : LItem->Prev;
}

static pDLITEM DL_NextItem(pDLITEM LItem)
{
    return (LItem == NULL) ? NULL : LItem->Next;
}

static pDLITEM DL_ItemByData(pDLIST DList, void *Data, int32_t *Index)
{
    pDLITEM tmpItem = NULL;
    int32_t Result = -1;

    if ((DList != NULL) && (Data != NULL))
    {
        tmpItem = DList->First;
        if (Index == NULL)
        {
            while(tmpItem != NULL)
            {
                if (tmpItem->Data == Data) break;
                tmpItem = tmpItem->Next;
            }
        }
        else
        {
            int32_t  i;

            for(i = 0; tmpItem != NULL; i++)
            {
                if (tmpItem->Data == Data)
                {
                    Result = i;
                    break;
                }
                tmpItem = tmpItem->Next;
            }
        }
    }
    if (Index != NULL) *Index = Result;

    return tmpItem;
}

static pDLITEM DL_ItemByDataRev(pDLIST DList, void *Data, int32_t *Index)
{
    pDLITEM tmpItem = NULL;
    int32_t Result = -1;

    if ((DList != NULL) && (Data != NULL))
    {
        tmpItem = DList->Last;
        if (Index == NULL)
        {
            while(tmpItem != NULL)
            {
                if (tmpItem->Data == Data) break;
                tmpItem = tmpItem->Prev;
            }
        }
        else
        {
            int32_t  i;

            for(i = DList->Count - 1; tmpItem != NULL; i--)
            {
                if (tmpItem->Data == Data)
                {
                    Result = i;
                    break;
                }
                tmpItem = tmpItem->Prev;
            }
        }
    }
    if (Index != NULL) *Index = Result;

    return tmpItem;
}

static int32_t DL_IndexOfItem(pDLIST DList, pDLITEM Item)
{
    pDLITEM tmpItem = NULL;
    int32_t i, Result = -1;

    if ((DList != NULL) && (Item != NULL))
    {
        tmpItem = DList->First;
        for(i = 0; tmpItem != NULL; i++)
        {
            if (tmpItem == Item)
            {
                Result = i;
                break;
            }
            tmpItem = tmpItem->Next;
        }
    }
    return Result;
}

static pDLITEM DL_ItemByIndex(pDLIST DList, uint32_t Index)
{
    int32_t i;
    pDLITEM tmpItem = NULL;

    if ((DList != NULL) && (Index < DList->Count))
    {
        if (Index < DList->Count / 2)
        {
            tmpItem = DList->First;
            for(i = 0; i < Index; i++)
                if (tmpItem != NULL) tmpItem = tmpItem->Next;
                else return NULL;
        }
        else
        {
            tmpItem = DList->Last;
            for(i = DList->Count - 1; i > Index; i--)
                if (tmpItem != NULL) tmpItem = tmpItem->Prev;
                else return NULL;
        }
    }
    return tmpItem;
}

pDLIST DL_Create(void)
{
    pDLIST tmpDList = malloc(sizeof(TDLIST));

    if (tmpDList != NULL) memset(tmpDList, 0x00, sizeof(TDLIST));

    return tmpDList;
}

pDLIST DL_Delete(pDLIST DList, boolean FreeData)
{
    uint32_t intflags;
    pDLITEM  tmpItem, tmpItemToFree;

    if (DList != NULL)
    {
        intflags = __disable_interrupts();

        tmpItem = DList->First;
        if (FreeData && ((uintptr_t)tmpItem->Data != (uintptr_t)tmpItem))
        {
            while(tmpItem != NULL)
            {
                if (IsDynamicMemory(tmpItem->Data)) free(tmpItem->Data);
                tmpItemToFree = tmpItem;
                tmpItem = tmpItem->Next;
                free(tmpItemToFree);
            }
        }
        else
        {
            while(tmpItem != NULL)
            {
                tmpItemToFree = tmpItem;
                tmpItem = tmpItem->Next;
                free(tmpItemToFree);
            }
        }
        if (IsDynamicMemory(DList)) free(DList);
        else __secure_memset(DList, 0x00, sizeof(TDLIST));

        __restore_interrupts(intflags);
    }
    return NULL;
}

uint32_t DL_GetItemsCount(pDLIST DList)
{
    uint32_t n;

    if (DList != NULL)
    {
        uint32_t intflags = __disable_interrupts();

        n = DList->Count;
        __restore_interrupts(intflags);
    }
    else n = 0;

    return n;
}

pDLITEM DL_GetFirstItem(pDLIST DList)
{
    pDLITEM  Item;
    uint32_t intflags = __disable_interrupts();

    Item = DL_FirstItem(DList);
    __restore_interrupts(intflags);

    return Item;
}

pDLITEM DL_GetLastItem(pDLIST DList)
{
    pDLITEM  Item;
    uint32_t intflags = __disable_interrupts();

    Item = DL_LastItem(DList);
    __restore_interrupts(intflags);

    return Item;
}

pDLITEM DL_GetPrevItem(pDLITEM LItem)
{
    pDLITEM  Item;
    uint32_t intflags = __disable_interrupts();

    Item = DL_PrevItem(LItem);
    __restore_interrupts(intflags);

    return Item;
}

pDLITEM DL_GetNextItem(pDLITEM LItem)
{
    pDLITEM  Item;
    uint32_t intflags = __disable_interrupts();

    Item = DL_NextItem(LItem);
    __restore_interrupts(intflags);

    return Item;
}

int32_t DL_GetItemIndex(pDLIST DList, pDLITEM Item)
{
    uint32_t intflags = __disable_interrupts();
    int32_t  Result;

    Result = DL_IndexOfItem(DList, Item);
    __restore_interrupts(intflags);

    return Result;
}

pDLITEM DL_FindItemByData(pDLIST DList, void *Data, int32_t *Index)
{
    uint32_t intflags = __disable_interrupts();
    pDLITEM  tmpItem;

    tmpItem = DL_ItemByData(DList, Data, Index);
    __restore_interrupts(intflags);

    return tmpItem;
}

pDLITEM DL_FindItemByDataReverse(pDLIST DList, void *Data, int32_t *Index)
{
    uint32_t intflags = __disable_interrupts();
    pDLITEM  tmpItem;

    tmpItem = DL_ItemByDataRev(DList, Data, Index);
    __restore_interrupts(intflags);

    return tmpItem;
}

pDLITEM DL_FindItemByIndex(pDLIST DList, uint32_t Index)
{
    uint32_t intflags = __disable_interrupts();
    pDLITEM  tmpItem;

    tmpItem = DL_ItemByIndex(DList, Index);
    __restore_interrupts(intflags);

    return tmpItem;
}

pDLITEM DL_AddItem(pDLIST DList, void *Data)
{
    pDLITEM  tmpItem;
    uint32_t intflags;

    if (DList == NULL) return NULL;

    tmpItem = malloc(sizeof(TDLITEM));
    if (tmpItem != NULL)
    {
        intflags = __disable_interrupts();

        tmpItem->Data = Data;
        tmpItem->Next = NULL;
        if (DList->Last != NULL)
        {
            tmpItem->Prev = DList->Last;
            DList->Last->Next = tmpItem;
            DList->Last = tmpItem;
        }
        else
        {
            tmpItem->Prev = NULL;
            DList->First = tmpItem;
            DList->Last = tmpItem;
        }
        DList->Count++;
        __restore_interrupts(intflags);
    }
    return tmpItem;
}

boolean DL_AddItemPtr(pDLIST DList, pDLITEM Item)
{
    if ((DList == NULL) || (Item == NULL)) return false;
    else
    {
        uint32_t intflags = __disable_interrupts();

        Item->Next = NULL;
// NOTE (ajscorp#1#): Keep in mind that the Item->Data pointer is assigned here. For now, let it be so.
        Item->Data = Item;

        if (DList->Last != NULL)
        {
            Item->Prev = DList->Last;
            DList->Last->Next = Item;
            DList->Last = Item;
        }
        else
        {
            Item->Prev = NULL;
            DList->First = Item;
            DList->Last = Item;
        }
        DList->Count++;
        __restore_interrupts(intflags);

        return true;
    }
}

pDLITEM DL_AddItemAtIndex(pDLIST DList, uint32_t Index, void *Data)
{
    uint32_t intflags;
    pDLITEM  NewIndexItem, tmpItem = NULL;

    if (DList == NULL) return NULL;

    intflags = __disable_interrupts();
    if (Index >= DList->Count)
    {
        tmpItem = DL_AddItem(DList, Data);
    }
    else
    {
        NewIndexItem = DL_ItemByIndex(DList, Index);
        if (NewIndexItem != NULL)
        {
            tmpItem = malloc(sizeof(TDLITEM));
            if (tmpItem != NULL)
            {
                tmpItem->Data = Data;

                if (NewIndexItem->Prev != NULL)
                    NewIndexItem->Prev->Next = tmpItem;
                else DList->First = tmpItem;

                tmpItem->Prev = NewIndexItem->Prev;
                tmpItem->Next = NewIndexItem;
                NewIndexItem->Prev = tmpItem;

                DList->Count++;
            }
        }
    }
    __restore_interrupts(intflags);
    return tmpItem;
}

boolean DL_AddItemAtIndexPtr(pDLIST DList, uint32_t Index, pDLITEM ItemToInsert)
{
    uint32_t intflags;
    boolean  Result = false;

    if (DList == NULL) return false;

    intflags = __disable_interrupts();
    if (Index >= DList->Count)
    {
        Result = DL_AddItemPtr(DList, ItemToInsert);
    }
    else
    {
        pDLITEM  NewIndexItem = DL_ItemByIndex(DList, Index);

        if (NewIndexItem != NULL)
        {
            ItemToInsert->Data = ItemToInsert;

            if (NewIndexItem->Prev != NULL)
                NewIndexItem->Prev->Next = ItemToInsert;
            else DList->First = ItemToInsert;

            ItemToInsert->Prev = NewIndexItem->Prev;
            ItemToInsert->Next = NewIndexItem;
            NewIndexItem->Prev = ItemToInsert;

            DList->Count++;
            Result = true;
        }
    }
    __restore_interrupts(intflags);
    return Result;
}


pDLITEM DL_InsertItemBefore(pDLIST DList, pDLITEM Item, void *Data)
{
    pDLITEM  tmpItem;
    uint32_t intflags;

    if (DList == NULL) return NULL;
    if (Item == NULL) return DL_AddItem(DList, Data);

    tmpItem = malloc(sizeof(TDLITEM));
    if (tmpItem != NULL)
    {
        intflags = __disable_interrupts();

        tmpItem->Data = Data;
        tmpItem->Next = Item;
        tmpItem->Prev = Item->Prev;
        Item->Prev = tmpItem;

        if (tmpItem->Prev == NULL) DList->First = tmpItem;
        else tmpItem->Prev->Next = tmpItem;

        DList->Count++;
        __restore_interrupts(intflags);
    }
    return tmpItem;
}

boolean DL_InsertItemBeforePtr(pDLIST DList, pDLITEM BaseItem, pDLITEM ItemToInsert)
{
    pDLITEM  tmpItem;
    uint32_t intflags;

    if (DList == NULL) return false;
    if (BaseItem == NULL) return DL_AddItemPtr(DList, ItemToInsert);

    intflags = __disable_interrupts();

// NOTE (ajscorp#1#): Keep in mind that the ItemToInsert->Data pointer is assigned here. For now, let it be so.
    ItemToInsert->Data = ItemToInsert;
    ItemToInsert->Next = BaseItem;
    ItemToInsert->Prev = BaseItem->Prev;
    BaseItem->Prev = ItemToInsert;

    if (ItemToInsert->Prev == NULL) DList->First = ItemToInsert;
    else ItemToInsert->Prev->Next = ItemToInsert;

    DList->Count++;
    __restore_interrupts(intflags);

    return true;
}

pDLITEM DL_InsertItemAfter(pDLIST DList, pDLITEM Item, void *Data)
{
    pDLITEM  tmpItem;
    uint32_t intflags;

    if (DList == NULL) return NULL;
    if (Item == NULL) return DL_AddItem(DList, Data);

    tmpItem = malloc(sizeof(TDLITEM));
    if (tmpItem != NULL)
    {
        intflags = __disable_interrupts();

        tmpItem->Data = Data;
        tmpItem->Prev = Item;
        tmpItem->Next = Item->Next;
        Item->Next = tmpItem;

        if (tmpItem->Next == NULL) DList->Last = tmpItem;
        else tmpItem->Next->Prev = tmpItem;

        DList->Count++;
        __restore_interrupts(intflags);
    }
    return tmpItem;
}

boolean DL_InsertItemAfterPtr(pDLIST DList, pDLITEM BaseItem, pDLITEM ItemToInsert)
{
    pDLITEM  tmpItem;
    uint32_t intflags;

    if (DList == NULL) return false;
    if (BaseItem == NULL) return DL_AddItemPtr(DList, ItemToInsert);

    intflags = __disable_interrupts();

// NOTE (ajscorp#1#): Keep in mind that the ItemToInsert->Data pointer is assigned here. For now, let it be so.
    ItemToInsert->Data = ItemToInsert;
    ItemToInsert->Prev = BaseItem;
    ItemToInsert->Next = BaseItem->Next;
    BaseItem->Next = ItemToInsert;

    if (ItemToInsert->Next == NULL) DList->Last = ItemToInsert;
    else ItemToInsert->Next->Prev = ItemToInsert;

    DList->Count++;
    __restore_interrupts(intflags);

    return true;
}

boolean DL_ExcludeItem(pDLIST DList, pDLITEM Item)
{
    boolean  Result = false;
    uint32_t intflags = __disable_interrupts();

    if ((DList != NULL) && (Item != NULL))
    {
        if (Item->Prev != NULL)
            Item->Prev->Next = Item->Next;
        else DList->First = Item->Next;

        if (Item->Next != NULL)
            Item->Next->Prev = Item->Prev;
        else DList->Last = Item->Prev;

        DList->Count--;
        Result = true;
    }
    __restore_interrupts(intflags);

    return Result;
}

boolean DL_DeleteItem(pDLIST DList, pDLITEM Item)
{
    boolean  Result;
    uint32_t intflags = __disable_interrupts();

    if ((Result = DL_ExcludeItem(DList, Item)) == true)
        free(Item);
    __restore_interrupts(intflags);

    return Result;
}

boolean DL_DeleteItemByData(pDLIST DList, void *Data)
{
    boolean  Result = false;
    uint32_t intflags = __disable_interrupts();
    pDLITEM  tmpItem;

    tmpItem = DL_ItemByData(DList, Data, NULL);
    if (tmpItem != NULL)
    {
        if (tmpItem->Prev != NULL)
            tmpItem->Prev->Next = tmpItem->Next;
        else DList->First = tmpItem->Next;

        if (tmpItem->Next != NULL)
            tmpItem->Next->Prev = tmpItem->Prev;
        else DList->Last = tmpItem->Prev;

        DList->Count--;
        free(tmpItem);
        Result = true;
    }
    __restore_interrupts(intflags);

    return Result;
}

boolean DL_DeleteItemByIndex(pDLIST DList, uint32_t Index)
{
    boolean  Result = false;
    uint32_t intflags = __disable_interrupts();
    pDLITEM  tmpItem;

    tmpItem = DL_ItemByIndex(DList, Index);
    if (tmpItem != NULL)
    {
        if (tmpItem->Prev != NULL)
            tmpItem->Prev->Next = tmpItem->Next;
        else DList->First = tmpItem->Next;

        if (tmpItem->Next != NULL)
            tmpItem->Next->Prev = tmpItem->Prev;
        else DList->Last = tmpItem->Prev;

        DList->Count--;
        free(tmpItem);
        Result = true;
    }
    __restore_interrupts(intflags);

    return Result;
}

boolean DL_DeleteFirstItem(pDLIST DList)
{
    boolean  Result = false;
    uint32_t intflags = __disable_interrupts();
    pDLITEM  tmpItem;

    tmpItem = DL_FirstItem(DList);
    if (tmpItem != NULL)
    {
        DList->First = tmpItem->Next;

        if (tmpItem->Next != NULL)
            tmpItem->Next->Prev = NULL;
        else DList->Last = NULL;

        DList->Count--;
        free(tmpItem);
        Result = true;
    }
    __restore_interrupts(intflags);

    return Result;
}

boolean DL_DeleteLastItem(pDLIST DList)
{
    boolean  Result = false;
    uint32_t intflags = __disable_interrupts();
    pDLITEM  tmpItem;

    tmpItem = DL_LastItem(DList);
    if (tmpItem != NULL)
    {
        DList->Last = tmpItem->Prev;

        if (tmpItem->Prev != NULL)
            tmpItem->Prev->Next = NULL;
        else DList->First = NULL;

        DList->Count--;
        free(tmpItem);
        Result = true;
    }
    __restore_interrupts(intflags);

    return Result;
}

boolean DL_MoveItemToIndex(pDLIST DList, uint32_t Index, pDLITEM Item)
{
    boolean  Result = false;
    uint32_t intflags = __disable_interrupts();
    int32_t  OldIndex = DL_IndexOfItem(DList, Item);

    if (OldIndex != -1)
    {
        if (OldIndex != Index)
        {
            pDLITEM NewIndexItem = DL_ItemByIndex(DList, Index);

            if (NewIndexItem != NULL)
            {
                /* Remove item from old place */
                if (Item->Prev != NULL)
                    Item->Prev->Next = Item->Next;
                else DList->First = Item->Next;

                if (Item->Next != NULL)
                    Item->Next->Prev = Item->Prev;
                else DList->Last = Item->Prev;

                /* Insert item to new place */
                if (Index < OldIndex)
                {
                    if (NewIndexItem->Prev != NULL)
                        NewIndexItem->Prev->Next = Item;
                    else DList->First = Item;

                    Item->Prev = NewIndexItem->Prev;
                    Item->Next = NewIndexItem;
                    NewIndexItem->Prev = Item;
                }
                else
                {
                    if (NewIndexItem->Next != NULL)
                        NewIndexItem->Next->Prev = Item;
                    else DList->Last = Item;

                    Item->Prev = NewIndexItem;
                    Item->Next = NewIndexItem->Next;
                    NewIndexItem->Next = Item;
                }
            }
        }
        Result = true;
    }
    __restore_interrupts(intflags);

    return Result;
}

boolean DL_ReplaceItemData(pDLIST DList, void *OldData, void *NewData)
{
    boolean  Result = false;
    uint32_t intflags;
    pDLITEM  tmpItem;

    if (DList == NULL) return false;

    intflags = __disable_interrupts();
    tmpItem = DL_ItemByData(DList, OldData, NULL);
    if (tmpItem != NULL)
    {
        tmpItem->Data = NewData;
        Result = true;
    }
    __restore_interrupts(intflags);

    return Result;
}



