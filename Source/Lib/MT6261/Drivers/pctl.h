/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 - 2019 AJScorp
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
#ifndef _PCTL_H_
#define _PCTL_H_

// CON0
#define PD_LCD                      (0x00)                                                          // LCD controller
#define PD_RESIZER                  (0x01)
#define PD_ROTDMA                   (0x02)
#define PD_CAM_BCLK                 (0x03)
#define PD_PAD2CAM                  (0x04)
#define PD_G2D                      (0x05)
#define PD_MM_COLOR                 (0x06)
#define PD_SLCD                     (0x07)                                                          // Serial LCD interface
#define PD_MD2G_26M                 (0x08)
#define PD_BT_26M                   (0x09)
#define PD_CAM_48M                  (0x0A)
#define PD_DMA2SFC                  (0x0B)
#define PD_2GDMA2SFC                (0x0C)
#define PD_BT_BUS                   (0x0D)
#define PD_BT_ARM7                  (0x0F)
// CON1
#define PD_SEJ                      (0x10)
#define PD_DMA                      (0x11)
#define PD_USB                      (0x12)
#define PD_MSDC                     (0x13)
#define PD_SIM                      (0x14)
#define PD_SIM2                     (0x15)
#define PD_I2C                      (0x16)
#define PD_SPI                      (0x17)
#define PD_OSTIMER                  (0x18)
#define PD_SLCD_EMI_IDLE            (0x19)
#define PD_SPISLV                   (0x1C)
#define PD_UART1                    (0x1D)
#define PD_UART2                    (0x1E)
#define PD_UART3                    (0x1F)
// CON2
#define PD_PWM1                     (0x20)
#define PD_BTIF                     (0x21)
#define PD_GPT                      (0x22)
#define PD_I2C_18V                  (0x23)
#define PD_PWM4                     (0x24)
#define PD_ROM                      (0x25)
#define PD_EFUSE                    (0x26)
#define PD_SW_LPM                   (0x27)
#define PD_SFC_DCM_PROT1            (0x28)
#define PD_SFC_DCM_PROT0            (0x29)
#define PD_MSDC2                    (0x2A)
#define PD_SFC                      (0x2B)
//#define PD_SPI_NAND                 (0x2C)
#define PD_FM_F26M                  (0x2D)
#define PD_FM_BCLK                  (0x2E)
#define PD_CNFG_MAX                 (0x2E)

#define CNFG_PDN_CON(x)             (*(volatile uint16_t *)(CONFIG_BASE + 0x0300 + 0x04 * (x)))
#define CNFG_PDN_CON0               (*(volatile uint16_t *)(CONFIG_BASE + 0x0300))
#define CNFG_PDN_CON1               (*(volatile uint16_t *)(CONFIG_BASE + 0x0304))
#define CNFG_PDN_CON2               (*(volatile uint16_t *)(CONFIG_BASE + 0x0308))
#define CNFG_PDN0_MASK              0xFFFF
#define CNFG_PDN1_MASK              0xFFFF
#define CNFG_PDN2_MASK              0xF7FF                                                          // Disable all peripherals, except serial flash controller

#define CNFG_PDN_CON_SET(x)         (*(volatile uint16_t *)(CONFIG_BASE + 0x0310 + 0x04 * (x)))
#define CNFG_PDN_CON0_SET           (*(volatile uint16_t *)(CONFIG_BASE + 0x0310))
#define CNFG_PDN_CON1_SET           (*(volatile uint16_t *)(CONFIG_BASE + 0x0314))
#define CNFG_PDN_CON2_SET           (*(volatile uint16_t *)(CONFIG_BASE + 0x0318))

#define CNFG_PDN_CON_CLR(x)         (*(volatile uint16_t *)(CONFIG_BASE + 0x0320 + 0x04 * (x)))
#define CNFG_PDN_CON0_CLR           (*(volatile uint16_t *)(CONFIG_BASE + 0x0320))
#define CNFG_PDN_CON1_CLR           (*(volatile uint16_t *)(CONFIG_BASE + 0x0324))
#define CNFG_PDN_CON2_CLR           (*(volatile uint16_t *)(CONFIG_BASE + 0x0328))

// Analog power control
#define PD_PWM3                     (0x30)
#define PD_PWM2                     (0x31)
#define PD_AUXADC_BCLK              (0x32)
#define PD_TP_BCLK                  (0x33)
#define PD_PMU_F26M                 (0x34)
#define PD_ACFG_MAX                 (0x34)

