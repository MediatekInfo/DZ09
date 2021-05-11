/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2021 AJScorp
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
#ifndef _GUILABEL__H_
#define _GUILABEL__H_

typedef struct tag_LABEL
{
    TGUIOBJECT Head;
    TTEXT      Caption;
    TCOLOR     ForeColor;
} TLABEL, *pLABEL;

extern void GUI_DrawDefaultLabel(pGUIOBJECT Object, pRECT Clip);
extern pGUIOBJECT GUI_CreateLabel(pGUIOBJECT Parent, TRECT Position, TTEXT Caption,
                                   TCOLOR ForeColor, TGOFLAGS Flags);
extern void GUI_DestroyLabel(pGUIOBJECT Object);
extern pTEXT GUI_GetTextLabel(pGUIOBJECT Object);
extern boolean GUI_SetTextLabel(pGUIOBJECT Object, pTEXT ObjectText);

#endif /* _GUILABEL__H_ */
