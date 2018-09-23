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

#define GPIO_MODEMASK               0x0F
#define GPIO_MODE0                  (*(volatile uint32_t*)(GPIO_Base + 0x0C00))
#define GPIO_MODE0_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C04))
#define GPIO_MODE0_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C08))
#define GPIO_MODE0MASK              (GPIO00MASK|GPIO01MASK|GPIO02MASK|GPIO03MASK|\
                                    GPIO04MASK|GPIO05MASK|GPIO06MASK|GPIO07MASK)
//GPIO0
#define GPIO00MASK                  0x0F
#define M00GPIO                     0x00                                                            //IO
#define M00EINT0                    0x01                                                            //I
#define M00XP                       0x02                                                            //AIO
#define M00U3RXD                    0x03                                                            //I
#define M00CMCSD2                   0x04                                                            //I
#define M00CMCSK                    0x05                                                            //I
#define M00EDIDO                    0x06                                                            //O
#define M00JTDI                     0x07                                                            //I
#define M00BTJTDI                   0x08                                                            //I
#define M00FMJTDI                   0x09                                                            //I
//GPIO1
#define GPIO01MASK                  0x0F
#define M01GPIO                     0x00                                                            //IO
#define M01EINT1                    0x01                                                            //I
#define M01XM                       0x02                                                            //AIO
#define M01U3TXD                    0x03                                                            //O
#define M01U1CTS                    0x04                                                            //I
#define M01CMMCLK                   0x05                                                            //O
#define M01EDIDI                    0x06                                                            //I
#define M01JTMS                     0x07                                                            //I
#define M01BTJTMS                   0x08                                                            //I
#define M01FMJTMS                   0x09                                                            //I
//GPIO2
#define GPIO02MASK                  0x0F
#define M02GPIO                     0x00                                                            //IO
#define M02EINT2                    0x01                                                            //I
#define M02YP                       0x02                                                            //AIO
#define M02GPSFSYNC                 0x03                                                            //O
#define M02PWM0                     0x04                                                            //O
#define M02CMCSD0                   0x05                                                            //I
#define M02EDIWS                    0x06                                                            //O
#define M02JTRST                    0x07                                                            //I
#define M02BTJTRST                  0x08                                                            //I
#define M02FMJTRST                  0x09                                                            //I
//GPIO3
#define GPIO03MASK                  0x0F
#define M03GPIO                     0x00                                                            //IO
#define M03G3MCINS                  0x01                                                            //I
#define M03YM                       0x02                                                            //AIO
#define M03PWM1                     0x04                                                            //O
#define M03CMCSD1                   0x05                                                            //I
#define M03EDICK                    0x06                                                            //O
#define M03JTDO                     0x07                                                            //O
#define M03BTJTDO                   0x08                                                            //O
#define M03FMJTDO                   0x09                                                            //O
//GPIO4
#define GPIO04MASK                  0x07
#define M04GPIO                     0x00                                                            //IO
#define M04EINT3                    0x01                                                            //I
#define M04U1RTS                    0x04                                                            //O
//GPIO5
#define GPIO05MASK                  0x07
#define M05GPIO                     0x00                                                            //IO
#define M05EINT4                    0x01                                                            //I
#define M05BPI_BUS3                 0x03                                                            //O
//GPIO6
#define GPIO06MASK                  0x07
#define M06GPIO                     0x00                                                            //IO
#define M06EINT5                    0x01                                                            //I
#define M06G6MCINS                  0x02                                                            //I
#define M06BPI_BUS4                 0x03                                                            //O
//GPIO7
#define GPIO07MASK                  0x07
#define M07GPIO                     0x00                                                            //IO
#define M07EINT6                    0x01                                                            //I
#define M07BPI_BUS5                 0x03                                                            //O

#define GPIO_MODE1                  (*(volatile uint32_t*)(GPIO_Base + 0x0C10))
#define GPIO_MODE1_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C14))
#define GPIO_MODE1_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C18))
#define GPIO_MODE1MASK              (GPIO08MASK|GPIO09MASK|GPIO10MASK|GPIO11MASK|\
                                    GPIO12MASK|GPIO13MASK|GPIO14MASK|GPIO15MASK)
