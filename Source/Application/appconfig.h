/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 - 2019 AJScorp
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; version 2 of the License.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/
#ifndef _APPCONFIG_H_
#define _APPCONFIG_H_

/* LCD interface settings */
#define LCD_XRESOLUTION 240
#define LCD_YRESOLUTION 240
#define LCD_SIF_TIMINGS (LCDIF_WR_2ND(0) | LCDIF_WR_1ST(0) | LCDIF_RD_2ND(0) |\
                         LCDIF_RD_1ST(0) | LCDIF_CSH(0) | LCDIF_CSS(0))
#define LCD_SIF_CON     (LCDIF_SIF0_SIZE8B | LCDIF_SIF0_3WIRE | LCDIF_SIF0_DIV2 | LCDIF_SIF0_HW_CS) // LCD serial interface configuration
#define LCD_SIF_WROI    (LCDIF_F_RGB | LCDIF_F_PADDLSB | LCDIF_F_RGB888 | LCDIF_F_ITF_8B)           // LCD module data format
#define LCD_BACKCOLOR   clBlack
#define LCD_REDRAWTIME  75000                                                                       // 75 ms
#define _ILI9341_LCD_DRIVER_
//#define _NO_LCD_DRIVER_

/* Touch screen interface settings */
#define _FT6236_TS_DRIVER_
//#define _NO_TS_DRIVER_

/* Backlight driver */
#define BACKLIGHTCHNL   ISINK_CH0
#define BACKLIGHTMODE   BM_PWM
#define BLMINVALUE      10                                                                          // % for PWM mode
#define BACKLIGHTREDUCE 10000                                                                       // ms
#define BACKLIGHTOFF    30000                                                                       // ms
#define BACKLIGHTDEFVAL 100                                                                         // In percents
#define BACKLIGHTCOUNT  163                                                                         // 32kHz / 163 = ~199.8 Hz

/* Battery charger */
#define APPUSEBATTERY   1
#define BATMAXCURRENT   200                                                                         // Max charging current in mA
#define BATMINCURRENT   25                                                                          // Cut-off charging current in mA

/* Power key */
#define APPUSEPWKEY     1

/* USB driver */
#define _USB_CDC_DRIVER_                                                                            // Prolific PL2303 emulation
//#define _NO_USB_DRIVER_

/* SD card driver */
#define SD_ITF          MSDC0
#define _SD_CARD_DRIVER_
//#define _NO_SD_CARD_DRIVER_

/* Application pins configuration */

/* LCD interface */
#define LCD_RESET       GPIO45                                                                      // LCDIF Reset
#define LCD_RESET_MODE  GPIO45_MODE_LSRSTB
#define LCD_CE          GPIO46                                                                      // LCDIF Chip Select
#define LCD_CE_MODE     GPIO46_MODE_LSCE_B0
#define LCD_SCK         GPIO47                                                                      // LCDIF Clock
#define LCD_SCK_MODE    GPIO47_MODE_LSCK0
#define LCD_SDA         GPIO48                                                                      // LCDIF Data IO line 0
#define LCD_SDA_MODE    GPIO48_MODE_LSDA0
//#define LCD_SDA1        GPIO49
//#define LCD_SDA1_MODE   GPIO49_MODE_LSA0DA0                                                       // LCDIF Data IO line 1
//#define LCD_LPTE        GPIO50
//#define LCD_LPTE_MODE   GPIO50_MODE_LPTE                                                          // LCDIF Tearing input

/* Touch screen pins configuration */
#define CPT_SCL         GPIO14                                                                      // Touch panel I2C clock line
#define CPT_SCL_MODE    GPIO14_MODE_IO
#define CPT_SDA         GPIO15                                                                      // Touch panel I2C data line
#define CPT_SDA_MODE    GPIO15_MODE_IO
#define CPT_RST         GPIO20                                                                      // Touch panel reset
#define CPT_RST_MODE    GPIO20_MODE_IO
#define CPT_INT         GPIO52                                                                      // Touch panel interrupt
#define CPT_INT_MODE    GPIO52_MODE_EINT23
#define CPT_INT_NUM     EINT23

/* SD/MMC card pins configuration */
#define SD_INS          GPIO03                                                                      // SD card insert detection
#define SD_INS_MODE     GPIO03_MODE_MCINS
#define SD_CK           GPIO31                                                                      // SD card clock
#define SD_CK_MODE      GPIO31_MODE_MCCK
#define SD_CMD          GPIO32                                                                      // SD card CMD / RESPONSE
#define SD_CMD_MODE     GPIO32_MODE_MCCMD
#define SD_DA0          GPIO33                                                                      // SD card DATA0 line
#define SD_DA0_MODE     GPIO33_MODE_MCDA0
#define SD_DA1          GPIO34                                                                      // SD card DATA1 line
#define SD_DA1_MODE     GPIO34_MODE_MCDA1
#define SD_DA2          GPIO35                                                                      // SD card DATA2 line
#define SD_DA2_MODE     GPIO35_MODE_MCDA2
#define SD_DA3          GPIO36                                                                      // SD card DATA3 line
#define SD_DA3_MODE     GPIO36_MODE_MCDA3

#include "appdrivers.h"

#endif /* _APPCONFIG_H_ */
