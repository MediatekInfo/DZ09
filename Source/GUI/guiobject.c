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
#include "guiobject.h"

pGUIHEADER GUILayer[LCDIF_NUMLAYERS];

static void GUI_DrawDefaultWindow(pGUIHEADER Object, pRECT Clip)
{
    pWIN  Win = (pWIN)Object;
    TRECT WinRect;

    if ((Object == NULL) || !Object->Visible ||
            !GUI_IsWindowObject((pGUIHEADER)Object) || (Clip == NULL)) return;

    WinRect = Object->Position;
    if (Win->Framed)
    {
        GDI_DrawFrame(Win->Layer, &WinRect, Clip, clWhite);
        WinRect.l++;
        WinRect.t++;
        WinRect.r--;
        WinRect.b--;
    }

    if ((WinRect.l <= WinRect.r) && (WinRect.t <= WinRect.b) &&
            GDI_ANDRectangles(&WinRect, Clip))
    {
        GDI_FillRectangle(Win->Layer, WinRect, Win->ForeColor);
    }
}

static void GUI_UpdateChildPositions(pGUIHEADER Object, pPOINT dXY)
{
    pDLIST ChildList = &((pWIN)Object)->ChildObjects;

    if (DL_GetItemsCount(ChildList))
    {
        pDLITEM tmpItem = DL_GetFirstItem(ChildList);

        while (tmpItem != NULL)
        {
            pGUIHEADER tmpObject = (pGUIHEADER)tmpItem->Data;

            if (tmpObject != NULL)
            {
                tmpObject->Position.l += dXY->x;
                tmpObject->Position.r += dXY->x;
                tmpObject->Position.t += dXY->y;
                tmpObject->Position.b += dXY->y;

                if (GUI_IsWindowObject(tmpObject))
                    GUI_UpdateChildPositions(tmpObject, dXY);
            }
            tmpItem = DL_GetNextItem(tmpItem);
        }
    }
}

TRECT GUI_CalculateClientArea(pGUIHEADER Object)
{
    TRECT ObjectRect = Object->Position;

    switch (Object->Type)
    {
    case GO_WINDOW:
        if (((pWIN)Object)->Framed)
        {
            ObjectRect.l++;
            ObjectRect.t++;
            ObjectRect.r--;
            ObjectRect.b--;
        }
        break;
    default:
        break;
    }

    return ObjectRect;
}

boolean GUI_GetObjectPosition(pGUIHEADER Object, pRECT Position)
{
    if (Object == NULL) return false;

    if (Position != NULL)
    {
        *Position = (Object->Parent != NULL) ?
                    GDI_GlobalToLocalRct(&Object->Position, &Object->Parent->Position.lt) :
                    Object->Position;
    }
    return true;
}

void GUI_SetObjectPosition(pGUIHEADER Object, pRECT Position)
{
    TRECT NewPosition;

    if ((Object == NULL) || (Position == NULL)) return;

    NewPosition = (Object->Parent == NULL) ? *Position :
                  GDI_LocalToGlobalRct(Position, &Object->Parent->Position.lt);
    if (memcmp(&Object->Position, &NewPosition, sizeof(TRECT)) != 0)
    {
        TPOINT dXY = GDI_GlobalToLocalPt(&NewPosition.lt, &Object->Position.lt);
        pDLIST UpdateRects = GDI_SUBRectangles(&Object->Position, &NewPosition);

        Object->Position = NewPosition;

        if (GUI_IsWindowObject(Object))
            GUI_UpdateChildPositions(Object, &dXY);
        GUI_Invalidate(Object, NULL);

        while (DL_GetItemsCount(UpdateRects))
        {
            pDLITEM tmpDLItem = DL_GetFirstItem(UpdateRects);

            GUI_Invalidate(Object->Parent, (pRECT)tmpDLItem->Data);
            free(tmpDLItem->Data);
            DL_DeleteFirstItem(UpdateRects);
        }
        DL_Delete(UpdateRects, false);
    }
}

boolean GUI_GetObjectVisibilty(pGUIHEADER Object)
{
    return ((Object != NULL) && Object->Visible);
}

