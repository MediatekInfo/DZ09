/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2024 - 2019 AJScorp
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
    .syntax unified
    .arch armv5te

    .equ    Mode_USR, 0x10
    .equ    Mode_FIQ, 0x11
    .equ    Mode_IRQ, 0x12
    .equ    Mode_SVC, 0x13
    .equ    Mode_ABT, 0x17
    .equ    Mode_UND, 0x1B
    .equ    Mode_SYS, 0x1F                                                                          // available on ARM Arch 4 and later
    .equ    Mode_Msk, 0x1F
    .equ    _I_, 0x80                                                                               // when I bit is set, IRQ is disabled
    .equ    _F_, 0x40                                                                               // when F bit is set, FIQ is disabled

    .text
    .code   32
    .align  2

///////////////////////////////////////////////////////////////////////////////////////////////////
    .globl  __enable_interrupts
    .type   __enable_interrupts, %function
    .func   __enable_interrupts
__enable_interrupts:
    stmfd   sp!,{lr}                                                                                // uint32_t __enable_interrupts(void); (Privileged modes)
    mrs     r0, cpsr

    bic     lr, r0, _F_ | _I_                                                                       // Enable IRQ and FIQ interrupts
    and     r0, r0, _F_ | _I_

    msr     cpsr_c, lr                                                                              // Apply mode
    ldmfd   sp!,{pc}                                                                                // r0 - previous state of IntEN flags
    .endfunc
///////////////////////////////////////////////////////////////////////////////////////////////////
    .globl  __disable_interrupts
    .type   __disable_interrupts, %function
    .func   __disable_interrupts
__disable_interrupts:
    stmfd   sp!,{lr}                                                                                // uint32_t __disable_interrupts(void); (Privileged modes)
    mrs     r0, cpsr

    orr     lr, r0, _F_ | _I_                                                                       // lr - mode with Ints disabled
    and     r0, r0, _F_ | _I_

    msr     cpsr_c, lr                                                                              // Apply mode
    ldmfd   sp!,{pc}                                                                                // r0 - previous state of IntEN flags
    .endfunc
///////////////////////////////////////////////////////////////////////////////////////////////////
    .globl  __restore_interrupts
    .type   __restore_interrupts, %function
    .func   __restore_interrupts
__restore_interrupts:
    stmfd   sp!,{r0, lr}                                                                            // void __restore_interrupts(uint32_t flags); (Privileged modes)

    mrs     lr, cpsr                                                                                // Control byte
    bic     lr, lr, _I_ | _F_                                                                       // Clear current IntEN flags
    and     r0, r0, _I_ | _F_                                                                       // Clear parameter with mask
    orr     r0, r0, lr

    msr     cpsr_c, r0                                                                              // Apply new interrupt settings
    ldmfd   sp!,{r0, pc}
    .endfunc
///////////////////////////////////////////////////////////////////////////////////////////////////
    .globl  __ctz
    .type   __ctz, %function
    .func   __ctz
__ctz:
    stmfd   sp!, {lr}                                                                               // uint32_t __ctz(uint32_t Value);
    rsbs    lr, r0, #0
    and     lr, lr, r0
    clzcc   lr, lr
    rsc     r0, lr, #32
    ldmfd   sp!, {pc}
    .endfunc
///////////////////////////////////////////////////////////////////////////////////////////////////
    .globl  __clz
    .type   __clz, %function
    .func   __clz
__clz:                                                                                              // uint32_t __clz(uint32_t Value);
    clz     r0, r0
    mov     pc, lr
    .endfunc
///////////////////////////////////////////////////////////////////////////////////////////////////
    .align  2
    .globl  __get_cpu_freq_ticks
    .type   __get_cpu_freq_ticks, %function
    .func   __get_cpu_freq_ticks
__get_cpu_freq_ticks:
    stmfd   sp!,{r1, lr}                                                                            // uint32_t __get_cpu_freq_ticks(void);

    ldr     r1, __freq_loops
    bl      __cpu_freq_loop                                                                         // Fake call for cache filling

    ldr     r1, __freq_loops
    bl      USC_GetCurrentTicks                                                                     // r0 = Ticks
    bl      __cpu_freq_loop

    mov     r1, r0
    bl      USC_GetCurrentTicks                                                                     // r0 = Ticks
    sub     r0, r0, r1

    ldmfd   sp!,{r1, pc}

__cpu_freq_loop:
    subs    r1, r1, #1                                                                              // 1 cycle
    bne     __cpu_freq_loop                                                                         // 3 cycles
    mov     pc, lr                                                                                  // 4 cycles
    .endfunc

    .globl  __freq_loops_cycles
__freq_loops_cycles:
    .long   4000004
__freq_loops:
    .long   1000000                                                                                 // 4000004 cycles summary loop
///////////////////////////////////////////////////////////////////////////////////////////////////
    .align  2
    .globl  __secure_memset
    .type   __secure_memset, %function
    .func   __secure_memset
__secure_memset:
    stmfd   sp!, {r0, r3, lr}                                                                       // void *__secure_memset(void *memptr, int val, size_t num);
    mov     r3, r0
    add     r2, r0, r2
    bl      __disable_interrupts
__loop_sec_memset:
    cmp     r3, r2
    strbne  r1, [r3], #1
    bne     __loop_sec_memset
    bl      __restore_interrupts
    ldmfd   sp!, {r0, r3, pc}
    .endfunc
///////////////////////////////////////////////////////////////////////////////////////////////////
    .globl  __is_in_isr_mode
    .type   __is_in_isr_mode, %function
    .func   __is_in_isr_mode
__is_in_isr_mode:
    stmfd   sp!,{lr}                                                                                // boolean __is_in_isr_mode(void); (Privileged modes)
    mrs     lr, cpsr

    mov     r0, #0
    and     lr, lr, Mode_Msk
    subs    lr, lr, Mode_FIQ                                                                        // Mode_FIQ = 0x11
    moveq   r0, #1
    subs    lr, lr, #1                                                                              // Mode_IRQ = 0x12
    moveq   r0, #1

    ldmfd   sp!,{pc}
    .endfunc

    .end
