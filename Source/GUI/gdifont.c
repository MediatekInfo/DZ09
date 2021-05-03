// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "gdifont.h"

static pBFC_CHARINFO GDI_GetFontCharInfo(pBFC_FONT Font, uint32_t Symbol)
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

static pDLIST GDI_DrawText16(pLCONTEXT lc, pTEXT Text, pRECT Client, pRECT Clip,
                             TCOLOR ForeColor, TCOLOR BackColor)
{
    uint16_t  *FrameBuffer;
    int16_t   FrameWidth, XShift, YShift;
    TRECT     TextRect;
    pDLIST    SubRects = NULL;

    if (lc->ColorFormat != CF_RGB565) return NULL;

    FrameBuffer = lc->FrameBuffer;
    FrameWidth  = (lc->LayerRgn.r - lc->LayerRgn.l + 1);

    ForeColor = RGB_565(ForeColor);
    BackColor = RGB_565(BackColor);

    switch (Text->Align & AH_MASK)
    {
    case AH_RIGHT:
        XShift =  Client->r - Text->Extent.sx - Client->l + 1;
        break;
    case AH_CENTER:
        XShift = (Client->r - Text->Extent.sx - Client->l + 1 + 1) / 2;
        break;
    case AH_LEFT:
    default:
        XShift = 0;
        break;
    }

    switch (Text->Align & AV_MASK)
    {
    case AV_BOTTOM:
        YShift =  Client->b - Text->Extent.sy - Client->t + 1;
        break;
    case AV_CENTER:
        YShift = (Client->b - Text->Extent.sy - Client->t + 1 + 1) / 2;
        break;
    case AV_TOP:
    default:
        YShift = 0;
        break;
    }

    TextRect = Rect(Client->l + XShift,
                    Client->t + YShift,
                    Text->Extent.sx - 1 + Client->l + XShift,
                    Text->Extent.sy - 1 + Client->t + YShift);

    if (GDI_ANDRectangles(&TextRect, Clip))
    {
        uint32_t      PixX, PixY, dx, dy, BitStartIndex;
        uint16_t      *dstImagePtr = &FrameBuffer[FrameWidth * TextRect.t + TextRect.l];
        pBFC_CHARINFO CharInfo;
        char          *CapPtr;

        SubRects = GDI_SUBRectangles(Clip, &TextRect);

        PixX = TextRect.l - Client->l;                                                          // Pixel X shift at client
        PixY = TextRect.t - Client->t;                                                          // Pixel Y shift at client
        dx   = TextRect.r - TextRect.l + 1;                                                     // X pixels to draw
        dy   = TextRect.b - TextRect.t + 1;                                                     // Y pixels to draw

        CapPtr = GDI_GetStringPosByXShift(&CharInfo, Text, PixX - XShift, &BitStartIndex);
        if (CapPtr != NULL)
        {
            while(dx)
            {
                uint8_t  *SymData;
                uint32_t BitsDraw, BitIndex, tmpX, tmpY, ImagePitch;
                uint16_t *tmpdstImagePtr = dstImagePtr;

                SymData = (uint8_t *)CharInfo->p.pData +
                          (((PixY - YShift) * CharInfo->Width + BitStartIndex) >> 3);
                BitIndex = ((PixY - YShift) * CharInfo->Width + BitStartIndex) & 0x07;
                BitsDraw = min(dx, CharInfo->Width - BitStartIndex);
                tmpY = dy;
                ImagePitch = FrameWidth - BitsDraw;

                while(tmpY--)
                {
                    tmpX = BitsDraw;
                    while(tmpX--)
                    {
                        *tmpdstImagePtr++ = (*SymData & (0x80 >> BitIndex)) ? ForeColor : BackColor;
                        if (++BitIndex > 7)
                        {
                            BitIndex -= 8;
                            SymData++;
                        }
                    }
                    tmpdstImagePtr += ImagePitch;
                    BitIndex += CharInfo->Width - BitsDraw;
                    SymData += BitIndex >> 3;
                    BitIndex &= 0x07;
                }

                if (dx -= BitsDraw)
                {
                    while (*++CapPtr)
                    {
                        if ((CharInfo = GDI_GetFontCharInfo(Text->Font, *CapPtr)) != NULL)
                        {
                            BitStartIndex = 0;
                            break;
                        }
                    }
                    if (!*CapPtr) break;
                    TextRect.l += BitsDraw;
                    dstImagePtr += BitsDraw;
                }
            }
        }
        else SubRects = DL_Delete(SubRects, true);
    }
    return SubRects;
}

