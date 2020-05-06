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
#include "pctl.h"

void PCTL_Initialize(void)
{
    CNFG_PDN_CON0_SET = CNFG_PDN0_MASK;
    CNFG_PDN_CON1_SET = CNFG_PDN1_MASK;
    CNFG_PDN_CON2_SET = CNFG_PDN2_MASK;

#if _DEBUG_
    {
        int32_t PDCode = USART_GetPDCode(DBG_USARTINF.USART);

        if (PDCode != -1) PCTL_PowerUp(PDCode);
    }
#endif

// TODO (scorp#1#): Analog CFGSYS needs to be researched
    ACFG_CLK_CON_SET = ACFG_CLK_MASK;
}

boolean PCTL_GetPeripheralPowerStatus(uint32_t Periph)
{
    if      (Periph <= PD_CNFG_MAX) return !(CNFG_PDN_CON(Periph >> 4) & (1 << (Periph & 0x0F)));
    else if (Periph <= PD_ACFG_MAX) return !(ACFG_CLK_CON & (1 << (Periph & 0x0F)));

    return false;
}