#define ACFG_CLK_CON                (*(volatile uint16_t *)(ANA_CFGSYS_BASE + 0x0008))
#define ACFG_CLK_CON_SET            (*(volatile uint16_t *)(ANA_CFGSYS_BASE + 0x000C))
#define ACFG_CLK_CON_CLR            (*(volatile uint16_t *)(ANA_CFGSYS_BASE + 0x0010))
#define ACFG_CLK_MASK               0xFFFF

// Modem peripherals power control
#define MD2GSYS_CG_CON0             (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0000))               // Power Down Control 0 Register
#define PDN_IRDMA                   (1 << 6)
#define PDN_RX_BUF                  (1 << 8)
#define PDN_TX_BUF                  (1 << 9)
#define MD2GSYS_CG_CON2             (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0008))               // Power Down Control 2 Register
#define PDN_TDMA                    (1 << 0)
#define PDN_BSI                     (1 << 2)
#define PDN_BPI                     (1 << 3)
#define PDN_AFC                     (1 << 4)
#define PDN_VAFE                    (1 << 8)
#define PDN_DIVIDER                 (1 << 11)
#define PDN_FCS                     (1 << 12)
#define PDN_GCU                     (1 << 13)
#define PDN_AAFE                    PDN_VAFE                                                        // Audio / Voice single clock source (afe_def.h)
#define MD2GSYS_CG_CON4             (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0030))               // Power Down Control 4 Register
#define MD2GSYS_CG_SET0             (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0010))               // Power Down Disable 0 Register
#define MD2GSYS_CG_SET2             (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0018))               // Power Down Disable 2 Register
#define MD2GSYS_CG_SET4             (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0034))               // Power Down Disable 4 Register
#define MD2GSYS_CG_CLR0             (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0020))               // Power Down Enable 0 Register
#define MD2GSYS_CG_CLR2             (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0028))               // Power Down Enable 2 Register
#define MD2GSYS_CG_CLR4             (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0038))               // Power Down Enable 4 Register

#define MODEMSYS_CG_CON2            (*(volatile uint32_t *)(MDCONFIG_BASE + 0x0008))
#define MODEMSYS_CG_CON4            (*(volatile uint32_t *)(MDCONFIG_BASE + 0x0088))
#define MODEMSYS_CG_SET2            (*(volatile uint32_t *)(MDCONFIG_BASE + 0x0028))
#define MODEMSYS_CG_SET4            (*(volatile uint32_t *)(MDCONFIG_BASE + 0x00A8))
#define MODEMSYS_CG_CLR2            (*(volatile uint32_t *)(MDCONFIG_BASE + 0x0018))
#define MODEMSYS_CG_CLR4            (*(volatile uint32_t *)(MDCONFIG_BASE + 0x0098))

// Other power control
#define DSPCLK_CON                  (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0040))               // mask 0x7100
#define HWCG_BYPASS                 (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0058))
#define HWCG_BPBIT                  (1 << 5)
#define MD2GSYS_CG_CON              (*(volatile uint16_t *)(MD2GCONFG_BASE + 0x0214))               // mask 0x0380
#define MPERI_PWR_AWARE             (*(volatile uint32_t *)(MDCONFIG_BASE + 0x0400))                // Modemsys bus active aware

#define PCTL_PowerDown(x)           do\
                                    {\
                                        typeof(x) _x = x;\
                                        if (_x <= PD_CNFG_MAX)\
                                        {\
                                            CNFG_PDN_CON_SET(_x >> 4) = (1UL << (_x & 0x0F));\
                                        }\
                                        else if (_x <= PD_ACFG_MAX)\
                                        {\
                                            ACFG_CLK_CON_SET = (1UL << (_x & 0x0F));\
                                        }\
                                    }\
                                    while(0)

#define PCTL_PowerUp(x)             do\
                                    {\
                                        typeof(x) _x = x;\
                                        if (_x <= PD_CNFG_MAX)\
                                        {\
                                            CNFG_PDN_CON_CLR(_x >> 4) = (1UL << (_x & 0x0F));\
                                        }\
                                        else if (_x <= PD_ACFG_MAX)\
                                        {\
                                            ACFG_CLK_CON_CLR = (1UL << (_x & 0x0F));\
                                        }\
                                    }\
                                    while(0)

extern void PCTL_Initialize(void);
extern boolean PCTL_GetPeripheralPowerStatus(uint32_t Periph);

#endif /* _PCTL_H_ */
