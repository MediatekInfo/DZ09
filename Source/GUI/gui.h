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
#ifndef _GUI_H_
#define _GUI_H_

typedef struct tag_PENEVENT
{
    uint32_t PenIndex;
    TPOINT   PXY;
} TPENEVENT, *pPENEVENT;

typedef struct tag_PAINTEV
{
    pGUIOBJECT Object;
    TRECT      UpdateRect;
    TVLINDEX   Layer;
} TPAINTEV, *pPAINTEV;

extern boolean GUI_Initialize(void);
extern void GUI_Invalidate(pGUIOBJECT Object, pRECT Rct);
extern void GUI_OnPaintHandler(pPAINTEV Event);

#endif /* _GUI_H_ */
