// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "gpt.h"

static TGPTSTATE GPTStatus;

static uint16_t GPT_GetStatus(void)
{
    return GPTIMER_STA;
}

static void GPT_PowerUp(void)
{
    PCTL_PowerUp(PD_GPT);
}

static void GPT_PowerDown(void)
{
    PCTL_PowerDown(PD_GPT);
}

static boolean GPT_IsPoweredUp(void)
{
    return PCTL_GetPeripheralPowerStatus(PD_GPT);
}

static void GPT_UpdatePowerState(void)
{
    if (!GPTStatus.GPTEnabled) GPT_PowerDown();
}

static void GPT_InterruptHandler(void)
{
    uint16_t Status = GPT_GetStatus();

    do
    {
        if ((Status & GPT1_TO) && (GPTStatus.GPT.GPT1_Handler != NULL)) GPTStatus.GPT.GPT1_Handler();
        if ((Status & GPT2_TO) && (GPTStatus.GPT.GPT2_Handler != NULL)) GPTStatus.GPT.GPT2_Handler();
        Status = GPT_GetStatus();
    }
    while (Status);
}

static boolean GPT_RegisterInterrupt(void)
{
#ifdef USEINTERRUPTS
    GPTStatus.GPT.GPTIntsRegistered = NVIC_RegisterIRQ(IRQ_GPT_CODE, GPT_InterruptHandler, IRQ_SENS_EDGE, true);
#else
    GPTStatus.GPT.GPTIntsRegistered = false;
#endif

    return GPTStatus.GPT.GPTIntsRegistered;
}

static boolean GPT_TryUnregisterInterrupt(void)
{
    if (!GPTStatus.GPT.GPTIntsRegistered) return true;
    if ((GPTStatus.GPT.GPT1_Handler != NULL) ||
            (GPTStatus.GPT.GPT2_Handler != NULL)) return false;

#ifdef USEINTERRUPTS
    GPTStatus.GPT.GPTIntsRegistered = !NVIC_UnregisterIRQ(IRQ_GPT_CODE);
#else
    GPTStatus.GPT.GPTIntsRegistered = false;
#endif
    return !GPTStatus.GPT.GPTIntsRegistered;
}

void GPT_InitializeTimers(void)
{
    if (GPTStatus.GPT.GPTIntsRegistered) GPT_TryUnregisterInterrupt();
    if (!GPT_IsPoweredUp()) GPT_PowerUp();                                                          //Enable clock for GPT to initialize it
    GPTIMER1_CON = 0;                                                                               //Disable GPT1
    GPTIMER2_CON = 0;                                                                               //Disable GPT2
    if (!(GPTIMER4_CON & GPT4_LOCK)) GPTIMER4_CON &= ~GPT4_Enable;                                  //Disable GPT4 if it not locked
    memset(&GPTStatus, 0x00, sizeof(GPTStatus));
    GPTStatus.GPT.GPT4_Enabled = GPTIMER4_CON & GPT4_Enable;                                        //Update GPT4 status
    GPT_UpdatePowerState();                                                                         //Disable clock for GPT
}

boolean GPT_StartTimer(TGPT Index)
{
    boolean Result = false;

    if (!GPT_IsPoweredUp()) GPT_PowerUp();

    switch (Index)
    {
    case GP_TIMER1:
        GPTIMER1_CON |= GPT_Enable;
        Result = GPTStatus.GPT.GPT1_Enabled = (GPTIMER1_CON & GPT_Enable) ? true : false;
        break;
    case GP_TIMER2:
        GPTIMER2_CON |= GPT_Enable;
        Result = GPTStatus.GPT.GPT2_Enabled = (GPTIMER2_CON & GPT_Enable) ? true : false;
        break;
    case GP_TIMER4:
        if (!(GPTIMER4_CON & GPT4_LOCK)) GPTIMER4_CON |= GPT4_Enable;                               //Try to enable timer
        Result = GPTStatus.GPT.GPT4_Enabled = (GPTIMER4_CON & GPT4_Enable) ? true : false;
        break;
    }

    GPT_UpdatePowerState();
    return Result;
}

boolean GPT_StopTimer(TGPT Index)
{
    boolean Result = false;

    if (!GPT_IsPoweredUp()) GPT_PowerUp();

    switch (Index)
    {
    case GP_TIMER1:
        GPTIMER1_CON &= ~GPT_Enable;
        Result = !(GPTStatus.GPT.GPT1_Enabled = (GPTIMER1_CON & GPT_Enable) ? true : false);
        break;
    case GP_TIMER2:
        GPTIMER2_CON &= ~GPT_Enable;
        Result = !(GPTStatus.GPT.GPT2_Enabled = (GPTIMER2_CON & GPT_Enable) ? true : false);
        break;
    case GP_TIMER4:
        if (!(GPTIMER4_CON & GPT4_LOCK)) GPTIMER4_CON &= ~GPT4_Enable;                              //Try to disable timer
        Result = !(GPTStatus.GPT.GPT4_Enabled = (GPTIMER4_CON & GPT_Enable) ? true : false);
        break;
    }

    GPT_UpdatePowerState();
    return Result;
}

uint32_t GPT_Get26MTicksCount(void)
{
    return (GPTStatus.GPT.GPT4_Enabled) ? GPTIMER4_DAT : 0;
}

