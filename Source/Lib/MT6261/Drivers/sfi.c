// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 AJScorp
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
#include "sfi.h"

static void SFI_MaskAHBChannel(boolean Mask)
{
    if (Mask) RW_SFI_MISC_CTL3 = RW_SFI_MISC_CTL3 | SFI_CH2_TRANS_MASK;
    else      RW_SFI_MISC_CTL3 = RW_SFI_MISC_CTL3 & ~SFI_CH2_TRANS_MASK;
}

static boolean SFI_IsQPIMode(TSFI_CS CS)
{
    if      (CS == SFI_CS0) return !!(RW_SFI_DIRECT_CTL & SFI_QPI_EN);
    else if (CS == SFI_CS1) return !!(RW_SFI_DIRECT_CTL2 & SFI_QPI_EN);
    else return false;
}

static void SFI_MACEnable(TSFI_CS CS)
{
    uint32_t Value;

    SFI_MaskAHBChannel(true);

    Value = RW_SFI_MAC_CTL;
    if (Value >= SFI_CSMAX)
    {
        DebugPrint("SFI CS out of range (%d)\r\n", Value);
        return;
    }
    else if (SFI_IsQPIMode(CS))
        Value |= SFI_MAC_SIO_SEL;

    Value |= SFI_MAC_EN;

    while(!(RW_SFI_MISC_CTL3 & SFI_CH2_TRANS_IDLE)) {}
    while(!(RW_SFI_MISC_CTL & SFI_REQ_IDLE)) {}

    RW_SFI_MAC_CTL = Value;
}

static uint32_t SFI_MACTrigger(TSFI_CS CS)
{
    uint32_t Value = RW_SFI_MAC_CTL;

    Value |= SFI_TRIG | SFI_MAC_EN;
    if (CS == SFI_CS1) Value |= SFI_MAC_SEL;
    RW_SFI_MAC_CTL = Value;

    while(!(RW_SFI_MAC_CTL & SFI_WIP_READY));
    while(RW_SFI_MAC_CTL & SFI_WIP);

    return 0;
}

static void SFI_MACLeave(TSFI_CS CS)
{

}

static void SFI_MACWaitReady(TSFI_CS CS)
{
    SFI_MACTrigger(CS);
    SFI_MACLeave(CS);
}

void SFI_WriteCommand(TSFI_CS CS, uint8_t Command, uint8_t ReadLength)
{
    uint32_t intflags = __disable_interrupts();

    SFI_MACEnable(CS);
    RW_SFI_GPRAM_DATA = Command;
    RW_SFI_MAC_OUTL = ReadLength;
    RW_SFI_MAC_INL = 0;
    SFI_MACWaitReady(CS);
    __restore_interrupts(intflags);
}

void SFI_Initialize(void)
{
    /* GPIO high-Z Enable*/
    /* Normal MODE */
    SFIO_CFG0 = SFIO_CFG0 & SF_NORMAL_HIGHZ;
    SFIO_CFG1 = SFIO_CFG1 & SF_NORMAL_HIGHZ;
    SFIO_CFG2 = SFIO_CFG2 & SF_NORMAL_HIGHZ;

    /* SLT  MODE */
//    if((SFI_ReadReg32(SEJ_BASE)&SF_SLT_MODE_MASK) ==SF_SLT_MODE)
//    {
//        SFI_WriteReg32(GPIO_RESEN0_1, (SFI_ReadReg32(GPIO_RESEN0_1)& (SF_SLT_HIGHZ)));
//        SFI_WriteReg32(GPIO_RESEN1_1, (SFI_ReadReg32(GPIO_RESEN1_1)& (SF_SLT_HIGHZ)));
//        SFI_WriteReg32(GPIO_DRV1, (SFI_ReadReg32(GPIO_DRV1)&(SF_SLT_DRIVING_CLR))|SF_SLT_DRIVING_12mA ); //SLT driving 12mA
//    }
}
