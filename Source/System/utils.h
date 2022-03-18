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
#ifndef _UTILS_H_
#define _UTILS_H_

#define MAX_UL      (~1UL + 1)
#define max(a,b)    ({\
                        typeof(a) _a = a;\
                        typeof(b) _b = b;\
                        (_a > _b) ? _a : _b;\
                    })
#define min(a,b)    ({\
                        typeof(a) _a = a;\
                        typeof(b) _b = b;\
                        (_a < _b) ? _a : _b;\
                    })

extern uint32_t __enable_interrupts(void);                                                          // From asmutils.s
extern uint32_t __disable_interrupts(void);                                                         // From asmutils.s
extern void __restore_interrupts(uint32_t flags);                                                   // From asmutils.s
extern uint32_t __ctz(uint32_t Value);                                                              // From asmutils.s
extern uint32_t __clz(uint32_t Value);                                                              // From asmutils.s
extern uint32_t __get_cpu_freq_ticks(void);                                                         // from asmutils.s
extern void *__secure_memset(void *memptr, int val, size_t num);                                    // from asmutils.s
extern boolean __is_in_isr_mode(void);                                                              // from asmutils.s
extern uint32_t GetCPUFrequency(void);

#endif /* _UTILS_H_ */
