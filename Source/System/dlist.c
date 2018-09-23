// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
        tmpItem = DL_FirstItem(DList);
        if (Index == NULL)
        {
            while(tmpItem != NULL)
            {
                if (tmpItem->Data == Data) break;
                tmpItem = DL_NextItem(tmpItem);
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
                tmpItem = DL_NextItem(tmpItem);
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
        tmpItem = DL_FirstItem(DList);
        for(i = 0; tmpItem != NULL; i++)
        {
            if (tmpItem == Item)
            {
                Result = i;
                break;
            }
            tmpItem = DL_NextItem(tmpItem);
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

pDLIST DL_Create(uint32_t ItemCount)
{
    pDLIST   tmpDList;
    pDLITEM  tmpFirst = NULL, tmpLast = NULL;
    pDLITEM  tmpPrev = NULL,  tmpNext = NULL;
    uint32_t i;

    tmpDList = malloc(sizeof(TDLIST));
    if (tmpDList != NULL)
    {
        for(i = 0; i < ItemCount; i++)
        {
            tmpNext = malloc(sizeof(TDLITEM));

            if (i == 0) tmpFirst = tmpNext;
            if (i == ItemCount - 1) tmpLast = tmpNext;

            if (tmpNext != NULL)
            {
                tmpNext->Prev = tmpPrev;
                tmpNext->Next = tmpNext->Data = NULL;
                if (tmpPrev != NULL) tmpPrev->Next = tmpNext;
                tmpPrev = tmpNext;
            }
            else
            {
                while (tmpFirst != NULL)
                {
                    tmpNext = tmpFirst->Next;
                    free(tmpFirst);
                    tmpFirst = tmpNext;
                }
                free(tmpDList);
                return NULL;
            }
        }
    }
    else return NULL;

    tmpDList->First = tmpFirst;
    tmpDList->Last  = tmpLast;
    tmpDList->Count = ItemCount;

    return tmpDList;
}

pDLIST DL_Delete(pDLIST DList, boolean FreeData)
{
    uint32_t intflags;
    pDLITEM  tmpItem, tmpItemToFree;

    if (DList != NULL)
    {
        intflags = DisableInterrupts();

        tmpItem = DL_FirstItem(DList);
        if (FreeData)
        {
            while(tmpItem != NULL)
            {
                if (tmpItem->Data != NULL) free(tmpItem->Data);
                tmpItemToFree = tmpItem;
                tmpItem = DL_NextItem(tmpItem);
                free(tmpItemToFree);
            }
        }
        else
        {
            while(tmpItem != NULL)
            {
                tmpItemToFree = tmpItem;
                tmpItem = DL_NextItem(tmpItem);
                free(tmpItemToFree);
            }
        }
        free(DList);

        RestoreInterrupts(intflags);
    }
    return NULL;
}

uint32_t DL_GetItemsCount(pDLIST DList)
{
    uint32_t n;

    if (DList != NULL)
    {
        uint32_t intflags = DisableInterrupts();

        n = DList->Count;
        RestoreInterrupts(intflags);
    }
    else n = 0;

    return n;
}

pDLITEM DL_GetFirstItem(pDLIST DList)
{
    pDLITEM  Item;
    uint32_t intflags = DisableInterrupts();

    Item = DL_FirstItem(DList);
    RestoreInterrupts(intflags);

    return Item;
}

pDLITEM DL_GetLastItem(pDLIST DList)
{
    pDLITEM  Item;
    uint32_t intflags = DisableInterrupts();

    Item = DL_LastItem(DList);
    RestoreInterrupts(intflags);

    return Item;
}

pDLITEM DL_GetPrevItem(pDLITEM LItem)
{
    pDLITEM  Item;
    uint32_t intflags = DisableInterrupts();

    Item = DL_PrevItem(LItem);
    RestoreInterrupts(intflags);

    return Item;
}

pDLITEM DL_GetNextItem(pDLITEM LItem)
{
    pDLITEM  Item;
    uint32_t intflags = DisableInterrupts();

    Item = DL_NextItem(LItem);
    RestoreInterrupts(intflags);

    return Item;
}

int32_t DL_GetItemIndex(pDLIST DList, pDLITEM Item)
{
    uint32_t intflags = DisableInterrupts();
    int32_t  Result;

    Result = DL_IndexOfItem(DList, Item);
    RestoreInterrupts(intflags);

    return Result;
}

pDLITEM DL_FindItemByData(pDLIST DList, void *Data, int32_t *Index)
{
    uint32_t intflags = DisableInterrupts();
    pDLITEM  tmpItem;

    tmpItem = DL_ItemByData(DList, Data, Index);
    RestoreInterrupts(intflags);

    return tmpItem;
}

pDLITEM DL_FindItemByIndex(pDLIST DList, uint32_t Index)
{
    uint32_t intflags = DisableInterrupts();
    pDLITEM  tmpItem;

    tmpItem = DL_ItemByIndex(DList, Index);
    RestoreInterrupts(intflags);

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
        intflags = DisableInterrupts();

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
        RestoreInterrupts(intflags);
    }
    return tmpItem;
}

pDLITEM DL_AddItemAtIndex(pDLIST DList, uint32_t Index, void *Data)
{
    uint32_t intflags;
    pDLITEM  NewIndexItem, tmpItem = NULL;

    if (DList == NULL) return NULL;

    intflags = DisableInterrupts();
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
    RestoreInterrupts(intflags);
    return tmpItem;
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
        intflags = DisableInterrupts();

        tmpItem->Data = Data;
        tmpItem->Next = Item;
        tmpItem->Prev = Item->Prev;
        Item->Prev = tmpItem;

        if (tmpItem->Prev == NULL) DList->First = tmpItem;
        else tmpItem->Prev->Next = tmpItem;

        DList->Count++;
        RestoreInterrupts(intflags);
    }
    return tmpItem;
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
        intflags = DisableInterrupts();

        tmpItem->Data = Data;
        tmpItem->Prev = Item;
        tmpItem->Next = Item->Next;
        Item->Next = tmpItem;

        if (tmpItem->Next == NULL) DList->Last = tmpItem;
        else tmpItem->Next->Prev = tmpItem;

        DList->Count++;
        RestoreInterrupts(intflags);
    }
    return tmpItem;
}

