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
#ifndef _NVIC_H_
#define _NVIC_H_

#include "adienvic.h"

#define IRQ_MASK0                   (*(volatile uint32_t*)(CIRQ_base + 0x0000))                     //IRQ Mask 0x00 to 0x1F
#define IRQ_MASK0_ALL               0xFFFFFFFF
#define IRQ_MASK1                   (*(volatile uint32_t*)(CIRQ_base + 0x0004))                     //IRQ Mask 0x20 to 0x34
#define IRQ_MASK1_ALL               0xFFFFFFFF
#define IRQ_MASK_SET0               (*(volatile uint32_t*)(CIRQ_base + 0x0020))                     //IRQ Mask SET 0x00 to 0x1F
#define IRQ_MASK_SET1               (*(volatile uint32_t*)(CIRQ_base + 0x0024))                     //IRQ Mask SET 0x20 to 0x34
#define IRQ_MASK_CLR0               (*(volatile uint32_t*)(CIRQ_base + 0x0040))                     //IRQ Mask CLR 0x00 to 0x1F
#define IRQ_MASK_CLR1               (*(volatile uint32_t*)(CIRQ_base + 0x0044))                     //IRQ Mask CLR 0x20 to 0x34

#define IRQ_SENS0                   (*(volatile uint32_t*)(CIRQ_base + 0x0060))                     //IRQ sensitive 0x00 to 0x1F
#define IRQ_SENS1                   (*(volatile uint32_t*)(CIRQ_base + 0x0064))                     //IRQ sensitive 0x20 to 0x34
#define IRQ_SENS_SET0               (*(volatile uint32_t*)(CIRQ_base + 0x0080))                     //IRQ sensitive SET 0x00 to 0x1F
#define IRQ_SENS_SET1               (*(volatile uint32_t*)(CIRQ_base + 0x0084))                     //IRQ sensitive SET 0x20 to 0x34
#define IRQ_SENS_CLR0               (*(volatile uint32_t*)(CIRQ_base + 0x00A0))                     //IRQ sensitive CLR 0x00 to 0x1F
#define IRQ_SENS_CLR1               (*(volatile uint32_t*)(CIRQ_base + 0x00A4))                     //IRQ sensitive CLR 0x20 to 0x34
#define IRQ_SENS_EDGE               0
#define IRQ_SENS_LEVEL              1

#define IRQ_SOFT0                   (*(volatile uint32_t*)(CIRQ_base + 0x00C0))                     //IRQ SW interrupt 0x00 to 0x1F
#define IRQ_SOFT1                   (*(volatile uint32_t*)(CIRQ_base + 0x00C4))                     //IRQ SW interrupt 0x20 to 0x34
#define IRQ_SOFT_SET0               (*(volatile uint32_t*)(CIRQ_base + 0x00E0))                     //IRQ SW interrupt SET 0x00 to 0x1F
#define IRQ_SOFT_SET1               (*(volatile uint32_t*)(CIRQ_base + 0x00E4))                     //IRQ SW interrupt SET 0x20 to 0x34
#define IRQ_SOFT_CLR0               (*(volatile uint32_t*)(CIRQ_base + 0x0100))                     //IRQ SW interrupt CLR 0x00 to 0x1F
#define IRQ_SOFT_CLR1               (*(volatile uint32_t*)(CIRQ_base + 0x0104))                     //IRQ SW interrupt CLR 0x20 to 0x34

#define IRQ_ASTA0                   (*(volatile uint32_t*)(CIRQ_base + 0x0120))                     //All IRQ status 0
#define IRQ_ASTA1                   (*(volatile uint32_t*)(CIRQ_base + 0x0124))                     //All IRQ status 1

#define FIQ_ASTA0                   (*(volatile uint32_t*)(CIRQ_base + 0x0140))                     //All FIQ status 0
#define FIQ_ASTA1                   (*(volatile uint32_t*)(CIRQ_base + 0x0144))                     //All FIQ status 1

