// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "init.h"

void Init(void)
{
    MPU_Initialize();                                                                               // Setup system cache
    PCTL_Initialize();                                                                              // Power down peripherals by default
    GPIO_Initialize();                                                                              // Set GPIO to default state
    DBG_Initialize();                                                                               // Setup debug interface

    DebugPrint("\r\n--System initialization--\r\n");
    USC_StartCounter();




//    USART_Initialize(DBG_USART, DBG_BAUDRATE, NULL, USART_EnFlag);
//    DebugPrint("Initialization!\r\n");
//
//    InitializeMemoryPool();
//
//
////////////////////////////////////////////////////////////
//    PMU_DisableUSBDownloaderWDT();
////    PMU_SetVibrationOutput(true);
//    PMU_SetISINKMode(false);
//    PMU_SetISINKParameters(ISINK_CH0, IC_8mA, true);
////////////////////////////////////////////////////////////
//

}
