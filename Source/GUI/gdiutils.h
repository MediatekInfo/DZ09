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
#ifndef _GDIUTILS_H_
#define _GDIUTILS_H_

#define RGB_565(v)                  ((((v) & 0xF80000) >> 8) | (((v) & 0xFC00) >> 5) | ((v) & 0x1F))
#define NORMALIZEVAL(c0, c1)        do\
                                    {\
                                        typeof(c0) tval;\
\
                                        if (c0 > c1)\
                                        {\
                                            tval = c0;\
                                            c0 = c1;\
                                            c1 = tval;\
                                        }\
                                    }\
                                    while(0)

extern TPOINT Point(int16_t x, int16_t y);
extern TRECT Rect(int16_t l, int16_t t, int16_t r, int16_t b);
extern TSIZEXY SizeXY(uint16_t sx, uint16_t sy);
extern boolean IsRectsOverlaps(pRECT a, pRECT b);
extern boolean IsPointInRect(pPOINT Pt, pRECT Rct);
extern boolean IsRectCollapsed(pRECT rct);
extern pRLIST GDI_CreateRList(void);
extern pRLIST GDI_DeleteRList(pRLIST RList);
extern TPOINT GDI_LocalToGlobalPt(pPOINT pt, pPOINT Offset);
extern TPOINT GDI_GlobalToLocalPt(pPOINT pt, pPOINT Offset);
extern TRECT GDI_LocalToGlobalRct(pRECT rct, pPOINT Offset);
extern TRECT GDI_GlobalToLocalRct(pRECT rct, pPOINT Offset);
extern TPOINT GDI_ScreenToLayerPt(TVLINDEX Layer, pPOINT pt);
extern boolean GDI_ANDRectangles(pRECT a, pRECT b);
extern pDLIST GDI_ADDRectangles(pRECT a, pRECT b);
extern pRLIST GDI_SUBRectangles(pRECT a, pRECT b);
extern boolean GDI_ADDRectToRegion(pDLIST Region, pRECT Rct);
extern boolean GDI_SUBRectFromRegion(pDLIST Region, pRECT Rct);
extern void GDI_FillRectangleX(pLCONTEXT lc, pRECT Rct, TCOLOR Color);

#endif /* _GDIUTILS_H_ */
