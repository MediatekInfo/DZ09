#ifndef _EVMNGR_H_
#define _EVMNGR_H_

typedef enum tag_EVTYPE
{
    ET_UNKNOWN,
    /* Touchscreen events */
    ET_PENPRESSED,
    ET_PENRELEASED,
    ET_PENMOVED,
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
