// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "gui.h"

pDLIST GUIWinZOrder[LCDIF_NUMLAYERS];

static boolean GUI_IsObjectVisibleAcrossParents(pPAINTEV PEvent)
{
    boolean    IsStillVisible = false;
    pGUIHEADER Object;

    if ((PEvent != NULL) && ((Object = PEvent->Object) != NULL))
    {
        TRECT ObjectPosition;

        if (Object->Parent != NULL)
        {
            ObjectPosition = GUI_CalculateClientArea(Object->Parent);
            GDI_ANDRectangles(&ObjectPosition, &Object->Position);
        }
        else ObjectPosition = Object->Position;

        IsStillVisible = Object->Visible &&
                         GDI_ANDRectangles(&PEvent->UpdateRect, &ObjectPosition) &&
                         ((Object->Parent != NULL) || IsWindowObject(Object));                      // The topmost object in the hierarchy must be a TWIN object.

        while(IsStillVisible && (Object->Parent != NULL))
        {
            ObjectPosition = GUI_CalculateClientArea(Object->Parent);

            IsStillVisible = Object->Parent->Visible &&
                             GDI_ANDRectangles(&PEvent->UpdateRect, &ObjectPosition) &&
                             IsWindowObject(Object->Parent);                                        // Only a TWIN object can be a parent.
            Object = Object->Parent;
        }

        if (IsStillVisible)
            PEvent->RootParent = Object;
    }
    return IsStillVisible;
}

static boolean GUI_SubTopChildObjectsFromRegion(pDLIST Region, pGUIHEADER Object)
{
    if (Object->Parent != NULL)
    {
        pDLIST  ChildList = &((pWIN)Object->Parent)->ChildObjects;
        pDLITEM tmpDLItem = DL_GetLastItem(ChildList);

        /* Subtract the positions of topmost child objects from the update region. */
        while((tmpDLItem != NULL) && DL_GetItemsCount(Region))
        {
            pGUIHEADER tmpObject = (pGUIHEADER)tmpDLItem->Data;

            if ((uintptr_t)tmpObject == (uintptr_t)Object) break;

            if ((tmpObject != NULL) && tmpObject->Visible)
            {
                if (!GDI_SUBRectFromRegion(Region, &tmpObject->Position)) break;
            }
            tmpDLItem = DL_GetPrevItem(tmpDLItem);
        }
    }
    return DL_GetItemsCount(Region) != 0;
}

static void GUI_UpdateObjectByRegion(pDLIST Region, pGUIHEADER Object, pRECT Clip)
{
    pDLITEM tmpItem = DL_GetFirstItem(Region);

    while(tmpItem != NULL)
    {
        if (tmpItem->Data != NULL)
        {
            TRECT tmpRect = *(pRECT)tmpItem->Data;

            if (GDI_ANDRectangles(&tmpRect, Clip))
                GUI_DrawObjectDefault(Object, &tmpRect);
        }
        tmpItem = DL_GetNextItem(tmpItem);
    }
}

static boolean GUI_UpdateChildTree(pDLIST Region, pWIN Win, pRECT Clip)
{
    pDLITEM    tmpItem = DL_GetLastItem(&Win->ChildObjects);
    pGUIHEADER tmpObject;
    TRECT      tmpWinRect = GUI_CalculateClientArea((pGUIHEADER)Win);

    while((tmpItem != NULL) && ((tmpObject = (pGUIHEADER)tmpItem->Data) != NULL))
    {
        TRECT tmpObjectRect = tmpObject->Position;

        if ((tmpObject->Visible) && GDI_ANDRectangles(&tmpObjectRect, &tmpWinRect))
        {
            if (IsWindowObject(tmpObject))
            {
                if (!GUI_UpdateChildTree(Region, (pWIN)tmpObject, &tmpObjectRect)) break;
            }
            else GUI_UpdateObjectByRegion(Region, tmpObject, &tmpObjectRect);
            GDI_SUBRectFromRegion(Region, &tmpObjectRect);
        }
        if (!DL_GetItemsCount(Region)) break;
        tmpItem = DL_GetPrevItem(tmpItem);
    }
    GUI_UpdateObjectByRegion(Region, &Win->Head, Clip);

    return DL_GetItemsCount(Region) != 0;
}

