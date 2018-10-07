// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "debug.h"

#if _DEBUG_

void DBG_Initialize(void)
{
    GPIO_SetupMode(DBG_RXPIN, GPMODE(DBG_RXPIN_MODE));
    GPIO_SetupMode(DBG_TXPIN, GPMODE(DBG_TXPIN_MODE));

    USART_Initialize(DBG_USARTINF.USART, DBG_BAUDRATE, NULL, USART_EnFlag);
}

int _write(int file, char *ptr, int len)
{
    int32_t Count = len;

    if (Count && (file == 1))                                                                       // stdout
    {
        DBG_USARTINF.USART_TX_Buffer = ptr;
        DBG_USARTINF.USART_TX_Count  = Count;
        DBG_USARTINF.USART_TX_Index = 0;
        USART_SendBufferPoll(&DBG_USARTINF);
    }
    return len;
}

#endif /* _DEBUG_ */
