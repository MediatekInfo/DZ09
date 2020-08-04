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
#ifndef _GPIO_H_
#define _GPIO_H_

#define GPIO0                       (0x00)
#define GPIO1                       (0x01)
#define GPIO2                       (0x02)
#define GPIO3                       (0x03)
#define GPIO4                       (0x04)
#define GPIO5                       (0x05)
#define GPIO6                       (0x06)
#define GPIO7                       (0x07)
#define GPIO8                       (0x08)
#define GPIO9                       (0x09)
#define GPIO10                      (0x0A)
#define GPIO11                      (0x0B)
#define GPIO12                      (0x0C)
#define GPIO13                      (0x0D)
#define GPIO14                      (0x0E)
#define GPIO15                      (0x0F)
#define GPIO16                      (0x10)
#define GPIO17                      (0x11)
#define GPIO18                      (0x12)
#define GPIO19                      (0x13)
#define GPIO20                      (0x14)
#define GPIO21                      (0x15)
#define GPIO22                      (0x16)
#define GPIO23                      (0x17)
#define GPIO24                      (0x18)
#define GPIO25                      (0x19)
#define GPIO26                      (0x1A)
#define GPIO27                      (0x1B)
#define GPIO28                      (0x1C)
#define GPIO29                      (0x1D)
#define GPIO30                      (0x1E)
#define GPIO31                      (0x1F)

#define GPIO32                      (0x20)
#define GPIO33                      (0x21)
#define GPIO34                      (0x22)
#define GPIO35                      (0x23)
#define GPIO36                      (0x24)
#define GPIO37                      (0x25)
#define GPIO38                      (0x26)
#define GPIO39                      (0x27)
#define GPIO40                      (0x28)
#define GPIO41                      (0x29)
#define GPIO42                      (0x2A)
#define GPIO43                      (0x2B)
#define GPIO44                      (0x2C)
#define GPIO45                      (0x2D)
#define GPIO46                      (0x2E)
#define GPIO47                      (0x2F)
#define GPIO48                      (0x30)
#define GPIO49                      (0x31)
#define GPIO50                      (0x32)
#define GPIO51                      (0x33)
#define GPIO52                      (0x34)
#define GPIO53                      (0x35)
#define GPIO54                      (0x36)
#define GPIO55                      (0x37)
#define GPIOMAX                     GPIO55

//GPIO flags
#define GPDI                        (0 << 0)                                                        //GPIO Data input
#define GPDO                        (1 << 0)                                                        //GPIO Data output
#define GPDIEN                      (1 << 1)                                                        //GPIO Data input enable
#define GPPULLEN                    (1 << 2)                                                        //GPIO Pullup/Pulldown enable
#define GPPUP                       (0 << 3)                                                        //GPIO Pullup
#define GPPDN                       (1 << 3)                                                        //GPIO Pulldown
#define GPSMT                       (1 << 4)                                                        //GPIO Schmitt trigger enable
#define GPMODE(v)                   (((v) & 0x0F) << 8)                                             //GPIO mode << 8

#define GPIO_DIR0                   (*(volatile uint32_t*)(GPIO_Base + 0x0000))                     //0 - Input/1 - Output
#define GPIO_DIR0_SET               (*(volatile uint32_t*)(GPIO_Base + 0x0004))
#define GPIO_DIR0_CLR               (*(volatile uint32_t*)(GPIO_Base + 0x0008))
#define GPIO_DIR0_MASK              0xFFFFFFFF
#define GPIO_DIR1                   (*(volatile uint32_t*)(GPIO_Base + 0x0010))
#define GPIO_DIR1_SET               (*(volatile uint32_t*)(GPIO_Base + 0x0014))
#define GPIO_DIR1_CLR               (*(volatile uint32_t*)(GPIO_Base + 0x0018))
#define GPIO_DIR1_MASK              0x00CFFFFFF
#define GPIO_SETDIRIN(Pin)          do\
                                    {\
                                        uint32_t  p = (Pin);\
                                        if (p < 0x20) GPIO_DIR0_CLR = (1UL << p);\
                                        else if (p < 0x40)\
                                            GPIO_DIR1_CLR = (1UL << (p - 0x20));\
                                    }\
                                    while(0)
#define GPIO_SETDIROUT(Pin)         do\
                                    {\
                                        uint32_t  p = (Pin);\
                                        if (p < 0x20) GPIO_DIR0_SET = (1UL << p);\
                                        else if (p < 0x40)\
                                            GPIO_DIR1_SET = (1UL << (p - 0x20));\
                                    }\
                                    while(0)


#define GPIO_PULLEN0                (*(volatile uint32_t*)(GPIO_Base + 0x0100))                     //0 - Disable/1 - Enable
#define GPIO_PULLEN0_SET            (*(volatile uint32_t*)(GPIO_Base + 0x0104))
#define GPIO_PULLEN0_CLR            (*(volatile uint32_t*)(GPIO_Base + 0x0108))
#define PULLEN0_MASK                0x43C00BFF
#define GPIO_PULLEN1                (*(volatile uint32_t*)(GPIO_Base + 0x0110))
#define GPIO_PULLEN1_SET            (*(volatile uint32_t*)(GPIO_Base + 0x0114))
#define GPIO_PULLEN1_CLR            (*(volatile uint32_t*)(GPIO_Base + 0x0118))
#define PULLEN1_MASK                0x00F01800
#define GPIO_PULLENABLE(Pin)        do\
                                    {\
                                        uint32_t  v, p = (Pin);\
                                        if (p < 0x20)\
                                        {\
                                            v = (1UL << p);\
                                            if (v & PULLSEL0_MASK) GPIO_PULLEN0_SET = v;\
                                            else if (v & RESEN0_0_MASK)\
                                                GPIO_RESEN0_0_SET = v;\
                                        }\
                                        else if (p < 0x40)\
                                        {\
                                            v = (1UL << (p - 0x20));\
                                            if (v & PULLSEL1_MASK) GPIO_PULLEN1_SET = v;\
                                            else if (v & RESEN0_1_MASK)\
                                                GPIO_RESEN0_1_SET = v;\
                                        }\
                                    }\
                                    while(0)
