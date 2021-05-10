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
#ifndef _GDIFONT_H_
#define _GDIFONT_H_

#include "bfcfont.h"

typedef enum tag_TXTALIGN
{
    AH_LEFT     = (0 << 0),
    AH_RIGHT    = (1 << 0),
    AH_CENTER   = (2 << 0),
    AH_MASK     = (3 << 0),
    AV_TOP      = (0 << 2),
    AV_BOTTOM   = (1 << 2),
    AV_CENTER   = (2 << 2),
    AV_MASK     = (3 << 2)
} TTXTALIGN;

typedef struct tag_TEXTCOLOR
{
    TCOLOR  ForeColor;
    TCOLOR  BackColor;
} TTEXTCOLOR, *pTEXTCOLOR;

typedef struct tag_TEXT
{
    TSIZEXY     Extent;
    TTXTALIGN   Align;
    TTEXTCOLOR  Color;
    pBFC_FONT   Font;
    char        *Text;
} TTEXT, *pTEXT;

extern TTEXTCOLOR TextColor(TCOLOR ForeColor, TCOLOR BackColor);
extern TTEXT Text(const BFC_FONT *Font, char *Caption, TTXTALIGN Align, TTEXTCOLOR Color);
extern void GDI_UpdateTextExtent(pTEXT Text);
extern char *GDI_GetStringPosByXShift(pBFC_CHARINFO *CharInfo, pTEXT Text, int32_t ReqXShift,
                                      uint32_t *DataBitIndex);
extern pDLIST GDI_DrawText(TVLINDEX Layer, pTEXT Text, pRECT Client, pRECT Clip,
                           TCOLOR ForeColor, TCOLOR BackColor);
#endif /* _GDIFONT_H_ */
