// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "lcdif.h"

pLAYER LCDIF_LAYER[LCDIF_NUMLAYERS] = {(volatile pLAYER) &LCDIF_LAYER0BASE,
                                       (volatile pLAYER) &LCDIF_LAYER1BASE,
                                       (volatile pLAYER) &LCDIF_LAYER2BASE,
                                       (volatile pLAYER) &LCDIF_LAYER3BASE
                                      };

TLCDINFO LCDInfo;
TSCREEN LCDScreen;

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

void LCDIF_Initialize(void)
{
    memset(&LCDInfo, 0x00, sizeof(TLCDINFO));
    memset(&LCDScreen, 0x00, sizeof(LCDScreen));

    LCDIF_SetClock(LCD_CLOCK_MPLL_DIV4);
    PCTL_PowerUp(PD_SLCD);                                                                          //Power up LCD serial interface
    PCTL_PowerUp(PD_LCD);                                                                           //Power up LCD controller

    LCDInfo.HWLCD_XMax = LCD_XRESOLUTION - 1;
    LCDInfo.HWLCD_YMax = LCD_YRESOLUTION - 1;
    LCDInfo.HWLCD_Command = LCDIF_WriteCommand;
    LCDInfo.HWLCD_WRData  = LCDIF_WriteData;
    LCDInfo.HWLCD_RDData  = LCDIF_ReadData;


}