boolean GUI_Initialize(void)
{
    uint32_t i;
    boolean  Result;

    DebugPrint("GUI subsystem initialization:\r\n");

    DebugPrint(" LCD interface initialization...");
    Result = LCDIF_Initialize();                                                                    //Initialize subsystem

    if (Result)
    {
        for(i = 0; i < LCDIF_NUMLAYERS; i++)
        {
// TODO (scorp#1#): May need to check for objects in the lists.
            if (GUIWinZOrder[i] == NULL) GUIWinZOrder[i] = DL_Create(0);
            if (GUIWinZOrder[i] == NULL)
            {
                while(i--)
                {
                    free(GUIWinZOrder[i]);
                    GUIWinZOrder[i] = NULL;
                }
                LCDIF_DisableInterface();
                Result = false;
                break;
            }
        }
    }

    BL_Initialize();

    if (Result)
    {
        TSDRV_Initialize();

        LCDIF_UpdateRectangleBlocked(&LCDScreen.ScreenRgn);
        USC_Pause_us(LCD_REDRAWTIME);                                                               // Wait until the screen is redrawn.
    }
    else DebugPrint("GUI initialization failed!\r\n");

    return Result;
}

/*
1. If Object != NULL - Rct coordinates relative to the object.
   If Rct == NULL - Invalidate whole object
2. If Object == NULL - Rct coordinates relative to the screen.
   If Rct == NULL - Invalidate whole screen
*/
void GUI_Invalidate(pGUIHEADER Object, pRECT Rct)
{
    TPAINTEV PaintEvent = {0};

    if (Object != NULL)
    {
        PaintEvent.Object = Object;
        PaintEvent.UpdateRect = (Rct != NULL) ? *Rct : Object->Position;

        if (GUI_IsObjectVisibleAcrossParents(&PaintEvent))
            EM_PostEvent(ET_ONPAINT, NULL, &PaintEvent, sizeof(TPAINTEV));
    }
    else
    {
        PaintEvent.UpdateRect = (Rct != NULL) ? *Rct : LCDScreen.ScreenRgn;

        EM_PostEvent(ET_ONPAINT, NULL, &PaintEvent, sizeof(TPAINTEV));
    }
}

void GUI_OnPaintHandler(pPAINTEV Event)
{
    if (Event != NULL)
    {
        if (Event->RootParent != NULL)                                                              // Invalidate by object
        {
            if (IsWindowObject(Event->RootParent) &&
                    GDI_ANDRectangles(&Event->UpdateRect,
                                      &LCDScreen.VLayer[((pWIN)Event->RootParent)->Layer].LayerRgn))
            {
                pDLIST UpdateRgn = DL_Create(0);
                pRECT  SeedRect = malloc(sizeof(TRECT));

                if ((UpdateRgn != NULL) && (SeedRect != NULL) &&
                        (DL_AddItem(UpdateRgn, SeedRect) != NULL))
                {
                    pDLITEM    tmpDLItem;
                    pGUIHEADER tmpObject;

                    *SeedRect = Event->UpdateRect;

                    /* Subtract the positions of topmost windows from the update region. */
                    tmpDLItem = DL_GetLastItem(GUIWinZOrder[((pWIN)Event->RootParent)->Layer]);
                    while((tmpDLItem != NULL) && DL_GetItemsCount(UpdateRgn))
                    {
                        tmpObject = (pGUIHEADER)tmpDLItem->Data;

                        if ((uintptr_t)tmpObject == (uintptr_t)Event->RootParent) break;
                        if ((tmpObject != NULL) && tmpObject->Visible &&
                                !GDI_SUBRectFromRegion(UpdateRgn, &tmpObject->Position)) break;

                        tmpDLItem = DL_GetPrevItem(tmpDLItem);
                    }

                    if (DL_GetItemsCount(UpdateRgn))
                    {
                        if (Event->Object->Parent != NULL)
                        {
                            tmpObject = Event->Object;
                            /* Subtract the positions of the topmost child back through the parent tree. */
                            while (tmpObject->Parent != NULL)
                            {
                                if (!GUI_SubTopChildObjectsFromRegion(UpdateRgn, tmpObject)) break;
                                tmpObject = tmpObject->Parent;
                            }
                        }

                        if (IsWindowObject(Event->Object) && DL_GetItemsCount(UpdateRgn))
                        {
                            /* Update the tree of child objects. */
                            if (GUI_UpdateChildTree(UpdateRgn, (pWIN)Event->Object, &Event->Object->Position))
                                GDI_SUBRectFromRegion(UpdateRgn, &Event->Object->Position);
                        }

                        /* Draw parts of the object */
                        while((tmpDLItem = DL_GetFirstItem(UpdateRgn)) != NULL)
                        {
                            pRECT tmpObjectRect = (pRECT)tmpDLItem->Data;

                            if (tmpObjectRect != NULL)
                            {
                                GUI_DrawObjectDefault(Event->Object, tmpObjectRect);
                                free(tmpDLItem->Data);
                            }
                            DL_DeleteFirstItem(UpdateRgn);
                        }
                    }
                }
                else if (SeedRect != NULL) free(SeedRect);

                DL_Delete(UpdateRgn, false);
            }
        }
        else                                                                                        // Invalidate by screen
        {

        }
    }
}
