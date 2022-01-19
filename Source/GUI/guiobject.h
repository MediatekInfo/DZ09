/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 - 2019 AJScorp
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
    boolean    InheritedEnabled;
    boolean    InheritedVisible;
    int32_t    Tag;
    void       (*OnPress)(pGUIOBJECT, pPOINT);
    void       (*OnRelease)(pGUIOBJECT, pPOINT);
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
extern boolean GUI_SetObjectHandlerOnPress(pGUIOBJECT Object, void (*Handler)(pGUIOBJECT, pPOINT));
extern boolean GUI_SetObjectHandlerOnRelease(pGUIOBJECT Object, void (*Handler)(pGUIOBJECT, pPOINT));
extern boolean GUI_SetObjectHandlerOnMove(pGUIOBJECT Object, void (*Handler)(pGUIOBJECT, pPOINT));
extern boolean GUI_SetObjectHandlerOnClick(pGUIOBJECT Object, void (*Handler)(pGUIOBJECT, pPOINT));
extern boolean GUI_SetObjectHandlerOnPaint(pGUIOBJECT Object, void (*Handler)(pGUIOBJECT, pRECT));
extern boolean GUI_SetObjectHandlerOnDestroy(pGUIOBJECT Object, void (*Handler)(pGUIOBJECT));
extern boolean GUI_GetObjectPosition(pGUIOBJECT Object, pRECT Position);
extern boolean GUI_SetObjectPosition(pGUIOBJECT Object, pRECT Position);
extern boolean GUI_GetObjectVisibility(pGUIOBJECT Object);
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
extern pGUIOBJECT GUI_GetObjectActive(void);
extern void GUI_SetObjectActive(pGUIOBJECT Object, boolean Invalidate);
extern void GUI_UpdateActiveState(pGUIOBJECT Object, boolean Active, boolean Invalidate);

#endif /* _GUIOBJECT_H_ */