#define IRQ_EOIOH0                  (*(volatile uint32_t*)(CIRQ_base + 0x0160))                     //IRQ end of interrupt 0x00 to 0x1F
#define IRQ_EOIOH1                  (*(volatile uint32_t*)(CIRQ_base + 0x0164))                     //IRQ end of interrupt 0x20 to 0x3F

#define IRQ_FSEL0                   (*(volatile uint32_t*)(CIRQ_base + 0x0180))                     //FIQ Source selection 0x0 to 0x1F
#define IRQ_FSEL1                   (*(volatile uint32_t*)(CIRQ_base + 0x0184))                     //FIQ Source selection 0x20 to 0x3F

#define IRQ_STA2                    (*(volatile uint32_t*)(CIRQ_base + 0x01A0))                     //Binary Code Value of IRQ_STATUS
#define NOIRQ                       (1 << 8)
#define IRQMASK                     0x3F
#define FIQ_STA2                    (*(volatile uint32_t*)(CIRQ_base + 0x01A4))                     //Binary Code Value of FIQ_STATUS
#define NOFIQ                       (1 << 8)
#define IRQ_EOI2                    (*(volatile uint32_t*)(CIRQ_base + 0x01A8))                     //Binary Code Value of IRQ_EOI

#define IRQ_STV                     (*(volatile uint32_t*)(CIRQ_base + 0x01BC))                     //CIRQ Starvation Control

#define IRQ_SEL0                    (*(volatile uint32_t*)(CIRQ_base + 0x0200))                     //Source selection 0 to 3
#define IRQ_SEL1                    (*(volatile uint32_t*)(CIRQ_base + 0x0204))                     //Source selection 4 to 7
#define IRQ_SEL2                    (*(volatile uint32_t*)(CIRQ_base + 0x0208))                     //Source selection 8 to 0xB
#define IRQ_SEL3                    (*(volatile uint32_t*)(CIRQ_base + 0x020C))                     //Source selection 0xC to 0xF
#define IRQ_SEL4                    (*(volatile uint32_t*)(CIRQ_base + 0x0210))                     //Source selection 0x10 to 0x12

//x - SelNum
//v - SourceNum
#define IRQ_SEL(x, v)   do\
                        {\
                            (*(volatile uint32_t*)(CIRQ_base + 0x0200 + 4 * ((x) >> 2))) &= ~(0xFF << (8 * ((x) & 0x03)));\
                            (*(volatile uint32_t*)(CIRQ_base + 0x0200 + 4 * ((x) >> 2))) |= ((v) & 0x3F) << (8 * ((x) & 0x03));\
                        }\
                        while(0)