#define GPIO_PULLDISABLE(Pin)       do\
                                    {\
                                        uint32_t  v, p = (Pin);\
                                        if (p < 0x20)\
                                        {\
                                            v = (1UL << p);\
                                            if (v & PULLSEL0_MASK) GPIO_PULLEN0_CLR = v;\
                                            else if (v & RESEN0_0_MASK)\
                                                GPIO_RESEN0_0_CLR = v;\
                                        }\
                                        else if (p < 0x40)\
                                        {\
                                            v = (1UL << (p - 0x20));\
                                            if (v & PULLSEL1_MASK) GPIO_PULLEN1_CLR = v;\
                                            else if (v & RESEN0_1_MASK)\
                                                GPIO_RESEN0_1_CLR = v;\
                                        }\
                                    }\
                                    while(0)

#define GPIO_DINV0                  (*(volatile uint32_t*)(GPIO_Base + 0x0200))
#define GPIO_DINV0_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0204))
#define GPIO_DINV0_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0208))
#define GPIO_DINV1                  (*(volatile uint32_t*)(GPIO_Base + 0x0210))
#define GPIO_DINV1_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0214))
#define GPIO_DINV1_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0218))

#define GPIO_DOUT0                  (*(volatile uint32_t*)(GPIO_Base + 0x0300))
#define GPIO_DOUT0_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0304))
#define GPIO_DOUT0_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0308))
#define GPIO_DOUT1                  (*(volatile uint32_t*)(GPIO_Base + 0x0310))
#define GPIO_DOUT1_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0314))
#define GPIO_DOUT1_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0318))
#define GPIO_DATAOUT(Pin, Data)     do\
                                    {\
                                        uint32_t  v, p = (Pin);\
                                        if (p < 0x20)\
                                        {\
                                            v = 1UL << p;\
                                            (Data) ? (GPIO_DOUT0_SET = v) : (GPIO_DOUT0_CLR = v);\
                                        }\
                                        else if (p < 0x40)\
                                        {\
                                            v = 1UL << (p - 0x20);\
                                            (Data) ? (GPIO_DOUT1_SET = v) : (GPIO_DOUT1_CLR = v);\
                                        }\
                                    }\
                                    while(0)

#define GPIO_DIN0                   (*(volatile uint32_t*)(GPIO_Base + 0x0400))
#define GPIO_DIN1                   (*(volatile uint32_t*)(GPIO_Base + 0x0410))
#define GPIO_DATAIN(Pin)            (((Pin) < 0x20) ? ((GPIO_DIN0 & (1UL << (Pin))) ? true : false) :\
                                     ((Pin) < 0x40) ? ((GPIO_DIN1 & (1UL << ((Pin) - 0x20))) ? true : false) : false)

#define GPIO_PULLSEL0               (*(volatile uint32_t*)(GPIO_Base + 0x0500))                     //0 - PullDown/1 - PullUp
#define GPIO_PULLSEL0_SET           (*(volatile uint32_t*)(GPIO_Base + 0x0504))
#define GPIO_PULLSEL0_CLR           (*(volatile uint32_t*)(GPIO_Base + 0x0508))
#define PULLSEL0_MASK               0x43C00BFF
#define GPIO_PULLSEL1               (*(volatile uint32_t*)(GPIO_Base + 0x0510))                     //0 - PullDown/1 - PullUp
#define GPIO_PULLSEL1_SET           (*(volatile uint32_t*)(GPIO_Base + 0x0514))
#define GPIO_PULLSEL1_CLR           (*(volatile uint32_t*)(GPIO_Base + 0x0518))
#define PULLSEL1_MASK               0x00F01800
#define GPIO_SETPULLUP(Pin)         do\
                                    {\
                                        uint32_t  v, p = (Pin);\
                                        if (p < 0x20)\
                                        {\
                                            v = (1UL << p);\
                                            if (v & PULLSEL0_MASK) GPIO_PULLSEL0_SET = v;\
                                            else if (v & PUPD0_MASK)\
                                                GPIO_PUPD0_CLR = v;\
                                        }\
                                        else if (p < 0x40)\
                                        {\
                                            v = (1UL << (p - 0x20));\
                                            if (v & PULLSEL1_MASK) GPIO_PULLSEL1_SET = v;\
                                            else if (v & PUPD1_MASK)\
                                                GPIO_PUPD1_CLR = v;\
                                        }\
                                    }\
                                    while(0)
#define GPIO_SETPULLDOWN(Pin)       do\
                                    {\
                                        uint32_t  v, p = (Pin);\
                                        if (p < 0x20)\
                                        {\
                                            v = (1UL << p);\
                                            if (v & PULLSEL0_MASK) GPIO_PULLSEL0_CLR = v;\
                                            else if (v & PUPD0_MASK)\
                                                GPIO_PUPD0_SET = v;\
                                        }\
                                        else if (p < 0x40)\
                                        {\
                                            v = (1UL << (p - 0x20));\
                                            if (v & PULLSEL1_MASK) GPIO_PULLSEL1_CLR = v;\
                                            else if (v & PUPD1_MASK)\
                                                GPIO_PUPD1_SET = v;\
                                        }\
                                    }\
                                    while(0)

