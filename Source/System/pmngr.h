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
#ifndef _PMNGR_H_
#define _PMNGR_H_

typedef enum tag_PUPREASON
{
    PUR_UNKNOWN,
    PUR_RTCALARM,
    PUR_PWRKEY,
    PUR_CHARGER,
    PUR_WDT_HW,
    PUR_WDT_SW
} TPUPREASON;

typedef enum tag_PUPMODE
{
    PUM_UNKNOWN,
    PUM_NORMAL,
    PUM_RTCALARM,
    PUM_CHARGE
} TPUMODE;

extern void PMNGR_Initialize(void);
extern TPUPREASON PMNGR_GetPowerUpReason(void);

#endif /* _PMNGR_H_ */
