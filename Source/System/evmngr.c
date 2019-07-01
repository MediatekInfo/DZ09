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
#include "evmngr.h"

static pDLIST EventsList;

static boolean EM_AddEvent(pEVENT Event)
{
    return ((Event == NULL) || (DL_AddItem(EventsList, Event) == NULL)) ? false : true;
}

static pEVENT EM_GetTopEvent(void)
{
    pDLITEM tmpItem = DL_GetFirstItem(EventsList);

    return (tmpItem != NULL) ? tmpItem->Data : NULL;
}

boolean EM_Initialize(void)
{
    if (EventsList == NULL) EventsList = DL_Create(0);
    if (EventsList == NULL) return false;

    return true;
}

boolean EM_PostEvent(TEVTYPE Type, void *Object, void *Param, uint32_t ParamSz)
{
    pEVENT tmpEvent;

    if (Param == NULL) ParamSz = 0;

    tmpEvent = malloc(sizeof(TEVENT) + ParamSz);
    if (tmpEvent != NULL)
    {
        tmpEvent->Event = Type;
        tmpEvent->Object = Object;
        tmpEvent->ParamSz = ParamSz;
        if (Param != NULL) memcpy(tmpEvent->Param, Param, ParamSz);
        if (EM_AddEvent(tmpEvent)) return true;
        else free(tmpEvent);
    }
    return false;
}

void EM_ProcessEvents(void)
{
    pEVENT tmpEvent;

    while((tmpEvent = EM_GetTopEvent()) != NULL)
    {
        DL_DeleteFirstItem(EventsList);

        switch(tmpEvent->Event)
        {
        case ET_PENPRESSED:
        {
            pPENEVENT TSEvent = (pPENEVENT)tmpEvent->Param;

            if (tmpEvent->ParamSz)
            {
//                GUI_OnPenPressed(TSEvent);
                DebugPrint("Pen %u Pressed x= %d, y= %d\r\n", TSEvent->PenIndex, TSEvent->PXY.x, TSEvent->PXY.y);
            }
        }
        break;
        case ET_PENRELEASED:
        {
            pPENEVENT TSEvent = (pPENEVENT)tmpEvent->Param;

            if (tmpEvent->ParamSz)
            {
//                GUI_OnPenReleased(TSEvent);
                DebugPrint("Pen %u Released x= %d, y= %d\r\n", TSEvent->PenIndex, TSEvent->PXY.x, TSEvent->PXY.y);
            }
        }
        break;
        case ET_PENMOVED:
        {
            pPENEVENT TSEvent = (pPENEVENT)tmpEvent->Param;

            if (tmpEvent->ParamSz)
            {
//                GUI_OnPenMoved(TSEvent);
                DebugPrint("Pen %u Moved x= %d, y= %d\r\n", TSEvent->PenIndex, TSEvent->PXY.x, TSEvent->PXY.y);
            }
        }
        break;
        case ET_ONPAINT:
            GUI_OnPaintHandler((pPAINTEV)tmpEvent->Param);
            break;
        case ET_PWRKEY:
            break;
        case ET_ONTIMER:
            break;
        default:
            break;
        }
        free(tmpEvent);
    }
}





