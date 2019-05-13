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
#ifndef _USTIMER_H_
#define _USTIMER_H_

#define USC_FREQUENCY               1000000

#define USCNT_CON                   (*(volatile uint32_t *)(TOPSM_base + 0x0080))
#define USC_START                   (1 << 0)
#define USC_STOP                    (0 << 0)
#define USC_KEY                     (0x1153 << 16)
#define F32K_FM                     (*(volatile uint32_t *)(TOPSM_base + 0x0084))
#define USCNTI_VAL                  (*(volatile uint32_t *)(TOPSM_base + 0x0088))

#define USCNT_START_CODE            (USC_KEY | USC_START)
#define USCNT_STOP_CODE             (USC_KEY | USC_STOP)

extern void USC_StartCounter(void);
extern void USC_StopCounter(void);
extern int32_t USC_GetCurrentTicks(void);
extern void USC_Pause_us(uint32_t us);

#endif /* _USTIMER_H_ */
