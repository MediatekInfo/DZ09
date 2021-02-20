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

typedef struct tag_GUIOBJECT *pGUIOBJECT;
typedef struct tag_GUIOBJECT
{
    TRECT      Position;
    pGUIOBJECT Parent;
    TGOTYPE    Type;
    boolean    Enabled;
    boolean    Visible;
    int32_t    Tag;
    void       (*OnPressed)(pGUIOBJECT, pPOINT);
    void       (*OnReleased)(pGUIOBJECT, pPOINT);
    void       (*OnMove)(pGUIOBJECT, pPOINT);
    void       (*OnClick)(pGUIOBJECT, pPOINT);
    void       (*OnPaint)(pGUIOBJECT, pRECT);
    void       (*OnDestroy)(pGUIOBJECT);
} TGUIOBJECT, *pGUIOBJECT;

#include "guiwin.h"

extern TRECT GUI_CalculateClientArea(pGUIOBJECT Object);
extern boolean GUI_GetObjectPosition(pGUIOBJECT Object, pRECT Position);
extern void GUI_SetObjectPosition(pGUIOBJECT Object, pRECT Position);
extern boolean GUI_GetObjectVisibilty(pGUIOBJECT Object);
extern boolean GUI_SetObjectVisibility(pGUIOBJECT Object, boolean Visible);
extern void GUI_DrawObjectDefault(pGUIOBJECT Object, pRECT Clip);
extern void *GUI_DestroyObject(pGUIOBJECT Object);

#endif /* _GUIOBJECT_H_ */
