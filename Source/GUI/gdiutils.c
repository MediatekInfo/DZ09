// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "gdiutils.h"

TPOINT Point(int16_t x, int16_t y)
{
    TPOINT Result = {x, y};

    return Result;
}

TRECT Rect(int16_t l, int16_t t, int16_t r, int16_t b)
{
    TRECT Result = {l, t, r, b};

    return Result;
}

boolean IsRectsOverlaps(pRECT a, pRECT b)
{
    if ((a != NULL) && (b != NULL))
    {
        if ((a->l > b->r) || (a->r < b->l)) return false;
        if ((a->t > b->b) || (a->b < b->t)) return false;
        return true;
    }
    return false;
}

boolean IsPointInRect(int16_t x, int16_t y, pRECT Rct)
{
    return ((Rct != NULL) &&
            (x >= Rct->l) && (x <= Rct->r) &&
            (y >= Rct->t) && (y <= Rct->b)) ? true : false;
}

//a in b or b in a, a = larger rectangle
boolean IsRectInRect(pRECT a, pRECT b)
{
    if ((a == NULL) || (b == NULL)) return false;
    if (!IsRectsOverlaps(a, b)) return false;

    if (IsPointInRect(a->l, a->t, b) && IsPointInRect(a->r, a->t, b) &&
            IsPointInRect(a->l, a->b, b) && IsPointInRect(a->r, a->b, b))
    {
        memcpy(a, b, sizeof(TRECT));
        return true;
    }
    else if (IsPointInRect(b->l, b->t, a) && IsPointInRect(b->r, b->t, a) &&
             IsPointInRect(b->l, b->b, a) && IsPointInRect(b->r, b->b, a))
    {
        return true;
    }
    return false;
}

TPOINT GDI_LocalToGlobal(pPOINT pt, pPOINT Offset)
{
    TPOINT Res = {0};

    if (pt != NULL)
    {
        if (Offset != NULL)
        {
            Res.x = Offset->x + pt->x;
            Res.y = Offset->y + pt->y;
        }
        else
        {
            Res.x = pt->x;
            Res.y = pt->y;
        }
    }
    return Res;
}

TPOINT GDI_GlobalToLocal(pPOINT pt, pPOINT Offset)
{
    TPOINT Res = {0};

    if (pt != NULL)
    {
        if (Offset != NULL)
        {
            Res.x = pt->x - Offset->x;
            Res.y = pt->y - Offset->y;
        }
        else
        {
            Res.x = pt->x;
            Res.y = pt->y;
        }
    }
    return Res;
}

//a = a & b
boolean GDI_ANDRectangles(pRECT a, pRECT b)
{
    if ((a != NULL) && (b != NULL))
    {
        if (IsRectsOverlaps(a, b))
        {
            a->l = max(a->l, b->l);
            a->r = min(a->r, b->r);
            a->t = max(a->t, b->t);
            a->b = min(a->b, b->b);
            return true;
        }
    }
    return false;
}

//a + b
pDLIST GDI_ADDRectangles(pRECT a, pRECT b)
{
    pDLIST ResRects = NULL;
    pRECT  tmpRectA, tmpRectB;

    if ((a == NULL) || (b == NULL)) return NULL;
    if (!IsRectsOverlaps(a, b))
    {
        ResRects = DL_Create(0);
        if (ResRects != NULL)
        {
            tmpRectA = malloc(sizeof(TRECT));
            tmpRectB = malloc(sizeof(TRECT));
            if ((tmpRectA == NULL) || (tmpRectB == NULL))
            {
                if (tmpRectA != NULL) free(tmpRectA);
                if (tmpRectB != NULL) free(tmpRectB);
                free(ResRects);
                return NULL;
            }
            *tmpRectA = *a;
            *tmpRectB = *b;
            DL_AddItem(ResRects, tmpRectA);
            DL_AddItem(ResRects, tmpRectB);
        }
    }
    else
    {
        if (IsRectInRect(a, b))
        {
            tmpRectA = malloc(sizeof(TRECT));
            if (tmpRectA != NULL)
            {
                ResRects = DL_Create(0);
                *tmpRectA = *a;
                if (ResRects != NULL) DL_AddItem(ResRects, tmpRectA);
                else
                {
                    free(tmpRectA);
                    return NULL;
                }
            }
        }
        else
        {
            ResRects = GDI_SUBRectangles(a, b);
            if (ResRects == NULL) ResRects = DL_Create(0);
            if (ResRects != NULL)
            {
                tmpRectB = malloc(sizeof(TRECT));
                if (tmpRectB != NULL)
                {
                    *tmpRectB = *b;
                    DL_AddItem(ResRects, tmpRectB);
                }
            }
        }
    }
    return ResRects;
}

