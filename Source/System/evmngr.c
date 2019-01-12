// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "evmngr.h"

static pDLIST EventsList;

static boolean EM_AddEvent(pEVENT Event)
{
    return ((Event == NULL) || (DL_AddItem(EventsList, Event) == NULL)) ? false : true;
}

static boolean EM_DeleleEvent(void)
{
    return DL_DeleteFirstItem(EventsList);
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
        switch(tmpEvent->Event)
        {
        case ET_PENPRESSED:
            break;
        case ET_PENRELEASED:
            break;
        case ET_PENMOVED:
            break;
        case ET_ONPAINT:
            break;
        case ET_PWRKEY:
            break;
        case ET_ONTIMER:
            break;
        default:
            break;
        }
        EM_DeleleEvent();
    }
}





