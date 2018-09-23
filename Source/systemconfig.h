#ifndef _SYSTEMCONFIG_H_
#define _SYSTEMCONFIG_H_

#include "systypes.h"

#define _DEBUG_             (1)
#define _USEBATTERY_        (0)
#define VIBRVoltage         VIBR_VO18V

#define SystemMemorySize    (3 * 1024 * 1024)
#define SysCacheSize        CACHE_32kB

//Debug USART interface
#define DBG_USARTn          0
#define DBG_USARTINF        USARTINFO[DBG_USARTn]
#define DBG_BAUDRATE        115200
#define DBG_RXPIN           GPIO10
#define DBG_RXPIN_MODE      M10U1RXD
#define DBG_TXPIN           GPIO11
#define DBG_TXPIN_MODE      M11U1TXD

#include "systemlib.h"

#endif /* _SYSTEMCONFIG_H_ */