#define GPIO_SMT0                   (*(volatile uint32_t*)(GPIO_Base + 0x0600))                     //Schmitt trigger control
#define GPIO_SMT0_SET               (*(volatile uint32_t*)(GPIO_Base + 0x0604))
#define GPIO_SMT0_CLR               (*(volatile uint32_t*)(GPIO_Base + 0x0608))
#define GPIO_SMT0_MASK              0xFFFFFFFF
#define GPIO_SMT1                   (*(volatile uint32_t*)(GPIO_Base + 0x0610))
#define GPIO_SMT1_SET               (*(volatile uint32_t*)(GPIO_Base + 0x0614))
#define GPIO_SMT1_CLR               (*(volatile uint32_t*)(GPIO_Base + 0x0618))
#define GPIO_SMT1_MASK              0x00001FE0
#define GPIO_SMTENABLE(Pin)         do\
                                    {\
                                        uint32_t p = (Pin), v;\
                                        if (p < 0x20)\
                                        {\
                                            v = 1UL << p;\
                                            if (v & GPIO_SMT0_MASK) GPIO_SMT0_SET = (1UL << p);\
                                        }\
                                        else if (p < 0x40)\
                                        {\
                                            v = 1UL << (p - 0x20);\
                                            if (v & GPIO_SMT1_MASK) GPIO_SMT1_SET = (1UL << (p - 0x20));\
                                        }\
                                    }\
                                    while(0)
#define GPIO_SMTDISABLE(Pin)        do\
                                    {\
                                        uint32_t p = (Pin), v;\
                                        if (p < 0x20)\
                                        {\
                                            v = 1UL << p;\
                                            if (v & GPIO_SMT0_MASK) GPIO_SMT0_CLR = (1UL << p);\
                                        }\
                                        else if (p < 0x40)\
                                        {\
                                            v = 1UL << (p - 0x20);\
                                            if (v & GPIO_SMT1_MASK) GPIO_SMT1_CLR = (1UL << (p - 0x20));\
                                        }\
                                    }\
                                    while(0)

#define GPIO_SR0                    (*(volatile uint32_t*)(GPIO_Base + 0x0700))                     //Slew rate control
#define GPIO_SR0_SET                (*(volatile uint32_t*)(GPIO_Base + 0x0704))
#define GPIO_SR0_CLR                (*(volatile uint32_t*)(GPIO_Base + 0x0708))
#define GPIO_SR1                    (*(volatile uint32_t*)(GPIO_Base + 0x0710))
#define GPIO_SR1_SET                (*(volatile uint32_t*)(GPIO_Base + 0x0714))
#define GPIO_SR1_CLR                (*(volatile uint32_t*)(GPIO_Base + 0x0718))
#define GPIO_SIM_SR                 (*(volatile uint32_t*)(GPIO_Base + 0x0720))
#define GPIO_SIM_SR_SET             (*(volatile uint32_t*)(GPIO_Base + 0x0724))
#define GPIO_SIM_SR_CLR             (*(volatile uint32_t*)(GPIO_Base + 0x0728))

#define GPIO_DRV0                   (*(volatile uint32_t*)(GPIO_Base + 0x0800))
#define GPIO_DRV0_SET               (*(volatile uint32_t*)(GPIO_Base + 0x0804))
#define GPIO_DRV0_CLR               (*(volatile uint32_t*)(GPIO_Base + 0x0808))
#define GPIO_DRV1                   (*(volatile uint32_t*)(GPIO_Base + 0x0810))
#define GPIO_DRV1_SET               (*(volatile uint32_t*)(GPIO_Base + 0x0814))
#define GPIO_DRV1_CLR               (*(volatile uint32_t*)(GPIO_Base + 0x0818))

#define GPIO_IES0                   (*(volatile uint32_t*)(GPIO_Base + 0x0900))
#define GPIO_IES0_SET               (*(volatile uint32_t*)(GPIO_Base + 0x0904))
#define GPIO_IES0_CLR               (*(volatile uint32_t*)(GPIO_Base + 0x0908))
#define GPIO_IES0_MASK              0x43C00BFF
#define GPIO_IES1                   (*(volatile uint32_t*)(GPIO_Base + 0x0910))
#define GPIO_IES1_SET               (*(volatile uint32_t*)(GPIO_Base + 0x0914))
#define GPIO_IES1_CLR               (*(volatile uint32_t*)(GPIO_Base + 0x0918))
#define GPIO_IES1_MASK              0x00001FE0
#define GPIO_SETINPUTEN(Pin)        do\
                                    {\
                                        uint32_t p = (Pin), v;\
                                        if (p < 0x20)\
                                        {\
                                            v = 1UL << p;\
                                            if (v & GPIO_IES0_MASK) GPIO_IES0_SET = (1UL << p);\
                                        }\
                                        else if (p < 0x40)\
                                        {\
                                            v = 1UL << (p - 0x20);\
                                            if (v & GPIO_IES1_MASK) GPIO_IES1_SET = (1UL << (p - 0x20));\
                                        }\
                                    }\
                                    while(0)
#define GPIO_SETINPUTDIS(Pin)       do\
                                    {\
                                        uint32_t p = (Pin), v;\
                                        if (p < 0x20)\
                                        {\
                                            v = 1UL << p;\
                                            if (v & GPIO_IES0_MASK) GPIO_IES0_CLR = (1UL << p);\
                                        }\
                                        else if (p < 0x40)\
                                        {\
                                            v = 1UL << (p - 0x20);\
                                            if (v & GPIO_IES1_MASK) GPIO_IES1_CLR = (1UL << (p - 0x20));\
                                        }\
                                    }\
                                    while(0)

//PUPD/R0/R1 description
//KCOL0-4
//PUPD  R0  R1  WEAK PULL UP/DOWN STATE
//  0   0   0   Disable both resistors
//  0   0   1   PU-36k
//  0   1   0   PU-1.2k
//  0   1   1   PU-1.2k para 36k
//  1   0   0   Disable both resistors
//  1   0   1   PD-36k
//  1   1   0   PD-1.2k
//  1   1   1   PD-1.2k para 36k

//KROW0-4
//PUPD  R0  R1  WEAK PULL UP/DOWN STATE
//  0   0   0   Disable both resistors
//  0   0   1   PU-36k
//  0   1   0   PU-1k
//  0   1   1   PU-1k para 36k
//  1   0   0   Disable both resistors
//  1   0   1   PD-36k
//  1   1   0   PD-1k
//  1   1   1   PD-1k para 36k

