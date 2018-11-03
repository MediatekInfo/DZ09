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