//GPIO8
#define GPIO08MASK                  0x07
#define M08GPIO                     0x00                                                            //IO
#define M08EINT7                    0x01                                                            //I
#define M08SCL                      0x02                                                            //IO
//GPIO9
#define GPIO09MASK                  0x07
#define M09GPIO                     0x00                                                            //IO
#define M09EINT8                    0x01                                                            //I
#define M09SDA                      0x02                                                            //IO
//GPIO10
#define GPIO10MASK                  0x07
#define M10GPIO                     0x00                                                            //IO
#define M10U1RXD                    0x01                                                            //I
#define M10CMRST                    0x02                                                            //O
#define M10EINT9                    0x03                                                            //I
#define M10G10MCINS                 0x04                                                            //I
//GPIO11
#define GPIO11MASK                  0x07
#define M11GPIO                     0x00                                                            //IO
#define M11U1TXD                    0x01                                                            //O
#define M11CMPDN                    0x02                                                            //O
#define M11EINT10                   0x03                                                            //I
//GPIO12
#define GPIO12MASK                  0x07
#define M12GPIO                     0x00                                                            //IO
#define M12KCOL4                    0x01                                                            //IO
#define M12U2RXD                    0x02                                                            //I
#define M12EDIDI                    0x03                                                            //I
#define M12FMJTDI                   0x04                                                            //I
#define M12JTDI                     0x05                                                            //I
#define M12BTJTDI                   0x06                                                            //I
//GPIO13
#define GPIO13MASK                  0x07
#define M13GPIO                     0x00                                                            //IO
#define M13KCOL3                    0x01                                                            //IO
#define M13EINT11                   0x02                                                            //I
#define M13PWM0                     0x03                                                            //O
#define M13FMJTMS                   0x04                                                            //I
#define M13JTMS                     0x05                                                            //I
#define M13BTJTMS                   0x06                                                            //I
//GPIO14
#define GPIO14MASK                  0x07
#define M14GPIO                     0x00                                                            //IO
#define M14KCOL2                    0x01                                                            //IO
#define M14EINT12                   0x02                                                            //I
#define M14U1RTS                    0x03                                                            //I
//GPIO15
#define GPIO15MASK                  0x07
#define M15GPIO                     0x00                                                            //IO
#define M15KCOL1                    0x01                                                            //IO
#define M15GPSFSYNC                 0x02                                                            //O
#define M15U1CTS                    0x03                                                            //I
#define M15FMJTCK                   0x04                                                            //I
#define M15JTCK                     0x05                                                            //I
#define M15BTJTCK                   0x06                                                            //I

#define GPIO_MODE2                  (*(volatile uint32_t*)(GPIO_Base + 0x0C20))
#define GPIO_MODE2_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C24))
#define GPIO_MODE2_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C28))
#define GPIO_MODE2MASK              (GPIO16MASK|GPIO17MASK|GPIO18MASK|GPIO19MASK|\
                                    GPIO20MASK|GPIO21MASK|GPIO22MASK|GPIO23MASK)