//CIRQ Interrupt Sources
#define IRQ_TDMA_CODE               0x00
#define IRQ_CTIRQ1_CODE             0x01
#define IRQ_CTIRQ2_CODE             0x02
#define IRQ_GPI_CODE                0x03
#define IRQ_GPII_CODE               0x04
#define IRQ_HIF_CODE                0x05
#define IRQ_SW_LISR1_CODE           0x06
#define IRQ_SW_LISR2_CODE           0x07
#define IRQ_MD_SLEEP_CODE           0x08
#define IRQ_RESERVED_9_CODE         0x09                                                            //IRQ_HIF_1_CODE
#define IRQ_DIE2DIE_CODE            0x0A
#define IRQ_OSTIMER_ARM_CODE        0x0B
#define IRQ_TOPSM_CODE              0x0C
//IRQ0x0D ~ IRQ0x11 is designed for patch purpose. (DSP?)
#define IRQ_SIM_CODE                0x12
#define IRQ_DMA_CODE                0x13
#define IRQ_UART1_CODE              0x14
#define IRQ_KPAD_CODE               0x15
#define IRQ_UART2_CODE              0x16
#define IRQ_GPT_CODE                0x17
#define IRQ_EINT_CODE               0x18
#define IRQ_USB_CODE                0x19
#define IRQ_MSDC_CODE               0x1A
#define IRQ_SFI_CODE                0x1B
#define IRQ_LCD_CODE                0x1C
#define IRQ_UART3_CODE              0x1D
#define IRQ_WDT_CODE                0x1E
#define IRQ_DSP2CPU_CODE            0x1F
#define IRQ_RESZ_CODE               0x20
#define IRQ_G2D_CODE                0x21
#define IRQ_MSDC_CD_CODE            0x22
#define IRQ_SPI_CODE                0x23
#define IRQ_I2C_CODE                0x24
#define IRQ_IRDEBUG_CODE            0x25
#define IRQ_SIM2_CODE               0x26
#define IRQ_CAMERA_CODE             0x27
#define IRQ_TIMCON_CODE             0x28
#define IRQ_ROT_DMA_CODE            0x29
#define IRQ_PAD2CAM_CODE            0x2A
#define IRQ_BTIF_CODE               0x2B
#define IRQ_RESERVED_39_CODE        0x2C                                                            //IRQ_LZMA_CODE
#define IRQ_NFI_CODE                0x2D                                                            //IRQ_RESERVED_40_CODE
#define IRQ_RESERVED_41_CODE        0x2E
#define IRQ_FM_CODE                 0x2F                                                            //IRQ_RESERVED_42_CODE
#define IRQ_MSDC2_CODE              0x30                                                            //IRQ_RESERVED_43_CODE
#define IRQ_MSDC2_CD_CODE           0x31                                                            //IRQ_RESERVED_44_CODE
#define IRQ_SPISLV_CODE             0x32
#define IRQ_I2C_18V_CODE            0x33
#define IRQ_RESERVED_47_CODE        0x34

#define NUM_IRQ_SOURCES             0x30
#define MAX_IRQ_SELECTIONS          0x12
#define TOTAL_IRQ_SOURCES           0x40

#define EINT_STATUS                 (*(volatile uint32_t*)(CIRQ_base + 0x0300))                     //External interrupt status register
#define EINT_INTACK                 (*(volatile uint32_t*)(CIRQ_base + 0x0308))                     //External interrupt acknowledgment register
#define EINT_EEVT                   (*(volatile uint32_t*)(CIRQ_base + 0x0310))                     //External interrupt event status register
#define EINT_NOEVT                  (1 << 0)
#define EINT_MASK                   (*(volatile uint32_t*)(CIRQ_base + 0x0318))                     //External interrupt mask register
#define EINT_MASK_ALL               0xFFFFFFFF
#define EINT_MASK_SET               (*(volatile uint32_t*)(CIRQ_base + 0x0320))                     //External interrupt mask set register
#define EINT_MASK_CLR               (*(volatile uint32_t*)(CIRQ_base + 0x0328))                     //External interrupt mask clear register

#define EINT_SENS                   (*(volatile uint32_t*)(CIRQ_base + 0x0330))                     //External interrupt sensitivity register
#define EINT_SENS_SET               (*(volatile uint32_t*)(CIRQ_base + 0x0338))                     //External interrupt sensitivity set register
#define EINT_SENS_CLR               (*(volatile uint32_t*)(CIRQ_base + 0x0340))                     //External interrupt sensitivity clear register
#define EINT_SENS_EDGE              0
#define EINT_SENS_LEVEL             1
#define EINT_SOFT                   (*(volatile uint32_t*)(CIRQ_base + 0x0348))                     //Software external interrupt status register
#define EINT_SOFT_SET               (*(volatile uint32_t*)(CIRQ_base + 0x0350))                     //Software external interrupt set register
#define EINT_SOFT_CLR               (*(volatile uint32_t*)(CIRQ_base + 0x0358))                     //Software external interrupt clear register

#define EINT_D0EN                   (*(volatile uint32_t*)(CIRQ_base + 0x0360))                     //Domain 0 external interrupt enabling control register

