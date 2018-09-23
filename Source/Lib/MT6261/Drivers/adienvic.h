#ifndef _ADIENVIC_H_
#define _ADIENVIC_H_

#define ADIE_IRQ_MASK               (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0000))                //IRQ Mask 0x00 to 0x03
#define ADIE_IRQ_MASK_ALL           0xFFFF
#define ADIE_IRQ_MASK_SET           (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0020))                //IRQ Mask SET 0x00 to 0x03
#define ADIE_IRQ_MASK_CLR           (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0040))                //IRQ Mask CLR 0x00 to 0x03

#define ADIE_IRQ_SENS               (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0060))                //IRQ sensitive 0x00 to 0x03
#define ADIE_IRQ_SENS_SET           (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0080))                //IRQ sensitive SET 0x00 to 0x03
#define ADIE_IRQ_SENS_CLR           (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x00A0))                //IRQ sensitive CLR 0x00 to 0x03
#define IRQ_SENS_EDGE               0
#define IRQ_SENS_LEVEL              1

#define ADIE_IRQ_SOFT               (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x00C0))                //IRQ SW interrupt 0x00 to 0x03
#define ADIE_IRQ_SOFT_SET           (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x00E0))                //IRQ SW interrupt SET 0x00 to 0x03
#define ADIE_IRQ_SOFT_CLR           (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0100))                //IRQ SW interrupt CLR 0x00 to 0x03

#define ADIE_IRQ_ASTA               (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0120))                //All IRQ status 0
#define ADIE_FIQ_ASTA               (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0140))                //All FIQ status 0
#define ADIE_IRQ_EOIOH              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0160))                //IRQ end of interrupt 0x00 to 0x03

#define ADIE_IRQ_FSEL               (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0180))                //FIQ Source selection 0x00 to 0x03

#define ADIE_IRQ_STA2               (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x01A0))                //Binary Code Value of IRQ_STATUS
#define NOIRQ                       (1 << 8)
#define AIRQMASK                    0x03
#define ADIE_FIQ_STA2               (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x01A4))                //Binary Code Value of FIQ_STATUS
#define NOFIQ                       (1 << 8)
#define ADIE_IRQ_EOI2               (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x01A8))                //Binary Code Value of IRQ_EOI

#define ADIE_IRQ_PWRCON0            (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x01AC))

#define ADIE_IRQ_STV                (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x01BC))                //CIRQ Starvation Control

#define ADIE_IRQ_SEL0               (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0200))                //Source selection 0 to 1
#define ADIE_IRQ_SEL1               (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0204))                //Source selection 2 to 3

//x - SelNum
//v - SourceNum
#define ADIE_IRQ_SEL(x, v)  {\
                            (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0200 + 4 * ((x) >> 1))) &= ~(0x03 << (8 * ((x) & 0x01)));\
                            (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0200 + 4 * ((x) >> 1))) |= ((v) & 0x03) << (8 * ((x) & 0x01));\
                            }
//ADIE CIRQ Interrupt Sources
#define IRQ_ADIE_EINT_CODE          (0x00 + TOTAL_IRQ_SOURCES)                                      //EINT
#define IRQ_RTC_CODE                (0x01 + TOTAL_IRQ_SOURCES)                                      //RTC
#define IRQ_TPC_CODE                (0x02 + TOTAL_IRQ_SOURCES)                                      //Touch Panel
#define IRQ_ACCDET_CODE             (0x03 + TOTAL_IRQ_SOURCES)                                      //ACCDET
#define ADIE_NUM_IRQ_SOURCES        0x04
#define MAX_ADIE_IRQ_SELECTIONS     0x04
#define GLB_IRQ_SOURCES             (TOTAL_IRQ_SOURCES + ADIE_NUM_IRQ_SOURCES)

#define ADIE_EINT_STATUS            (*(volatile uint16_t*)(ADIE_CIRQ_base  +0x0300))                //External interrupt status register
#define ADIE_EINT_INTACK            (*(volatile uint16_t*)(ADIE_CIRQ_base  +0x0308))                //External interrupt acknowledgment register

#define ADIE_EINT_EEVT              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0310))                //External interrupt event status register
#define ADIE_EINT_NOEVT             (1 << 0)

#define ADIE_EINT_MASK              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0318))                //External interrupt mask register
#define ADIE_EINT_MASK_ALL          0xFFFF
#define ADIE_EINT_MASK_SET          (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0320))                //External interrupt mask set register
#define ADIE_EINT_MASK_CLR          (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0328))                //External interrupt mask clear register

#define ADIE_EINT_SENS              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0330))                //External interrupt sensitivity register
#define ADIE_EINT_SENS_SET          (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0338))                //External interrupt sensitivity set register
#define ADIE_EINT_SENS_CLR          (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0340))                //External interrupt sensitivity clear register
#define ADIE_EINT_SENS_EDGE         0
#define ADIE_EINT_SENS_LEVEL        1

