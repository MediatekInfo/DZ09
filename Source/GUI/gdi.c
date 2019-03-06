// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "gdi.h"

void GDI_FillRectangle(TVLINDEX Layer, TRECT Rct, uint32_t Color)
{
    pLCONTEXT lc;

    if ((Layer >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Layer].Initialized) return;

    lc = &LCDScreen.VLayer[Layer];
    if (GDI_ANDRectangles(&Rct, &lc->LayerRgn)) GDI_FillRectangleX(lc, &Rct, Color);
}

void GDI_DrawLine(TVLINDEX Layer, TPOINT P0, TPOINT P1, uint32_t Color)
{
    if ((Layer >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Layer].Initialized) return;

    if ((P0.x == P1.x) || (P0.y == P1.y))
    {
        TRECT     Rct;
        pLCONTEXT lc;

        Rct.lt = P0;
        Rct.rb = P1;

        lc = &LCDScreen.VLayer[Layer];
        if (GDI_ANDRectangles(&Rct, &lc->LayerRgn)) GDI_FillRectangleX(lc, &Rct, Color);
    }
}

void GDI_SetPixel(TVLINDEX Layer, TPOINT P, uint32_t Color)
{
    TRECT     Rct;
    pLCONTEXT lc;

    if ((Layer >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Layer].Initialized) return;

    Rct.lt = Rct.rb = P;

    lc = &LCDScreen.VLayer[Layer];
    if (IsPointInRect(P.x, P.y, &lc->LayerRgn)) GDI_FillRectangleX(lc, &Rct, Color);
}
