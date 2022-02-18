/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2021 - 2019 AJScorp
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
#ifndef _GDITYPES_H_
#define _GDITYPES_H_

typedef enum tag_COLOR
{
    clBlack         = 0xFF000000,
    clBrown         = 0xFF003366,
    clMaroon        = 0xFF000080,
    clGreen         = 0xFF008000,
    clOlive         = 0xFF008080,
    clDarkBlue      = 0xFF400000,
    clDarkGray      = 0xFF404040,
    clNavy          = 0xFF800000,
    clPurple        = 0xFF800080,
    clTeal          = 0xFF808000,
    clGray          = 0xFF808080,
    clSilver        = 0xFFC0C0C0,
    clRed           = 0xFF0000FF,
    clMidGreen      = 0xFF00C000,
    clLime          = 0xFF00FF00,
    clYellow        = 0xFF00FFFF,
    clBlue          = 0xFFFF0000,
    clFuchsia       = 0xFFFF00FF,
    clAqua          = 0xFFFFFF00,
    clWhite         = 0xFFFFFFFF,
    clMoneyGreen    = 0xFFC0DCC0,
    clSkyBlue       = 0xFFF0C8A4,
    clCream         = 0xFFF0F8FC,
    clMedGray       = 0xFFA4A0A0,
    clBtnFace       = 0xFFC8D0D4
} TCOLOR;

typedef enum tag_CFORMAT
{
    CF_8IDX,                                                                                        // 1BPP
    CF_RGB565,                                                                                      // 2BPP
    CF_YUYV422,                                                                                     // Not supported
    CF_RGB888,                                                                                      // 3BPP
    CF_ARGB8888,                                                                                    // 4BPP
    CF_PARGB8888,                                                                                   // 4BPP
    CF_xRGB8888,                                                                                    // 4BPP
    CF_NUM
} TCFORMAT, *pCFORMAT;

#define clAlpha(c, alpha)   (((c) & 0x00FFFFFF) | (((alpha) & 0xFF) << 24))

typedef struct tag_POINT
{
    int16_t x;
    int16_t y;
} TPOINT, *pPOINT;

typedef union tag_RECT
{
    struct
    {
        TPOINT  lt;
        TPOINT  rb;
    };
    struct
    {
        int16_t l;
        int16_t t;
        int16_t r;
        int16_t b;
    };
} TRECT, *pRECT;

typedef struct tag_RECTITEM
{
    TDLITEM ListHeader;
    TRECT   Rct;
} TRECTITEM, *pRECTITEM;

typedef struct tag_SIZEXY
{
    uint16_t sx;
    uint16_t sy;
} TSIZEXY, *pSIZEXY;

typedef struct tag_RLIST
{
    uint32_t Count;
    TRECT    Item[4];
} TRLIST, *pRLIST;

#endif /* _GDITYPES_H_ */
