// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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

uint8_t *GDI_GetPixelPtr(pLCONTEXT lc, TPOINT pt)
{
    uint8_t *p = (uint8_t *)lc->FrameBuffer;

    return &p[(pt.y * (lc->LayerRgn.r - lc->LayerRgn.l + 1) + pt.x) * lc->BPP];
}

void GDI_FillRectangle16(pLCONTEXT lc, pRECT Rct, uint32_t Color)
{
    uint16_t *p;
    int32_t  x, y, dpx;

    if ((lc == NULL) || (Rct == NULL) || (lc->FrameBuffer == NULL)) return;

    switch (lc->ColorFormat)
    {
    case CF_RGB565:
        Color = RGB_565(Color);
        p = (uint16_t *)GDI_GetPixelPtr(lc, Rct->lt);
        dpx = (lc->LayerRgn.r + 1) - (Rct->r - Rct->l + 1);
        for(y = Rct->t; y <= Rct->b; y++)
        {
            for(x = Rct->l; x <= Rct->r; x++) *p++ = Color;
            p += dpx;
        }
        break;
    default:
        break;
    }
    return;
}

void GDI_FillRectangle32(pLCONTEXT lc, pRECT Rct, uint32_t Color)
{
    uint32_t *p;
    int32_t  x, y, dpx;

    if ((lc == NULL) || (Rct == NULL) || (lc->FrameBuffer == NULL)) return;

    switch (lc->ColorFormat)
    {
    case CF_ARGB8888:
    case CF_PARGB8888:
    case CF_xRGB8888:
        p = (uint32_t *)GDI_GetPixelPtr(lc, Rct->lt);
        dpx = (lc->LayerRgn.r + 1) - (Rct->r + 1 - Rct->l);
        for(y = Rct->t; y <= Rct->b; y++)
        {
            for(x = Rct->l; x <= Rct->r; x++) *p++ = Color;
            p += dpx;
        }
        break;
    default:
        break;
    }
    return;
}
