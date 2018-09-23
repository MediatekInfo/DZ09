#ifndef _GPT_H_
#define _GPT_H_

#define FREERUNFREQ                 26000000UL
#define MAX_GPT_FREQ                16384                                                           //32kHz source and /2 prescaler

#define GPTIMER1_CON                (*(volatile uint32_t*)(GPT_base + 0x0000))
#define GPT_OneShot                 (0 << 14)
#define GPT_ARepeat                 (1 << 14)
#define GPT_Enable                  (1 << 15)
#define GPTIMER1_DAT                (*(volatile uint32_t*)(GPT_base + 0x0004))
#define GPTIMER2_CON                (*(volatile uint32_t*)(GPT_base + 0x0008))
#define GPT_OneShot                 (0 << 14)
#define GPT_ARepeat                 (1 << 14)
#define GPT_Enable                  (1 << 15)
#define GPTIMER2_DAT                (*(volatile uint32_t*)(GPT_base + 0x000C))
#define GPTIMER_STA                 (*(volatile uint32_t*)(GPT_base + 0x0010))
#define GPT1_TO                     (1 << 0)                                                        //Read Clear
#define GPT2_TO                     (1 << 1)                                                        //Read Clear
#define GPTIMER1_PS                 (*(volatile uint32_t*)(GPT_base + 0x0014))
#define GPT_PS(v)                   (((v) & 0x07) << 0)
#define GPT_PS16kHz                 0
#define GPT_PS8kHz                  1
#define GPT_PS4kHz                  2
#define GPT_PS2kHz                  3
#define GPT_PS1kHz                  4
#define GPT_PS512Hz                 5
#define GPT_PS256Hz                 6
#define GPT_PS128Hz                 7
#define GPTIMER2_PS                 (*(volatile uint32_t*)(GPT_base + 0x0018))
#define GPT_PS(v)                   (((v) & 0x07) << 0)
#define GPT_PS16384                 0
#define GPT_PS8192                  1
#define GPT_PS4069                  2
#define GPT_PS2048                  3
#define GPT_PS1024                  4
#define GPT_PS512                   5
#define GPT_PS256                   6
#define GPT_PS128                   7
#define GPTIMER4_CON                (*(volatile uint32_t*)(GPT_base + 0x0028))
#define GPT4_Enable                 (1 << 0)
#define GPT4_LOCK                   (1 << 1)
#define GPTIMER4_DAT                (*(volatile uint32_t*)(GPT_base + 0x002C))

typedef enum tag_GPT
{
    GP_TIMER1 = 0,
    GP_TIMER2 = 1,
    GP_TIMER4 = 3
} TGPT, *pGPT;

typedef union tag_GPTSTATE
{
    struct
    {
        unsigned GPT1_Enabled       : 1;
        unsigned GPT2_Enabled       : 1;
        unsigned                    : 1;
        unsigned GPT4_Enabled       : 1;
        unsigned                    : 4;
        unsigned GPT1_AutoRep       : 1;
        unsigned GPT2_AutoRep       : 1;
        unsigned                    : 2;
        unsigned GPTIntsRegistered  : 1;
        unsigned                    : 3;
        void     (*GPT1_Handler)(void);
        uint16_t GPT1_Prescaler;
        uint16_t GPT1_Value;
        void     (*GPT2_Handler)(void);
        uint16_t GPT2_Prescaler;
        uint16_t GPT2_Value;
    } GPT;
    uint8_t GPTEnabled;
} TGPTSTATE, *pGPTSTATE;

extern void     GPT_InitializeTimers(void);
extern boolean  GPT_StartTimer(TGPT Index);
extern boolean  GPT_StopTimer(TGPT Index);
extern uint32_t GPT_Get26MTicksCount(void);
extern boolean  GPT_SetupTimer(TGPT Index, uint16_t Freq, boolean Arepeat, void (*Handler)(void), boolean Start);
extern void     GPT_SleepTimers(void);
extern void     GPT_ResumeTimers(void);

#endif /* _GPT_H_ */
