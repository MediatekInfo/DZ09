// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "gpio.h"

void GPIO_Initialize(void)
{
    GPIO_DIR0_CLR = GPIO_DIR0_MASK;                                                                 //Set all GPIO input
    GPIO_DIR1_CLR = GPIO_DIR1_MASK;

    GPIO_PULLEN0_CLR  = PULLEN0_MASK;                                                               //Disable Pullup/PullDown
    GPIO_PULLEN1_CLR  = PULLEN1_MASK;
    GPIO_RESEN0_0_CLR = RESEN0_0_MASK;
    GPIO_RESEN0_1_CLR = RESEN0_1_MASK;
    GPIO_RESEN1_0_CLR = RESEN1_0_MASK;
    GPIO_RESEN1_1_CLR = RESEN1_1_MASK;

    GPIO_MODE0_CLR = GPIO_MODE0MASK;                                                                //Set pins mode
    GPIO_MODE1_CLR = GPIO_MODE1MASK;
    GPIO_MODE2_CLR = GPIO_MODE2MASK;
    GPIO_MODE3_CLR = GPIO_MODE3MASK;
    GPIO_MODE4_CLR = GPIO_MODE4MASK;
    GPIO_MODE5_CLR = GPIO_MODE5MASK;
    GPIO_MODE6_CLR = GPIO_MODE6MASK;

    GPIO_SetupMode(GPIO51, GPMODE(M51RESETB));
}

void GPIO_SetupMode(uint32_t Pin, uint32_t Flags)
{
    if (Pin <= GPIOMAX)
    {
        if (Flags & GPDO) GPIO_SETDIROUT(Pin);
        else GPIO_SETDIRIN(Pin);

        if (Flags & GPDIEN) GPIO_SETINPUTEN(Pin);
        else GPIO_SETINPUTDIS(Pin);

        if (Flags & GPPDN) GPIO_SETPULLDOWN(Pin);
        else GPIO_SETPULLUP(Pin);

        if (Flags & GPPULLEN) GPIO_PULLENABLE(Pin);
        else GPIO_PULLDISABLE(Pin);

        if (Flags & GPSMT) GPIO_SMTENABLE(Pin);
        else GPIO_SMTDISABLE(Pin);

        GPIO_SETMODE(Pin, (Flags >> 8) & GPIO_MODEMASK);
    }
}