#define ADIE_EINT_SOFT              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0348))                //Software external interrupt status register
#define ADIE_EINT_SOFT_SET          (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0350))                //Software external interrupt set register
#define ADIE_EINT_SOFT_CLR          (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0358))                //Software external interrupt clear register

#define ADIE_EINT_D0EN              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0360))                //Domain 0 external interrupt enabling control register

#define ADIE_EINT_CON(i)            (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0380 + 0x04 * (i)))   //External interrupt debounce control register
#define ADIE_EINT0_CON              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0380))
#define ADIE_EINT1_CON              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0384))
#define ADIE_EINT2_CON              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0388))
#define ADIE_EINT3_CON              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x038C))
#define ADIE_EINT4_CON              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0390))
#define ADIE_EINT5_CON              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0394))
#define ADIE_EINT6_CON              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0398))
#define ADIE_EINT7_CON              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x039C))
#define ADIE_EINT8_CON              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x03A0))
#define ADIE_EINT9_CON              (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x03A4))
#define ADIE_EINT10_CON             (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x03A8))
#define ADIE_EINT11_CON             (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x03AC))
#define ADIE_EINT12_CON             (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x03B0))
#define ADIE_EINT13_CON             (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x03B4))
#define ADIE_EINT_CNT(v)            (((v) & 0x7FF) << 0)
#define ADIE_EINT_POLL              (0 << 11)
#define ADIE_EINT_POLH              (1 << 11)
#define ADIE_EINT_PS(v)             (((v) & 0x07) << 12)
#define ADIE_EINT_PSMASK            (0x07 << 12)
#define ADIE_EINT_PS32768           0                //62.5ms
#define ADIE_EINT_PS16384           1
#define ADIE_EINT_PS8192            2
#define ADIE_EINT_PS4096            3
#define ADIE_EINT_PS2048            4
#define ADIE_EINT_PS1024            5
#define ADIE_EINT_PS512             6
#define ADIE_EINT_PS256             7                //8s
#define ADIE_EINT_DEBEN             (1 << 15)

#define ADIE_EINT_DBCRST            (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0410))                //Debounce counter reset register

#define ADIE_EINT_WAKE_MASK         (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0420))                //Wakeup mask register
#define ADIE_EINT_WAKE_MASK_SET     (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0428))                //Wakeup mask set register
#define ADIE_EINT_WAKE_MASK_CLR     (*(volatile uint16_t*)(ADIE_CIRQ_base + 0x0430))                //Wakeup mask clear register

//ADIE EINT Interrupt Sources
#define ADIE_EINT_PWRKEY            (0x00 + NUM_EINT_SOURCES)                                       //+Power key
#define ADIE_EINT_CHRDET            (0x01 + NUM_EINT_SOURCES)                                       //+Charger detection
#define ADIE_EINT_PMUOC             (0x02 + NUM_EINT_SOURCES)                                       //PMU OC status
#define ADIE_EINT_VBAT              (0x03 + NUM_EINT_SOURCES)                                       //VBAT Over Voltage
#define ADIE_EINT_CHRLDO            (0x04 + NUM_EINT_SOURCES)                                       //+Charger LDO detection
#define ADIE_EINT_PMU_STATUS0       (0x05 + NUM_EINT_SOURCES)                                       //PMU Thermal Status 0
#define ADIE_EINT_PMU_STATUS1       (0x06 + NUM_EINT_SOURCES)                                       //PMU Thermal Status 1
#define ADIE_EINT_PMU_STATUS2       (0x07 + NUM_EINT_SOURCES)                                       //PMU Thermal Status 2
#define ADIE_EINT_PMU_STATUS3       (0x08 + NUM_EINT_SOURCES)                                       //PMU Thermal Status 3
#define ADIE_EINT_PMU_STATUS4       (0x09 + NUM_EINT_SOURCES)                                       //PMU Thermal Status 4
#define ADIE_EINT_BAT_REMOVE        (0x0A + NUM_EINT_SOURCES)                                       //BAT Removal Detection
#define ADIE_EINT_RTC               (0x0B + NUM_EINT_SOURCES)                                       //RTC
#define ADIE_EINT_TP                (0x0C + NUM_EINT_SOURCES)                                       //TP
#define ADIE_EINT_ACCDET            (0x0D + NUM_EINT_SOURCES)                                       //ACCDET
#define NUM_ADIE_EINT_SOURCES       0x0E
#define GLB_EINT_SOURCES            (NUM_EINT_SOURCES + NUM_ADIE_EINT_SOURCES)

#endif /* _ADIENVIC_H_ */
