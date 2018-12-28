#ifndef _APPDRIVERS_H_
#define _APPDRIVERS_H_

#if defined(_LCD_DRIVER_ASSIGNED_)
#undefine _LCD_DRIVER_ASSIGNED_
#endif
#if defined(_ILI9341_LCD_DRIVER_)
#include "ili9341.h"
#define LCDDRV_Initialize()                 ILI9341_Initialize()
#define LCDDRV_Sleep()                      ILI9341_SleepLCD()
#define LCDDRV_Resume()                     ILI9341_ResumeLCD()
#define LCDDRV_SetOutputWindow(a, b, c, d)  ILI9341_SetOutputWindow(a, b, c, d)
#define _LCD_DRIVER_ASSIGNED_
#endif
#if defined(_NO_LCD_DRIVER_)
#if defined(_LCD_DRIVER_ASSIGNED_)
#error Duplicate LCD driver definition!
#else
#define LCDDRV_Initialize()                 false
#define LCDDRV_Sleep()
#define LCDDRV_Resume()
#define LCDDRV_SetOutputWindow(a, b, c, d)  NULL
#define _LCD_DRIVER_ASSIGNED_
#endif
#endif
#if !defined(_LCD_DRIVER_ASSIGNED_)
#error LCD driver not assigned!
#endif

#endif /* _APPDRIVERS_H_ */