static pDLIST GDI_DrawText32(pLCONTEXT lc, pTEXT Text, pRECT Client, pRECT Clip,
                             TCOLOR ForeColor, TCOLOR BackColor)
{
    uint32_t  *FrameBuffer;
    int16_t   FrameWidth, XShift, YShift;
    TRECT     TextRect;
    pDLIST    SubRects = NULL;

    if ((lc->ColorFormat != CF_ARGB8888) &&
            (lc->ColorFormat != CF_PARGB8888) &&
            (lc->ColorFormat != CF_xRGB8888))
        return NULL;

    FrameBuffer = lc->FrameBuffer;
    FrameWidth  = (lc->LayerRgn.r - lc->LayerRgn.l + 1);

    switch (Text->Align & AH_MASK)
    {
    case AH_RIGHT:
        XShift =  Client->r - Text->Extent.sx - Client->l + 1;
        break;
    case AH_CENTER:
        XShift = (Client->r - Text->Extent.sx - Client->l + 1 + 1) / 2;
        break;
    case AH_LEFT:
    default:
        XShift = 0;
        break;
    }

    switch (Text->Align & AV_MASK)
    {
    case AV_BOTTOM:
        YShift =  Client->b - Text->Extent.sy - Client->t + 1;
        break;
    case AV_CENTER:
        YShift = (Client->b - Text->Extent.sy - Client->t + 1 + 1) / 2;
        break;
    case AV_TOP:
    default:
        YShift = 0;
        break;
    }

    TextRect = Rect(Client->l + XShift,
                    Client->t + YShift,
                    Text->Extent.sx - 1 + Client->l + XShift,
                    Text->Extent.sy - 1 + Client->t + YShift);

    if (GDI_ANDRectangles(&TextRect, Clip))
    {
        uint32_t      PixX, PixY, dx, dy, BitStartIndex;
        uint32_t      *dstImagePtr = &FrameBuffer[FrameWidth * TextRect.t + TextRect.l];
        pBFC_CHARINFO CharInfo;
        char          *CapPtr;

        SubRects = GDI_SUBRectangles(Clip, &TextRect);

        PixX = TextRect.l - Client->l;                                                          // Pixel X shift at client
        PixY = TextRect.t - Client->t;                                                          // Pixel Y shift at client
        dx   = TextRect.r - TextRect.l + 1;                                                     // X pixels to draw
        dy   = TextRect.b - TextRect.t + 1;                                                     // Y pixels to draw

        CapPtr = GDI_GetStringPosByXShift(&CharInfo, Text, PixX - XShift, &BitStartIndex);
        if (CapPtr != NULL)
        {
            while(dx)
            {
                uint8_t  *SymData;
                uint32_t BitsDraw, BitIndex, tmpX, tmpY, ImagePitch;
                uint32_t *tmpdstImagePtr = dstImagePtr;

                SymData = (uint8_t *)CharInfo->p.pData +
                          (((PixY - YShift) * CharInfo->Width + BitStartIndex) >> 3);
                BitIndex = ((PixY - YShift) * CharInfo->Width + BitStartIndex) & 0x07;
                BitsDraw = min(dx, CharInfo->Width - BitStartIndex);
                tmpY = dy;
                ImagePitch = FrameWidth - BitsDraw;

                while(tmpY--)
                {
                    tmpX = BitsDraw;
                    while(tmpX--)
                    {
                        *tmpdstImagePtr++ = (*SymData & (0x80 >> BitIndex)) ? ForeColor : BackColor;
                        if (++BitIndex > 7)
                        {
                            BitIndex -= 8;
                            SymData++;
                        }
                    }
                    tmpdstImagePtr += ImagePitch;
                    BitIndex += CharInfo->Width - BitsDraw;
                    SymData += BitIndex >> 3;
                    BitIndex &= 0x07;
                }

                if (dx -= BitsDraw)
                {
                    while (*++CapPtr)
                    {
                        if ((CharInfo = GDI_GetFontCharInfo(Text->Font, *CapPtr)) != NULL)
                        {
                            BitStartIndex = 0;
                            break;
                        }
                    }
                    if (!*CapPtr) break;
                    TextRect.l += BitsDraw;
                    dstImagePtr += BitsDraw;
                }
            }
        }
        else SubRects = DL_Delete(SubRects, true);
    }
    return SubRects;
}