//URXD/CMPDN/CMCSD0/CMCSD1/CMMCLK/MCCK/MCCM0/MCDA0/MCDA1/MCDA2/MCDA3
//LSRSTB/LSCE_B/LSCK/LSDA/LSA0/LPTE/RESETB
//PUPD  R0  R1  WEAK PULL UP/DOWN STATE
//  0   0   0   Disable both resistors
//  0   0   1   PU-47k
//  0   1   0   PU-47k
//  0   1   1   PU-23.5k
//  1   0   0   Disable both resistors
//  1   0   1   PD-47k
//  1   1   0   PD-47k
//  1   1   1   PD-23.5k
#define GPIO_PUPD0                  (*(volatile uint32_t*)(GPIO_Base + 0x0A00))                     //Select pullup/pulldown
#define GPIO_PUPD0_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0A04))
#define GPIO_PUPD0_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0A08))
#define PUPD0_MASK                  0xBC3FF400
#define GPIO_PUPD1                  (*(volatile uint32_t*)(GPIO_Base + 0x0A10))
#define GPIO_PUPD1_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0A14))
#define GPIO_PUPD1_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0A18))
#define PUPD1_MASK                  0x000FE7FF

#define GPIO_RESEN0_0               (*(volatile uint32_t*)(GPIO_Base + 0x0B00))                     //R0 control
#define GPIO_RESEN0_0_SET           (*(volatile uint32_t*)(GPIO_Base + 0x0B04))
#define GPIO_RESEN0_0_CLR           (*(volatile uint32_t*)(GPIO_Base + 0x0B08))
#define RESEN0_0_MASK               0xBC3FF400
#define GPIO_RESEN0_1               (*(volatile uint32_t*)(GPIO_Base + 0x0B10))                     //R0 control
#define GPIO_RESEN0_1_SET           (*(volatile uint32_t*)(GPIO_Base + 0x0B14))
#define GPIO_RESEN0_1_CLR           (*(volatile uint32_t*)(GPIO_Base + 0x0B18))
#define RESEN0_1_MASK               0x000FE7FF
#define GPIO_RESEN1_0               (*(volatile uint32_t*)(GPIO_Base + 0x0B20))                     //R1 control
#define GPIO_RESEN1_0_SET           (*(volatile uint32_t*)(GPIO_Base + 0x0B24))
#define GPIO_RESEN1_0_CLR           (*(volatile uint32_t*)(GPIO_Base + 0x0B28))
#define RESEN1_0_MASK               0xBC3FF400
#define GPIO_RESEN1_1               (*(volatile uint32_t*)(GPIO_Base + 0x0B30))                     //R1 control
#define GPIO_RESEN1_1_SET           (*(volatile uint32_t*)(GPIO_Base + 0x0B34))
#define GPIO_RESEN1_1_CLR           (*(volatile uint32_t*)(GPIO_Base + 0x0B38))
#define RESEN1_1_MASK               0x000FE7FF

#define GPIO_MODE(x)                (*(volatile uint32_t*)(GPIO_Base + 0x0C00 + 0x10 * (x)))
#define GPIO_MODE_SET(x)            (*(volatile uint32_t*)(GPIO_Base + 0x0C04 + 0x10 * (x)))
#define GPIO_MODE_CLR(x)            (*(volatile uint32_t*)(GPIO_Base + 0x0C08 + 0x10 * (x)))

#define GPIO_MODE0                  (*(volatile uint32_t*)(GPIO_Base + 0x0C00))
#define GPIO_MODE0_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C04))
#define GPIO_MODE0_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C08))
#define GPIO_MODE0MASK              ((GPIO00_MASK <<  0) | (GPIO01_MASK <<  4) | (GPIO02_MASK <<  8) |\
                                     (GPIO03_MASK << 12) | (GPIO04_MASK << 16) | (GPIO05_MASK << 20) |\
                                     (GPIO06_MASK << 24) | (GPIO07_MASK << 28))

#define GPIO00_MASK                 0x0F
#define GPIO00_MODE_IO              0x00                                                            //IO
#define GPIO00_MODE_EINT0           0x01                                                            //I
#define GPIO00_MODE_XP              0x02                                                            //AIO
#define GPIO00_MODE_U3RXD           0x03                                                            //I
#define GPIO00_MODE_CMCSD2          0x04                                                            //I
#define GPIO00_MODE_CMCSK           0x05                                                            //I
#define GPIO00_MODE_EDIDO           0x06                                                            //O
#define GPIO00_MODE_JTDI            0x07                                                            //I
#define GPIO00_MODE_BTJTDI          0x08                                                            //I
#define GPIO00_MODE_FMJTDI          0x09                                                            //I

#define GPIO01_MASK                 0x0F
#define GPIO01_MODE_IO              0x00                                                            //IO
#define GPIO01_MODE_EINT1           0x01                                                            //I
#define GPIO01_MODE_XM              0x02                                                            //AIO
#define GPIO01_MODE_U3TXD           0x03                                                            //O
#define GPIO01_MODE_U1CTS           0x04                                                            //I
#define GPIO01_MODE_CMMCLK          0x05                                                            //O
#define GPIO01_MODE_EDIDI           0x06                                                            //I
#define GPIO01_MODE_JTMS            0x07                                                            //I
#define GPIO01_MODE_BTJTMS          0x08                                                            //I
#define GPIO01_MODE_FMJTMS          0x09                                                            //I

#define GPIO02_MASK                 0x0F
#define GPIO02_MODE_IO              0x00                                                            //IO
#define GPIO02_MODE_EINT2           0x01                                                            //I
#define GPIO02_MODE_YP              0x02                                                            //AIO
#define GPIO02_MODE_GPSFSYNC        0x03                                                            //O
#define GPIO02_MODE_PWM0            0x04                                                            //O
#define GPIO02_MODE_CMCSD0          0x05                                                            //I
#define GPIO02_MODE_EDIWS           0x06                                                            //O
#define GPIO02_MODE_JTRST           0x07                                                            //I
#define GPIO02_MODE_BTJTRST         0x08                                                            //I
#define GPIO02_MODE_FMJTRST         0x09                                                            //I

