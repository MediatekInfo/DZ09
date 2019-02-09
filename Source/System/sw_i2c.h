#ifndef _SW_I2C_H_
#define _SW_I2C_H_

#define SW_I2C_ACK                  false
#define SW_I2C_NACK                 true

#define SetupSW_I2C_SCL(Pin, Mode)  do\
                                    {\
                                        GPIO_SETMODE(Pin, Mode);\
                                        GPIO_SETDIRIN(Pin);\
                                        GPIO_SETPULLUP(Pin);\
                                        GPIO_PULLENABLE(Pin);\
                                    }\
                                    while(0)
#define SetupSW_I2C_SDA(Pin, Mode)  do\
                                    {\
                                        GPIO_SETMODE(Pin, Mode);\
                                        GPIO_SETDIRIN(Pin);\
                                        GPIO_SETPULLUP(Pin);\
                                        GPIO_PULLENABLE(Pin);\
                                        GPIO_SETINPUTEN(Pin);\
                                    }\
                                    while(0)

#define SW_I2C_SCL_HI()             GPIO_SETDIRIN(SWI2C_SCL)
#define SW_I2C_SCL_LO()             do\
                                    {\
                                        GPIO_DATAOUT(SWI2C_SCL, 0);\
                                        GPIO_SETDIROUT(SWI2C_SCL);\
                                    }\
                                    while(0)

#define SW_I2C_SDA_HI()             GPIO_SETDIRIN(SWI2C_SDA)
#define SW_I2C_SDA_LO()             do\
                                    {\
                                        GPIO_DATAOUT(SWI2C_SDA, 0);\
                                        GPIO_SETDIROUT(SWI2C_SDA);\
                                    }\
                                    while(0)

#define SW_I2C_START()              do\
                                    {\
                                        SW_I2C_SDA_HI();\
                                        SW_I2C_SCL_HI();\
                                        USC_Pause_us(SWI2C_HALFBIT);\
                                        SW_I2C_SDA_LO(); USC_Pause_us(SWI2C_HALFBIT);\
                                        SW_I2C_SCL_LO(); USC_Pause_us(SWI2C_HALFBIT);\
                                    }\
                                    while(0)
#define SW_I2C_REPSTART()           do\
                                    {\
                                        SW_I2C_SCL_HI(); USC_Pause_us(SWI2C_HALFBIT);\
                                        SW_I2C_SDA_LO(); USC_Pause_us(SWI2C_HALFBIT);\
                                        SW_I2C_SCL_LO(); USC_Pause_us(SWI2C_HALFBIT);\
                                    }\
                                    while(0)
#define SW_I2C_STOP()               do\
                                    {\
                                        SW_I2C_SDA_LO(); USC_Pause_us(SWI2C_HALFBIT);\
                                        SW_I2C_SCL_HI(); USC_Pause_us(SWI2C_HALFBIT);\
                                        SW_I2C_SDA_HI(); USC_Pause_us(SWI2C_HALFBIT);\
                                    }\
                                    while(0)
#define SW_I2C_DATAIN()             GPIO_DATAIN(SWI2C_SDA)
#define SW_I2C_WRITEBYTE(b, res)    do\
                                    {\
                                        uint32_t i;\
                                        uint8_t  byte = b;\
                                        for(i = 0; i < 8; i++)\
                                        {\
                                            if (byte & 0x80) SW_I2C_SDA_HI();\
                                            else SW_I2C_SDA_LO();\
                                            USC_Pause_us(SWI2C_HALFBIT); SW_I2C_SCL_HI();\
                                            USC_Pause_us(SWI2C_BITDELAY); SW_I2C_SCL_LO();\
                                            USC_Pause_us(SWI2C_HALFBIT);\
                                            byte <<= 1;\
                                        }\
                                        SW_I2C_SDA_HI(); USC_Pause_us(SWI2C_BITDELAY);\
                                        SW_I2C_SCL_HI(); USC_Pause_us(SWI2C_BITDELAY);\
                                        i = SW_I2C_DATAIN();\
                                        SW_I2C_SCL_LO(); USC_Pause_us(SWI2C_BITDELAY);\
                                        res = (i) ? SW_I2C_NACK : SW_I2C_ACK;\
                                    }\
                                    while(0)
#define SW_I2C_READBYTE(b, ack)     do\
                                    {\
                                        uint32_t i, v, res = 0;\
                                        SW_I2C_SDA_HI();\
                                        for(i = 0; i < 8; i++)\
                                        {\
                                            res <<= 1;\
                                            SW_I2C_SCL_HI(); USC_Pause_us(SWI2C_BITDELAY);\
                                            v = SW_I2C_DATAIN();\
                                            SW_I2C_SCL_LO(); USC_Pause_us(SWI2C_BITDELAY);\
                                            if (v) res |= 0x01;\
                                        }\
                                        if (ack) SW_I2C_SDA_HI();\
                                        else SW_I2C_SDA_LO();\
                                        SW_I2C_SCL_HI(); USC_Pause_us(SWI2C_BITDELAY);\
                                        SW_I2C_SCL_LO(); USC_Pause_us(SWI2C_BITDELAY);\
                                        b = res;\
                                    }\
                                    while(0)
#define SW_I2C_WRITEDATA(Slave, Reg, Data, Size, Res)\
                                    do\
                                    {\
                                        boolean Ack = SW_I2C_NACK;\
                                        uint8_t *Dat = Data, Sz = Size;\
                                        SW_I2C_START();\
                                        while(true)\
                                        {\
                                            SW_I2C_WRITEBYTE(Slave << 1, Ack);\
                                            if (Ack == SW_I2C_NACK) break;\
                                            SW_I2C_WRITEBYTE(Reg, Ack);\
                                            if (Dat != NULL)\
                                            {\
                                                while(Sz-- && (Ack == SW_I2C_ACK))\
                                                {\
                                                    SW_I2C_WRITEBYTE(*Dat++, Ack);\
                                                }\
                                            }\
                                        break;\
                                        }\
                                        SW_I2C_STOP();\
                                        Res = !Ack;\
                                    }\
                                    while(0)
#define SW_I2C_READDATA(Slave, Reg, Data, Size, Res)\
                                    do\
                                    {\
                                        boolean Ack = SW_I2C_NACK;\
                                        uint8_t *Dat = Data, Sz = Size;\
                                        SW_I2C_START();\
                                        while(Sz && (Dat != NULL))\
                                        {\
                                            SW_I2C_WRITEBYTE(Slave << 1, Ack);\
                                            if (Ack == SW_I2C_NACK) break;\
                                            SW_I2C_WRITEBYTE(Reg, Ack);\
                                            if (Ack == SW_I2C_NACK) break;\
                                            SW_I2C_REPSTART();\
                                            SW_I2C_WRITEBYTE((Slave << 1) | 0x01, Ack);\
                                            if (Ack == SW_I2C_NACK) break;\
                                            while(Sz)\
                                            {\
                                                Ack = (Sz--) ? SW_I2C_ACK : SW_I2C_NACK;\
                                                SW_I2C_READBYTE(*Dat++, Ack);\
                                            }\
                                            Ack = false;\
                                        }\
                                        Res = !Ack;\
                                        SW_I2C_STOP();\
                                    }\
                                    while(0)
#define SW_I2C_CHECKDEVICE(Slave, Res)\
                                    do\
                                    {\
                                        boolean Ack;\
                                        SW_I2C_START();\
                                        SW_I2C_WRITEBYTE(Slave << 1, Ack);\
                                        SW_I2C_STOP();\
                                        Res = !Ack;\
                                    }\
                                    while(0)
#endif /* _SW_I2C_H_ */
