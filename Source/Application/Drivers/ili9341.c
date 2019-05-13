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
#include "appconfig.h"
#include "ili9341.h"

boolean ILI9341_Initialize(void)
{
    LCDIF_WriteCommand(ILI9341_PCONTROL1);
    LCDIF_WriteData(VRH(0x23));

    LCDIF_WriteCommand(ILI9341_PCONTROL2);
    LCDIF_WriteData(BT(0x10));

    LCDIF_WriteCommand(ILI9341_VCOMCONTROL1);
    LCDIF_WriteData(VMH(0x3E));
    LCDIF_WriteData(VMH(0x28));

    LCDIF_WriteCommand(ILI9341_MADCTL);
    LCDIF_WriteData(MC_RGB);

    LCDIF_WriteCommand(ILI9341_PIXFMT);
    LCDIF_WriteData(DPI(DPI18bit) | DBI(DBI18bit));

    LCDIF_WriteCommand(ILI9341_FRAMERATE);
    LCDIF_WriteData(DIVA(0x00));
    LCDIF_WriteData(RTNA(0x18));

    LCDIF_WriteCommand(ILI9341_DFUNCCONTROL);
    LCDIF_WriteData(PTG(0x02) | PT(0x00));
    LCDIF_WriteData(REV | ISC(0x02));
    LCDIF_WriteData(NL(0x1D));

    LCDIF_WriteCommand(ILI9341_SLPOUT);
    LCDIF_WriteCommand(ILI9341_DISPON);

    return true;                                                                                    //I can't read the display ID, so here just returns true.
}

void ILI9341_SleepLCD(void)
{
    LCDIF_WriteCommand(ILI9341_DISPOFF);
    LCDIF_WriteCommand(ILI9341_SLPIN);
}

void ILI9341_ResumeLCD(void)
{
    LCDIF_WriteCommand(ILI9341_SLPOUT);
    LCDIF_WriteCommand(ILI9341_DISPON);
}

uint32_t *ILI9341_SetOutputWindow(pRECT Rct, uint32_t *Count, uint32_t DataAttr, uint32_t CmdAttr)
{
    uint32_t *Data = NULL;

    if ((Rct != NULL) && (Count != NULL))
    {
        uint32_t i = 0;

        Data = malloc(ILI9341_SETWINCMDSIZE * sizeof(uint32_t));
        if (Data != NULL)
        {
            Data[i++] = LCDIF_COMM(ILI9341_CASET) | CmdAttr;
            Data[i++] = LCDIF_COMM(CASSH(Rct->l)) | DataAttr;
            Data[i++] = LCDIF_COMM(CASSL(Rct->l)) | DataAttr;
            Data[i++] = LCDIF_COMM(CASEH(Rct->r)) | DataAttr;
            Data[i++] = LCDIF_COMM(CASEL(Rct->r)) | DataAttr;

            Data[i++] = LCDIF_COMM(ILI9341_RASET) | CmdAttr;
            Data[i++] = LCDIF_COMM(RASSH(Rct->t + ILI9341_ROWSHIFT)) | DataAttr;
            Data[i++] = LCDIF_COMM(RASSL(Rct->t + ILI9341_ROWSHIFT)) | DataAttr;
            Data[i++] = LCDIF_COMM(RASEH(Rct->b + ILI9341_ROWSHIFT)) | DataAttr;
            Data[i++] = LCDIF_COMM(RASEL(Rct->b + ILI9341_ROWSHIFT)) | DataAttr;

            Data[i++] = LCDIF_COMM(ILI9341_RAMWR) | CmdAttr;

            *Count = i;
        }
    }
    return Data;
}