#define GPIO03_MASK                 0x0F
#define GPIO03_MODE_IO              0x00                                                            //IO
#define GPIO03_MODE_G3MCINS         0x01                                                            //I
#define GPIO03_MODE_YM              0x02                                                            //AIO
#define GPIO03_MODE_PWM1            0x04                                                            //O
#define GPIO03_MODE_CMCSD1          0x05                                                            //I
#define GPIO03_MODE_EDICK           0x06                                                            //O
#define GPIO03_MODE_JTDO            0x07                                                            //O
#define GPIO03_MODE_BTJTDO          0x08                                                            //O
#define GPIO03_MODE_FMJTDO          0x09                                                            //O

#define GPIO04_MASK                 0x07
#define GPIO04_MODE_IO              0x00                                                            //IO
#define GPIO04_MODE_EINT3           0x01                                                            //I
#define GPIO04_MODE_U1RTS           0x04                                                            //O

#define GPIO05_MASK                 0x07
#define GPIO05_MODE_IO              0x00                                                            //IO
#define GPIO05_MODE_EINT4           0x01                                                            //I
#define GPIO05_MODE_BPI_BUS3        0x03                                                            //O

#define GPIO06_MASK                 0x07
#define GPIO06_MODE_IO              0x00                                                            //IO
#define GPIO06_MODE_EINT5           0x01                                                            //I
#define GPIO06_MODE_G6MCINS         0x02                                                            //I
#define GPIO06_MODE_BPI_BUS4        0x03                                                            //O

#define GPIO07_MASK                 0x07
#define GPIO07_MODE_IO              0x00                                                            //IO
#define GPIO07_MODE_EINT6           0x01                                                            //I
#define GPIO07_MODE_BPI_BUS5        0x03                                                            //O

#define GPIO_MODE1                  (*(volatile uint32_t*)(GPIO_Base + 0x0C10))
#define GPIO_MODE1_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C14))
#define GPIO_MODE1_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C18))
#define GPIO_MODE1MASK              ((GPIO08_MASK <<  0) | (GPIO09_MASK <<  4) | (GPIO10_MASK <<  8) |\
                                     (GPIO11_MASK << 12) | (GPIO12_MASK << 16) | (GPIO13_MASK << 20) |\
                                     (GPIO14_MASK << 24) | (GPIO15_MASK << 28))

#define GPIO08_MASK                 0x07
#define GPIO08_MODE_IO              0x00                                                            //IO
#define GPIO08_MODE_EINT7           0x01                                                            //I
#define GPIO08_MODE_SCL             0x02                                                            //IO

#define GPIO09_MASK                 0x07
#define GPIO09_MODE_IO              0x00                                                            //IO
#define GPIO09_MODE_EINT8           0x01                                                            //I
#define GPIO09_MODE_SDA             0x02                                                            //IO

#define GPIO10_MASK                 0x07
#define GPIO10_MODE_IO              0x00                                                            //IO
#define GPIO10_MODE_U1RXD           0x01                                                            //I
#define GPIO10_MODE_CMRST           0x02                                                            //O
#define GPIO10_MODE_EINT9           0x03                                                            //I
#define GPIO10_MODE_G10MCINS        0x04                                                            //I

#define GPIO11_MASK                 0x07
#define GPIO11_MODE_IO              0x00                                                            //IO
#define GPIO11_MODE_U1TXD           0x01                                                            //O
#define GPIO11_MODE_CMPDN           0x02                                                            //O
#define GPIO11_MODE_EINT10          0x03                                                            //I

#define GPIO12_MASK                 0x07
#define GPIO12_MODE_IO              0x00                                                            //IO
#define GPIO12_MODE_KCOL4           0x01                                                            //IO
#define GPIO12_MODE_U2RXD           0x02                                                            //I
#define GPIO12_MODE_EDIDI           0x03                                                            //I
#define GPIO12_MODE_FMJTDI          0x04                                                            //I
#define GPIO12_MODE_JTDI            0x05                                                            //I
#define GPIO12_MODE_BTJTDI          0x06                                                            //I

#define GPIO13_MASK                 0x07
#define GPIO13_MODE_IO              0x00                                                            //IO
#define GPIO13_MODE_KCOL3           0x01                                                            //IO
#define GPIO13_MODE_EINT11          0x02                                                            //I
#define GPIO13_MODE_PWM0            0x03                                                            //O
#define GPIO13_MODE_FMJTMS          0x04                                                            //I
#define GPIO13_MODE_JTMS            0x05                                                            //I
#define GPIO13_MODE_BTJTMS          0x06                                                            //I

#define GPIO14_MASK                 0x07
#define GPIO14_MODE_IO              0x00                                                            //IO
#define GPIO14_MODE_KCOL2           0x01                                                            //IO
#define GPIO14_MODE_EINT12          0x02                                                            //I
#define GPIO14_MODE_U1RTS           0x03                                                            //I

#define GPIO15_MASK                 0x07
#define GPIO15_MODE_IO              0x00                                                            //IO
#define GPIO15_MODE_KCOL1           0x01                                                            //IO
#define GPIO15_MODE_GPSFSYNC        0x02                                                            //O
#define GPIO15_MODE_U1CTS           0x03                                                            //I
#define GPIO15_MODE_FMJTCK          0x04                                                            //I
#define GPIO15_MODE_JTCK            0x05                                                            //I
#define GPIO15_MODE_BTJTCK          0x06                                                            //I

