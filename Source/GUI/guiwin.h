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

#ifndef _GUIWIN_H_
#define _GUIWIN_H_

typedef struct tag_WIN *pWIN;
typedef struct tag_WIN
{
    TGUIOBJECT  Head;
    boolean     Topmost;
    boolean     Framed;
    uint32_t    Layer;
    TCOLOR      ForeColor;
    TDLIST      ChildObjects;
    boolean     (*EventHandler)(pEVENT, pGUIOBJECT);
} TWIN, *pWIN;

extern pGUIOBJECT GUILayer[LCDIF_NUMLAYERS];

extern void GUI_DrawDefaultWindow(pGUIOBJECT Object, pRECT Clip);
extern boolean GUI_CreateLayer(TVLINDEX Layer, TRECT Position, TCFORMAT CFormat,
                               uint8_t GlobalAlpha, TCOLOR ForeColor);
extern pGUIOBJECT GUI_CreateWindow(pGUIOBJECT Parent, TRECT Position,
                                   boolean (*Handler)(pEVENT, pGUIOBJECT),
                                   TCOLOR ForeColor, TGOFLAGS Flags);
extern void GUI_DestroyWindow(pGUIOBJECT Object);
extern boolean GUI_IsLayerObject(pGUIOBJECT Object);
extern boolean GUI_IsWindowObject(pGUIOBJECT Object);
extern int32_t GUI_GetWindowZIndex(pGUIOBJECT Win);
extern pGUIOBJECT GUI_GetTopWindow(pGUIOBJECT Parent, boolean Topmost, pDLITEM *ObjectItem);
extern pGUIOBJECT GUI_MoveWindowTreeToTop(pGUIOBJECT Object);
extern void GUI_CalcClientAreaWindow(pGUIOBJECT Object, pRECT ClientArea);

#endif /* _GUIWIN_H_ */
