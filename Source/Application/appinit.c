// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "appinit.h"

boolean APP_Initialize(void)
{
    boolean Result = true;

    DebugPrint("LCD interface initialization...");
    GPIO_SetupMode(LCD_RESET, GPMODE(LCD_RESET_MODE));                                              //Setup Reset pin
    GPIO_SetupMode(   LCD_CE, GPMODE(LCD_CE_MODE));                                                 //Setup CS pin
    GPIO_SetupMode(  LCD_SCK, GPMODE(LCD_SCK_MODE));                                                //Setup Clock pin
    GPIO_SetupMode(  LCD_SDA, GPMODE(LCD_SDA_MODE));                                                //Setup Data pin
    Result &= LCDIF_Initialize();                                                                   //Initialize subsystem

    return Result;
}
