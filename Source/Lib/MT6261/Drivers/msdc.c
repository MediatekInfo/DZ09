// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 AJScorp
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
#include "msdc.h"

static TMSDCCONTEXT MSDCCONTEXT[MSDC_ITFNUM] =
{
    {MSDC0, PD_MSDC},
    {MSDC1, PD_MSDC2}
};

static TMSDCCONTEXT *MSDC_GetModuleContext(TMSDC Index)
{
    if (Index >= MSDC_ITFNUM) return NULL;
    else return &MSDCCONTEXT[Index];
}

static void MSDC_Reset(TMSDCCONTEXT *Context)
{
    Context->MSDC->MSDC_CFG |= MSDC_RST;
    USC_Pause_us(2000);                                                                             // Pause 2 ms
    Context->MSDC->MSDC_CFG &= ~(MSDC_RST | MSDC_EN);
}

static void MSDC_ClockInit(TMSDCCONTEXT *Context)
{
    Context->MSDC->CLK_RED &= ~MSDC_CLKPAD_RED;
    Context->MSDC->SDC_CFG  = (Context->MSDC->SDC_CFG & ~SDC_DTOC(-1)) | SDC_DTOC(80);
}

boolean MSDC_IsMultiLineSupported(TMSDC Index)
{
    return (Index == MSDC_ITF0) ? true : false;
}