boolean DL_DeleteItem(pDLIST DList, pDLITEM Item)
{
    boolean  Result = false;
    uint32_t intflags = DisableInterrupts();

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
    RestoreInterrupts(intflags);

    return Result;
}

boolean DL_DeleteItemByData(pDLIST DList, void *Data)
{
    boolean  Result = false;
    uint32_t intflags = DisableInterrupts();
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
    RestoreInterrupts(intflags);

    return Result;
}

boolean DL_DeleteItemByIndex(pDLIST DList, uint32_t Index)
{
    boolean  Result = false;
    uint32_t intflags = DisableInterrupts();
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
        if (tmpItem->Data != NULL) free(tmpItem->Data);
        free(tmpItem);
        Result = true;
    }
    RestoreInterrupts(intflags);

    return Result;
}

boolean DL_DeleteFirstItem(pDLIST DList)
{
    boolean  Result = false;
    uint32_t intflags = DisableInterrupts();
    pDLITEM  tmpItem;

    tmpItem = DL_FirstItem(DList);
    if (tmpItem != NULL)
    {
        DList->First = tmpItem->Next;

        if (tmpItem->Next != NULL)
            tmpItem->Next->Prev = NULL;
        else DList->Last = NULL;

        DList->Count--;
        if (tmpItem->Data != NULL) free(tmpItem->Data);
        free(tmpItem);
        Result = true;
    }
    RestoreInterrupts(intflags);

    return Result;
}

boolean DL_DeleteLastItem(pDLIST DList)
{
    boolean  Result = false;
    uint32_t intflags = DisableInterrupts();
    pDLITEM  tmpItem;

    tmpItem = DL_LastItem(DList);
    if (tmpItem != NULL)
    {
        DList->Last = tmpItem->Prev;

        if (tmpItem->Prev != NULL)
            tmpItem->Prev->Next = NULL;
        else DList->First = NULL;

        DList->Count--;
        if (tmpItem->Data != NULL) free(tmpItem->Data);
        free(tmpItem);
        Result = true;
    }
    RestoreInterrupts(intflags);

    return Result;
}

boolean DL_MoveItemToIndex(pDLIST DList, uint32_t OldIndex, uint32_t NewIndex)
{
    boolean  Result = false;
    uint32_t intflags;
    pDLITEM  OldIndexItem, NewIndexItem;

    if (OldIndex != NewIndex)
    {
        intflags = DisableInterrupts();
        OldIndexItem = DL_ItemByIndex(DList, OldIndex);
        if (OldIndexItem != NULL)
        {
            NewIndexItem = DL_ItemByIndex(DList, NewIndex);
            if (NewIndexItem != NULL)
            {
                /* Remove item from old place */
                if (OldIndexItem->Prev != NULL)
                    OldIndexItem->Prev->Next = OldIndexItem->Next;
                else DList->First = OldIndexItem->Next;

                if (OldIndexItem->Next != NULL)
                    OldIndexItem->Next->Prev = OldIndexItem->Prev;
                else DList->Last = OldIndexItem->Prev;

                /* Insert item to new place */
                if (NewIndex < OldIndex)
                {
                    if (NewIndexItem->Prev != NULL)
                        NewIndexItem->Prev->Next = OldIndexItem;
                    else DList->First = OldIndexItem;

                    OldIndexItem->Prev = NewIndexItem->Prev;
                    OldIndexItem->Next = NewIndexItem;
                    NewIndexItem->Prev = OldIndexItem;
                }
                else
                {
                    if (NewIndexItem->Next != NULL)
                        NewIndexItem->Next->Prev = OldIndexItem;
                    else DList->Last = OldIndexItem;

                    OldIndexItem->Prev = NewIndexItem;
                    OldIndexItem->Next = NewIndexItem->Next;
                    NewIndexItem->Next = OldIndexItem;
                }
            }
        }
        RestoreInterrupts(intflags);
    }
    else return true;

    return Result;
}

boolean DL_ReplaceItemData(pDLIST DList, void *OldData, void *NewData)
{
    boolean  Result = false;
    uint32_t intflags;
    pDLITEM  tmpItem;

    if (DList == NULL) return false;

    intflags = DisableInterrupts();
    tmpItem = DL_ItemByData(DList, OldData, NULL);
    if (tmpItem != NULL)
    {
        tmpItem->Data = NewData;
        Result = true;
    }
    RestoreInterrupts(intflags);

    return Result;
}



