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
#include "guiobject.h"

pWIN GUI_CreateWindow(pGUIHEADER Parent, TRECT Position, boolean (*Handler)(pEVENT, pWIN),
                      TVLINDEX Layer, uint32_t ForeColor, TGOFLAGS Flags)
{
    pWIN    Win;
    boolean Result;

    if ((Layer >= LCDIF_NUMLAYERS) ||
            ((Parent != NULL) && !IsWindowObject(Parent))) return NULL;

    Win = malloc(sizeof(TWIN));
    if (Win != NULL)
    {
        pDLIST ObjectsList;

        Layer = (Parent != NULL) ? ((pWIN)Parent)->Layer : Layer;
        ObjectsList = (Parent == NULL) ? GUIWinZOrder[Layer] : &((pWIN)Parent)->ChildObjects;

        memset(Win, 0x00, sizeof(TWIN));

        Win->Head.Position = (Parent != NULL) ?
                             GDI_LocalToGlobalRct(&Position, &Parent->Position.lt) : Position;
        Win->Head.Parent = Parent;
        Win->Head.Enabled = (Flags & GF_ENABLED) != 0;
        Win->Head.Visible = (Flags & GF_VISIBLE) != 0;

        Win->Topmost = (Flags & GF_TOPMOST) != 0;
        Win->Framed = (Flags & GF_FRAMED) != 0;
        Win->Layer = Layer;
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
                        (!IsWindowObject(tmpObject) || !((pWIN)tmpObject)->Topmost))
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
    return Win;
}

boolean IsWindowObject(pGUIHEADER Object)
{
    return ((Object != NULL) && (Object->Type == GO_WINDOW));
}

int32_t GUI_GetWindowZIndex(pWIN Win)
{
    int32_t ZL = -1;

    if ((Win != NULL) && IsWindowObject((pGUIHEADER)Win) && (Win->Layer < LCDIF_NUMLAYERS))
    {
        DL_FindItemByData(GUIWinZOrder[Win->Layer], Win, &ZL);
    }
    return ZL;
}

pWIN GUI_GetTopWindow(TVLINDEX Layer, boolean Topmost)
{
    pWIN    tmpWIN, Res = NULL;
    pDLITEM tmpItem;

    if (Layer >= LCDIF_NUMLAYERS) return NULL;

    if (Topmost)
    {
        tmpItem = DL_GetLastItem(GUIWinZOrder[Layer]);
        tmpWIN = (tmpItem == NULL) ? NULL : (pWIN)tmpItem->Data;
        Res = ((tmpWIN == NULL) || !tmpWIN->Topmost) ? NULL : tmpWIN;
    }
    else
    {
        tmpItem = DL_GetLastItem(GUIWinZOrder[Layer]);
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
    return Res;
}

pWIN GUI_GetWindowFromPoint(pPOINT pt, int32_t *ZIndex)
{
    int32_t i;
    pWIN    Win;

    if (pt != NULL)
    {
        for(i = LCDIF_NUMLAYERS - 1; i >= 0; i--)
        {
            pDLITEM tmpItem;
            int32_t ItemIndex;

            tmpItem = DL_GetLastItem(GUIWinZOrder[i]);
            ItemIndex = DL_GetItemsCount(GUIWinZOrder[i]) - 1;
            while(tmpItem != NULL)
            {
                Win = tmpItem->Data;
                if ((Win != NULL) && Win->Head.Visible && IsPointInRect(pt->x, pt->y, &Win->Head.Position))
                {
                    if (ZIndex != NULL) *ZIndex = ItemIndex;
                    return Win;
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
                break;
            default:
                return;
            }

        Layer = (Object->Parent != NULL) ?
                ((pWIN)Object->Parent)->Layer : ((pWIN)Object)->Layer;
        UpdateRect = GDI_LocalToGlobalRct(Clip, &LCDScreen.VLayer[Layer].LayerOffset);
        LCDIF_UpdateRectangle(UpdateRect);
    }
}