//GPIO16
#define GPIO16MASK                  0x07
#define M16GPIO                     0x00                                                            //IO
#define M16KCOL0                    0x01                                                            //IO
//GPIO17
#define GPIO17MASK                  0x07
#define M17GPIO                     0x00                                                            //IO
#define M17KROW4                    0x01                                                            //IO
#define M17U2TXD                    0x02                                                            //O
#define M17EDICK                    0x03                                                            //O
//GPIO18
#define GPIO18MASK                  0x07
#define M18GPIO                     0x00                                                            //IO
#define M18KROW3                    0x01                                                            //IO
#define M18EINT13                   0x02                                                            //I
#define M18CLKO0                    0x03                                                            //O
#define M18FMJTRSTB                 0x04                                                            //I
#define M18JTRST_B                  0x05                                                            //I
#define M18BTJTRSTB                 0x06                                                            //I
//GPIO19
#define GPIO19MASK                  0x07
#define M19GPIO                     0x00                                                            //IO
#define M19KROW2                    0x01                                                            //IO
#define M19PWM1                     0x02                                                            //I
#define M19EDIWS                    0x03                                                            //O
#define M19FMJTDO                   0x04                                                            //O
#define M19JTDO                     0x05                                                            //O
#define M19BTJTDO                   0x06                                                            //O
//GPIO20
#define GPIO20MASK                  0x07
#define M20GPIO                     0x00                                                            //IO
#define M20KROW1                    0x01                                                            //IO
#define M20EINT14                   0x02                                                            //I
#define M20EDIDO                    0x03                                                            //O
#define M20BTPRI                    0x04                                                            //IO
#define M20JTRCK                    0x05                                                            //O
#define M20BTDBGACKN                0x06                                                            //O
//GPIO21
#define GPIO21MASK                  0x07
#define M21GPIO                     0x00                                                            //IO
#define M21KROW0                    0x01                                                            //IO
#define M21MCINS                    0x05                                                            //I
#define M21BTDBGIN                  0x06                                                            //I
//GPIO22
#define GPIO22MASK                  0x07
#define M22GPIO                     0x00                                                            //IO
#define M22BPI_BUS2                 0x01                                                            //O
//GPIO23
#define GPIO23MASK                  0x07
#define M23GPIO                     0x00                                                            //IO
#define M23PI_BUS1                  0x01                                                            //O

#define GPIO_MODE3                  (*(volatile uint32_t*)(GPIO_Base + 0x0C30))
#define GPIO_MODE3_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C34))
#define GPIO_MODE3_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C38))
#define GPIO_MODE3MASK              (GPIO24MASK|GPIO25MASK|GPIO26MASK|GPIO27MASK|\
                                    GPIO28MASK|GPIO29MASK|GPIO30MASK|GPIO31MASK)
//GPIO24
#define GPIO24MASK                  0x07
#define M24GPIO                     0x00                                                            //IO
#define M24BPI_BUS0                 0x01                                                            //O
//GPIO25
#define GPIO25MASK                  0x07
#define M25GPIO                     0x00                                                            //IO
#define M25CMRST                    0x01                                                            //O
#define M25LSRSTB                   0x02                                                            //O
#define M25CLKO1                    0x03                                                            //O
#define M25EINT15                   0x04                                                            //I
#define M25FMJTDI                   0x05                                                            //I
#define M25JTDI                     0x06                                                            //I
//GPIO26
#define GPIO26MASK                  0x07
#define M26GPIO                     0x00                                                            //IO
#define M26CMPDN                    0x01                                                            //O
#define M26LSCK1                    0x02                                                            //O
#define M26DAICLK                   0x03                                                            //O
#define M26SPICS                    0x04                                                            //IO
#define M26FMJTMS                   0x05                                                            //I
#define M26JTMS                     0x06                                                            //I
//GPIO27
#define GPIO27MASK                  0x0F
#define M27GPIO                     0x00                                                            //IO
#define M27CMCSD0                   0x01                                                            //I
#define M27LSCE_B1                  0x02                                                            //O
#define M27DAIPCMIN                 0x03                                                            //I
#define M27SPISCK                   0x04                                                            //IO
#define M27FMJTCK                   0x05                                                            //I
#define M27JTCK                     0x06                                                            //I
#define M27MC2CM0                   0x08                                                            //O
//GPIO28
#define GPIO28MASK                  0x0F
#define M28GPIO                     0x00                                                            //IO
#define M28CMCSD1                   0x01                                                            //I
#define M28LSDA1                    0x02                                                            //IO
#define M28DAIPCMOUT                0x03                                                            //O
#define M28SPIMOSI                  0x04                                                            //IO
#define M28FMJTRSTB                 0x05                                                            //I
#define M28JTRST_B                  0x06                                                            //I
#define M28MC2CK                    0x08                                                            //O
//GPIO29
#define GPIO29MASK                  0x0F
#define M29GPIO                     0x00                                                            //IO
#define M29CMMCLK                   0x01                                                            //O
#define M29LSA0DA1                  0x02                                                            //O
#define M29DAISYNC                  0x03                                                            //O
#define M29SPIMISO                  0x04                                                            //IO
#define M29FMJTDO                   0x05                                                            //O
#define M29JTDO                     0x06                                                            //O
#define M29MC2DA0                   0x08                                                            //IO
//GPIO30
#define GPIO30MASK                  0x07
#define M30GPIO                     0x00                                                            //IO
#define M30CMCSK                    0x01                                                            //I
#define M30LPTE                     0x02                                                            //I
#define M30CMCSD2                   0x03                                                            //I
#define M30EINT16                   0x04                                                            //I
#define M30JTRCK                    0x06                                                            //O
//GPIO31
#define GPIO31MASK                  0x07
#define M31GPIO                     0x00                                                            //IO
#define M31MCCK                     0x01                                                            //O
#define M31U2RXD                    0x04                                                            //I

