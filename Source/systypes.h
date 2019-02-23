#ifndef _SYSTYPES_H_
#define _SYSTYPES_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false = 0, true = !false}     boolean;
typedef volatile uint8_t __attribute__((aligned(4))) uint8x32_t;
typedef void* pHANDLE;                                                                              //A temporary definition, may not be necessary in the future.

typedef enum tag_TSYSOBJECT
{
    SO_UNDEFINED = 0x00000000,
    SO_TIMER     = 0x00010000,
    SO_GUI       = 0x00020000
} TSYSOBJECT;

#endif /* _SYSTYPES_H_ */
