// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "lcdif.h"

pLAYER LCDIF_LAYER[LCDIF_NUMLAYERS] = {(volatile pLAYER) &LCDIF_LAYER0BASE,
                                       (volatile pLAYER) &LCDIF_LAYER1BASE,
                                       (volatile pLAYER) &LCDIF_LAYER2BASE,
                                       (volatile pLAYER) &LCDIF_LAYER3BASE
                                      };

TSCREEN LCDScreen;
pDLIST  LCDIFQueue;

void LCDIF_WriteCommand(uint8_t Cmd)
{
    LCDIF_SCMD0 = Cmd;
}

void LCDIF_WriteData(uint8_t Data)
{
    LCDIF_SDAT0 = Data;
}

uint8_t LCDIF_ReadData(void)
{
    return LCDIF_SDAT0;
}

void LCDIF_SetClock(TLCDSCLOCK Clock)
{
    LCD_SERIAL_CLOCK_REG = (LCD_SERIAL_CLOCK_REG & ~LCD_SERIAL_CLOCK_MASK) | LCD_SERIAL_CLOCK(Clock);
}

void LCDIF_ISR(void)
{

}

boolean RegisterLCDIF_ISR(void)
{
    return NVIC_RegisterIRQ(IRQ_LCD_CODE, LCDIF_ISR, IRQ_SENS_LEVEL, true);
}

boolean UnregisterLCDIF_ISR(void)
{
    return NVIC_UnregisterIRQ(IRQ_LCD_CODE);
}

void LCDIF_DisableInterface(void)
{
    LCDIF_INTEN = 0;                                                                                //Disable LCDIF interrupts
    LCDIF_START = LCDIF_INT_RESET;

    UnregisterLCDIF_ISR();

    LCDDRV_Sleep();
    PCTL_PowerDown(PD_LCD);                                                                         //Power down LCD controller
    PCTL_PowerDown(PD_SLCD);                                                                        //Power down serial interface
    LCDIFQueue = DL_Delete(LCDIFQueue, true);
}

boolean LCDIF_Initialize(void)
{
    memset(&LCDScreen, 0x00, sizeof(LCDScreen));

    LCDIF_SetClock(LCD_CLOCK_MPLL_DIV4);
    PCTL_PowerUp(PD_SLCD);                                                                          //Power up LCD serial interface
    PCTL_PowerUp(PD_LCD);                                                                           //Power up LCD controller

    LCDScreen.ScreenRgn = Rect(0, 0, LCD_XRESOLUTION - 1, LCD_YRESOLUTION - 1);
    LCDScreen.ScreenOffset = Point(0, 0);
    LCDScreen.ScreenCount = 1;
    LCDScreen.ScreenIndex = 0;

    LCDScreen.VLayer[0].LayerEnMask = LCDIF_L0EN;
    LCDScreen.VLayer[1].LayerEnMask = LCDIF_L1EN;
    LCDScreen.VLayer[2].LayerEnMask = LCDIF_L2EN;
    LCDScreen.VLayer[3].LayerEnMask = LCDIF_L3EN;

    LCDIF_INTEN = 0;                                                                                //Disable LCDIF interrupts
    LCDIF_START = LCDIF_INT_RESET;                                                                  //Assert LCD controller internal Reset
    LCDIF_START = 0;                                                                                //Release LCD controller internal Reset

    if (LCDIFQueue == NULL)  LCDIFQueue = DL_Create(0);
    if ((LCDIFQueue == NULL) || !RegisterLCDIF_ISR())
    {
        if (LCDIFQueue == NULL)
        {
            DebugPrint("Failed! (Insufficient memory)\r\n");
            DebugPrint(" Total used %uKiB\r\n", GetTotalUsedMemory() >> 10);
        }
        else DebugPrint("Failed! (Unable to register LCD ISR 0x%02X)\r\n", IRQ_LCD_CODE);
        LCDIF_DisableInterface();
        return false;
    }

    LCDIF_RSTB = LCDIF_RESET0;                                                                      //Assert LCD panel reset
    USC_Pause_us(1000);                                                                             //Delay 1ms for reset
    LCDIF_RSTB = LCDIF_RESET1;                                                                      //Release LCD panel reset

    LCDIF_SIF0_TIMING = LCD_SIF_TIMINGS;                                                            //Setup SIF timing
    LCDIF_SIF_CON = LCD_SIF_CON;                                                                    //Setup interface configuration

    LCDIF_WROICON = LCD_SIF_WROI;                                                                   //Setup LCD data format
    LCDIF_WROICADD = LCDIF_CSIF0;                                                                   //MT6261 has only one serial interface
    LCDIF_WROIDADD = LCDIF_DSIF0;
    LCDIF_WROIOFS = LCDIF_WROIOFX(0) | LCDIF_WROIOFY(0);
    LCDIF_WROISIZE = LCDIF_WROICOL(LCD_XRESOLUTION) | LCDIF_WROIROW(LCD_YRESOLUTION);
    LCDIF_WROI_BGCLR = LCD_BACKCOLOR;

    if (LCDDRV_Initialize())
    {
        LCDIF_INTEN = LCDIF_CPL;                                                                    //Enable LCD interrupts
        DebugPrint("Complete.\r\n");
        return true;
    }

    LCDIF_DisableInterface();
    DebugPrint("Failed! (Can't initialize LCD driver)\r\n");
    return false;
}

