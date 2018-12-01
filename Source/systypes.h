#ifndef _SYSTYPES_H_
#define _SYSTYPES_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false = 0, true = !false}     boolean;
typedef volatile uint8_t __attribute__((aligned(4))) uint8x32_t;

#endif /* _SYSTYPES_H_ */
