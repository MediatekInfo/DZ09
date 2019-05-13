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
#ifndef _GDI_H_
#define _GDI_H_

extern void GDI_FillRectangle(TVLINDEX Layer, TRECT Rct, uint32_t Color);
extern void GDI_DrawLine(TVLINDEX Layer, TPOINT P0, TPOINT P1, uint32_t Color);
extern void GDI_SetPixel(TVLINDEX Layer, TPOINT P, uint32_t Color);

#endif /* _GDI_H_ */
