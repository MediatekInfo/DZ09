/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2021, 2020, 2019 AJScorp
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
    GO_BUTTON,
    GO_LABEL,

    GO_NUMTYPES
} TGOTYPE;

typedef enum tag_GOFLAGS
{
    GF_ENABLED    = (1 << 0),
    GF_VISIBLE    = (1 << 1),
    GF_TOPMOST    = (1 << 2),
    GF_FRAMED     = (1 << 3),
    GF_AUTOREPEAT = (1 << 4)
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
#include "guibutton.h"
#include "guilabel.h"

extern TRECT GUI_CalculateClientArea(pGUIOBJECT Object);
extern pGUIOBJECT GUI_GetObjectFromPoint(pPOINT pt, pGUIOBJECT *RootParent);
extern pGUIOBJECT GUI_GetTopNoWindowObject(pGUIOBJECT Parent, pDLITEM *ObjectItem);
extern boolean GUI_GetObjectPosition(pGUIOBJECT Object, pRECT Position);
extern boolean GUI_SetObjectPosition(pGUIOBJECT Object, pRECT Position);
extern boolean GUI_GetObjectVisibilty(pGUIOBJECT Object);
extern boolean GUI_SetObjectVisibility(pGUIOBJECT Object, boolean Visible);
extern pTEXT GUI_GetObjectText(pGUIOBJECT Object);
extern boolean GUI_SetObjectText(pGUIOBJECT Object, TTEXT ObjectText);
extern pBFC_FONT GUI_GetObjectFont(pGUIOBJECT Object);
extern boolean GUI_SetObjectFont(pGUIOBJECT Object, pBFC_FONT ObjectFont);
extern pTEXTCOLOR GUI_GetObjectTextColor(pGUIOBJECT Object);
extern boolean GUI_SetObjecTextColor(pGUIOBJECT Object, TTEXTCOLOR Color);
extern char *GUI_GetObjectCaption(pGUIOBJECT Object);
extern boolean GUI_SetObjectCaption(pGUIOBJECT Object, char *Caption);
extern void GUI_DrawObjectDefault(pGUIOBJECT Object, pRECT Clip);
extern void *GUI_DestroyObject(pGUIOBJECT Object);

#endif /* _GUIOBJECT_H_ */
