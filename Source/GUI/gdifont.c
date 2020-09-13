// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2020 AJScorp
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
#include "gdifont.h"

static pBFC_CHARINFO GDI_GetFontCharInfo(pBFC_FONT Font, uint16_t Symbol)
{
    pBFC_FONT_PROP pProp;
    pBFC_CHARINFO  Result = NULL;

    if (Font == NULL) return NULL;

    pProp = (pBFC_FONT_PROP)Font->p.pProp;
    while(pProp != NULL)
    {
        if (Symbol < pProp->FirstChar) break;
        if (Symbol <= pProp->LastChar)
        {
            Result = (pBFC_CHARINFO)pProp->pFirstCharInfo;
            Result += Symbol - pProp->FirstChar;
            break;
        }
        else pProp = (pBFC_FONT_PROP)pProp->pNextProp;
    }
    return Result;
}

static wchar_t *GDI_GetTextSymbolByXShift(pBFC_CHARINFO *CharInfo, pTEXT Text, int32_t x, uint32_t *DataBitIndex)
{
    wchar_t  *p;
    uint32_t tmpX = 0;

    if ((Text == NULL) || (Text->Font == NULL) || (Text->Text == NULL)) return NULL;
    if (x < 0) x = 0;

    p = Text->Text;
    while(*p)
    {
        pBFC_CHARINFO tmpCharInfo = GDI_GetFontCharInfo(Text->Font, *p);

        if (tmpCharInfo != NULL)
        {
            if ((x >= tmpX) && (x < (tmpX + tmpCharInfo->Width)))
            {
                if (DataBitIndex != NULL) *DataBitIndex = x - tmpX;
                if (CharInfo != NULL)     *CharInfo = tmpCharInfo;
                return p;
            }
            tmpX += tmpCharInfo->Width;
        }
        p++;
    }
    return NULL;
}

pDLIST GDI_DrawText565(TVLINDEX Layer, pTEXT Text, pRECT Client, pRECT Clip,
                       uint32_t ForeColor, uint32_t BackColor, int16_t TextDX, int16_t TextDY)
{
    uint16_t *FrameBuffer;
    int32_t  FrameWidth;
    int16_t  XShift, YShift;
    TRECT    tmpRect, tmpClient;
    pDLIST   BorderRects = NULL;

    if ((Layer >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Layer].Initialized ||
            (LCDScreen.VLayer[Layer].ColorFormat != CF_RGB565))
        return NULL;

    if ((Client != NULL) && (Clip != NULL))
    {
        tmpClient = *Client;
        if (!GDI_ANDRectangles(&tmpClient, &LCDScreen.VLayer[Layer].LayerRgn) ||
                !GDI_ANDRectangles(&tmpClient, Clip))
            return NULL;
        BorderRects = DL_Create(0);
        GDI_ADDRectToRegion(BorderRects, &tmpClient);
    }
    else return NULL;

    FrameBuffer = LCDScreen.VLayer[Layer].FrameBuffer;
    FrameWidth  = LCDScreen.VLayer[Layer].LayerRgn.r - LCDScreen.VLayer[Layer].LayerRgn.l + 1;
    ForeColor = RGB_565(ForeColor);
    BackColor = RGB_565(BackColor);

    if ((Text != NULL) && (Text->Font != NULL) && (Text->Text != NULL))
    {
        switch (Text->Align & AH_MASK)
        {
        case AH_RIGHT:
            XShift = Client->r - Text->Extent.sx - Client->l + 1;
            break;
        case AH_CENTER:
            XShift = (Client->r - Client->l - Text->Extent.sx + 1) / 2;
            break;
        case AH_LEFT:
        default:
            XShift = 0;
            break;
        }

        switch (Text->Align & AV_MASK)
        {
        case AV_BOTTOM:
            YShift = Client->b - Text->Extent.sy - Client->t + 1;
            break;
        case AV_CENTER:
            YShift = (Client->b - Client->t - Text->Extent.sy + 1) / 2;
            break;
        case AV_TOP:
        default:
            YShift = 0;
            break;
        }

        XShift += TextDX;
        YShift += TextDY;

        tmpRect = Rect(0 + Client->l + XShift,
                       0 + Client->t + YShift,
                       Text->Extent.sx - 1 + Client->l + XShift,
                       Text->Extent.sy - 1 + Client->t + YShift);

        if (GDI_ANDRectangles(&tmpRect, &tmpClient))
        {
            uint16_t      PixX, PixY, dx, dy, BitStartIndex;
            pBFC_CHARINFO CharInfo;
            wchar_t       *CapPtr;

            if (!GDI_SUBRectFromRegion(BorderRects, &tmpRect))
                BorderRects = DL_Delete(BorderRects, false);

            PixX = tmpRect.l - Client->l;                                                           // Pixel X shift at client
            PixY = tmpRect.t - Client->t;                                                           // Pixel Y shift at client
            dx   = tmpRect.r - tmpRect.l + 1;                                                       // X pixels to draw
            dy   = tmpRect.b - tmpRect.t + 1;                                                       // Y pixels to draw





        }
    }
    return BorderRects;
}









