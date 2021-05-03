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
    .syntax divided
    .arch armv5te

    .equ    _I_, 0x80                                                                               // when I bit is set, IRQ is disabled
    .equ    _F_, 0x40                                                                               // when F bit is set, FIQ is disabled

    .text
    .code   32
    .align  2

    .globl  __nvic_irq_handler
    .type   __nvic_irq_handler, %function
    .func   __nvic_irq_handler
__nvic_irq_handler:
    stmfd   sp!, {r0}                                                                               // NoteXXX: SW workaround for ARM7 family common bug
    mrs     r0, SPSR                                                                                // An interrupt may trigger when an MSR is executed to set I-bit.
    tst     r0, #_I_
    ldmfd   sp!, {r0}
    subnes  pc, lr, #4

    sub     lr, lr, #4
    stmfd   sp!, {r0-r12, lr}

    bl      NVIC_C_IRQ_Handler                                                                      // Calling 'C' handler

    ldmfd   sp!, {r0-r12, pc}^

    .end
