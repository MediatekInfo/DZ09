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
#ifndef _BACKLIGHT_H_
#define _BACKLIGHT_H_

typedef enum tag_BLMODE
{
    BM_ISINK,
    BM_PWM,
    BM_MODES
} TBLMODE;

typedef struct tag_BLSTATE
{
    uint32_t Value;
    boolean  Enabled;
    boolean  Reduced;
    TBLMODE  Mode;
} TBLSTATE;

extern void PMUBL_Initialize(void);
extern void PMUBL_SetBacklightMode(TBLMODE Mode);
extern void PMUBL_SetupValue(uint32_t Value);
extern void PMUBL_TurnOn(boolean TurnOn);
extern void PMUBL_RestartReduceTimer(void);

#endif /* _BACKLIGHT_H_ */
