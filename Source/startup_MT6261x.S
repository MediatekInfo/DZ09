/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2021 - 2019 AJScorp
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

// --- System stack locations
    .equ    FIQ_StackSz, 0
    .equ    IRQ_StackSz, 4096
    .equ    ABT_StackSz, 0
    .equ    UND_StackSz, 0
    .equ    SVC_StackSz, 1024
    .equ    USR_StackSz, 0

    .section .stack
    .align  2

#if defined(TARGET_SYSTEM)
    .equ    SUMM_StackSz, (ABT_StackSz + UND_StackSz + SVC_StackSz + USR_StackSz)
#else
    .equ    SUMM_StackSz, (FIQ_StackSz + IRQ_StackSz + ABT_StackSz + UND_StackSz + SVC_StackSz + USR_StackSz)
#endif
    .equ    Stack_Size, SUMM_StackSz

    .globl  SUMM_StackSz
    .globl  __stack_top
    .globl  __stack_limit
__stack_limit:
    .space  Stack_Size
    .size   __stack_limit, . - __stack_limit
__stack_top:
    .size   __stack_top, . - __stack_top

#if defined(TARGET_SYSTEM)
    .section .intstack
    .align  2

    .equ    SUMM_Int_StackSz, (FIQ_StackSz + IRQ_StackSz)
    .equ    Int_Stack_Size, SUMM_Int_StackSz

    .globl  SUMM_Int_StackSz
    .globl  __int_stack_top
    .globl  __int_stack_limit
__int_stack_limit:
    .space  Int_Stack_Size
    .size   __int_stack_limit, . - __int_stack_limit
__int_stack_top:
    .size   __int_stack_top, . - __int_stack_top
#endif

    .section .heap
    .align  2
#ifdef __HEAP_SIZE
    .equ    Heap_Size, __HEAP_SIZE
#else
    .equ    Heap_Size, 0x0C00
#endif
    .globl  __heap_base
    .globl  __heap_limit
__heap_base:
    .if Heap_Size
    .space  Heap_Size
    .endif
    .size   __heap_base, . - __heap_base
__heap_limit:
    .size   __heap_limit, . - __heap_limit

    .section .isr_vectors
    .align  2
    .globl  __isr_vectors
__isr_vectors:
    ldr     pc, __reset_address
    ldr     pc, __undef_address
    ldr     pc, __swi_address
    ldr     pc, __prefetch_address
    ldr     pc, __abort_address
    .long   0x00000000
    ldr     pc, __irq_address
    ldr     pc, __fiq_address
__reset_address:
    .long   __reset_handler
__undef_address:
    .long   __undefined_handler
__swi_address:
    .long   __swi_handler
__prefetch_address:
    .long   __prefetch_handler
__abort_address:
    .long   __abort_handler
__irq_address:
    .long   __nvic_irq_handler
__fiq_address:
    .long   __nvic_fiq_handler

    .size    __isr_vectors, . - __isr_vectors

// --- Standard definitions of mode bits and interrupt (I & F) flags in PSRs
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

    .section .reset_handler
    .align  2
    .globl  __reset_handler
    .type   __reset_handler, %function

__reset_handler:
#if defined(TARGET_SYSTEM)
    ldr     r0, =__IntStackTop
#else
    ldr     r0, =__StackTop
#endif
// Setup MCU modes and stack pointers
    msr     cpsr_c, Mode_FIQ | _I_ | _F_
    mov     sp, r0
    sub     r0, r0, FIQ_StackSz
    msr     cpsr_c, Mode_IRQ | _I_ | _F_
    mov     sp, r0
    sub     r0, r0, IRQ_StackSz
#if defined(TARGET_SYSTEM)
    ldr     r0, =__StackTop
#endif
    msr     cpsr_c, Mode_ABT | _I_ | _F_
    mov     sp, r0
    sub     r0, r0, ABT_StackSz
    msr     cpsr_c, Mode_UND | _I_ | _F_
    mov     sp, r0
    sub     r0, r0, UND_StackSz
    msr     cpsr_c, Mode_SVC | _I_ | _F_
    mov     sp, r0

    /* Zero fill the bss segment. */
    mov     r0, #0
    ldr     r1, = __bss_start__
    ldr     r2, = __bss_end__
__loop_zero_bss:
    cmp     r1, r2
    strcc   r0, [r1], #4
    bcc     __loop_zero_bss

    /* Copy flash data to RAM */
    ldr    r1, =__etext
    ldr    r2, =__data_start__
    ldr    r3, =__data_end__

__flash_to_ram_loop:
    cmp     r2, r3
    ldrcc   r0, [r1], #4
    strcc   r0, [r2], #4
    bcc     __flash_to_ram_loop

    /* Jump to our main */
    bl      main
    b       .

    .pool
    .size   __reset_handler, . - __reset_handler

    .text
    .align  2
/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
    .macro  def_irq_handler handler_name
    .align  2
    .weak   \handler_name
    .type   \handler_name, %function
\handler_name:
    b    .
    .size    \handler_name, . - \handler_name
    .endm

    def_irq_handler    __undefined_handler
    def_irq_handler    __swi_handler
    def_irq_handler    __prefetch_handler
    def_irq_handler    __abort_handler
    def_irq_handler    __nvic_irq_handler
    def_irq_handler    __nvic_fiq_handler

    .end
