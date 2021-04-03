/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2021, 2020, 2019 AJScorp
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

    .equ    _I_, 0x80                                                                               // when I bit is set, IRQ is disabled
    .equ    _F_, 0x40                                                                               // when F bit is set, FIQ is disabled

    .text
    .code   32
    .align  2

///////////////////////////////////////////////////////////////////////////////////////////////////
    .globl  EnableInterrupts
    .type   EnableInterrupts, %function
    .func   EnableInterrupts
EnableInterrupts:
    stmfd   sp!,{lr}                                                                                // uint32_t EnableInterrupts(void); (Privileged modes)
    mrs     r0, cpsr

    orr     lr, r0, _F_                                                                             // lr - mode with FIQ disabled
    and     r0, r0, _F_ | _I_
    bic     lr, lr, _I_                                                                             // Enable IRQ

    msr     cpsr_c, lr                                                                              // Apply mode
    ldmfd   sp!,{pc}                                                                                // r0 - previous state of IntEN flags
    .endfunc
///////////////////////////////////////////////////////////////////////////////////////////////////
    .globl  DisableInterrupts
    .type   DisableInterrupts, %function
    .func   DisableInterrupts
DisableInterrupts:
    stmfd   sp!,{lr}                                                                                // uint32_t DisableInterrupts(void); (Privileged modes)
    mrs     r0, cpsr

    orr     lr, r0, _F_ | _I_                                                                       // lr - mode with Ints disabled
    and     r0, r0, _F_ | _I_

    msr     cpsr_c, lr                                                                              // Apply mode
    ldmfd   sp!,{pc}                                                                                // r0 - previous state of IntEN flags
    .endfunc
///////////////////////////////////////////////////////////////////////////////////////////////////
    .globl  RestoreInterrupts
    .type   RestoreInterrupts, %function
    .func   RestoreInterrupts
RestoreInterrupts:
    stmfd   sp!,{r0, lr}                                                                            // void RestoreInterrupts(uint32_t flags); (Privileged modes)

    mrs     lr, cpsr                                                                                // Control byte
    bic     lr, lr, _I_ | _F_                                                                       // Clear current IntEN flags
    and     r0, r0, _I_ | _F_                                                                       // Clear parameter with mask
    orr     r0, r0, lr

    msr     cpsr_c, r0                                                                              // Apply new interrupt settings
    ldmfd   sp!,{r0, pc}
    .endfunc
///////////////////////////////////////////////////////////////////////////////////////////////////
    .globl  CTZ
    .type   CTZ, %function
    .func   CTZ
CTZ:
    stmfd   sp!,{r1, r2, lr}                                                                        // uint32_t CTZ(uint32_t Value);
    rsb     r1, r0, #0
    and     r1, r1, r0                                                                              // isolate lowest bit
    add     r1, r1, r1, LSL#4                                                                       // *(2^4 + 1)
    add     r1, r1, r1, LSL#6                                                                       // *(2^6 + 1)
    rsb     r1, r1, r1, LSL#16                                                                      // *(2^16 - 1)
    adr     r2, ctz_hash_table
    ldrb    r0, [r2, r1, LSR#26]
    ldmfd   sp!,{r1, r2, pc}
    .endfunc

ctz_hash_table:
    .byte   0x20, 0x00, 0x01, 0x0c, 0x02, 0x06, 0xff, 0x0d
    .byte   0x03, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 0x0e
    .byte   0x0a, 0x04, 0xff, 0xff, 0x08, 0xff, 0xff, 0x19
    .byte   0xff, 0xff, 0xff, 0xff, 0xff, 0x15, 0x1b, 0x0f
    .byte   0x1f, 0x0b, 0x05, 0xff, 0xff, 0xff, 0xff, 0xff
    .byte   0x09, 0xff, 0xff, 0x18, 0xff, 0xff, 0x14, 0x1a
    .byte   0x1e, 0xff, 0xff, 0xff, 0xff, 0x17, 0xff, 0x13
    .byte   0x1d, 0xff, 0x16, 0x12, 0x1c, 0x11, 0x10
///////////////////////////////////////////////////////////////////////////////////////////////////
    .align  2
    .globl  GetCPUFreqTicks
    .type   GetCPUFreqTicks, %function
    .func   GetCPUFreqTicks
GetCPUFreqTicks:
    stmfd   sp!,{r1, lr}                                                                            // uint32_t GetMCUFreqTicks(void);

    ldr     r1, FreqLoops
    bl      CPUFreqLoop                                                                             // Fake call for cache filling

    ldr     r1, FreqLoops
    bl      USC_GetCurrentTicks                                                                     // r0 = Ticks
    bl      CPUFreqLoop

    mov     r1, r0
    bl      USC_GetCurrentTicks                                                                     // r0 = Ticks
    sub     r0, r0, r1

    ldmfd   sp!,{r1, pc}

CPUFreqLoop:
    subs    r1, r1, #1                                                                              // 1 cycle
    bne     CPUFreqLoop                                                                             // 3 cycles
    mov     pc, lr                                                                                  // 4 cycles
    .endfunc

    .globl  FreqLoopsCycles
FreqLoopsCycles:
    .long   4000004
FreqLoops:
    .long   1000000                                                                                 // 4000004 cycles summary loop
///////////////////////////////////////////////////////////////////////////////////////////////////
    .align  2
    .globl  SecureMemSet
    .type   SecureMemSet, %function
    .func   SecureMemSet
SecureMemSet:
    stmfd   sp!, {r0, r3, lr}                                                                       // void *SecureMemSet(void *memptr, int val, size_t num);
	mov	    r3, r0
	add	    r2, r0, r2
	bl      DisableInterrupts
.loop_secmem_set:
	cmp	    r3, r2
	strbne	r1, [r3], #1
	bne	    .loop_secmem_set
	bl      RestoreInterrupts
	ldmfd   sp!, {r0, r3, pc}
    .endfunc
    .end
