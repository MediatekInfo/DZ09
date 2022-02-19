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
#include "guibutton.h"

#define BUTTONLONGDELAY             1000
#define BUTTONAUTOREPEAT            75

static pTIMER     ButtonTimer;
static pGUIOBJECT ArepeatButton;
static boolean    ButtonDelayDone;

static void GUI_DisableButtonTimer(void)
{
    LRT_Stop(ButtonTimer);
    LRT_Destroy(ButtonTimer);
    ButtonTimer = NULL;
    ArepeatButton = NULL;
}

static void GUI_ButtonTimerHandler(pTIMER Timer)
{
    if (((uintptr_t)GUI_GetObjectActive() == (uintptr_t)ArepeatButton) &&
            ((pBUTTON)ArepeatButton)->Autorepeat && (ArepeatButton->OnClick != NULL))
    {
        TPOINT DummyPoint = {0};

        if (!ButtonDelayDone)
        {
            ButtonDelayDone = true;
            LRT_SetInterval(Timer, BUTTONAUTOREPEAT);
        }
        ArepeatButton->OnClick(ArepeatButton, &DummyPoint);
    }
    else GUI_DisableButtonTimer();
}

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
            pRLIST BackRects = GDI_DrawText(((pWIN)Button->Head.Parent)->Layer,
                                            &Button->Caption,
                                            &ButtonRect,
                                            Clip,
                                            (Button->Head.Enabled && Button->Head.InheritedEnabled) ?
                                            Button->Caption.Color.ForeColor : clGray,
                                            Button->Caption.Color.BackColor);
            if (BackRects != NULL)
            {
                uint32_t i;

                for(i = 0; i < BackRects->Count; i++)
                    GDI_FillRectangle(Layer, BackRects->Item[i], Button->ForeColor);

                GDI_DeleteRList(BackRects);
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

    if ((Parent == NULL) ||
            !GUI_IsWindowObject(Parent) || GUI_IsLayerObject(Parent)) return NULL;

    Button = malloc(sizeof(TBUTTON));
    if (Button != NULL)
    {
        pDLIST ObjectsList = &((pWIN)Parent)->ChildObjects;

        memset(Button, 0x00, sizeof(TBUTTON));

        NORMALIZEVAL(Position.l, Position.r);
        NORMALIZEVAL(Position.t, Position.b);

        Button->Head.Position = GDI_LocalToGlobalRct(&Position, &Parent->Position.lt);
        Button->Head.Parent = Parent;
        Button->Head.Enabled = !!(Flags & GF_ENABLED);
        Button->Head.Visible = !!(Flags & GF_VISIBLE);
        Button->Head.InheritedEnabled = Parent->Enabled && Parent->InheritedEnabled;
        Button->Head.InheritedVisible = Parent->Visible && Parent->InheritedVisible;

        Button->ForeColor = ForeColor;
        Button->Autorepeat = !!(Flags & GF_AUTOREPEAT);

        GDI_UpdateTextExtent(&Caption);
        Button->Caption = Caption;
        Button->Caption.Color.BackColor = Button->ForeColor;

        if (!ObjectsList->Count) Result = DL_AddItemPtr(ObjectsList, &Button->Head.ListHeader);
        else
        {
            pDLITEM tmpDLItem;

            GUI_GetTopNonWindowObject(Parent, &tmpDLItem);

            Result = (tmpDLItem == NULL) ?
                     DL_AddItemAtIndexPtr(ObjectsList, 0, &Button->Head.ListHeader) :
                     DL_InsertItemAfterPtr(ObjectsList, tmpDLItem, &Button->Head.ListHeader);
        }

        if (Result)
        {
            Button->Head.Type = GO_BUTTON;
            if (Button->Head.Visible && Button->Head.InheritedVisible)
                GUI_Invalidate((pGUIOBJECT)Button, NULL);
        }
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

        if ((Button->Caption.Font != NULL) && (IsDynamicMemory(Button->Caption.Font)))
            free(Button->Caption.Font);
        Button->Caption.Font = NULL;

        if ((Button->Caption.Text != NULL) && (IsDynamicMemory(Button->Caption.Text)))
            free(Button->Caption.Text);
        Button->Caption.Text = NULL;
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
        ((pBUTTON)Object)->Caption = *ObjectText;
        ((pBUTTON)Object)->Caption.Color.BackColor = ((pBUTTON)Object)->ForeColor;

        return true;
    }
    return false;
}

void GUI_SetActiveButton(pGUIOBJECT Object, boolean Active)
{
    if ((Object != NULL) && (Object->Type == GO_BUTTON))
    {
        ((pBUTTON)Object)->Pressed = Active;

        if (Active && ((pBUTTON)Object)->Autorepeat)
        {
            ButtonDelayDone = false;
            ButtonTimer = LRT_Create(BUTTONLONGDELAY, GUI_ButtonTimerHandler, TF_AUTOREPEAT | TF_ENABLED);
            ArepeatButton = (ButtonTimer != NULL) ? Object : NULL;
        }
        else if (ButtonTimer != NULL)
            GUI_DisableButtonTimer();
    }
    return;
}

boolean GUI_GetActiveButton(pGUIOBJECT Object)
{
    return ((Object != NULL) && (Object->Type == GO_BUTTON)) ?
           ((pBUTTON)Object)->Pressed : false;
}
