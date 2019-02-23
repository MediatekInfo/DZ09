// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "gui.h"

static pDLIST GUIWinZOrder[LCDIF_NUMLAYERS];

boolean GUI_Initialize(void)
{
    uint32_t i;
    boolean  Result;

    DebugPrint("GUI subsystem initialization:\r\n");

    DebugPrint(" LCD interface initialization...");
    GPIO_SetupMode(LCD_RESET, GPMODE(LCD_RESET_MODE));                                              //Setup Reset pin
    GPIO_SetupMode(   LCD_CE, GPMODE(LCD_CE_MODE));                                                 //Setup CS pin
    GPIO_SetupMode(  LCD_SCK, GPMODE(LCD_SCK_MODE));                                                //Setup Clock pin
    GPIO_SetupMode(  LCD_SDA, GPMODE(LCD_SDA_MODE));                                                //Setup Data pin
    Result = LCDIF_Initialize();                                                                    //Initialize subsystem

    if (Result)
    {
        for(i = 0; i < LCDIF_NUMLAYERS; i++)
        {
// TODO (scorp#1#): May need to check for objects in the lists.
            if (GUIWinZOrder[i] == NULL) GUIWinZOrder[i] = DL_Create(0);
            if (GUIWinZOrder[i] == NULL)
            {
                while(i--)
                {
                    free(GUIWinZOrder[i]);
                    GUIWinZOrder[i] = NULL;
                }
                LCDIF_DisableInterface();
                Result = false;
                break;
            }
        }
    }
    if (Result) TSDRV_Initialize();
    else DebugPrint("GUI initialization failed!\r\n");

    return Result;
}
