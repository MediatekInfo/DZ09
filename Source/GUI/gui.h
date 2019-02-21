#ifndef _GUI_H_
#define _GUI_H_

typedef struct tag_PENEVENT
{
    uint32_t PenIndex;
    TPOINT   PXY;
} TPENEVENT, *pPENEVENT;

extern boolean GUI_Initialize(void);

#endif /* _GUI_H_ */
