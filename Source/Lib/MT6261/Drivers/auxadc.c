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
#include "auxadc.h"

#define AUXADCBUSYMAX               50000                                                           // 50 ms must be enough

static boolean AUXADC_WaitBusy(void)
{
    uint32_t tmpUSTicks, CurrentTicks;

    CurrentTicks = tmpUSTicks = USC_GetCurrentTicks();
    while((AUXADC_CON3 & AUXADCSTA) &&
            ((CurrentTicks = USC_GetCurrentTicks()) - tmpUSTicks < AUXADCBUSYMAX));

    return (CurrentTicks - tmpUSTicks < AUXADCBUSYMAX);
}

boolean AUXADC_Enable(void)
{
    PCTL_PowerUp(PD_AUXADC_BCLK);                                                                   // Power up AUXADC

    AUXADC_CON3 = ADC_SOFT_RST;
    AUXADC_CON3 &= ~ADC_SOFT_RST;                                                                   // Software reset module

    AUXADC_CON0 = 0;
    AUXADC_CON1 = 0;
    AUXADC_CON2 = 0;

    if (!AUXADC_WaitBusy())
    {
        AUXADC_Disable();
        return false;
    }
    return true;
}

void AUXADC_Disable(void)
{
    AUXADC_CON3 = ADC_SOFT_RST;                                                                     // Reset module to unlock BUSY flag
    /* We'll probably have to do something else here. */
    PCTL_PowerDown(PD_AUXADC_BCLK);                                                                 // Power down AUXADC
}

uint16_t AUXADC_MeasureChannel(uint16_t Channel)
{
    uint16_t Mask = ((1 << Channel) & AUXADCCHNLMASK);
    uint16_t Result = 0;

    if (Mask)
    {
        AUXADC_CON1 &= ~Mask;
        AUXADC_CON1 |= Mask;
        if (AUXADC_WaitBusy()) Result = AUXADC_DAT(Channel);
    }
    return Result;
}

boolean AUXADC_MeasureMultiple(uint16_t *DataArray, uint16_t ChannelsMask)
{
    uint16_t Mask = ChannelsMask & AUXADCCHNLMASK;

    if (DataArray != NULL)
    {
        AUXADC_CON1 &= ~Mask;
        AUXADC_CON1 |= Mask;
        if (AUXADC_WaitBusy())
        {
            uint32_t i;

            for(i = 0; Mask != 0; i++, Mask >>= 1)
            {
                if (Mask & 0x0001)
                    *DataArray++ = AUXADC_DAT(i);
            }
            return true;
        }
    }
    return false;
}
