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

static boolean GUI_IsObjectVisibleBackwards(pPAINTEV PEvent)
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

            PEvent->UpdateRect.lt = GDI_LocalToGlobal(&PEvent->UpdateRect.lt, &ParentBase);
            PEvent->UpdateRect.rb = GDI_LocalToGlobal(&PEvent->UpdateRect.rb, &ParentBase);
            tmpPoint = GDI_LocalToGlobal(&tmpPoint, &Object->Parent->Position.lt);

            IsStillVisible = Object->Visible &&
                             GDI_ANDRectangles(&PEvent->UpdateRect, &Object->Parent->Position) &&
                             (Object->Parent->Type == GO_WINDOW);                                   // Only a TWIN object can be a parent.

            Object = Object->Parent;
        }
    }
    if (IsStillVisible)
    {
        PEvent->RootParent = Object;
        PEvent->GlobalShift = tmpPoint;
    }

    return IsStillVisible;
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

        if (GUI_IsObjectVisibleBackwards(&PaintEvent))
            EM_PostEvent(ET_ONPAINT, NULL, &PaintEvent, sizeof(TPAINTEV));
    }
    else
    {
        PaintEvent.UpdateRect = (Rct != NULL) ? *Rct : LCDScreen.ScreenRgn;

        EM_PostEvent(ET_ONPAINT, NULL, &PaintEvent, sizeof(TPAINTEV));
    }
}


