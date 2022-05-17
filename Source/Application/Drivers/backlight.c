// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 - 2020 AJScorp
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
#include "backlight.h"

TBLSTATE BLState;
pTIMER   BLReduceTimer;

static void PMUBL_UpdateValues(uint32_t Value, boolean TurnOn)
{
    Value = min(Value, 100);

    if (BLState.Mode == BM_ISINK)
    {
        if      (Value < 20) PMU_SetISINKParameters(BACKLIGHTCHNL, IC_4mA, TurnOn);
        else if (Value < 40) PMU_SetISINKParameters(BACKLIGHTCHNL, IC_8mA, TurnOn);
        else if (Value < 60) PMU_SetISINKParameters(BACKLIGHTCHNL, IC_12mA, TurnOn);
        else if (Value < 80) PMU_SetISINKParameters(BACKLIGHTCHNL, IC_16mA, TurnOn);
        else PMU_SetISINKParameters(BACKLIGHTCHNL, IC_20mA, TurnOn);
    }
    else if (BLState.Mode == BM_PWM)
    {
#ifndef BLMINVALUE
#define BLMINVALUE      0
#elif (BLMINVALUE >= 100)
#warning the BLMINVALUE value is set to >100%, redefined to 100%
#undef  BLMINVALUE
#define BLMINVALUE      100
#endif
        PMU_SetISINKParameters(BACKLIGHTCHNL, IC_20mA, TurnOn);
        if (!TurnOn)
        {
            PWM_SetPowerDown(LCD_PWMCHANNEL, true);
            GUI_SetLockState(true);
        }
        else
        {
            Value = BLMINVALUE + (Value * (100 - BLMINVALUE)) / 100;
            PWM_SetDutyCycle(LCD_PWMCHANNEL, Value);
            PWM_SetPowerDown(LCD_PWMCHANNEL, false);
        }
    }
}

static void PMUBL_HideTimerHandler(pTIMER Timer)
{
    if (BLState.Stage == BS_REDUCED)
    {
        PMUBL_UpdateValues(BLState.Value, false);
        LRT_Stop(BLReduceTimer);
    }
    else
    {
        BLState.Stage = BS_REDUCED;
        PMUBL_UpdateValues(BLState.Value / 3, true);
        LRT_SetInterval(BLReduceTimer, BACKLIGHTOFF);
    }
}

void PMUBL_Initialize(void)
{
    BLReduceTimer = LRT_Create(BACKLIGHTREDUCE, PMUBL_HideTimerHandler, TF_DIRECT | TF_AUTOREPEAT);
    memset(&BLState, 0x00, sizeof(TBLSTATE));

    PMU_DisableISINKs();
    PWM_SetupChannel(LCD_PWMCHANNEL, BACKLIGHTCOUNT, 0, PWF_FSEL_32K | PWF_CLKDIV1);
    PMUBL_SetBacklightMode(BACKLIGHTMODE);

    PMUBL_TurnOn(false);
    PMUBL_SetupValue(BACKLIGHTDEFVAL);
}

void PMUBL_SetBacklightMode(TBLMODE Mode)
{
    if (Mode < BM_MODES)
    {
        BLState.Mode = Mode;
        PMU_SetISINKMode((BLState.Mode == BM_ISINK) ? false : true);
    }
}

void PMUBL_SetupValue(uint32_t Value)
{
    uint32_t intflags = __disable_interrupts();

    BLState.Value = Value;

    if (BLState.Stage == BS_FULL) PMUBL_UpdateValues(BLState.Value, true);
    else if (BLState.Stage == BS_REDUCED) PMUBL_UpdateValues(BLState.Value / 3, true);
    else PMUBL_UpdateValues(BLState.Value, false);

    __restore_interrupts(intflags);
}

void PMUBL_TurnOn(boolean TurnOn)
{
    if (!TurnOn)
    {
        uint32_t intflags = __disable_interrupts();

        LRT_Stop(BLReduceTimer);
        PMUBL_UpdateValues(BLState.Value, false);
        BLState.Stage = BS_OFF;
        __restore_interrupts(intflags);
    }
    else PMUBL_RestartBacklightTimer(true);
}

void PMUBL_RestartBacklightTimer(boolean UnlockGUI)
{
    uint32_t intflags = __disable_interrupts();

    BLState.Stage = BS_FULL;
    LRT_SetInterval(BLReduceTimer, BACKLIGHTREDUCE);
    LRT_Start(BLReduceTimer);
    PMUBL_UpdateValues(BLState.Value, true);
    if (UnlockGUI) GUI_SetLockState(false);
    __restore_interrupts(intflags);
}

TBLSTAGE PMUBL_GetBacklightStage(void)
{
    return BLState.Stage;
}
