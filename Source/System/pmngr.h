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
