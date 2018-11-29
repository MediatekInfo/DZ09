#ifndef _SYSTEMCONFIG_H_
#define _SYSTEMCONFIG_H_

#include "systypes.h"

//Debug USART interface
#define DBG_USARTn          0
#define DBG_USARTINF        USARTINFO[DBG_USARTn]
#define DBG_BAUDRATE        115200
#define DBG_RXPIN           GPIO10
#define DBG_RXPIN_MODE      GPIO10_MODE_U1RXD
#define DBG_TXPIN           GPIO11
#define DBG_TXPIN_MODE      GPIO11_MODE_U1TXD

#if defined(TARGET_SYSTEM)

#define _DEBUG_             (1)
#define _USEBATTERY_        (0)
#define USEINTERRUPTS
#define VIBRVoltage         VIBR_VO18V

#define SystemMemorySize    (3 * 1024 * 1024)
#define SysCacheSize        CACHE_32kB
#include "systemlib.h"
#include "guilib.h"
#include "appconfig.h"

#elif defined(TARGET_BOOTLOADER)

#define _DEBUG_             (1)
#include "mt6261.h"
#include "debug.h"
#endif

#endif /* _SYSTEMCONFIG_H_ */