#define GPIO_MODE4                  (*(volatile uint32_t*)(GPIO_Base + 0x0C40))
#define GPIO_MODE4_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C44))
#define GPIO_MODE4_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C48))
#define GPIO_MODE4MASK              (GPIO32MASK|GPIO33MASK|GPIO34MASK|GPIO35MASK|\
                                    GPIO36MASK|GPIO37MASK|GPIO38MASK|GPIO39MASK)
//GPIO32
#define GPIO32MASK                  0x07
#define M32GPIO                     0x00                                                            //IO
#define M32MCCM0                    0x01                                                            //O
#define M32U2TDX                    0x04                                                            //O
//GPIO33
#define GPIO33MASK                  0x07
#define M33GPIO                     0x00                                                            //IO
#define M33MCDA0                    0x01                                                            //IO
#define M33DAISYNC                  0x04                                                            //O
//GPIO34
#define GPIO34MASK                  0x07
#define M34GPIO                     0x00                                                            //IO
#define M34MCDA1                    0x01                                                            //IO
#define M34EINT17                   0x02                                                            //I
#define M34DAIPCMIN                 0x04                                                            //O
//GPIO35
#define GPIO35MASK                  0x07
#define M35GPIO                     0x00                                                            //IO
#define M35MCDA2                    0x01                                                            //IO
#define M35EINT18                   0x02                                                            //I
#define M35DAICLK                   0x04                                                            //O
//GPIO36
#define GPIO36MASK                  0x07
#define M36GPIO                     0x00                                                            //IO
#define M36MCDA3                    0x01                                                            //IO
#define M36EINT19                   0x02                                                            //I
#define M36CLKO2                    0x03                                                            //O
#define M36DAIPCMOUT                0x04                                                            //O
//GPIO37
#define GPIO37MASK                  0x07
#define M37GPIO                     0x00                                                            //IO
#define M37SIM1_SIO                 0x01                                                            //IO
//GPIO38
#define GPIO38MASK                  0x07
#define M38GPIO                     0x00                                                            //IO
#define M38SIM1_SRST                0x01                                                            //IO
//GPIO39
#define GPIO39MASK                  0x07
#define M39GPIO                     0x00                                                            //IO
#define M39SIM1_SCLK                0x01                                                            //IO

#define GPIO_MODE5                  (*(volatile uint32_t*)(GPIO_Base + 0x0C50))
#define GPIO_MODE5_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C54))
#define GPIO_MODE5_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C58))
#define GPIO_MODE5MASK              (GPIO40MASK|GPIO41MASK|GPIO42MASK|GPIO43MASK|\
                                    GPIO44MASK|GPIO45MASK|GPIO46MASK|GPIO47MASK)
