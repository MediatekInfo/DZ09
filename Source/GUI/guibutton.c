// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2021 AJScorp
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
#include "guibutton.h"

void GUI_DrawDefaultButton(pGUIOBJECT Object, pRECT Clip)
{
    pBUTTON  Button = (pBUTTON)Object;
    TRECT    ButtonRect;
    TVLINDEX Layer;

    if ((Object == NULL) || !Object->Visible ||
            (Object->Type != GO_BUTTON) || (Clip == NULL)) return;

    ButtonRect = Object->Position;
    Layer = ((pWIN)Object->Parent)->Layer;

    GDI_Draw3DFrame(Layer, &ButtonRect, Clip, clWhite, clGray, Button->Pressed);
    GUI_CalcClientAreaButton(Object, &ButtonRect);

    if (!IsRectCollapsed(&ButtonRect))
    {
        if (Button->Caption.Text != NULL)
        {
            pDLIST BackRects = GDI_DrawText(((pWIN)Button->Head.Parent)->Layer,
                                            &Button->Caption,
                                            &ButtonRect,
                                            Clip,
                                            (Button->Head.Enabled) ? Button->Caption.Color.ForeColor : clGray,
                                            Button->Caption.Color.BackColor);
            if (BackRects != NULL)
            {
                pDLITEM tmpItem;

                while ((tmpItem = DL_GetFirstItem(BackRects)) != NULL)
                {
                    if (tmpItem->Data != NULL)
                    {
                        GDI_FillRectangle(Layer, *(pRECT)tmpItem->Data, Button->ForeColor);
                        free(tmpItem->Data);
                    }
                    DL_DeleteFirstItem(BackRects);
                }
                DL_Delete(BackRects, false);
                return;
            }
        }
        if (GDI_ANDRectangles(&ButtonRect, Clip))
            GDI_FillRectangle(Layer, ButtonRect, Button->ForeColor);
    }
}

pGUIOBJECT GUI_CreateButton(pGUIOBJECT Parent, TRECT Position, TTEXT Caption,
                            TCOLOR ForeColor, TGOFLAGS Flags)
{
    pBUTTON Button;
    boolean Result;

    if ((Parent == NULL) || !GUI_IsWindowObject(Parent)) return NULL;

    Button = malloc(sizeof(TBUTTON));
    if (Button != NULL)
    {
        pDLIST ObjectsList = &((pWIN)Parent)->ChildObjects;

        memset(Button, 0x00, sizeof(TBUTTON));

        Button->Head.Position = GDI_LocalToGlobalRct(&Position, &Parent->Position.lt);
        Button->Head.Parent = Parent;
        Button->Head.Enabled = !!(Flags & GF_ENABLED);
        Button->Head.Visible = !!(Flags & GF_VISIBLE);

        Button->ForeColor = ForeColor;
        Button->Autorepeat = !!(Flags & GF_AUTOREPEAT);

        GDI_UpdateTextExtent(&Caption);
        Button->Caption = Caption;
        Button->Caption.Color.BackColor = Button->ForeColor;

        if (!ObjectsList->Count) Result = DL_AddItem(ObjectsList, Button) != NULL;
        else
        {
            pDLITEM tmpDLItem;

            GUI_GetTopNoWindowObject(Parent, &tmpDLItem);

            Result = ((tmpDLItem == NULL) ?
                      DL_AddItemAtIndex(ObjectsList, 0, Button) :
                      DL_InsertItemAfter(ObjectsList, tmpDLItem, Button)) != NULL;
        }
        if (Result) Button->Head.Type = GO_BUTTON;
        else
        {
            free(Button);
            Button = NULL;
        }
    }
    return (pGUIOBJECT)Button;
}

void GUI_DestroyButton(pGUIOBJECT Object)
{
    if ((Object != NULL) && (Object->Type == GO_BUTTON))
    {
        pBUTTON  Button = (pBUTTON)Object;
        uint32_t intflags = __disable_interrupts();

        if ((Button->Caption.Font != NULL) && (IsDynamicMemory(Button->Caption.Font)))
            free(Button->Caption.Font);
        Button->Caption.Font = NULL;

        if ((Button->Caption.Text != NULL) && (IsDynamicMemory(Button->Caption.Text)))
            free(Button->Caption.Text);
        Button->Caption.Text = NULL;

        __restore_interrupts(intflags);
    }
}

void GUI_CalcClientAreaButton(pGUIOBJECT Object, pRECT ClientArea)
{
    if ((Object != NULL) && (ClientArea != NULL))
    {
        ClientArea->l = Object->Position.l + 1;
        ClientArea->t = Object->Position.t + 1;
        ClientArea->r = Object->Position.r - 1;
        ClientArea->b = Object->Position.b - 1;
    }
}

pTEXT GUI_GetTextButton(pGUIOBJECT Object)
{
    if ((Object != NULL) && (Object->Type == GO_BUTTON))
    {
        ((pBUTTON)Object)->Caption.Color.BackColor = ((pBUTTON)Object)->ForeColor;

        return &((pBUTTON)Object)->Caption;
    }
    else return NULL;
}

boolean GUI_SetTextButton(pGUIOBJECT Object, pTEXT ObjectText)
{
    if ((Object != NULL) && (Object->Type == GO_BUTTON) && (ObjectText != NULL))
    {
        uint32_t intflags = __disable_interrupts();

        ((pBUTTON)Object)->Caption = *ObjectText;
        ((pBUTTON)Object)->Caption.Color.BackColor = ((pBUTTON)Object)->ForeColor;
        __restore_interrupts(intflags);

        return true;
    }
    return false;
}
