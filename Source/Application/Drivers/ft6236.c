// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "appconfig.h"
#include "ft6236.h"

// Software I2C configuration
#ifdef SWI2C_SCL
#undef SWI2C_SCL
#endif
#ifdef SWI2C_SDA
#undef SWI2C_SDA
#endif
#ifdef SWI2C_BITDELAY
#undef SWI2C_BITDELAY
#endif

#define SWI2C_SDA       CPT_SDA
#define SWI2C_SCL       CPT_SCL
#define SWI2C_HALFBIT   1
#define SWI2C_BITDELAY  (2 * SWI2C_HALFBIT)

boolean FT6236_PenPressed[FT6236_NUMPOFOINTS];
TPOINT  FT6326_PenCoordinates[FT6236_NUMPOFOINTS];

boolean FT6236_ReadData(uint8_t Register, uint8_t *Data, uint32_t Count)
{
    if (Data == NULL) return false;
    if (Count)
    {
        boolean Res;

        SW_I2C_READDATA(FT6236_ADDRESS, Register, Data, Count, Res);
        return Res;
    }
    return true;
}

boolean FT6236_WriteData(uint8_t Register, uint8_t *Data, uint32_t Count)
{
    if (Data == NULL) return false;
    if (Count)
    {
        boolean Res;

        SW_I2C_WRITEDATA(FT6236_ADDRESS, Register, Data, Count, Res);
        return Res;
    }
    return true;
}

void FT6236_ISR(void)
{
    uint8_t  TPData[6 * FT6236_NUMPOFOINTS + 1];                                                    // TD_STATUS + 6 bytes per point
    uint32_t i, p;

    if (FT6236_ReadData(TD_STATUS, TPData, sizeof(TPData)))
    {
        for(i = 0; i < FT6236_NUMPOFOINTS; i++)
        {
            TPENEVENT TSEvent;

            p = i * 6 + 1;
            TSEvent.PenIndex = TP_ID(TPData[p + 0x02]);
            if (TSEvent.PenIndex >= FT6236_NUMPOFOINTS) continue;

            TSEvent.PXY.x = PXHigh(TPData[p + 0x00]) | TPData[p + 0x01];
            TSEvent.PXY.y = PYHigh(TPData[p + 0x02]) | TPData[p + 0x03];

            switch (PEventVal(TPData[p + 0x00]))
            {
            case PE_PRESS:
                FT6326_PenCoordinates[TSEvent.PenIndex] = TSEvent.PXY;
                FT6236_PenPressed[TSEvent.PenIndex] = true;
                EM_PostEvent(ET_PENPRESS, NULL, &TSEvent, sizeof(TPENEVENT));
                break;
            case PE_LIFTUP:
                if (FT6236_PenPressed[TSEvent.PenIndex])
                    EM_PostEvent(ET_PENRELEASE, NULL, &TSEvent, sizeof(TPENEVENT));
                FT6236_PenPressed[TSEvent.PenIndex] = false;
                break;
            case PE_CONTACT:
                if (FT6236_PenPressed[TSEvent.PenIndex] &&
                        (FT6326_PenCoordinates[TSEvent.PenIndex].x != TSEvent.PXY.x) &&
                        (FT6326_PenCoordinates[TSEvent.PenIndex].y != TSEvent.PXY.y))
                {
                    FT6326_PenCoordinates[TSEvent.PenIndex] = TSEvent.PXY;
                    EM_PostEvent(ET_PENMOVE, NULL, &TSEvent, sizeof(TPENEVENT));
                }
                break;
            case PE_NOEVENT:
                break;
            }
        }
    }
}

boolean FT6236_RegisterISR(void)
{
    return NVIC_RegisterEINT(CPT_INT_NUM, FT6236_ISR, EINT_SENS_EDGE, EINT_POLL, false);
}

boolean FT6236_UnregisterISR(void)
{
    return NVIC_UnregisterEINT(CPT_INT_NUM);
}

boolean FT6236_Initialize(void)
{
    boolean DeviceFound;

    DebugPrint(" TS driver initialization...");

    SetupSW_I2C_SCL(CPT_SCL, CPT_SCL_MODE);
    SetupSW_I2C_SDA(CPT_SDA, CPT_SDA_MODE);

    GPIO_SETMODE(CPT_RST, CPT_RST_MODE);                                                            // Reset pin setup
    GPIO_SETDIROUT(CPT_RST);

    GPIO_SETMODE(CPT_INT, CPT_INT_MODE);                                                            // External interrupt pin setup

    GPIO_DATAOUT(CPT_RST, 0);                                                                       // Assert CTP reset
    USC_Pause_us(10000);
    GPIO_DATAOUT(CPT_RST, 1);                                                                       // Release CTP reset

    SW_I2C_CHECKDEVICE(FT6236_ADDRESS, DeviceFound);
    if (DeviceFound && FT6236_RegisterISR())
    {
        /*
        There should be ft6236 initialization here, but it is
        not required for the chip with Chinese firmware.
        */

        NVIC_EnableEINT(CPT_INT_NUM);
        DebugPrint("found at address 0x%02X - Complete.\r\n", FT6236_ADDRESS);
        return true;
    }
    DebugPrint("Failed!\r\n");
    return false;
}

void FT6236_Sleep(void)
{
}

void FT6236_Resume(void)
{
}

