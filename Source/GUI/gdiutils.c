// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "gdiutils.h"

static void GDI_MergeRectsInRegion(pDLIST Region)
{
    pDLITEM ModItem, CmpItem;
    pRECT   ModRect, CmpRect;

    if ((Region == NULL) || (DL_GetItemsCount(Region) <= 1)) return;

    ModItem = DL_GetFirstItem(Region);
    CmpItem = DL_GetNextItem(ModItem);

    while((ModItem != NULL) && (CmpItem != NULL))
    {
        ModRect = (pRECT)ModItem->Data;
        while ((ModRect != NULL) && (CmpItem != NULL))
        {
            CmpRect = (pRECT)CmpItem->Data;

            if ((CmpRect != NULL) && (ModRect->t == CmpRect->t) && (ModRect->b == CmpRect->b) &&
                    ((ModRect->l - CmpRect->r == 1) || (CmpRect->l - ModRect->r == 1)))
            {
                pDLITEM tmpItem = DL_GetNextItem(CmpItem);

                ModRect->l = min(ModRect->l, CmpRect->l);
                ModRect->r = max(ModRect->r, CmpRect->r);

                free(CmpRect);
                DL_DeleteItem(Region, CmpItem);
                CmpItem = tmpItem;
                continue;
            }
            CmpItem = DL_GetNextItem(CmpItem);
        }
        ModItem = DL_GetNextItem(ModItem);
        CmpItem = DL_GetNextItem(ModItem);
    }
}

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

TSIZEXY SizeXY(uint16_t sx, uint16_t sy)
{
    TSIZEXY Result;

    Result.sx = sx;
    Result.sy = sy;

    return Result;
}

boolean IsRectsOverlaps(pRECT a, pRECT b)
{
    if ((a != NULL) && (b != NULL))
    {
        if ((a->l > a->r) || (a->t > a->b)) return false;
        if ((b->l > b->r) || (b->t > b->b)) return false;
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

// a in b or b in a, a = larger rectangle
boolean IsRectInRect(pRECT a, pRECT b)
{
    if ((a == NULL) || (b == NULL)) return false;
    if (!IsRectsOverlaps(a, b)) return false;

    if (IsPointInRect(a->l, a->t, b) && IsPointInRect(a->r, a->b, b))
    {
        memcpy(a, b, sizeof(TRECT));
        return true;
    }
    else if (IsPointInRect(b->l, b->t, a) && IsPointInRect(b->r, b->b, a))
    {
        return true;
    }
    return false;
}

boolean IsRectCollapsed(pRECT rct)
{
    return (rct == NULL) ||
           (rct->l > rct->r) || (rct->t > rct->b);
}

pRLIST GDI_CreateRList(void)
{
    pRLIST tmpRList = malloc(sizeof(TRLIST));

    if (tmpRList != NULL)
        tmpRList->Count = 0;

    return tmpRList;
}

pRLIST GDI_DeleteRList(pRLIST RList)
{
    free(RList);

    return NULL;
}

TPOINT GDI_LocalToGlobalPt(pPOINT pt, pPOINT Offset)
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

TPOINT GDI_GlobalToLocalPt(pPOINT pt, pPOINT Offset)
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

TRECT GDI_LocalToGlobalRct(pRECT rct, pPOINT Offset)
{
    TRECT Res = {0};

    if (rct != NULL)
    {
        if (Offset != NULL)
        {
            Res.l = Offset->x + rct->l;
            Res.t = Offset->y + rct->t;
            Res.r = Offset->x + rct->r;
            Res.b = Offset->y + rct->b;
        }
        else
        {
            Res.l = rct->l;
            Res.t = rct->t;
            Res.r = rct->l;
            Res.b = rct->t;
        }
    }
    return Res;
}

TRECT GDI_GlobalToLocalRct(pRECT rct, pPOINT Offset)
{
    TRECT Res = {0};

    if (rct != NULL)
    {
        if (Offset != NULL)
        {
            Res.l = rct->l - Offset->x;
            Res.t = rct->t - Offset->y;
            Res.r = rct->r - Offset->x;
            Res.b = rct->b - Offset->y;
        }
        else
        {
            Res.l = rct->l;
            Res.t = rct->t;
            Res.r = rct->l;
            Res.b = rct->t;
        }
    }
    return Res;
}

TPOINT GDI_ScreenToLayerPt(TVLINDEX Layer, pPOINT pt)
{
    TPOINT Res;

    if ((pt == NULL) || (Layer >= LCDIF_NUMLAYERS) || (GUILayer[Layer] != NULL))
        Res = *pt;
    else
    {
        Res.x = pt->x + LCDScreen.ScreenOffset.x - LCDScreen.VLayer[Layer].LayerOffset.x;
        Res.y = pt->y + LCDScreen.ScreenOffset.y - LCDScreen.VLayer[Layer].LayerOffset.y;
    }
    return Res;
}

// a = a & b
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

// a + b
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
                free(tmpRectA);
                free(tmpRectB);
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
            pRLIST tmpRList = GDI_SUBRectangles(a, b);

            if (tmpRList != NULL)
            {
                if (tmpRList->Count &&
                        ((ResRects = DL_Create(0)) != NULL))
                {
                    uint32_t i;

                    for(i = 0; i < tmpRList->Count; i++)
                    {
                        tmpRectB = malloc(sizeof(TRECT));
                        if (tmpRectB != NULL)
                        {
                            *tmpRectB = tmpRList->Item[i];
                            DL_AddItem(ResRects, tmpRectB);
                        }
                    }
                    tmpRectB = malloc(sizeof(TRECT));
                    if (tmpRectB != NULL)
                    {
                        *tmpRectB = *b;
                        DL_AddItem(ResRects, tmpRectB);
                    }
                }
                free(tmpRList);
            }
        }
    }
    return ResRects;
}