boolean GUI_SetObjectVisibility(pGUIHEADER Object, boolean Visible)
{
    if (Object == NULL) return false;
    if (Object->Visible != Visible)
    {
        Object->Visible = Visible;
        GUI_Invalidate(Object, NULL);
    }
    return true;
}

boolean GUI_CreateLayer(TVLINDEX Layer, TRECT Position, TCFORMAT CFormat,
                        uint8_t GlobalAlpha, uint32_t ForeColor)
{
    pGUILAYER LObject;
    boolean   Result = false;

    if ((Layer >= LCDIF_NUMLAYERS) || (GUILayer[Layer] != NULL)) return false;

    LObject = malloc(sizeof(TGUILAYER));
    if (LObject != NULL)
    {
        memset(LObject, 0x00, sizeof(TGUILAYER));

        LObject->Head.Position = GDI_GlobalToLocalRct(&Position, &Position.lt);                      // Left/Top of Layer object must be zero
        LObject->Head.Enabled = true;
        LObject->Head.Visible = true;
        LObject->Layer = Layer;
        LObject->ForeColor = ForeColor;

        Result = LCDIF_SetupLayer(Layer, Position.lt, Position.r - Position.l + 1,
                                  Position.b - Position.t + 1, CFormat, GlobalAlpha, ForeColor);

        if (!Result) free(LObject);
        else
        {
            uint32_t intflags = DisableInterrupts();

            LObject->Head.Type = GO_WINDOW;
            GUILayer[Layer] = (pGUIHEADER)LObject;
            RestoreInterrupts(intflags);
        }
    }
    return Result;
}

pGUIHEADER GUI_CreateWindow(pGUIHEADER Parent, TRECT Position,
                            boolean (*Handler)(pEVENT, pGUIHEADER),
                            uint32_t ForeColor, TGOFLAGS Flags)
{
    pWIN    Win;
    boolean Result;

    if ((Parent == NULL) || !GUI_IsWindowObject(Parent)) return NULL;

    Win = malloc(sizeof(TWIN));
    if (Win != NULL)
    {
        pDLIST ObjectsList = &((pWIN)Parent)->ChildObjects;

        memset(Win, 0x00, sizeof(TWIN));

        Win->Head.Position = GDI_LocalToGlobalRct(&Position, &Parent->Position.lt);
        Win->Head.Parent = Parent;
        Win->Head.Enabled = (Flags & GF_ENABLED) != 0;
        Win->Head.Visible = (Flags & GF_VISIBLE) != 0;

        Win->Topmost = (Flags & GF_TOPMOST) != 0;
        Win->Framed = (Flags & GF_FRAMED) != 0;
        Win->Layer = ((pWIN)Parent)->Layer;
        Win->ForeColor = ForeColor;
        Win->EventHandler = Handler;

        if (Win->Topmost) Result = DL_AddItem(ObjectsList, Win) != NULL;                            // Put the handle directly to the top of the list
        else                                                                                        // Looking for top window among non-topmost objects
        {
            pDLITEM tmpItem = DL_GetLastItem(ObjectsList);

            while(tmpItem != NULL)
            {
                pGUIHEADER tmpObject = tmpItem->Data;

                if ((tmpObject != NULL) &&
                        (!GUI_IsWindowObject(tmpObject) || !((pWIN)tmpObject)->Topmost))
                {
                    Result = DL_InsertItemAfter(ObjectsList, tmpItem, Win) != NULL;
                    break;
                }
                tmpItem = DL_GetPrevItem(tmpItem);
            }
            if (tmpItem == NULL) Result = DL_AddItemAtIndex(ObjectsList, 0, Win) != NULL;
        }
        if (Result) Win->Head.Type = GO_WINDOW;
        else
        {
            free(Win);
            Win = NULL;
        }
    }
    return (pGUIHEADER)Win;
}

boolean GUI_IsWindowObject(pGUIHEADER Object)
{
    return ((Object != NULL) && (Object->Type == GO_WINDOW));
}

