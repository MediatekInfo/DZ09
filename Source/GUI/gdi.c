// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "gdi.h"

void GDI_FillRectangle(uint8_t Index, TRECT Rct, uint32_t Color)
{
    pLCONTEXT lc;

    if ((Index >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Index].Initialized) return;

    lc = &LCDScreen.VLayer[Index];
    if (GDI_ANDRectangles(&Rct, &lc->LayerRgn)) GDI_FillRectangleX(lc, &Rct, Color);
}

void GDI_DrawLine(uint8_t Index, TPOINT P0, TPOINT P1, uint32_t Color)
{
    if ((Index >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Index].Initialized) return;

    if ((P0.x == P1.x) || (P0.y == P1.y))
    {
        TRECT     Rct;
        pLCONTEXT lc;

        Rct.lt = P0;
        Rct.rb = P1;

        lc = &LCDScreen.VLayer[Index];
        if (GDI_ANDRectangles(&Rct, &lc->LayerRgn)) GDI_FillRectangleX(lc, &Rct, Color);
    }
}

void GDI_SetPixel(uint8_t Index, TPOINT P, uint32_t Color)
{
    TRECT     Rct;
    pLCONTEXT lc;

    if ((Index >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Index].Initialized) return;

    Rct.lt = Rct.rb = P;

    lc = &LCDScreen.VLayer[Index];
    if (IsPointInRect(P.x, P.y, &lc->LayerRgn)) GDI_FillRectangleX(lc, &Rct, Color);
}