#define GPIO_MODE2                  (*(volatile uint32_t*)(GPIO_Base + 0x0C20))
#define GPIO_MODE2_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C24))
#define GPIO_MODE2_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C28))
#define GPIO_MODE2MASK              ((GPIO16_MASK <<  0) | (GPIO17_MASK <<  4) | (GPIO18_MASK <<  8) |\
                                     (GPIO19_MASK << 12) | (GPIO20_MASK << 16) | (GPIO21_MASK << 20) |\
                                     (GPIO22_MASK << 24) | (GPIO23_MASK << 28))

#define GPIO16_MASK                 0x07
#define GPIO16_MODE_IO              0x00                                                            //IO
#define GPIO16_MODE_KCOL0           0x01                                                            //IO

#define GPIO17_MASK                 0x07
#define GPIO17_MODE_IO              0x00                                                            //IO
#define GPIO17_MODE_KROW4           0x01                                                            //IO
#define GPIO17_MODE_U2TXD           0x02                                                            //O
#define GPIO17_MODE_EDICK           0x03                                                            //O

#define GPIO18_MASK                 0x07
#define GPIO18_MODE_IO              0x00                                                            //IO
#define GPIO18_MODE_KROW3           0x01                                                            //IO
#define GPIO18_MODE_EINT13          0x02                                                            //I
#define GPIO18_MODE_CLKO0           0x03                                                            //O
#define GPIO18_MODE_FMJTRSTB        0x04                                                            //I
#define GPIO18_MODE_JTRST_B         0x05                                                            //I
#define GPIO18_MODE_BTJTRSTB        0x06                                                            //I

#define GPIO19_MASK                 0x07
#define GPIO19_MODE_IO              0x00                                                            //IO
#define GPIO19_MODE_KROW2           0x01                                                            //IO
#define GPIO19_MODE_PWM1            0x02                                                            //I
#define GPIO19_MODE_EDIWS           0x03                                                            //O
#define GPIO19_MODE_FMJTDO          0x04                                                            //O
#define GPIO19_MODE_JTDO            0x05                                                            //O
#define GPIO19_MODE_BTJTDO          0x06                                                            //O

#define GPIO20_MASK                 0x07
#define GPIO20_MODE_IO              0x00                                                            //IO
#define GPIO20_MODE_KROW1           0x01                                                            //IO
#define GPIO20_MODE_EINT14          0x02                                                            //I
#define GPIO20_MODE_EDIDO           0x03                                                            //O
#define GPIO20_MODE_BTPRI           0x04                                                            //IO
#define GPIO20_MODE_JTRCK           0x05                                                            //O
#define GPIO20_MODE_BTDBGACKN       0x06                                                            //O

#define GPIO21_MASK                 0x07
#define GPIO21_MODE_IO              0x00                                                            //IO
#define GPIO21_MODE_KROW0           0x01                                                            //IO
#define GPIO21_MODE_MCINS           0x05                                                            //I
#define GPIO21_MODE_BTDBGIN         0x06                                                            //I

#define GPIO22_MASK                 0x07
#define GPIO22_MODE_IO              0x00                                                            //IO
#define GPIO22_MODE_BPI_BUS2        0x01                                                            //O

#define GPIO23_MASK                 0x07
#define GPIO23_MODE_IO              0x00                                                            //IO
#define GPIO23_MODE_PI_BUS1         0x01                                                            //O

#define GPIO_MODE3                  (*(volatile uint32_t*)(GPIO_Base + 0x0C30))
#define GPIO_MODE3_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C34))
#define GPIO_MODE3_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C38))
#define GPIO_MODE3MASK              ((GPIO24_MASK <<  0) | (GPIO25_MASK <<  4) | (GPIO26_MASK <<  8) |\
                                     (GPIO27_MASK << 12) | (GPIO28_MASK << 16) | (GPIO29_MASK << 20) |\
                                     (GPIO30_MASK << 24) | (GPIO31_MASK << 28))

#define GPIO24_MASK                 0x07
#define GPIO24_MODE_IO              0x00                                                            //IO
#define GPIO24_MODE_BPI_BUS0        0x01                                                            //O

#define GPIO25_MASK                 0x07
#define GPIO25_MODE_IO              0x00                                                            //IO
#define GPIO25_MODE_CMRST           0x01                                                            //O
#define GPIO25_MODE_LSRSTB          0x02                                                            //O
#define GPIO25_MODE_CLKO1           0x03                                                            //O
#define GPIO25_MODE_EINT15          0x04                                                            //I
#define GPIO25_MODE_FMJTDI          0x05                                                            //I
#define GPIO25_MODE_JTDI            0x06                                                            //I

#define GPIO26_MASK                 0x07
#define GPIO26_MODE_IO              0x00                                                            //IO
#define GPIO26_MODE_CMPDN           0x01                                                            //O
#define GPIO26_MODE_LSCK1           0x02                                                            //O
#define GPIO26_MODE_DAICLK          0x03                                                            //O
#define GPIO26_MODE_SPICS           0x04                                                            //IO
#define GPIO26_MODE_FMJTMS          0x05                                                            //I
#define GPIO26_MODE_JTMS            0x06                                                            //I

#define GPIO27_MASK                 0x0F
#define GPIO27_MODE_IO              0x00                                                            //IO
#define GPIO27_MODE_CMCSD0          0x01                                                            //I
#define GPIO27_MODE_LSCE_B1         0x02                                                            //O
#define GPIO27_MODE_DAIPCMIN        0x03                                                            //I
#define GPIO27_MODE_SPISCK          0x04                                                            //IO
#define GPIO27_MODE_FMJTCK          0x05                                                            //I
#define GPIO27_MODE_JTCK            0x06                                                            //I
#define GPIO27_MODE_MC2CM0          0x08                                                            //O

#define GPIO28_MASK                 0x0F
#define GPIO28_MODE_IO              0x00                                                            //IO
#define GPIO28_MODE_CMCSD1          0x01                                                            //I
#define GPIO28_MODE_LSDA1           0x02                                                            //IO
#define GPIO28_MODE_DAIPCMOUT       0x03                                                            //O
#define GPIO28_MODE_SPIMOSI         0x04                                                            //IO
#define GPIO28_MODE_FMJTRSTB        0x05                                                            //I
#define GPIO28_MODE_JTRST_B         0x06                                                            //I
#define GPIO28_MODE_MC2CK           0x08                                                            //O

