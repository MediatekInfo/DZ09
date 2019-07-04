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
    GF_TOPMOST  = (1 << 2)
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
    TSYSOBJECT  SOType;
    boolean     Topmost;
    uint32_t    Layer;
    uint32_t    ForeColor;
    TDLIST      ChildObjects;
    boolean     (*EventHandler)(pEVENT, pWIN);
} TWIN, *pWIN;

extern pWIN GUI_CreateWindow(pGUIHEADER Parent, TRECT Position, boolean (*Handler)(pEVENT, pWIN),
                             uint8_t Layer, uint32_t ForeColor, TGOFLAGS Flags);
extern void GDI_DrawObjectDefault(pGUIHEADER Object, pRECT ClipRect, pPOINT GlbShift);

#endif /* _GUIOBJECT_H_ */
