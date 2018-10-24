#ifndef _UTILS_H_
#define _UTILS_H_

#define MAX_UL      (~1UL + 1)
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

extern uint32_t EnableInterrupts(void);                                                             //From asmutils.s
extern uint32_t DisableInterrupts(void);                                                            //From asmutils.s
extern void RestoreInterrupts(uint32_t flags);                                                      //From asmutils.s
extern uint32_t CTZ(uint32_t Value);                                                                //From asmutils.s
extern uint32_t GetCPUFreqTicks(void);                                                              //from asmutils.s
extern uint32_t GetCPUFrequency(void);

#endif /* _UTILS_H_ */