TTEXT Text(const BFC_FONT *Font, char *Caption, TTXTALIGN Align, TCOLOR ForeColor, TCOLOR BackColor)
{
    TTEXT Text;

    Text.Align = Align;
    Text.Font = (pBFC_FONT)Font;
    Text.Text = Caption;
    Text.ForeColor = ForeColor;
    Text.BackColor = BackColor;
    GDI_UpdateTextExtent(&Text);

    return Text;
}

void GDI_UpdateTextExtent(pTEXT Text)
{
    if (Text != NULL)
    {
        TSIZEXY SzXY = {0};

        if ((Text->Text != NULL) && (Text->Font != NULL))
        {
            char *p = Text->Text;

            SzXY.sy = Text->Font->FontHeight;

            while(*p)
            {
                pBFC_CHARINFO CharInfo;

                if ((CharInfo = GDI_GetFontCharInfo(Text->Font, *p++)) != NULL)
                    SzXY.sx += CharInfo->Width;
            }
            if (!SzXY.sx) SzXY.sy = 0;
        }
        Text->Extent = SzXY;
    }
}

char *GDI_GetStringPosByXShift(pBFC_CHARINFO *CharInfo, pTEXT Text, int32_t ReqXShift,
                               uint32_t *DataBitIndex)
{
    char     *p;
    uint32_t CurrentShift = 0;

    if ((Text == NULL) || (Text->Font == NULL) || (Text->Text == NULL)) return NULL;
    if (ReqXShift < 0) ReqXShift = 0;

    p = Text->Text;
    while(*p)
    {
        pBFC_CHARINFO tmpCharInfo = GDI_GetFontCharInfo(Text->Font, *p);

        if (tmpCharInfo != NULL)
        {
            if ((ReqXShift >= CurrentShift) && (ReqXShift < (CurrentShift + tmpCharInfo->Width)))
            {
                if (DataBitIndex != NULL) *DataBitIndex = ReqXShift - CurrentShift;
                if (CharInfo != NULL)     *CharInfo = tmpCharInfo;
                return p;
            }
            CurrentShift += tmpCharInfo->Width;
        }
        p++;
    }
    return NULL;
}

pDLIST GDI_DrawText(TVLINDEX Layer, pTEXT Text, pRECT Client, pRECT Clip,
                    TCOLOR ForeColor, TCOLOR BackColor)
{
    static pDLIST (*const DrawText[CF_NUM])(pLCONTEXT, pTEXT, pRECT, pRECT, TCOLOR, TCOLOR) =
    {
        NULL,                                                                                       // CF_8IDX
        GDI_DrawText16,                                                                             // CF_RGB565
        NULL,                                                                                       // CF_YUYV422
        NULL,                                                                                       // CF_RGB888
        GDI_DrawText32,                                                                             // CF_ARGB8888
        GDI_DrawText32,                                                                             // CF_PARGB8888
        GDI_DrawText32                                                                              // CF_xRGB8888
    };

    if (((Layer < LCDIF_NUMLAYERS) && LCDScreen.VLayer[Layer].Initialized) &&
            (Text != NULL) && (Text->Font != NULL) && (Text->Text != NULL) &&
            (Text->Extent.sx > 0) && (Text->Extent.sy > 0) &&
            (Client != NULL) && (Clip != NULL))
    {
        TRECT     tmpClip = *Clip;
        pLCONTEXT lc = &LCDScreen.VLayer[Layer];

        if (GDI_ANDRectangles(&tmpClip, &lc->LayerRgn) &&
                GDI_ANDRectangles(&tmpClip, Client) &&
                (DrawText[lc->ColorFormat] != NULL))
            return DrawText[lc->ColorFormat](lc, Text, Client, &tmpClip, ForeColor, BackColor);
    }
    return NULL;
}