//a - b
pDLIST GDI_SUBRectangles(pRECT a, pRECT b)
{
    pDLIST Rlist = DL_Create(0);
    pRECT  Rct;

    if (Rlist == NULL) return NULL;
    if ((a == NULL) || (b == NULL)) return Rlist;

    if (!IsRectsOverlaps(a, b))
    {
        Rct = malloc(sizeof(TRECT));
        if (Rct != NULL)
        {
            *Rct = *a;
            DL_AddItem(Rlist, Rct);
        }
        return Rlist;
    }
    if (((b->l - a->l) > 0) && ((a->b - a->t) >= 0))
    {
        Rct = malloc(sizeof(TRECT));                                                                //Left vertical rectangle
        if (Rct != NULL)
        {
            Rct->l = a->l;
            Rct->t = a->t;
            Rct->r = b->l - 1;
            Rct->b = a->b;
            DL_AddItem(Rlist, Rct);
        }
    }
    if (((b->r - b->l) >= 0) && ((b->t - a->t) > 0))
    {
        Rct = malloc(sizeof(TRECT));                                                                //Top horizontal rectangle
        if (Rct != NULL)
        {
            Rct->l = max(a->l, b->l);
            Rct->t = a->t;
            Rct->r = min(a->r, b->r);
            Rct->b = b->t - 1;
            DL_AddItem(Rlist, Rct);
        }
    }
    if (((a->r - b->r) > 0) && ((a->b - a->t) >= 0))
    {
        Rct = malloc(sizeof(TRECT));                                                                //Right vertical rectangle
        if (Rct != NULL)
        {
            Rct->l = b->r + 1;
            Rct->t = a->t;
            Rct->r = a->r;
            Rct->b = a->b;
            DL_AddItem(Rlist, Rct);
        }
    }
    if (((b->r - b->l) >= 0) && ((a->b - b->b) > 0))
    {
        Rct = malloc(sizeof(TRECT));                                                                //Bottom horizontal rectangle
        if (Rct != NULL)
        {
            Rct->l = max(a->l, b->l);
            Rct->t = b->b + 1;
            Rct->r = min(a->r, b->r);
            Rct->b = a->b;
            DL_AddItem(Rlist, Rct);
        }
    }
    return Rlist;
}

boolean GDI_ADDRectToRegion(pDLIST Region, pRECT Rct)
{
    pRECT tmpRect;

    if ((Region == NULL) || (Rct == NULL)) return false;

    if (DL_GetItemsCount(Region))
    {
        pDLITEM tmpItem = DL_GetFirstItem(Region);

        while(tmpItem != NULL)
        {
            pRECT tmpRect = (pRECT)tmpItem->Data;

            if (IsRectsOverlaps(tmpRect, Rct))
            {
                pDLIST tmpList = GDI_SUBRectangles(tmpRect, Rct);

                if (tmpList != NULL)
                {
                    pDLITEM tmpSUBItem;

                    if (DL_GetItemsCount(tmpList))
                    {
                        tmpSUBItem = DL_GetFirstItem(tmpList);

                        *tmpRect = *(pRECT)tmpSUBItem->Data;
                        free(tmpSUBItem->Data);
                        DL_DeleteFirstItem(tmpList);

                        while((tmpSUBItem = DL_GetFirstItem(tmpList)) != NULL)
                        {
                            DL_InsertItemBefore(Region, tmpItem, tmpSUBItem->Data);
                            DL_DeleteFirstItem(tmpList);
                        }
                    }
                    else
                    {
                        tmpSUBItem = DL_GetNextItem(tmpItem);

                        DL_DeleteItem(Region, tmpItem);
                        free(tmpItem->Data);
                        free(tmpItem);

                        tmpItem = tmpSUBItem;
                        free(tmpList);
                        continue;
                    }
                    free(tmpList);
                }
            }
            tmpItem = DL_GetNextItem(tmpItem);
        }
    }
    tmpRect = malloc(sizeof(TRECT));
    if (tmpRect != NULL)
    {
        *tmpRect = *Rct;
        DL_AddItem(Region, tmpRect);
        return true;
    }
    return false;
}

