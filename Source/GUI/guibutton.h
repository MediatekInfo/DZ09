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
#ifndef _GUIBUTTON__H_
#define _GUIBUTTON__H_

typedef struct tag_BUTTON
{
    TGUIOBJECT Head;
    TTEXT      Caption;
    boolean    Autorepeat;
    boolean    Pressed;
    TCOLOR     ForeColor;
} TBUTTON, *pBUTTON;

extern void GUI_DrawDefaultButton(pGUIOBJECT Object, pRECT Clip);
extern pGUIOBJECT GUI_CreateButton(pGUIOBJECT Parent, TRECT Position, TTEXT Caption,
                                   TCOLOR ForeColor, TGOFLAGS Flags);
extern void GUI_DestroyButton(pGUIOBJECT Object);
extern void GUI_CalcClientAreaButton(pGUIOBJECT Object, pRECT ClientArea);
extern pTEXT GUI_GetTextButton(pGUIOBJECT Object);
extern boolean GUI_SetTextButton(pGUIOBJECT Object, pTEXT ObjectText);
extern void GUI_SetActiveButton(pGUIOBJECT Object, boolean Active);
extern boolean GUI_GetActiveButton(pGUIOBJECT Object);

#endif /* _GUIBUTTON__H_ */