#define GPIO29_MASK                 0x0F
#define GPIO29_MODE_IO              0x00                                                            //IO
#define GPIO29_MODE_CMMCLK          0x01                                                            //O
#define GPIO29_MODE_LSA0DA1         0x02                                                            //O
#define GPIO29_MODE_DAISYNC         0x03                                                            //O
#define GPIO29_MODE_SPIMISO         0x04                                                            //IO
#define GPIO29_MODE_FMJTDO          0x05                                                            //O
#define GPIO29_MODE_JTDO            0x06                                                            //O
#define GPIO29_MODE_MC2DA0          0x08                                                            //IO

#define GPIO30_MASK                 0x07
#define GPIO30_MODE_IO              0x00                                                            //IO
#define GPIO30_MODE_CMCSK           0x01                                                            //I
#define GPIO30_MODE_LPTE            0x02                                                            //I
#define GPIO30_MODE_CMCSD2          0x03                                                            //I
#define GPIO30_MODE_EINT16          0x04                                                            //I
#define GPIO30_MODE_JTRCK           0x06                                                            //O

#define GPIO31_MASK                 0x07
#define GPIO31_MODE_IO              0x00                                                            //IO
#define GPIO31_MODE_MCCK            0x01                                                            //O
#define GPIO31_MODE_U2RXD           0x04                                                            //I

#define GPIO_MODE4                  (*(volatile uint32_t*)(GPIO_Base + 0x0C40))
#define GPIO_MODE4_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C44))
#define GPIO_MODE4_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C48))
#define GPIO_MODE4MASK              ((GPIO32_MASK <<  0) | (GPIO33_MASK <<  4) | (GPIO34_MASK <<  8) |\
                                     (GPIO35_MASK << 12) | (GPIO36_MASK << 16) | (GPIO37_MASK << 20) |\
                                     (GPIO38_MASK << 24) | (GPIO39_MASK << 28))

#define GPIO32_MASK                 0x07
#define GPIO32_MODE_IO              0x00                                                            //IO
#define GPIO32_MODE_MCCM0           0x01                                                            //O
#define GPIO32_MODE_U2TDX           0x04                                                            //O

#define GPIO33_MASK                 0x07
#define GPIO33_MODE_IO              0x00                                                            //IO
#define GPIO33_MODE_MCDA0           0x01                                                            //IO
#define GPIO33_MODE_DAISYNC         0x04                                                            //O

#define GPIO34_MASK                 0x07
#define GPIO34_MODE_IO              0x00                                                            //IO
#define GPIO34_MODE_MCDA1           0x01                                                            //IO
#define GPIO34_MODE_EINT17          0x02                                                            //I
#define GPIO34_MODE_DAIPCMIN        0x04                                                            //O

#define GPIO35_MASK                 0x07
#define GPIO35_MODE_IO              0x00                                                            //IO
#define GPIO35_MODE_MCDA2           0x01                                                            //IO
#define GPIO35_MODE_EINT18          0x02                                                            //I
#define GPIO35_MODE_DAICLK          0x04                                                            //O

#define GPIO36_MASK                 0x07
#define GPIO36_MODE_IO              0x00                                                            //IO
#define GPIO36_MODE_MCDA3           0x01                                                            //IO
#define GPIO36_MODE_EINT19          0x02                                                            //I
#define GPIO36_MODE_CLKO2           0x03                                                            //O
#define GPIO36_MODE_DAIPCMOUT       0x04                                                            //O

#define GPIO37_MASK                 0x07
#define GPIO37_MODE_IO              0x00                                                            //IO
#define GPIO37_MODE_SIM1_SIO        0x01                                                            //IO

#define GPIO38_MASK                 0x07
#define GPIO38_MODE_IO              0x00                                                            //IO
#define GPIO38_MODE_SIM1_SRST       0x01                                                            //IO

#define GPIO39_MASK                 0x07
#define GPIO39_MODE_IO              0x00                                                            //IO
#define GPIO39_MODE_SIM1_SCLK       0x01                                                            //IO

#define GPIO_MODE5                  (*(volatile uint32_t*)(GPIO_Base + 0x0C50))
#define GPIO_MODE5_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C54))
#define GPIO_MODE5_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C58))
#define GPIO_MODE5MASK              ((GPIO40_MASK <<  0) | (GPIO41_MASK <<  4) | (GPIO42_MASK <<  8) |\
                                     (GPIO43_MASK << 12) | (GPIO44_MASK << 16) | (GPIO45_MASK << 20) |\
                                     (GPIO46_MASK << 24) | (GPIO47_MASK << 28))

#define GPIO40_MASK                 0x07
#define GPIO40_MODE_IO              0x00                                                            //IO
#define GPIO40_MODE_SIM2_SIO        0x01                                                            //IO
#define GPIO40_MODE_U2RTS           0x03                                                            //O

#define GPIO41_MASK                 0x07
#define GPIO41_MODE_IO              0x00                                                            //IO
#define GPIO41_MODE_SIM2_SRST       0x01                                                            //IO
#define GPIO41_MODE_CLKO3           0x02                                                            //IO
#define GPIO41_MODE_U2CTS           0x03                                                            //I

#define GPIO42_MASK                 0x07
#define GPIO42_MODE_IO              0x00                                                            //IO
#define GPIO42_MODE_SIM2_SCLK       0x01                                                            //IO
#define GPIO42_MODE_LSCE1_B1        0x02                                                            //O

#define GPIO43_MASK                 0x07
#define GPIO43_MODE_IO              0x00                                                            //IO
#define GPIO43_MODE_SCL             0x01                                                            //IO

#define GPIO44_MASK                 0x07
#define GPIO44_MODE_IO              0x00                                                            //IO
#define GPIO44_MODE_SDA             0x01                                                            //IO

