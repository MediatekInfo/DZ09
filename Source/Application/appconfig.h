#ifndef _APPCONFIG_H_
#define _APPCONFIG_H_

/* LCD interface settings */
#define LCD_XRESOLUTION 240
#define LCD_YRESOLUTION 240
#define LCD_SIF_TIMINGS (LCDIF_WR_2ND(0) | LCDIF_WR_1ST(0) | LCDIF_RD_2ND(0) |\
                         LCDIF_RD_1ST(0) | LCDIF_CSH(0) | LCDIF_CSS(0))
#define LCD_SIF_CON     (LCDIF_SIF0_SIZE8B | LCDIF_SIF0_3WIRE | LCDIF_SIF0_DIV2 | LCDIF_SIF0_HW_CS) //LCD serial interface configuration
#define LCD_SIF_WROI    (LCDIF_F_RGB | LCDIF_F_PADDLSB | LCDIF_F_RGB888 | LCDIF_F_ITF_8B)           //LCD module data format
#define LCD_BACKCOLOR   clBlack
#define _ILI9341_LCD_DRIVER_
//#define _NO_LCD_DRIVER_

/* Touch screen interface settings */
#define _FT6236_TS_DRIVER_
//#define _NO_TS_DRIVER_

/* Application pins configuration */

/* LCD interface */
#define LCD_RESET       GPIO45                                                                      //LCDIF Reset
#define LCD_RESET_MODE  GPIO45_MODE_LSRSTB
#define LCD_CE          GPIO46                                                                      //LCDIF Chip Select
#define LCD_CE_MODE     GPIO46_MODE_LSCE_B0
#define LCD_SCK         GPIO47                                                                      //LCDIF Clock
#define LCD_SCK_MODE    GPIO47_MODE_LSCK0
#define LCD_SDA         GPIO48                                                                      //LCDIF Data IO line 0
#define LCD_SDA_MODE    GPIO48_MODE_LSDA0
//#define LCD_SDA1        GPIO49
//#define LCD_SDA1_MODE   GPIO49_MODE_LSA0DA0                                                       //LCDIF Data IO line 1
//#define LCD_LPTE        GPIO50
//#define LCD_LPTE_MODE   GPIO50_MODE_LPTE                                                          //LCDIF Tearing input

/* Touch screen pins configuration */
#define CPT_SCL         GPIO14                                                                      //Touch panel I2C clock line
#define CPT_SCL_MODE    GPIO14_MODE_IO
#define CPT_SDA         GPIO15                                                                      //Touch panel I2C data line
#define CPT_SDA_MODE    GPIO15_MODE_IO
#define CPT_RST         GPIO20                                                                      //Touch panel reset
#define CPT_RST_MODE    GPIO20_MODE_IO
#define CPT_INT         GPIO52                                                                      //Touch panel interrupt
#define CPT_INT_MODE    GPIO52_MODE_EINT23
#define CPT_INT_NUM     EINT23

#include "appdrivers.h"

#endif /* _APPCONFIG_H_ */