boolean GDI_SUBRectFromRegion(pDLIST Region, pRECT Rct)
{
    if ((Region == NULL) || (Rct == NULL)) return false;

    if (DL_GetItemsCount(Region))
    {
        pDLITEM tmpItem = DL_GetFirstItem(Region);

        while(tmpItem != NULL)
        {
            pRECT tmpRect = (pRECT)tmpItem->Data;

            if (IsRectsOverlaps(tmpRect, Rct))
            {
                pDLIST tmpList = GDI_SUBRectangles(tmpRect, Rct);

                if (tmpList != NULL)
                {
                    pDLITEM tmpSUBItem;

                    if (DL_GetItemsCount(tmpList))
                    {
                        tmpSUBItem = DL_GetFirstItem(tmpList);

                        *tmpRect = *(pRECT)tmpSUBItem->Data;
                        free(tmpSUBItem->Data);
                        DL_DeleteFirstItem(tmpList);

                        while((tmpSUBItem = DL_GetFirstItem(tmpList)) != NULL)
                        {
                            DL_InsertItemBefore(Region, tmpItem, tmpSUBItem->Data);
                            DL_DeleteFirstItem(tmpList);
                        }
                    }
                    else
                    {
                        tmpSUBItem = DL_GetNextItem(tmpItem);

                        DL_DeleteItem(Region, tmpItem);
                        free(tmpItem->Data);
                        free(tmpItem);

                        tmpItem = tmpSUBItem;
                        free(tmpList);
                        continue;
                    }
                    free(tmpList);
                }
            }
            tmpItem = DL_GetNextItem(tmpItem);
        }
    }
    else return false;

    return true;
}

uint8_t *GDI_GetPixelPtr(pLCONTEXT lc, TPOINT pt)
{
    uint8_t *p = (uint8_t *)lc->FrameBuffer;

    return &p[(pt.y * (lc->LayerRgn.r - lc->LayerRgn.l + 1) + pt.x) * lc->BPP];
}

void GDI_FillRectangleX(pLCONTEXT lc, pRECT Rct, uint32_t Color)
{
    int32_t  x, y, dpx;

    if ((lc == NULL) || (Rct == NULL) || (lc->FrameBuffer == NULL)) return;

    switch (lc->ColorFormat)
    {
    case CF_RGB565:
    {
        uint16_t *p = (uint16_t *)GDI_GetPixelPtr(lc, Rct->lt);

        Color = RGB_565(Color);
        dpx = (lc->LayerRgn.r + 1) - (Rct->r - Rct->l + 1);
        for(y = Rct->t; y <= Rct->b; y++)
        {
            for(x = Rct->l; x <= Rct->r; x++) *p++ = Color;
            p += dpx;
        }
    }
    break;
    case CF_ARGB8888:
    case CF_PARGB8888:
    case CF_xRGB8888:
    {
        uint32_t *p = (uint32_t *)GDI_GetPixelPtr(lc, Rct->lt);

        dpx = (lc->LayerRgn.r + 1) - (Rct->r + 1 - Rct->l);
        for(y = Rct->t; y <= Rct->b; y++)
        {
            for(x = Rct->l; x <= Rct->r; x++) *p++ = Color;
            p += dpx;
        }
    }
    break;
    default:
        break;
    }
    return;
}