// a - b
pRLIST GDI_SUBRectangles(pRECT a, pRECT b)
{
    pRLIST Rlist = GDI_CreateRList();
    pRECT  Rct;

    if (Rlist == NULL) return NULL;
    if ((a == NULL) || (b == NULL)) return Rlist;

    if (!IsRectsOverlaps(a, b))
    {
        Rlist->Item[Rlist->Count++] = *a;

        return Rlist;
    }
    if (((b->l - a->l) > 0) && ((a->b - a->t) >= 0))
    {
        /* Left vertical rectangle */
        Rlist->Item[Rlist->Count].l = a->l;
        Rlist->Item[Rlist->Count].t = a->t;
        Rlist->Item[Rlist->Count].r = b->l - 1;
        Rlist->Item[Rlist->Count].b = a->b;
        Rlist->Count++;
    }
    if (((b->r - b->l) >= 0) && ((b->t - a->t) > 0))
    {
        /* Top horizontal rectangle */
        Rlist->Item[Rlist->Count].l = max(a->l, b->l);
        Rlist->Item[Rlist->Count].t = a->t;
        Rlist->Item[Rlist->Count].r = min(a->r, b->r);
        Rlist->Item[Rlist->Count].b = b->t - 1;
        Rlist->Count++;
    }
    if (((a->r - b->r) > 0) && ((a->b - a->t) >= 0))
    {
        /* Right vertical rectangle */
        Rlist->Item[Rlist->Count].l = b->r + 1;
        Rlist->Item[Rlist->Count].t = a->t;
        Rlist->Item[Rlist->Count].r = a->r;
        Rlist->Item[Rlist->Count].b = a->b;
        Rlist->Count++;
    }
    if (((b->r - b->l) >= 0) && ((a->b - b->b) > 0))
    {
        /* Bottom horizontal rectangle */
        Rlist->Item[Rlist->Count].l = max(a->l, b->l);
        Rlist->Item[Rlist->Count].t = b->b + 1;
        Rlist->Item[Rlist->Count].r = min(a->r, b->r);
        Rlist->Item[Rlist->Count].b = a->b;
        Rlist->Count++;
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
            tmpRect = (pRECT)tmpItem->Data;

            if (IsRectsOverlaps(tmpRect, Rct))
            {
                pRLIST tmpList = GDI_SUBRectangles(tmpRect, Rct);

                if (tmpList != NULL)
                {
                    if (tmpList->Count)
                    {
                        uint32_t i;

                        *tmpRect = tmpList->Item[0];

                        for(i = 1; i < tmpList->Count; i++)
                        {
                            if ((tmpRect = malloc(sizeof(TRECT))) != NULL)
                            {
                                *tmpRect = tmpList->Item[i];
                                DL_InsertItemBefore(Region, tmpItem, tmpRect);
                            }
                        }
                    }
                    else
                    {
                        pDLITEM tmpSUBItem = DL_GetNextItem(tmpItem);

                        free(tmpItem->Data);
                        DL_DeleteItem(Region, tmpItem);

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
        if (DL_AddItem(Region, tmpRect) == NULL) free(tmpRect);
        else return true;
    }
    return false;
}

boolean GDI_SUBRectFromRegion(pDLIST Region, pRECT Rct)
{
    if (Region == NULL) return false;

    if (DL_GetItemsCount(Region) && (Rct != NULL))
    {
        pDLITEM tmpItem = DL_GetFirstItem(Region);

        while(tmpItem != NULL)
        {
            pRECT tmpRect = (pRECT)tmpItem->Data;

            if (IsRectsOverlaps(tmpRect, Rct))
            {
                pRLIST tmpList = GDI_SUBRectangles(tmpRect, Rct);

                if (tmpList != NULL)
                {
                    if (tmpList->Count)
                    {
                        uint32_t i;

                        *tmpRect = tmpList->Item[0];

                        for(i = 1; i < tmpList->Count; i++)
                        {
                            if ((tmpRect = malloc(sizeof(TRECT))) != NULL)
                            {
                                *tmpRect = tmpList->Item[i];
                                DL_InsertItemBefore(Region, tmpItem, tmpRect);
                            }
                        }
                    }
                    else
                    {
                        pDLITEM tmpSUBItem = DL_GetNextItem(tmpItem);

                        free(tmpItem->Data);
                        DL_DeleteItem(Region, tmpItem);

                        tmpItem = tmpSUBItem;
                        free(tmpList);
                        continue;
                    }
                    free(tmpList);
                }
            }
            tmpItem = DL_GetNextItem(tmpItem);
        }
        GDI_MergeRectsInRegion(Region);
    }
    return DL_GetItemsCount(Region) != 0;
}

uint8_t *GDI_GetPixelPtr(pLCONTEXT lc, TPOINT pt)
{
    uint8_t *p = (uint8_t *)lc->FrameBuffer;

    return &p[(pt.y * (lc->LayerRgn.r - lc->LayerRgn.l + 1) + pt.x) * lc->BPP];
}

void GDI_FillRectangleX(pLCONTEXT lc, pRECT Rct, TCOLOR Color)
{
    int32_t  x, y, dpx;

    if ((lc == NULL) || (Rct == NULL) || (lc->FrameBuffer == NULL)) return;

    dpx = lc->LayerRgn.r - (Rct->r - Rct->l);

    switch (lc->ColorFormat)
    {
    case CF_RGB565:
    {
        uint16_t *p = (uint16_t *)GDI_GetPixelPtr(lc, Rct->lt);

        Color = RGB_565(Color);
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
