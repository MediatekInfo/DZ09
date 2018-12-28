// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "gdi.h"

void (*FillRectangleX[CF_NUM])(pLCONTEXT, pRECT, uint32_t) =
{
    NULL,
    &GDI_FillRectangle16,
    NULL,
    NULL,
    &GDI_FillRectangle32,
    &GDI_FillRectangle32,
    &GDI_FillRectangle32
};

void FillRectangle(uint8_t Index, TRECT Rct, uint32_t Color)
{
    pLCONTEXT lc;

    if ((Index >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Index].Initialized) return;

    lc = &LCDScreen.VLayer[Index];
    if (/*ANDRects(&Rct, &lc->LayerRgn) && */FillRectangleX[lc->ColorFormat] != NULL)
        FillRectangleX[lc->ColorFormat](lc, &Rct, Color);
}
