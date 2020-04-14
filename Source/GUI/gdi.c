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
#include "bfcfont.h"
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

void GDI_DrawFrame(TVLINDEX Layer, pRECT Client, pRECT Clip, uint32_t Color)
{
    if ((Layer >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Layer].Initialized) return;
    if ((Client != NULL) && (Clip != NULL))
    {
        TRECT tmpClient = *Client;

        if (GDI_ANDRectangles(&tmpClient, &LCDScreen.VLayer[Layer].LayerRgn) &&
                GDI_ANDRectangles(&tmpClient, Clip))
        {
            TRECT  DrwRect;

            DrwRect = Rect(Client->l, Client->t, Client->r, Client->t);                             // Top line
            if (GDI_ANDRectangles(&DrwRect, &tmpClient))
                GDI_FillRectangle(Layer, DrwRect, Color);
            DrwRect = Rect(Client->l, Client->t, Client->l, Client->b);                             // Left line
            if (GDI_ANDRectangles(&DrwRect, &tmpClient))
                GDI_FillRectangle(Layer, DrwRect, Color);
            DrwRect = Rect(Client->l + 1, Client->b, Client->r, Client->b);                         // Bottom line
            if (GDI_ANDRectangles(&DrwRect, &tmpClient))
                GDI_FillRectangle(Layer, DrwRect, Color);
            DrwRect = Rect(Client->r, Client->t + 1, Client->r, Client->b);                         // Right line
            if (GDI_ANDRectangles(&DrwRect, &tmpClient))
                GDI_FillRectangle(Layer, DrwRect, Color);
        }
    }
}
