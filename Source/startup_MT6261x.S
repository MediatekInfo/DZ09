/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2020, 2019 AJScorp
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
    .equ    IRQ_StackSz, 1024
    .equ    ABT_StackSz, 0
    .equ    UND_StackSz, 0
    .equ    SVC_StackSz, 1024
    .equ    USR_StackSz, 0

    .section .stack
    .align  2

    .equ    SUMM_StackSz, (FIQ_StackSz + IRQ_StackSz + ABT_StackSz + UND_StackSz + SVC_StackSz + USR_StackSz)
    .equ    Stack_Size, SUMM_StackSz

    .globl  SUMM_StackSz
    .globl  __StackTop
    .globl  __StackLimit
__StackLimit:
    .space  Stack_Size
    .size   __StackLimit, . - __StackLimit
__StackTop:
    .size   __StackTop, . - __StackTop

    .section .heap
    .align  2
#ifdef __HEAP_SIZE
    .equ    Heap_Size, __HEAP_SIZE
#else
    .equ    Heap_Size, 0x0C00
#endif
    .globl  __HeapBase
    .globl  __HeapLimit
__HeapBase:
    .if Heap_Size
    .space  Heap_Size
    .endif
    .size   __HeapBase, . - __HeapBase
__HeapLimit:
    .size   __HeapLimit, . - __HeapLimit

    .section .isr_vectors
    .align  2
    .globl  __isr_vectors
    .globl  ROM_Image_Base, ROM_Image_Limit
__isr_vectors:
    ldr     pc, Reset_Address
    ldr     pc, Undef_Address
    ldr     pc, SWI_Address
    ldr     pc, Prefetch_Address
    ldr     pc, Abort_Address
    .long   0x00000000
    ldr     pc, IRQ_Address
    ldr     pc, FIQ_Address
Reset_Address:
    .long   Reset_Handler
Undef_Address:
    .long   Undefined_Handler
SWI_Address:
    .long   SWI_Handler
Prefetch_Address:
    .long   Prefetch_Handler
Abort_Address:
    .long   Abort_Handler
IRQ_Address:
    .long   NVIC_IRQ_Handler
FIQ_Address:
    .long   FIQ_Handler

ROM_Image_Base:
    .long   __rom_image_base
ROM_Image_Limit:
    .long   __rom_image_limit

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
    .globl  Reset_Handler
    .type   Reset_Handler, %function

Reset_Handler:
    ldr     r0, =__StackTop
// Setup MCU modes and stack pointers
    msr     cpsr_c, Mode_FIQ | _I_ | _F_
    mov     sp, r0
    sub     r0, r0, FIQ_StackSz
    msr     cpsr_c, Mode_IRQ | _I_ | _F_
    mov     sp, r0
    sub     r0, r0, IRQ_StackSz
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
.loop_zero_bss:
    cmp     r1, r2
    strcc   r0, [r1], #4
    bcc     .loop_zero_bss

    /* Copy flash data to RAM */
    ldr    r1, =__etext
    ldr    r2, =__data_start__
    ldr    r3, =__data_end__

.flash_to_ram_loop:
    cmp     r2, r3
    ldrcc   r0, [r1], #4
    strcc   r0, [r2], #4
    bcc     .flash_to_ram_loop

    /* Jump to our main */
    bl      main
    b       .

    .pool
    .size   Reset_Handler, . - Reset_Handler

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

    def_irq_handler    Undefined_Handler
    def_irq_handler    SWI_Handler
    def_irq_handler    Prefetch_Handler
    def_irq_handler    Abort_Handler
    def_irq_handler    NVIC_IRQ_Handler
    def_irq_handler    FIQ_Handler

    .end