//GPIO40
#define GPIO40MASK                  0x07
#define M40GPIO                     0x00                                                            //IO
#define M40SIM2_SIO                 0x01                                                            //IO
#define M40U2RTS                    0x03                                                            //O
//GPIO41
#define GPIO41MASK                  0x07
#define M41GPIO                     0x00                                                            //IO
#define M41SIM2_SRST                0x01                                                            //IO
#define M41CLKO3                    0x02                                                            //IO
#define M41U2CTS                    0x03                                                            //I
//GPIO42
#define GPIO42MASK                  0x07
#define M42GPIO                     0x00                                                            //IO
#define M42SIM2_SCLK                0x01                                                            //IO
#define M42LSCE1_B1                 0x02                                                            //O
//GPIO43
#define GPIO43MASK                  0x07
#define M43GPIO                     0x00                                                            //IO
#define M43SCL                      0x01                                                            //IO
//GPIO44
#define GPIO44MASK                  0x07
#define M44GPIO                     0x00                                                            //IO
#define M44SDA                      0x01                                                            //IO
//GPIO45
#define GPIO45MASK                  0x07
#define M45GPIO                     0x00                                                            //IO
#define M45LSRSTB                   0x01                                                            //O
#define M45CMRST                    0x03                                                            //O
//GPIO46
#define GPIO46MASK                  0x07
#define M46GPIO                     0x00                                                            //IO
#define M46LSCE_B0                  0x01                                                            //O
#define M46EINT20                   0x02                                                            //I
#define M46CMCSD0                   0x03                                                            //I
#define M46CLKO4                    0x04                                                            //O
//GPIO47
#define GPIO47MASK                  0x07
#define M47GPIO                     0x00                                                            //IO
#define M47LSCK0                    0x01                                                            //O
#define M47CMPDN                    0x03                                                            //O

#define GPIO_MODE6                  (*(volatile uint32_t*)(GPIO_Base + 0x0C60))
#define GPIO_MODE6_SET              (*(volatile uint32_t*)(GPIO_Base + 0x0C64))
#define GPIO_MODE6_CLR              (*(volatile uint32_t*)(GPIO_Base + 0x0C68))
#define GPIO_MODE6MASK              (GPIO48MASK|GPIO49MASK|GPIO50MASK|GPIO51MASK|\
                                    GPIO52MASK|GPIO53MASK|GPIO54MASK|GPIO55MASK)
//GPIO48
#define GPIO48MASK                  0x07
#define M48GPIO                     0x00                                                            //IO
#define M48LSDA0                    0x01                                                            //IO
#define M48EINT21                   0x02                                                            //I
#define M48CMCSD1                   0x03                                                            //I
#define M48WIFITOBT                 0x04                                                            //I
//GPIO49
#define GPIO49MASK                  0x07
#define M49GPIO                     0x00                                                            //IO
#define M49LSA0DA0                  0x01                                                            //O
#define M49LSCE1_B0                 0x02                                                            //O
#define M49CMMCLK                   0x03                                                            //O
//GPIO50
#define GPIO50MASK                  0x0F
#define M50GPIO                     0x00                                                            //IO
#define M50LPTE                     0x01                                                            //I
#define M50EINT22                   0x02                                                            //I
#define M50CMCSK                    0x03                                                            //I
#define M50CMCSD2                   0x04                                                            //I
#define M50MCINS                    0x06                                                            //I
#define M50CLKO5                    0x08                                                            //O
//GPIO51
#define GPIO51MASK                  0x07
#define M51GPIO                     0x00                                                            //IO
#define M51RESETB                   0x01                                                            //IO
//GPIO52
#define GPIO52MASK                  0x07
#define M52AGPI                     0x00                                                            //AGI
#define M52EINT23                   0x02                                                            //I
//GPIO53
#define GPIO53MASK                  0x07
#define M53AGPI53                   0x00                                                            //AGI
#define M53SRCLKENAI                0x01                                                            //I
#define M53EINT24                   0x02                                                            //I
//GPIO54
#define GPIO54MASK                  0x07
#define M54AGPIO                    0x00                                                            //AGIO
//GPIO55
#define GPIO55MASK                  0x07
#define M55AGPIO                    0x00                                                            //AGIO

#define GPIO_SETMODE(Pin, Mode)     do\
                                    {\
                                        if ((Pin) <= GPIOMAX)\
                                        {\
                                            uint8_t  RegIdx = ((Pin) >> 3) & 0x07;                  /* Index of GPIO_MODE_XXX register */\
                                            uint8_t  ModePos= ((Pin) & 0x07) << 2;                  /* Mode bits position */\
                                            uint32_t Mask = GPIO_MODEMASK;                          /* Bit field mask */\
                                            GPIO_MODE_CLR(RegIdx) = (Mask) << ModePos;\
                                            GPIO_MODE_SET(RegIdx) = ((Mode) & (Mask)) << ModePos;\
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
extern void GPIO_SetupMode(uint32_t Pin, uint32_t Flags);

#endif /* _GPIO_H_ */