int32_t GUI_GetWindowZIndex(pGUIHEADER Win)
{
    int32_t ZL = -1;

    if ((Win != NULL) && GUI_IsWindowObject(Win) &&
            (((pWIN)Win)->Layer < LCDIF_NUMLAYERS) && (GUILayer[((pWIN)Win)->Layer] != NULL))
    {
        DL_FindItemByData(&((pGUILAYER)GUILayer[((pWIN)Win)->Layer])->ChildObjects, Win, &ZL);
    }
    return ZL;
}

pGUIHEADER GUI_GetTopWindow(TVLINDEX Layer, boolean Topmost)
{
    pWIN    tmpWIN, Res = NULL;
    pDLITEM tmpItem;

    if ((Layer < LCDIF_NUMLAYERS) && (GUILayer[Layer] != NULL))
    {
        pGUILAYER tmpLayer = (pGUILAYER)GUILayer[Layer];

        if (Topmost)
        {
            tmpItem = DL_GetLastItem(&tmpLayer->ChildObjects);
            tmpWIN = (tmpItem == NULL) ? NULL : (pWIN)tmpItem->Data;
            Res = ((tmpWIN == NULL) || !tmpWIN->Topmost) ? NULL : tmpWIN;
        }
        else
        {
            tmpItem = DL_GetLastItem(&tmpLayer->ChildObjects);
            while(tmpItem != NULL)
            {
                tmpWIN = (pWIN)tmpItem->Data;
                if ((tmpWIN != NULL) && !tmpWIN->Topmost)
                {
                    Res = tmpWIN;
                    break;
                }
                tmpItem = DL_GetPrevItem(tmpItem);
            }
        }
    }
    return (pGUIHEADER)Res;
}

pGUIHEADER GUI_GetWindowFromPoint(pPOINT pt, int32_t *ZIndex)
{
    int32_t i;
    pWIN    Win;

    if (pt != NULL)
    {
        for(i = LCDIF_NUMLAYERS - 1; i >= 0; i--)
        {
            pDLITEM tmpItem;
            int32_t ItemIndex;

            if (GUILayer[i] == NULL) continue;

            tmpItem = DL_GetLastItem(&((pGUILAYER)GUILayer[i])->ChildObjects);
            ItemIndex = DL_GetItemsCount(&((pGUILAYER)GUILayer[i])->ChildObjects) - 1;
            while(tmpItem != NULL)
            {
                Win = tmpItem->Data;
                if ((Win != NULL) && Win->Head.Visible && IsPointInRect(pt->x, pt->y, &Win->Head.Position))
                {
                    if (ZIndex != NULL) *ZIndex = ItemIndex;
                    return (pGUIHEADER)Win;
                }
                ItemIndex--;
                tmpItem = DL_GetPrevItem(tmpItem);
            }
            if (LCDScreen.VLayer[i].Enabled && IsPointInRect(pt->x, pt->y, &LCDScreen.VLayer[i].LayerRgn))
                break;
        }
    }
    if (ZIndex != NULL) *ZIndex = -1;
    return NULL;
}

void GUI_DrawObjectDefault(pGUIHEADER Object, pRECT Clip)
{
    if ((Object != NULL) && (Clip != NULL))
    {
        TRECT    UpdateRect;
        TVLINDEX Layer;

        if (Object->OnPaint != NULL) Object->OnPaint(Object, Clip);
        else switch(Object->Type)
            {
            case GO_WINDOW:
                GUI_DrawDefaultWindow(Object, Clip);
                break;
            default:
                return;
            }

        Layer = (Object->Parent != NULL) ?
                ((pWIN)Object->Parent)->Layer : ((pWIN)Object)->Layer;
        UpdateRect = GDI_LocalToGlobalRct(Clip, &LCDScreen.VLayer[Layer].LayerOffset);
        UpdateRect = GDI_GlobalToLocalRct(&UpdateRect, &LCDScreen.ScreenOffset);
        LCDIF_UpdateRectangle(UpdateRect);
    }
}

void GUI_DestroyObject(pGUIHEADER Object)
{

}
