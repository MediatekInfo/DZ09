#ifndef _PCTL_H_
#define _PCTL_H_

//CON0
#define PD_LCD                      (0x00)                                                          //LCD controller
#define PD_RESIZER                  (0x01)
#define PD_ROTDMA                   (0x02)
#define PD_CAM_BCLK                 (0x03)
#define PD_PAD2CAM                  (0x04)
#define PD_G2D                      (0x05)
#define PD_MM_COLOR                 (0x06)
#define PD_SLCD                     (0x07)                                                          //Serial LCD interface
#define PD_MD2G_26M                 (0x08)
#define PD_BT_26M                   (0x09)
#define PD_CAM_48M                  (0x0A)
#define PD_DMA2SFC                  (0x0B)
#define PD_2GDMA2SFC                (0x0C)
#define PD_BT_BUS                   (0x0D)
#define PD_BT_ARM7                  (0x0F)
//CON1
#define PD_SEJ                      (0x10)
#define PD_DMA                      (0x11)
#define PD_USB                      (0x12)
#define PD_MSDC                     (0x13)
#define PD_SIM                      (0x14)
#define PD_SIM2                     (0x15)
#define PD_I2C                      (0x16)
#define PD_SPI                      (0x17)
#define PD_OSTIMER                  (0x18)
#define PD_HIF1                     (0x19)
#define PD_UART1                    (0x1D)
#define PD_UART2                    (0x1E)
#define PD_UART3                    (0x1F)
//CON2
#define PD_PWM1                     (0x20)                                                          //spec : PWM1
#define PD_BTIF                     (0x21)
#define PD_GPT                      (0x22)
#define PD_AUXADC                   (0x23)
#define PD_LZMA                     (0x24)
#define PD_ROM                      (0x25)
#define PD_EFUSE                    (0x26)
#define PD_SW_LPM                   (0x27)
#define PD_TP                       (0x28)
#define PD_NFI                      (0x29)
#define PD_MSDC2                    (0x2A)
#define PD_SFC                      (0x2B)
#define PD_SPI_NAND                 (0x2C)
#define PD_FM_F26M                  (0x2D)
#define PD_FM_BCLK                  (0x2E)
#define PD_CNFG_MAX                 (0x2E)

#define CNFG_PDN_CON(x)             (*(volatile uint16_t*)(CONFIG_base + 0x0300 + 0x04 * (x)))
#define CNFG_PDN_CON0               (*(volatile uint16_t*)(CONFIG_base + 0x0300))
#define CNFG_PDN_CON1               (*(volatile uint16_t*)(CONFIG_base + 0x0304))
#define CNFG_PDN_CON2               (*(volatile uint16_t*)(CONFIG_base + 0x0308))
#define CNFG_PDN0_MASK              0xFFFF

#define CNFG_PDN_CON_SET(x)         (*(volatile uint16_t*)(CONFIG_base + 0x0310 + 0x04 * (x)))
#define CNFG_PDN_CON0_SET           (*(volatile uint16_t*)(CONFIG_base + 0x0310))
#define CNFG_PDN_CON1_SET           (*(volatile uint16_t*)(CONFIG_base + 0x0314))
#define CNFG_PDN_CON2_SET           (*(volatile uint16_t*)(CONFIG_base + 0x0318))
#define CNFG_PDN1_MASK              0xFFFF

#define CNFG_PDN_CON_CLR(x)         (*(volatile uint16_t*)(CONFIG_base + 0x0320 + 0x04 * (x)))
#define CNFG_PDN_CON0_CLR           (*(volatile uint16_t*)(CONFIG_base + 0x0320))
#define CNFG_PDN_CON1_CLR           (*(volatile uint16_t*)(CONFIG_base + 0x0324))
#define CNFG_PDN_CON2_CLR           (*(volatile uint16_t*)(CONFIG_base + 0x0328))
#define CNFG_PDN2_MASK              0xF7FF                                                          //Disable all peripherals, except serial flash controller

//Analog power control
#define PD_PWM3                     (0x30)                                                          //spec : PWM3
#define PD_PWM2                     (0x31)                                                          //spec : PWM2
#define PD_AUXADC_BCLK              (0x32)
#define PD_TP_BCLK                  (0x33)
#define PD_PMU_F26M                 (0x34)
#define PD_ACFG_MAX                 (0x34)

#define ACFG_CLK_CON                (*(volatile uint16_t*)(ANA_CFGSYS_base + 0x0008))
#define ACFG_CLK_CON_SET            (*(volatile uint16_t*)(ANA_CFGSYS_base + 0x000C))
#define ACFG_CLK_CON_CLR            (*(volatile uint16_t*)(ANA_CFGSYS_base + 0x0010))
#define ACFG_CLK_MASK               0xFFFF

#define PCTL_PowerDown(x)           do\
                                    {\
                                        if ((x) <= PD_CNFG_MAX)\
                                        {\
                                            CNFG_PDN_CON_SET(x >> 4) = (1UL << ((x) & 0x0F));\
                                        }\
                                        else if ((x) <= PD_ACFG_MAX)\
                                        {\
                                            ACFG_CLK_CON_SET = (1UL << ((x) & 0x0F));\
                                        }\
                                    }\
                                    while(0)

#define PCTL_PowerUp(x)             do\
                                    {\
                                        if ((x) <= PD_CNFG_MAX)\
                                        {\
                                            CNFG_PDN_CON_CLR(x >> 4) = (1UL << ((x) & 0x0F));\
                                        }\
                                        else if ((x) <= PD_ACFG_MAX)\
                                        {\
                                            ACFG_CLK_CON_CLR = (1UL << ((x) & 0x0F));\
                                        }\
                                    }\
                                    while(0)

extern void PCTL_Initialize(void);
extern boolean PCTL_GetPeripheralPowerStatus(uint32_t Periph);


#endif /* _PCTL_H_ */
