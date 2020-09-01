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
#ifndef _LRTIMER_H_
#define _LRTIMER_H_

typedef enum tag_MRFLAGS
{
    TF_NONE       = 0,
    TF_ENABLED    = (1 << 0),
    TF_AUTOREPEAT = (1 << 1),
    TF_DIRECT     = (1 << 2)
} TMRFLAGS;

typedef struct tag_TIMER *pTIMER;
typedef struct tag_TIMER
{
    TMRFLAGS   Flags;
    uint32_t   Interval;
    int32_t    StartTicks;
    pHANDLE    Parent;
    void       (*Handler)(pTIMER);
} TTIMER, *pTIMER;

extern boolean LRT_Initialize(void);
extern pTIMER LRT_Create(uint32_t Interval, pHANDLE Parent, void (*Handler)(pTIMER), TMRFLAGS Flags);
extern boolean LRT_Destroy(pTIMER Timer);
extern boolean LRT_Start(pTIMER Timer);
extern boolean LRT_Stop(pTIMER Timer);
extern boolean LRT_SetMode(pTIMER Timer, TMRFLAGS Flags);
extern boolean LRT_SetInterval(pTIMER Timer, uint32_t Interval);

#endif /* _LRTIMER_H_ */
