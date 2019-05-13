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
#ifndef _PLL_H_
#define _PLL_H_

#define PLL_CLKSQ_CON0    (*(volatile uint16_t*)(MIXED_base + 0x0020))

#define PLL_PLL_CON4      (*(volatile uint16_t*)(MIXED_base + 0x0050))
#define PLL_PLL_CON6      (*(volatile uint16_t*)(MIXED_base + 0x0058))
#define PLL_PLL_CON7      (*(volatile uint16_t*)(MIXED_base + 0x005C))

#define PLL_MPLL_CON0     (*(volatile uint16_t*)(MIXED_base + 0x0100))
#define PLL_MPLL_CON1     (*(volatile uint16_t*)(MIXED_base + 0x0104))
#define PLL_MPLL_CON2     (*(volatile uint16_t*)(MIXED_base + 0x0108))

#define PLL_UPLL_CON0     (*(volatile uint16_t*)(MIXED_base + 0x0140))
#define PLL_UPLL_CON1     (*(volatile uint16_t*)(MIXED_base + 0x0144))
#define PLL_UPLL_CON2     (*(volatile uint16_t*)(MIXED_base + 0x0148))

#define PLL_MDDS_CON0     (*(volatile uint16_t*)(MIXED_base + 0x0640))
#define PLL_MDDS_CON1     (*(volatile uint16_t*)(MIXED_base + 0x0644))
#define PLL_MDDS_CON2     (*(volatile uint16_t*)(MIXED_base + 0x0648))

#define PLL_PLL_CON2      (*(volatile uint16_t*)(MIXED_base + 0x0048))
#define PLL_PLL_CON3      (*(volatile uint16_t*)(MIXED_base + 0x004C))

#define PLL_DPM_CON0      (*(volatile uint16_t*)(MIXED_base + 0x0090))
#define PLL_DPM_CON1      (*(volatile uint16_t*)(MIXED_base + 0x0094))
#define PLL_DPM_CON2      (*(volatile uint16_t*)(MIXED_base + 0x0098))

#define PLL_PLLTD_CON0    (*(volatile uint16_t*)(MIXED_base + 0x0700))
#define PLL_PLLTD_CON1    (*(volatile uint16_t*)(MIXED_base + 0x0704))
#define PLL_PLLTD_CON2    (*(volatile uint16_t*)(MIXED_base + 0x0708))
#define PLL_PLLTD_CON3    (*(volatile uint16_t*)(MIXED_base + 0x070C))
#define PLL_PLLTD_CON4    (*(volatile uint16_t*)(MIXED_base + 0x0710))
#define PLL_PLLTD_CON5    (*(volatile uint16_t*)(MIXED_base + 0x0714))
#define PLL_PLLTD_CON6    (*(volatile uint16_t*)(MIXED_base + 0x0718))
#define PLL_PLLTD_CON7    (*(volatile uint16_t*)(MIXED_base + 0x071C))

#define PLL_CLK_CONDA     (*(volatile uint32_t*)(CONFIG_base + 0x0100))
#define PLL_CLK_CONDB     (*(volatile uint32_t*)(CONFIG_base + 0x0104))
#define PLL_CLK_CONDC     (*(volatile uint32_t*)(CONFIG_base + 0x0108))
#define PLL_CLK_CONDD     (*(volatile uint32_t*)(CONFIG_base + 0x010C))
#define PLL_CLK_CONDE     (*(volatile uint32_t*)(CONFIG_base + 0x0110))
#define PLL_CLK_CONDF     (*(volatile uint32_t*)(CONFIG_base + 0x0114))
#define PLL_CLK_CONDG     (*(volatile uint32_t*)(CONFIG_base + 0x0118))
#define PLL_CLK_CONDH     (*(volatile uint32_t*)(CONFIG_base + 0x011C))

#define PLL_FH_CON0       (*(volatile uint32_t*)(MIXED_base + 0x0500))
#define PLL_FH_CON1       (*(volatile uint32_t*)(MIXED_base + 0x0504))
#define PLL_FH_CON2       (*(volatile uint32_t*)(MIXED_base + 0x0508))
#define PLL_FH_CON3       (*(volatile uint32_t*)(MIXED_base + 0x050C))
#define PLL_FH_CON4       (*(volatile uint32_t*)(MIXED_base + 0x0510))

extern void PLL_Initialize(void);

#endif /* _PLL_H_ */
