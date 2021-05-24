// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2021, 2020 AJScorp
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
#include "guiwin.h"

pGUIOBJECT GUILayer[LCDIF_NUMLAYERS];

void GUI_DrawDefaultWindow(pGUIOBJECT Object, pRECT Clip)
{
    pWIN  Win = (pWIN)Object;
    TRECT WinRect;

    if ((Object == NULL) || !Object->Visible ||
            !GUI_IsWindowObject(Object) || (Clip == NULL)) return;

    WinRect = Object->Position;
    if (Win->Framed)
        GDI_DrawFrame(Win->Layer, &WinRect, Clip, clWhite);

    GUI_CalcClientAreaWindow(Object, &WinRect);

    if (!IsRectCollapsed(&WinRect) && GDI_ANDRectangles(&WinRect, Clip))
    {
        GDI_FillRectangle(Win->Layer, WinRect, Win->ForeColor);
    }
}

boolean GUI_CreateLayer(TVLINDEX Layer, TRECT Position, TCFORMAT CFormat,
                        uint8_t GlobalAlpha, TCOLOR ForeColor)
{
    pWIN    LObject;
    boolean Result = false;

    if ((Layer >= LCDIF_NUMLAYERS) || (GUILayer[Layer] != NULL)) return false;

    LObject = malloc(sizeof(TWIN));
    if (LObject != NULL)
    {
        memset(LObject, 0x00, sizeof(TWIN));

        LObject->Head.Position = GDI_GlobalToLocalRct(&Position, &Position.lt);                      // Left/Top of Layer object must be zero
        LObject->Head.Enabled = true;
        LObject->Head.Visible = true;
        LObject->Head.InheritedEnabled = true;
        LObject->Head.InheritedVisible = true;
        LObject->Layer = Layer;
        LObject->ForeColor = ForeColor;

        Result = LCDIF_SetupLayer(Layer, Position.lt, Position.r - Position.l + 1,
                                  Position.b - Position.t + 1, CFormat, GlobalAlpha, ForeColor);

        if (!Result) free(LObject);
        else
        {
            uint32_t intflags = __disable_interrupts();

            LObject->Head.Type = GO_WINDOW;
            GUILayer[Layer] = (pGUIOBJECT)LObject;
            __restore_interrupts(intflags);
        }
    }
    return Result;
}

pGUIOBJECT GUI_CreateWindow(pGUIOBJECT Parent, TRECT Position,
                            boolean (*Handler)(pEVENT, pGUIOBJECT),
                            TCOLOR ForeColor, TGOFLAGS Flags)
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
        Win->Head.InheritedEnabled = Parent->Enabled;
        Win->Head.InheritedVisible = Parent->Visible;

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
                pGUIOBJECT tmpObject = tmpItem->Data;

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
    return (pGUIOBJECT)Win;
}

void GUI_DestroyWindow(pGUIOBJECT Object)
{
    return;
}

boolean GUI_IsWindowObject(pGUIOBJECT Object)
{
    return ((Object != NULL) && (Object->Type == GO_WINDOW));
}

int32_t GUI_GetWindowZIndex(pGUIOBJECT Win)
{
    int32_t ZL = -1;

    if ((Win != NULL) && GUI_IsWindowObject(Win) &&
            (((pWIN)Win)->Layer < LCDIF_NUMLAYERS) && (GUILayer[((pWIN)Win)->Layer] != NULL))
    {
        DL_FindItemByData(&((pWIN)GUILayer[((pWIN)Win)->Layer])->ChildObjects, Win, &ZL);
    }
    return ZL;
}

pGUIOBJECT GUI_GetTopWindow(pGUIOBJECT Parent, boolean Topmost, pDLITEM *ObjectItem)
{
    pGUIOBJECT Result = NULL;

    if ((Parent != NULL) && GUI_IsWindowObject(Parent))
    {
        pGUIOBJECT Object;
        pDLITEM    tmpDLItem;

        tmpDLItem = DL_GetLastItem(&((pWIN)Parent)->ChildObjects);
        if (Topmost)
        {
            Object = (tmpDLItem == NULL) ? NULL : (pGUIOBJECT)tmpDLItem->Data;
            Result = ((Object != NULL) &&
                      GUI_IsWindowObject(Object) &&
                      ((pWIN)Object)->Topmost) ? Object : NULL;
            *ObjectItem = ((ObjectItem != NULL) && (Result != NULL)) ? tmpDLItem : NULL;
        }
        else
        {
            while(tmpDLItem != NULL)
            {
                Object = (pGUIOBJECT)tmpDLItem->Data;
                if (Object != NULL)
                {
                    if (!GUI_IsWindowObject(Object)) break;
                    if (!((pWIN)Object)->Topmost)
                    {
                        Result = Object;
                        if (ObjectItem != NULL) *ObjectItem = tmpDLItem;
                        break;
                    }
                }
                tmpDLItem = DL_GetPrevItem(tmpDLItem);
            }
        }
    }
    return Result;
}

void GUI_CalcClientAreaWindow(pGUIOBJECT Object, pRECT ClientArea)
{
    if ((Object != NULL) && (ClientArea != NULL))
    {
        if (((pWIN)Object)->Framed)
        {
            ClientArea->l = Object->Position.l + 1;
            ClientArea->t = Object->Position.t + 1;
            ClientArea->r = Object->Position.r - 1;
            ClientArea->b = Object->Position.b - 1;
        }
        else *ClientArea = Object->Position;
    }
}
