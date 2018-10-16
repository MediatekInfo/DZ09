#ifndef _SYSTEMCONFIG_H_
#define _SYSTEMCONFIG_H_

/* This file is used to create the ability to use system libraries. */

#define _DEBUG_             (1)
#define VIBRVoltage         VIBR_VO18V

#include "systypes.h"
#include "mt6261.h"
#include "debug.h"

//Debug USART interface
#define DBG_USARTn          0
#define DBG_USARTINF        USARTINFO[DBG_USARTn]
#define DBG_BAUDRATE        115200
#define DBG_RXPIN           GPIO10
#define DBG_RXPIN_MODE      GPIO10_MODE_U1RXD
#define DBG_TXPIN           GPIO11
#define DBG_TXPIN_MODE      GPIO11_MODE_U1TXD

#endif /* _SYSTEMCONFIG_H_ */
