    .syntax divided
    .arch armv5te

    .equ    _I_, 0x80                                                                               //when I bit is set, IRQ is disabled
    .equ    _F_, 0x40                                                                               //when F bit is set, FIQ is disabled

    .text
    .code   32
    .align  2

    .globl  NVIC_IRQ_Handler
    .type   NVIC_IRQ_Handler, %function
    .func   NVIC_IRQ_Handler
NVIC_IRQ_Handler:
    stmfd   sp!, {r0}                                                                               ;//NoteXXX: SW workaround for ARM7 family common bug
    mrs     r0, SPSR                                                                                ;//An interrupt may trigger when an MSR is executed to set I-bit.
    tst     r0, #_I_
    ldmfd   sp!, {r0}
    subnes  pc, lr, #4

    sub     lr, lr, #4
    stmfd   sp!, {r0-r12, lr}

    bl      NVIC_C_IRQ_Handler                                                                      // Calling 'C' handler

    ldmfd   sp!, {r0-r12, pc}^

    .end
