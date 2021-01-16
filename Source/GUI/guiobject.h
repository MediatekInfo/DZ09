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
#ifndef _GUIOBJECT_H_
#define _GUIOBJECT_H_

typedef enum tag_GOTYPE
{
    GO_UNKNOWN,
    GO_WINDOW,

    GO_NUMTYPES
} TGOTYPE;

typedef enum tag_GOFLAGS
{
    GF_ENABLED  = (1 << 0),
    GF_VISIBLE  = (1 << 1),
    GF_TOPMOST  = (1 << 2),
    GF_FRAMED   = (1 << 3)
} TGOFLAGS;

typedef struct tag_GUIHEADER *pGUIHEADER;
typedef struct tag_GUIHEADER
{
    TRECT      Position;
    pGUIHEADER Parent;
    TGOTYPE    Type;
    boolean    Enabled;
    boolean    Visible;
    int32_t    Tag;
    void       (*OnPressed)(pGUIHEADER, pPOINT);
    void       (*OnReleased)(pGUIHEADER, pPOINT);
    void       (*OnMove)(pGUIHEADER, pPOINT);
    void       (*OnClick)(pGUIHEADER, pPOINT);
    void       (*OnPaint)(pGUIHEADER, pRECT);
} TGUIHEADER, *pGUIHEADER;

typedef struct tag_WIN *pWIN;
typedef struct tag_WIN
{
    TGUIHEADER  Head;
    boolean     Topmost;
    boolean     Framed;
    uint32_t    Layer;
    uint32_t    ForeColor;
    TDLIST      ChildObjects;
    boolean     (*EventHandler)(pEVENT, pWIN);
} TWIN, *pWIN;

typedef TWIN   TGUILAYER;
typedef pWIN   pGUILAYER;

extern pGUILAYER GUILayer[LCDIF_NUMLAYERS];

extern TRECT GUI_CalculateClientArea(pGUIHEADER Object);
extern boolean GUI_GetObjectPosition(pGUIHEADER Object, pRECT Position);
extern void GUI_SetObjectPosition(pGUIHEADER Object, pRECT Position);
extern boolean GUI_GetObjectVisibilty(pGUIHEADER Object);
extern boolean GUI_SetObjectVisibility(pGUIHEADER Object, boolean Visible);
extern boolean GUI_IsWindowObject(pGUIHEADER Object);
extern boolean GUI_CreateLayer(TVLINDEX Layer, TRECT Position, TCFORMAT CFormat,
                               uint8_t GlobalAlpha, uint32_t ForeColor);
extern pWIN GUI_CreateWindow(pGUIHEADER Parent, TRECT Position, boolean (*Handler)(pEVENT, pWIN),
                             uint8_t Layer, uint32_t ForeColor, TGOFLAGS Flags);
extern void GUI_DrawObjectDefault(pGUIHEADER Object, pRECT Clip);
extern void GUI_DestroyObject(pGUIHEADER Object);

#endif /* _GUIOBJECT_H_ */
