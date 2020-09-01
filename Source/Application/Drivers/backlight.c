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
#include "backlight.h"

TBLSTATE BLState;
pTIMER   BLReduceTimer;

static void PMUBL_UpdateValues(uint32_t Value, boolean TurnOn)
{
    if      (Value < 20) PMU_SetISINKParameters(BACKLIGHTCHNL, IC_4mA, TurnOn);
    else if (Value < 40) PMU_SetISINKParameters(BACKLIGHTCHNL, IC_8mA, TurnOn);
    else if (Value < 60) PMU_SetISINKParameters(BACKLIGHTCHNL, IC_12mA, TurnOn);
    else if (Value < 80) PMU_SetISINKParameters(BACKLIGHTCHNL, IC_16mA, TurnOn);
    else PMU_SetISINKParameters(BACKLIGHTCHNL, IC_20mA, TurnOn);
}

static void PMUBL_HideTimerHandler(pTIMER Timer)
{
    if (BLState.Reduced)
    {
        PMUBL_UpdateValues(BLState.Value, false);
        LRT_Stop(BLReduceTimer);
    }
    else
    {
        BLState.Reduced = true;
        PMUBL_UpdateValues(BLState.Value / 3, BLState.Enabled);
        LRT_SetInterval(BLReduceTimer, BACKLIGHTOFF);
    }
}

void PMUBL_Initialize(void)
{
    BLReduceTimer = LRT_Create(BACKLIGHTREDUCE, NULL, PMUBL_HideTimerHandler, TF_DIRECT | TF_AUTOREPEAT);
    memset(&BLState, 0x00, sizeof(TBLSTATE));

    PMU_DisableISINKs();
    PMU_SetISINKMode(BACKLIGHTPWM);

    PMUBL_TurnOn(false);
    PMUBL_SetupValue(BACKLIGHTDEFVAL);
}

void PMUBL_SetupValue(uint32_t Value)
{
    uint32_t iflags = DisableInterrupts();

    BLState.Value = Value;
    if (!BLState.Reduced) PMUBL_UpdateValues(BLState.Value, BLState.Enabled);
    else PMUBL_UpdateValues(BLState.Value / 3, BLState.Enabled);

    RestoreInterrupts(iflags);
}

void PMUBL_TurnOn(boolean TurnOn)
{
    BLState.Enabled = TurnOn;

    if (!TurnOn)
    {
        uint32_t iflags = DisableInterrupts();

        LRT_Stop(BLReduceTimer);
        PMUBL_UpdateValues(BLState.Value, BLState.Enabled);
        BLState.Reduced = false;
        RestoreInterrupts(iflags);
    }
    else PMUBL_RestartReduceTimer();
}

void PMUBL_RestartReduceTimer(void)
{
    uint32_t iflags = DisableInterrupts();

    BLState.Reduced = false;
    LRT_SetInterval(BLReduceTimer, BACKLIGHTREDUCE);
    LRT_Start(BLReduceTimer);
    PMUBL_UpdateValues(BLState.Value, BLState.Enabled);
    RestoreInterrupts(iflags);
}
