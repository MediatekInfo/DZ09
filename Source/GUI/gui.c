// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2019 AJScorp
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
    TPOINT     tmpPoint = {0, 0};
    boolean    IsStillVisible = false;
    pGUIHEADER Object;

    if ((PEvent != NULL) && ((Object = PEvent->Object) != NULL))
    {
        IsStillVisible = Object->Visible &&
                         GDI_ANDRectangles(&PEvent->UpdateRect, &Object->Position) &&
                         ((Object->Parent != NULL) || (Object->Type == GO_WINDOW));                 // The topmost object in the hierarchy must be a TWIN object.

        while(IsStillVisible && (Object->Parent != NULL))
        {
            TPOINT ParentBase = Object->Parent->Position.lt;

            PEvent->UpdateRect = GDI_LocalToGlobalRct(&PEvent->UpdateRect, &ParentBase);
            tmpPoint = GDI_LocalToGlobalPt(&tmpPoint, &Object->Parent->Position.lt);

            IsStillVisible = Object->Visible &&
                             GDI_ANDRectangles(&PEvent->UpdateRect, &Object->Parent->Position) &&
                             (Object->Parent->Type == GO_WINDOW);                                   // Only a TWIN object can be a parent.

            Object = Object->Parent;
        }

        PEvent->UpdateRect = GDI_GlobalToLocalRct(&PEvent->UpdateRect, &tmpPoint);
    }
    if (IsStillVisible)
    {
        PEvent->RootParent = Object;
        PEvent->ParentLayerBase = tmpPoint;
    }

    return IsStillVisible;
}

static boolean GUI_SubTopChildObjectsFromRegion(pDLIST Region, pGUIHEADER Object, pPOINT Shift)
{
    if ((Region != NULL) && Region->Count && (Object != NULL) && (Shift != NULL))
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
                    tmpObject->Position = GDI_GlobalToLocalRct(&tmpObject->Position, Shift);

                    if (!GDI_SUBRectFromRegion(Region, &tmpObject->Position)) break;
                }
                tmpDLItem = DL_GetPrevItem(tmpDLItem);
            }
        }
        return Region->Count != 0;
    }
    return false;
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
    if (Result) TSDRV_Initialize();
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
            if ((Event->RootParent->Type == GO_WINDOW) &&
                    GDI_ANDRectangles(&Event->UpdateRect,
                                      &LCDScreen.VLayer[((pWIN)Event->RootParent)->Layer].LayerRgn))
            {
                pDLIST UpdateRgn = DL_Create(0);
                pRECT  SeedRect = malloc(sizeof(TRECT));

                if ((UpdateRgn != NULL) && (SeedRect != NULL) &&
                        (DL_AddItem(UpdateRgn, SeedRect) != NULL))
                {
                    pDLITEM tmpDLItem;

                    *SeedRect = Event->UpdateRect;

                    /* Subtract the positions of topmost windows from the update region. */
                    tmpDLItem = DL_GetLastItem(GUIWinZOrder[((pWIN)Event->RootParent)->Layer]);
                    while((tmpDLItem != NULL) && DL_GetItemsCount(UpdateRgn))
                    {
                        pGUIHEADER tmpObject = (pGUIHEADER)tmpDLItem->Data;
                        TRECT      tmpObjectRect;

                        if ((uintptr_t)tmpObject == (uintptr_t)Event->RootParent) break;
                        if ((tmpObject != NULL) && tmpObject->Visible)
                        {
                            tmpObjectRect = GDI_GlobalToLocalRct(&tmpObject->Position, &Event->ParentLayerBase);
                            if (!GDI_SUBRectFromRegion(UpdateRgn, &tmpObjectRect)) break;
                        }
                        tmpDLItem = DL_GetPrevItem(tmpDLItem);
                    }

                    /* Subtract the positions of the topmost child back through the parent tree. */
                    if (UpdateRgn->Count && (Event->Object->Parent != NULL))
                    {
                        pGUIHEADER tmpObject = Event->Object;
                        TPOINT     tmpShift = {0};

                        while (tmpObject->Parent != NULL)
                        {
                            if (!GUI_SubTopChildObjectsFromRegion(UpdateRgn, tmpObject, &tmpShift)) break;

                            tmpShift = GDI_LocalToGlobalPt(&tmpShift, &tmpObject->Parent->Position.lt);
                            tmpObject = tmpObject->Parent;
                        }
                    }

                    if (DL_GetItemsCount(UpdateRgn))
                    {
                        TPOINT LayerOffset = LCDScreen.VLayer[((pWIN)Event->RootParent)->Layer].LayerOffset;

                        /* Draw parts of the object */
                        while(((tmpDLItem = DL_GetFirstItem(UpdateRgn)) != NULL) &&
                                DL_GetItemsCount(UpdateRgn))
                        {
                            pRECT tmpObjectRect = (pRECT)tmpDLItem->Data;

                            if (tmpObjectRect != NULL)
                            {
                                GDI_DrawObjectDefault(Event->Object, tmpObjectRect, &Event->ParentLayerBase);

                                tmpObjectRect->l += Event->ParentLayerBase.x + LayerOffset.x;
                                tmpObjectRect->t += Event->ParentLayerBase.y + LayerOffset.y;
                                tmpObjectRect->r += Event->ParentLayerBase.x + LayerOffset.x;
                                tmpObjectRect->b += Event->ParentLayerBase.y + LayerOffset.y;

                                LCDIF_UpdateRectangle(*tmpObjectRect);

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