#define GPIO45_MASK                 0x07
#define GPIO45_MODE_IO              0x00                                                            //IO
#define GPIO45_MODE_LSRSTB          0x01                                                            //O
#define GPIO45_MODE_CMRST           0x03                                                            //O

#define GPIO46_MASK                 0x07
#define GPIO46_MODE_IO              0x00                                                            //IO
#define GPIO46_MODE_LSCE_B0         0x01                                                            //O
#define GPIO46_MODE_EINT20          0x02                                                            //I
#define GPIO46_MODE_CMCSD0          0x03                                                            //I
#define GPIO46_MODE_CLKO4           0x04                                                            //O

#define GPIO47_MASK                 0x07
#define GPIO47_MODE_IO              0x00                                                            //IO
#define GPIO47_MODE_LSCK0           0x01                                                            //O
#define GPIO47_MODE_CMPDN           0x03                                                            //O

#define GPIO_MODE6                  (*(volatile uint32_t*)(GPIO_Base + 0x0C60))
#define GPIO_MODE6_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C64))
#define GPIO_MODE6_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C68))
#define GPIO_MODE6MASK              ((GPIO48_MASK <<  0) | (GPIO49_MASK <<  4) | (GPIO50_MASK <<  8) |\
                                     (GPIO51_MASK << 12) | (GPIO52_MASK << 16) | (GPIO53_MASK << 20) |\
                                     (GPIO54_MASK << 24) | (GPIO55_MASK << 28))

#define GPIO48_MASK                 0x07
#define GPIO48_MODE_IO              0x00                                                            //IO
#define GPIO48_MODE_LSDA0           0x01                                                            //IO
#define GPIO48_MODE_EINT21          0x02                                                            //I
#define GPIO48_MODE_CMCSD1          0x03                                                            //I
#define GPIO48_MODE_WIFITOBT        0x04                                                            //I

#define GPIO49_MASK                 0x07
#define GPIO49_MODE_IO              0x00                                                            //IO
#define GPIO49_MODE_LSA0DA0         0x01                                                            //O
#define GPIO49_MODE_LSCE1_B0        0x02                                                            //O
#define GPIO49_MODE_CMMCLK          0x03                                                            //O

#define GPIO50_MASK                 0x0F
#define GPIO50_MODE_IO              0x00                                                            //IO
#define GPIO50_MODE_LPTE            0x01                                                            //I
#define GPIO50_MODE_EINT22          0x02                                                            //I
#define GPIO50_MODE_CMCSK           0x03                                                            //I
#define GPIO50_MODE_CMCSD2          0x04                                                            //I
#define GPIO50_MODE_MCINS           0x06                                                            //I
#define GPIO50_MODE_CLKO5           0x08                                                            //O

#define GPIO51_MASK                 0x07
#define GPIO51_MODE_IO              0x00                                                            //IO
#define GPIO51_MODE_RESETB          0x01                                                            //IO

#define GPIO52_MASK                 0x07
#define GPIO52_MODE_AGPI            0x00                                                            //AGI
#define GPIO52_MODE_EINT23          0x02                                                            //I

#define GPIO53_MASK                 0x07
#define GPIO53_MODE_AGPI53          0x00                                                            //AGI
#define GPIO53_MODE_SRCLKENAI       0x01                                                            //I
#define GPIO53_MODE_EINT24          0x02                                                            //I

#define GPIO54_MASK                 0x07
#define GPIO54_MODE_AGPIO           0x00                                                            //AGIO

#define GPIO55_MASK                 0x07
#define GPIO55_MODE_AGPIO           0x00                                                            //AGIO

#define GPIO_SETMODE(Pin, Mode)     do\
                                    {\
                                        if ((Pin) <= GPIOMAX)\
                                        {\
                                            uint8_t  RegIdx = ((Pin) >> 3) & 0x07;                  /* Index of GPIO_MODE_XXX register */\
                                            uint8_t  ModePos = ((Pin) & 0x07) << 2;                 /* Mode bits position */\
                                            uint32_t Mask = 0;                                      /* Bit field mask */\
\
                                            if (Pin < 8) Mask = GPIO_MODE0MASK;\
                                            else if (Pin < 16) Mask = GPIO_MODE1MASK;\
                                            else if (Pin < 24) Mask = GPIO_MODE2MASK;\
                                            else if (Pin < 32) Mask = GPIO_MODE3MASK;\
                                            else if (Pin < 40) Mask = GPIO_MODE4MASK;\
                                            else if (Pin < 48) Mask = GPIO_MODE5MASK;\
                                            else if (Pin < 56) Mask = GPIO_MODE6MASK;\
                                            GPIO_MODE(RegIdx) = (GPIO_MODE(RegIdx) & Mask) |\
                                                                (((Mode) & Mask) << ModePos);\
                                        }\
                                    }\
                                    while(0)

#define GPIO_TDSEL                  (*(volatile uint32_t*)(GPIO_Base + 0x0D10))                     //TX duty control
#define GPIO_TDSEL_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0D14))
#define GPIO_TDSEL_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0D18))

#define CLK_OUT0                    (*(volatile uint32_t*)(GPIO_Base + 0x0E00))
#define CLK_OUT1                    (*(volatile uint32_t*)(GPIO_Base + 0x0E10))
#define CLK_OUT2                    (*(volatile uint32_t*)(GPIO_Base + 0x0E20))
#define CLK_OUT3                    (*(volatile uint32_t*)(GPIO_Base + 0x0E30))
#define CLK_OUT4                    (*(volatile uint32_t*)(GPIO_Base + 0x0E40))
#define CLK_OUT5                    (*(volatile uint32_t*)(GPIO_Base + 0x0E50))
#define CLKO_26MHz                  1
#define CLKO_32kHz                  4

extern void GPIO_Initialize(void);
extern void GPIO_Setup(uint32_t Pin, uint32_t Flags);

#endif /* _GPIO_H_ */