#define EINT_CON(i)                 (*(volatile uint32_t*)(CIRQ_base + 0x0380 + 0x04 * (i)))        //External interrupt debounce control register
#define EINT00_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x0380))
#define EINT01_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x0384))
#define EINT02_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x0388))
#define EINT03_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x038C))
#define EINT04_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x0390))
#define EINT05_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x0394))
#define EINT06_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x0398))
#define EINT07_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x039C))
#define EINT08_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03A0))
#define EINT09_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03A4))
#define EINT10_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03A8))
#define EINT11_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03AC))
#define EINT12_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03B0))
#define EINT13_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03B4))
#define EINT14_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03B8))
#define EINT15_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03BC))
#define EINT16_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03C0))
#define EINT17_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03C4))
#define EINT18_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03C8))
#define EINT19_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03CC))
#define EINT20_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03D0))
#define EINT21_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03D4))
#define EINT22_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03D8))
#define EINT23_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03DC))
#define EINT24_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03E0))
#define EINT25_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03E4))
#define EINT26_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03E8))
#define EINT27_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03EC))
#define EINT28_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03F0))
#define EINT29_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03F4))
#define EINT30_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03F8))
#define EINT31_CON                  (*(volatile uint32_t*)(CIRQ_base + 0x03FC))
#define EINT_CNT(v)                 (((v) & 0x7FF) << 0)
#define EINT_POLL                   (0 << 11)
#define EINT_POLH                   (1 << 11)
#define EINT_PS(v)                  (((v) & 0x07) << 12)
#define EINT_PS32768                0                  //62.5ms
#define EINT_PS16384                1
#define EINT_PS8192                 2
#define EINT_PS4096                 3
#define EINT_PS2048                 4
#define EINT_PS1024                 5
#define EINT_PS512                  6
#define EINT_PS256                  7                  //8s
#define EINT_DEBEN                  (1 << 15)

//EINT Interrupt Sources
#define EINT00                      0x00
#define EINT01                      0x01
#define EINT02                      0x02
#define EINT03                      0x03
#define EINT04                      0x04
#define EINT05                      0x05
#define EINT06                      0x06
#define EINT07                      0x07
#define EINT08                      0x08
#define EINT09                      0x09
#define EINT10                      0x0A
#define EINT11                      0x0B
#define EINT12                      0x0C
#define EINT13                      0x0D
#define EINT14                      0x0E
#define EINT15                      0x0F
#define EINT16                      0x10
#define EINT17                      0x11
#define EINT18                      0x12
#define EINT19                      0x13
#define EINT20                      0x14
#define PMU_CHR_EINT_PIN            0x15               //Charger external interrupt is fixed (!!!)
#define PMU_OC_EINT_PIN             0x16               //Charger external interrupt is fixed (!!!)
#define EINT23                      0x17
#define EINT24                      0x18
#define NUM_EINT_SOURCES            0x20

typedef struct tag_IRQHANDLER
{
    void (*Handler)(void);
} TIRQHANDLER, *pIRQHANDLER;

typedef struct tag_EINTHHANDLER
{
    void (*Handler)(void);
} TEINTHANDLER, *pEINTHANDLER;

extern void    NVIC_Initialize(void);
extern boolean NVIC_RegisterIRQ(uint32_t SourceIdx, void (*Handler)(void), uint8_t Sense, boolean Enable);
extern boolean NVIC_UnregisterIRQ(uint32_t SourceIdx);
extern boolean NVIC_RegisterEINT(uint32_t SourceIdx, void (*Handler)(void), uint8_t Sense, uint16_t Debounce, boolean Enable);
extern boolean NVIC_UnregisterEINT(uint32_t SourceIdx);
extern boolean NVIC_EnableEINT(uint32_t SourceIdx);
extern boolean NVIC_DisableEINT(uint32_t SourceIdx);
extern boolean NVIC_EnableIRQ(uint32_t SourceIdx);
extern boolean NVIC_DisableIRQ(uint32_t SourceIdx);

#endif /* _NVIC_H_ */
