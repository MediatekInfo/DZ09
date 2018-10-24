#ifndef _DEBUG_H_
#define _DEBUG_H_

#if _DEBUG_
#include <stdio.h>
#define DebugPrint(fmt, args...)    do\
                                    {\
                                        printf(fmt, ## args);\
                                        fflush(stdout);\
                                    }\
                                    while(0)
extern void DBG_Initialize(void);
extern void DBG_DumpMem32(uint32_t *Address, uint32_t Count);
#else
#if !defined(DebugPrint)
#define DebugPrint(fmt, args...)
#endif /* DebugPrint */

#define DBG_Initialize()
#define DBG_DumpMem32(x, y)
#endif /* _DEBUG_ */

#endif /* _DEBUG_H_ */