boolean GPT_SetupTimer(TGPT Index, uint16_t Frequency, boolean Arepeat, void (*Handler)(void), boolean Start)
{
    boolean  Result = false;
    uint32_t GPTValue;

    switch (Index)
    {
    case GP_TIMER1:
        if (!GPT_IsPoweredUp()) GPT_PowerUp();
        GPTIMER1_CON = 0;
        GPTStatus.GPT.GPT1_Enabled = (GPTIMER1_CON & GPT_Enable) ? true : false;

        if (Frequency > (MAX_GPT_FREQ >> 1)) break;
        if (!Frequency)
        {
            GPTStatus.GPT.GPT1_Handler = NULL;
            GPT_TryUnregisterInterrupt();
            break;
        }

        GPTValue = MAX_GPT_FREQ / Frequency - 1;
        if ((MAX_GPT_FREQ % Frequency) >= (Frequency >> 1)) GPTValue++;

        GPTStatus.GPT.GPT1_Handler = Handler;
        GPTStatus.GPT.GPT1_AutoRep = Arepeat;
        GPTStatus.GPT.GPT1_Prescaler = GPT_PS16384;
        GPTStatus.GPT.GPT1_Value = GPTValue;

        GPTIMER1_PS = GPT_PS(GPTStatus.GPT.GPT1_Prescaler);
        GPTIMER1_DAT = GPTStatus.GPT.GPT1_Value;

        if (!GPTStatus.GPT.GPTIntsRegistered && (Handler != NULL)) GPT_RegisterInterrupt();
        else GPT_TryUnregisterInterrupt();

        GPTIMER1_CON = ((Arepeat) ? GPT_ARepeat : GPT_OneShot);
        if (Start) GPTIMER1_CON |= GPT_Enable;
        GPTStatus.GPT.GPT1_Enabled = GPTIMER1_CON & GPT_Enable;
        Result = true;
        break;
    case GP_TIMER2:
        if (!GPT_IsPoweredUp()) GPT_PowerUp();
        GPTIMER2_CON = 0;
        GPTStatus.GPT.GPT2_Enabled = (GPTIMER2_CON & GPT_Enable) ? true : false;

        if (Frequency > (MAX_GPT_FREQ >> 1)) break;
        if (!Frequency)
        {
            GPTStatus.GPT.GPT2_Handler = NULL;
            GPT_TryUnregisterInterrupt();
            break;
        }

        GPTValue = MAX_GPT_FREQ / Frequency - 1;
        if ((MAX_GPT_FREQ % Frequency) >= (Frequency >> 1)) GPTValue++;

        GPTStatus.GPT.GPT2_Handler = Handler;
        GPTStatus.GPT.GPT2_AutoRep = Arepeat;
        GPTStatus.GPT.GPT2_Prescaler = GPT_PS16384;
        GPTStatus.GPT.GPT2_Value = GPTValue;

        GPTIMER2_PS = GPT_PS(GPTStatus.GPT.GPT2_Prescaler);
        GPTIMER2_DAT = GPTStatus.GPT.GPT2_Value;

        if (!GPTStatus.GPT.GPTIntsRegistered && (Handler != NULL)) GPT_RegisterInterrupt();
        else GPT_TryUnregisterInterrupt();

        GPTIMER2_CON = ((Arepeat) ? GPT_ARepeat : GPT_OneShot);
        if (Start) GPTIMER2_CON |= GPT_Enable;
        GPTStatus.GPT.GPT2_Enabled = GPTIMER2_CON & GPT_Enable;
        Result = true;
        break;
    default:
        break;
    }

    GPT_UpdatePowerState();
    return Result;
}

void GPT_SleepTimers(void)
{
    if (GPTStatus.GPTEnabled)
    {
        if (GPTStatus.GPT.GPT1_Enabled) GPTIMER1_CON &= ~GPT_Enable;
        if (GPTStatus.GPT.GPT2_Enabled) GPTIMER2_CON &= ~GPT_Enable;
        if (!(GPTIMER4_CON & GPT4_LOCK) && GPTStatus.GPT.GPT4_Enabled) GPTIMER4_CON &= ~GPT4_Enable;
        GPT_PowerDown();
#ifdef USEINTERRUPTS
        if (GPTStatus.GPT.GPTIntsRegistered) NVIC_DisableIRQ(IRQ_GPT_CODE);
#endif
    }
}

void GPT_ResumeTimers(void)
{
    if (GPTStatus.GPTEnabled)
    {
        GPT_PowerUp();
        if (GPTStatus.GPT.GPT1_Enabled) GPTIMER1_CON |= GPT_Enable;
        if (GPTStatus.GPT.GPT2_Enabled) GPTIMER2_CON |= GPT_Enable;
        if (!(GPTIMER4_CON & GPT4_LOCK) && GPTStatus.GPT.GPT4_Enabled) GPTIMER4_CON |= GPT4_Enable;
#ifdef USEINTERRUPTS
        if (GPTStatus.GPT.GPTIntsRegistered) NVIC_EnableIRQ(IRQ_GPT_CODE);
#endif
    }
}

void GPT4_Busy_Wait_us(uint32_t us)
{
    uint32_t start_tick, timeout_tick;
    uint32_t cur_tick, elapse_tick;
    boolean  GPT4Enabled = GPTStatus.GPT.GPT4_Enabled;

    if (!GPT4Enabled) GPT_StartTimer(GP_TIMER4);

    timeout_tick = GPT4_TIME_TO_TICK_US(us);
    start_tick   = GPT_Get26MTicksCount();

    do
    {
        cur_tick = GPT_Get26MTicksCount();

        if (start_tick <= cur_tick) elapse_tick = cur_tick - start_tick;
        else elapse_tick = (GPT4_MAX_TICK_CNT - start_tick) + cur_tick;
    }
    while(timeout_tick > elapse_tick);

    if (!GPT4Enabled) GPT_StopTimer(GP_TIMER4);
}

