/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2019 AJScorp
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
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

extern uint32_t EnableInterrupts(void);                                                             //From asmutils.s
extern uint32_t DisableInterrupts(void);                                                            //From asmutils.s
extern void RestoreInterrupts(uint32_t flags);                                                      //From asmutils.s
extern uint32_t CTZ(uint32_t Value);                                                                //From asmutils.s
extern uint32_t GetCPUFreqTicks(void);                                                              //from asmutils.s
extern uint32_t GetCPUFrequency(void);

#endif /* _UTILS_H_ */
