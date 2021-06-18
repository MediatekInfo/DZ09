/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2021 - 2019 AJScorp
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
#ifndef _EVMNGR_H_
#define _EVMNGR_H_

typedef enum tag_EVTYPE
{
    ET_UNKNOWN,
    /* Touchscreen events */
    ET_PENPRESS,
    ET_PENRELEASE,
    ET_PENMOVE,
    /* GUI events */
    ET_ONPAINT,
    /* System events */
    ET_PWRKEY,
    ET_ONTIMER
} TEVTYPE;

typedef struct tag_EVENT
{
    TEVTYPE  Event;
    void     *Object;
    uint32_t ParamSz;
    uint8_t  Param[];
} TEVENT, *pEVENT;

extern boolean EM_Initialize(void);
extern boolean EM_PostEvent(TEVTYPE Type, void *Object, void *Param, uint32_t ParamSz);
extern void EM_ProcessEvents(void);

#endif /* _EVMNGR_H_ */
