// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2020, 2019 AJScorp
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
#include "pll.h"

void PLL_Initialize(void)                                                                           // Copy-paste from mt6261_pll.c
{
    volatile uint32_t tmp;

    // enable HW mode TOPSM control and clock CG of PLL control
    PLL_PLL_CON2 = 0x0000;      // 0xA0170048, bit 12, 10 and 8 set to 0 to enable TOPSM control
    // bit 4, 2 and 0 set to 0 to enable clock CG of PLL control
    PLL_PLL_CON3 = 0x0000;      // 0xA017004C, bit 12 set to 0 to enable TOPSM control

    // enable delay control
    PLL_PLLTD_CON0 = 0x0000;    //0x A0170700, bit 0 set to 0 to enable delay control

    // wait for 1us for TOPSM and delay (HW) control signal stable
    USC_Pause_us(1);

    // Disable UPLL by default
    PLL_SetUPLLEnabled(false);

    //select MPLL frequency
    PLL_MPLL_CON0  = 0x1400;    // 0xA0170100, set MPLL = 520M
    PLL_MPLL_CON1  = 0x0000;    // 0xA0170104, set post divider = /1

    //enable MDDS
    PLL_MDDS_CON0 = 0x0001;     //0x A0170640, bit 0 set to 1 to enable MDDS

    //enable and reset MPLL
    tmp = PLL_MPLL_CON0;
    tmp  |= 0x0001;
    PLL_MPLL_CON0  = tmp;       //0xA0170100, bit 0 set to 1 to enable MPLL and generate reset of MPLL

    //wait 50us for PLL and DDS settle
    USC_Pause_us(50);

    //Disable DDS LDO PG detector to save power
    tmp = PLL_PLL_CON4;
    tmp  &= 0xFFFB;
    PLL_PLL_CON4 = tmp;         //0xA0170050, bit 2 set to 0

    /* __SFI_CLK_133MHZ__ */
    PLL_CLK_CONDH = 0xD000;     // 0xA001_011C, SFC_MUX_SEL = 3'b000

    PLL_CLK_CONDC = 0x8008;     // 0xA001_0108, bit 15 set to 1 to enable digital frequency divider
    // wait for 2us to enable divider
    USC_Pause_us(2);

//        // 0xA001_0108,
//        // sfc_gfmux_sel = 1'b0
//        // arm_gfmux_sel = 3'b100,
//        // dsp_gfmux_sel = 1'b1,
//        // x4g_gfmux_sel = 1'b1,
//        // rg_pllck_sel  = 1'b1
    PLL_CLK_CONDC = 0xB620;

    USC_Pause_us(50);
}

void PLL_SetUPLLEnabled(boolean Enable)
{
    uint32_t tmpUPLL = PLL_UPLL_CON0;

    if (Enable) tmpUPLL |= 0x0001;
    else tmpUPLL &= ~0x0001;

    PLL_UPLL_CON0 = tmpUPLL;
}
