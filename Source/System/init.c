// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "appinit.h"
#include "init.h"

void Init(void)
{
    DBG_Initialize();                                                                               // Setup debug interface
    DebugPrint("\r\n--System initialization--\r\n");
    MPU_Initialize();                                                                               // Setup system cache
    PCTL_Initialize();                                                                              // Power down peripherals by default
    GPIO_Initialize();                                                                              // Set GPIO to default state

    USC_StartCounter();

    DebugPrint("Initialize system memory pool - ");
    {
        size_t MemSize = InitializeMemoryPool();

        if (MemSize != -1) DebugPrint("%u KiB available\r\n", MemSize / 1024);
        else DebugPrint("failed!\r\n");
    }

    DebugPrint("Initialize event manager...");
    DebugPrint((EM_Initialize()) ? "Complete.\r\n" : "Failed\r\n");

    DebugPrint("Initialize NVICs...");
    NVIC_Initialize();
    DebugPrint("Complete.\r\n");

//
//
////////////////////////////////////////////////////////////
//    PMU_DisableUSBDownloaderWDT();
////    PMU_SetVibrationOutput(true);
//    PMU_SetISINKMode(false);
//    PMU_SetISINKParameters(ISINK_CH0, IC_8mA, true);
////////////////////////////////////////////////////////////
//

    APP_Initialize();

}
