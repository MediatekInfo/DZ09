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
#include "pwm.h"

static TPWM_CONTEXT PWMINFO[PWM_CHANNELS] =
{
    {(TPWMREGS *)PWM1, PD_PWM1},
    {(TPWMREGS *)PWM2, PD_PWM2},
    {(TPWMREGS *)PWM3, PD_PWM3},
    {(TPWMREGS *)PWM4, PD_PWM4},
};

boolean PWM_SetupChannel(TPWM Index, uint16_t Count, uint16_t Threshold, TPWM_FLAGS Flags)
{
    if (Index >= PWM_CHANNELS) return false;
    else
    {
        pPWMREGS PWM = PWMINFO[Index].PWM;

        PWM->Ctrl = (Flags & PWF_FSEL_32K) ? PWM_CLKSEL_32K : PWM_CLKSEL_13M;
        PWMINFO[Index].Threshold = PWM_THRESH(Threshold);

        if (Index == PWM_CHANNEL2)
        {
            /* PWM2 setup */
            PWMINFO[Index].Threshold &= PWM2_DUTY_MASK;
            if (PWMINFO[Index].Threshold > PWM2_DUTY_100) PWMINFO[Index].Threshold = PWM2_DUTY_100;
        }
        else
        {
            /* PWM1, PWM2, PWM4 setup */
            PWM->Ctrl |= PWM_CLKDIV(Flags & PWF_CLKDIV8);
            PWM->Count = PWM_COUNT(Count);
            if (((uintptr_t)PWM == PWM3_base) && (Flags & PWF_ALW_HIGH))
                PWM->Ctrl |= PWM3_ALWAYS_HIGH;
        }
        PWM->Threshold = PWM_THRESH(Threshold);
        PWM_SetPowerDown(Index, !!(Flags & PWF_ENABLED));
        PWMINFO[Index].Flags = Flags;
    }
    return true;
}

boolean PWM_SetPowerDown(TPWM Index, boolean PowerDown)
{
    if (Index >= PWM_CHANNELS) return false;
    else
    {
        boolean AlreadyInState = !(PWMINFO[Index].Flags & PWF_ENABLED);

        if (AlreadyInState ^ PowerDown)
        {
            PWMINFO[Index].PWM->Threshold = (PowerDown) ? 0 : PWMINFO[Index].Threshold;

            if (PowerDown)
            {
                PCTL_PowerDown(PWMINFO[Index].PD_Code);
                PWMINFO[Index].Flags &= ~PWF_ENABLED;
            }
            else
            {
                PCTL_PowerUp(PWMINFO[Index].PD_Code);
                PWMINFO[Index].Flags |= PWF_ENABLED;
            }
        }
    }
    return true;
}

boolean PWM_SetCount(TPWM Index, uint16_t Count)
{
    if (Index >= PWM_CHANNELS) return false;
    else if (Index >= PWM_CHANNEL2) return true;
    else
    {
        PWMINFO[Index].PWM->Count = PWM_COUNT(Count);
    }
    return true;
}

boolean PWM_SetThreshold(TPWM Index, uint16_t Threshold)
{
    if (Index >= PWM_CHANNELS) return false;
    else if (Index >= PWM_CHANNEL2)
    {
        PWMINFO[Index].Threshold &= PWM2_DUTY_MASK;
        if (PWMINFO[Index].Threshold > PWM2_DUTY_100) PWMINFO[Index].Threshold = PWM2_DUTY_100;
    }
    PWMINFO[Index].Threshold = PWM_THRESH(Threshold);
    PWMINFO[Index].PWM->Threshold = PWMINFO[Index].Threshold;

    return true;
}

boolean PWM_SetDutyCycle(TPWM Index, uint32_t Duty)                                                 // Duty in percents [0..100]
{
    if (Index >= PWM_CHANNELS) return false;
    else if (Index == PWM_CHANNEL2)
    {
        if (Duty < 50) PWMINFO[Index].Threshold = PWM2_DUTY_0;
        else if (Duty < 100) PWMINFO[Index].Threshold = PWM2_DUTY_50;
        else PWMINFO[Index].Threshold = PWM2_DUTY_100;
    }
    else
    {
        Duty = min(Duty, 100);
        if (PWMINFO[Index].PWM->Count)
            PWMINFO[Index].Threshold = PWM_THRESH((Duty * (PWMINFO[Index].PWM->Count - 1)) / 100);
        else PWMINFO[Index].Threshold = 0;
    }
    PWMINFO[Index].PWM->Threshold = PWMINFO[Index].Threshold;

    return true;
}
