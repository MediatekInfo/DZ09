// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 - 2021 AJScorp
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
#include "guilabel.h"

void GUI_DrawDefaultLabel(pGUIOBJECT Object, pRECT Clip)
{
    pLABEL   Label = (pLABEL)Object;
    TRECT    LabelRect;
    TVLINDEX Layer;

    if ((Object == NULL) || !Object->Visible ||
            (Object->Type != GO_LABEL) || (Clip == NULL)) return;

    LabelRect = Object->Position;
    Layer = ((pWIN)Object->Parent)->Layer;

    if (Label->Caption.Text != NULL)
    {
        pRLIST BackRects = GDI_DrawText(((pWIN)Label->Head.Parent)->Layer,
                                        &Label->Caption,
                                        &LabelRect,
                                        Clip,
                                        (Label->Head.Enabled && Label->Head.InheritedEnabled) ?
                                        Label->Caption.Color.ForeColor : clGray,
                                        Label->Caption.Color.BackColor);
        if (BackRects != NULL)
        {
            uint32_t i;

            for(i = 0; i < BackRects->Count; i++)
                GDI_FillRectangle(Layer, BackRects->Item[i], Label->ForeColor);

            GDI_DeleteRList(BackRects);
            return;
        }
    }
    if (GDI_ANDRectangles(&LabelRect, Clip))
        GDI_FillRectangle(Layer, LabelRect, Label->ForeColor);
}

pGUIOBJECT GUI_CreateLabel(pGUIOBJECT Parent, TRECT Position, TTEXT Caption,
                           TCOLOR ForeColor, TGOFLAGS Flags)
{
    pLABEL  Label;
    boolean Result;

    if ((Parent == NULL) ||
            !GUI_IsWindowObject(Parent) || GUI_IsLayerObject(Parent)) return NULL;

    Label = malloc(sizeof(TLABEL));
    if (Label != NULL)
    {
        pDLIST ObjectsList = &((pWIN)Parent)->ChildObjects;

        memset(Label, 0x00, sizeof(TLABEL));

        NORMALIZEVAL(Position.l, Position.r);
        NORMALIZEVAL(Position.t, Position.b);

        Label->Head.Position = GDI_LocalToGlobalRct(&Position, &Parent->Position.lt);
        Label->Head.Parent = Parent;
        Label->Head.Enabled = !!(Flags & GF_ENABLED);
        Label->Head.Visible = !!(Flags & GF_VISIBLE);
        Label->Head.InheritedEnabled = Parent->Enabled && Parent->InheritedEnabled;
        Label->Head.InheritedVisible = Parent->Visible && Parent->InheritedVisible;

        Label->ForeColor = ForeColor;

        GDI_UpdateTextExtent(&Caption);
        Label->Caption = Caption;
        Label->Caption.Color.BackColor = Label->ForeColor;

        if (!ObjectsList->Count) Result = DL_AddItem(ObjectsList, Label) != NULL;
        else
        {
            pDLITEM tmpDLItem;

            GUI_GetTopNoWindowObject(Parent, &tmpDLItem);

            Result = ((tmpDLItem == NULL) ?
                      DL_AddItemAtIndex(ObjectsList, 0, Label) :
                      DL_InsertItemAfter(ObjectsList, tmpDLItem, Label)) != NULL;
        }

        if (Result)
        {
            Label->Head.Type = GO_LABEL;
            if (Label->Head.Visible && Label->Head.InheritedVisible)
                GUI_Invalidate((pGUIOBJECT)Label, NULL);
        }
        else
        {
            free(Label);
            Label = NULL;
        }
    }
    return (pGUIOBJECT)Label;
}

void GUI_DestroyLabel(pGUIOBJECT Object)
{
    if ((Object != NULL) && (Object->Type == GO_LABEL))
    {
        pLABEL   Label = (pLABEL)Object;

        if ((Label->Caption.Font != NULL) && (IsDynamicMemory(Label->Caption.Font)))
            free(Label->Caption.Font);
        Label->Caption.Font = NULL;

        if ((Label->Caption.Text != NULL) && (IsDynamicMemory(Label->Caption.Text)))
            free(Label->Caption.Text);
        Label->Caption.Text = NULL;
    }
}

pTEXT GUI_GetTextLabel(pGUIOBJECT Object)
{
    if ((Object != NULL) && (Object->Type == GO_LABEL))
    {
        ((pLABEL)Object)->Caption.Color.BackColor = ((pLABEL)Object)->ForeColor;

        return &((pLABEL)Object)->Caption;
    }
    else return NULL;
}

boolean GUI_SetTextLabel(pGUIOBJECT Object, pTEXT ObjectText)
{
    if ((Object != NULL) && (Object->Type == GO_LABEL) && (ObjectText != NULL))
    {
        ((pLABEL)Object)->Caption = *ObjectText;
        ((pLABEL)Object)->Caption.Color.BackColor = ((pLABEL)Object)->ForeColor;

        return true;
    }
    return false;
}
