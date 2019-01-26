#ifndef _LRTIMER_H_
#define _LRTIMER_H_

typedef enum tag_MRFLAGS
{
    TF_ENABLED    = (1 << 0),
    TF_AUTOREPEAT = (1 << 1),
    TF_DIRECT     = (1 << 2)
} TMRFLAGS;

typedef struct tag_TIMER
{
    TSYSOBJECT Type;
    TMRFLAGS   Flags;
    uint32_t   Interval;
    int32_t    StartTicks;
    pHANDLE    Parent;
    void       (*Handler)(pHANDLE);
} TTIMER, *pTIMER;

extern boolean LRT_Initialize(void);
extern pTIMER LRT_Create(uint32_t Interval, pHANDLE Parent, void (*Handler)(pHANDLE), TMRFLAGS Flags);

#endif /* _LRTIMER_H_ */
