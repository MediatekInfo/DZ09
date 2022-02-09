// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2021, 2020, 2019 AJScorp
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
#include "lcdif.h"

const uint8_t CFormatToBPP[] = {1, 2, 0, 3, 4, 4, 4};

pLAYER LCDIF_LAYER[LCDIF_NUMLAYERS] = {(volatile pLAYER) &LCDIF_LAYER0BASE,
                                       (volatile pLAYER) &LCDIF_LAYER1BASE,
                                       (volatile pLAYER) &LCDIF_LAYER2BASE,
                                       (volatile pLAYER) &LCDIF_LAYER3BASE
                                      };

TSCREEN LCDScreen;
pDLIST  LCDIFQueue;

void LCDIF_WriteCommand(uint8_t Cmd)
{
    LCDIF_SCMD0 = Cmd;
}

void LCDIF_WriteData(uint8_t Data)
{
    LCDIF_SDAT0 = Data;
}

uint8_t LCDIF_ReadData(void)
{
    return LCDIF_SDAT0;
}

void LCDIF_SetClock(TLCDSCLOCK Clock)
{
    LCD_SERIAL_CLOCK_REG = (LCD_SERIAL_CLOCK_REG & ~LCD_SERIAL_CLOCK_MASK) | LCD_SERIAL_CLOCK(Clock);
}

void LCDIF_StartLCDTransfer(void)
{
    LCDIF_START = 0;
    LCDIF_START = LCDIF_RUN;
}

boolean LCDIF_IsQueueRunning(void)
{
    return (LCDIF_START & LCDIF_RUN) != 0;
}

void LCDIF_DeleteCommandFromQueue(void)
{
    pDLITEM tmpItem = DL_GetFirstItem(LCDIFQueue);

    if (tmpItem != NULL)
    {
        free(((pLCDCMD)tmpItem->Data)->Commands);
        free(tmpItem->Data);
        DL_DeleteFirstItem(LCDIFQueue);
    }
}

boolean LCDIF_GetCommandFromQueue(void)
{
    pDLITEM tmpItem;

    while((tmpItem = DL_GetFirstItem(LCDIFQueue)) != NULL)
    {
        pLCDCMD CMD = tmpItem->Data;

        if (CMD != NULL)
        {
            LCDIF_WROIOFS   = LCDIF_WROIOFX(CMD->UpdateRect.l + LCDScreen.ScreenOffset.x) |
                              LCDIF_WROIOFY(CMD->UpdateRect.t + LCDScreen.ScreenOffset.y);
            LCDIF_WROISIZE  = LCDIF_WROICOL(CMD->UpdateRect.r - CMD->UpdateRect.l + 1) |
                              LCDIF_WROIROW(CMD->UpdateRect.b - CMD->UpdateRect.t + 1);

            if (CMD->CMDCount)
            {
                uint32_t i;

                for(i = 0; i < CMD->CMDCount; i++) LCDIF_COMD(i) = CMD->Commands[i];
                LCDIF_WROICON &= ~LCDIF_COMMAND_MASK;
                LCDIF_WROICON |= LCDIF_COMMAND(CMD->CMDCount - 1) | LCDIF_ENC;
            }
            else LCDIF_WROICON &= ~LCDIF_ENC;

            LCDIF_DeleteCommandFromQueue();
            return true;
        }
        LCDIF_DeleteCommandFromQueue();
    }
    return false;
}

void LCDIF_RestartQueue(void)
{
    uint32_t flags = __disable_interrupts();

    if (!LCDIF_IsQueueRunning() && LCDIF_GetCommandFromQueue()) LCDIF_StartLCDTransfer();

    __restore_interrupts(flags);
}

boolean LCDIF_AddCommandToQueue(uint32_t *CmdArray, uint32_t CmdCount, pRECT UpdateRect)
{
    pLCDCMD CMD;

    if (CmdCount && (CmdArray != NULL))
    {
        CMD = malloc(sizeof(TLCDCMD));
        if (CMD != NULL)
        {
            CMD->CMDCount = CmdCount;
            CMD->UpdateRect = (UpdateRect != NULL) ? *UpdateRect : Rect(0, 0, 0, 0);
            CMD->Commands = CmdArray;

            if (DL_AddItem(LCDIFQueue, CMD) != NULL)
            {
                LCDIF_RestartQueue();
                while(DL_GetItemsCount(LCDIFQueue) >= MAX_LCDQUEUE_SIZE);
                return true;
            }
            free(CMD);
        }
    }
    free(CmdArray);

    return false;
}

void LCDIF_ISR(void)
{
    uint16_t IntID;

    LCDIF_START = 0;
    if ((IntID = LCDIF_INTSTA) & LCDIF_CPL)
    {
        if (LCDIF_GetCommandFromQueue()) LCDIF_START = LCDIF_RUN;
    }
    else DebugPrint("Unsolicited LCDIF interrupt code 0x%04X!\r\n", IntID);
}

boolean LCDIF_RegisterISR(void)
{
    return NVIC_RegisterIRQ(IRQ_LCD_CODE, LCDIF_ISR, IRQ_SENS_LEVEL, true);
}

boolean LCDIF_UnregisterISR(void)
{
    return NVIC_UnregisterIRQ(IRQ_LCD_CODE);
}

void LCDIF_DisableInterface(void)
{
    LCDScreen.Initialized = false;

    LCDIF_INTEN = 0;                                                                                // Disable LCDIF interrupts
    LCDIF_START = LCDIF_INT_RESET;

    LCDIF_UnregisterISR();

    LCDDRV_Sleep();
    PCTL_PowerDown(PD_LCD);                                                                         // Power down LCD controller
    PCTL_PowerDown(PD_SLCD);                                                                        // Power down serial interface
    LCDIFQueue = DL_Delete(LCDIFQueue, true);
}

boolean LCDIF_Initialize(void)
{
    memset(&LCDScreen, 0x00, sizeof(LCDScreen));

    GPIO_Setup(LCD_RESET, GPMODE(LCD_RESET_MODE));                                                  // Setup Reset pin
    GPIO_Setup(   LCD_CE, GPMODE(LCD_CE_MODE));                                                     // Setup CS pin
    GPIO_Setup(  LCD_SCK, GPMODE(LCD_SCK_MODE));                                                    // Setup Clock pin
    GPIO_Setup(  LCD_SDA, GPMODE(LCD_SDA_MODE));                                                    // Setup Data pin

    LCDIF_SetClock(LCD_CLOCK_MPLL_DIV4);
    PCTL_PowerUp(PD_SLCD);                                                                          // Power up LCD serial interface
    PCTL_PowerUp(PD_LCD);                                                                           // Power up LCD controller

    LCDScreen.ScreenRgn = Rect(0, 0, LCD_XRESOLUTION - 1, LCD_YRESOLUTION - 1);
    LCDScreen.ScreenOffset = Point(0, 0);
    LCDScreen.ScreenCount = 1;
    LCDScreen.ScreenIndex = 0;

    LCDScreen.VLayer[0].LayerEnMask = LCDIF_L0EN;
    LCDScreen.VLayer[1].LayerEnMask = LCDIF_L1EN;
    LCDScreen.VLayer[2].LayerEnMask = LCDIF_L2EN;
    LCDScreen.VLayer[3].LayerEnMask = LCDIF_L3EN;

    LCDIF_INTEN = 0;                                                                                // Disable LCDIF interrupts
    LCDIF_START = LCDIF_INT_RESET;                                                                  // Assert LCD controller internal Reset
    LCDIF_START = 0;                                                                                // Release LCD controller internal Reset

    if (LCDIFQueue == NULL)  LCDIFQueue = DL_Create(0);
    if ((LCDIFQueue == NULL) || !LCDIF_RegisterISR())
    {
        if (LCDIFQueue == NULL)
        {
            DebugPrint("Failed! (Insufficient memory)\r\n");
            DebugPrint(" Total used %uKiB\r\n", GetTotalUsedMemory() >> 10);
        }
        else DebugPrint("Failed! (Unable to register LCD ISR 0x%02X)\r\n", IRQ_LCD_CODE);
        LCDIF_DisableInterface();
        return false;
    }

    LCDIF_RSTB = LCDIF_RESET0;                                                                      // Assert LCD panel reset
    USC_Pause_us(1000);                                                                             // Delay 1ms for reset
    LCDIF_RSTB = LCDIF_RESET1;                                                                      // Release LCD panel reset

    LCDIF_SIF0_TIMING = LCD_SIF_TIMINGS;                                                            // Setup SIF timing
    LCDIF_SIF_CON = LCD_SIF_CON;                                                                    // Setup interface configuration

    LCDIF_WROICON = LCD_SIF_WROI;                                                                   // Setup LCD data format
    LCDIF_WROICADD = LCDIF_CSIF0;                                                                   // MT6261 has only one serial interface
    LCDIF_WROIDADD = LCDIF_DSIF0;
    LCDIF_WROIOFS = LCDIF_WROIOFX(0) | LCDIF_WROIOFY(0);
    LCDIF_WROISIZE = LCDIF_WROICOL(LCD_XRESOLUTION) | LCDIF_WROIROW(LCD_YRESOLUTION);
    LCDIF_WROI_BGCLR = LCD_BACKCOLOR;

    if (LCDDRV_Initialize())
    {
        LCDIF_INTEN = LCDIF_CPL;                                                                    // Enable LCD interrupts
        LCDScreen.Initialized = true;
        DebugPrint("Complete.\r\n");
        return true;
    }

    LCDIF_DisableInterface();
    DebugPrint("Failed! (Can't initialize LCD driver)\r\n");
    return false;
}

boolean LCDIF_SetupLayer(TVLINDEX Layer, TPOINT Offset, uint32_t SizeX, uint32_t SizeY,
                         TCFORMAT CFormat, uint8_t GlobalAlpha, uint32_t ForeColor)
{
    if (Layer >= LCDIF_NUMLAYERS) return false;

    LCDScreen.VLayer[Layer].Enabled = false;
    LCDScreen.VLayer[Layer].Initialized = false;
    LCDIF_WROICON &= ~LCDScreen.VLayer[Layer].LayerEnMask;
    if (LCDScreen.VLayer[Layer].FrameBuffer != NULL)
    {
        free(LCDScreen.VLayer[Layer].FrameBuffer);
        LCDScreen.VLayer[Layer].FrameBuffer = NULL;
    }

    if (SizeX && SizeY && (CFormat < CF_NUM))
    {
        uint32_t n;

        LCDScreen.VLayer[Layer].LayerRgn = Rect(0, 0, SizeX - 1, SizeY - 1);
        LCDScreen.VLayer[Layer].LayerOffset = Offset;
        LCDScreen.VLayer[Layer].ColorFormat = CFormat;
        LCDScreen.VLayer[Layer].BPP = CFormatToBPP[CFormat];

        n = SizeX * SizeY * LCDScreen.VLayer[Layer].BPP;
        if (n)
        {
            LCDScreen.VLayer[Layer].FrameBuffer = malloc(n);
            if (LCDScreen.VLayer[Layer].FrameBuffer != NULL)
            {
                LCDIF_LAYER[Layer]->LCDIF_LWINCON = LCDIF_LROTATE(LCDIF_LR_NO) | LCDIF_LCF(CFormat);
                if ((CFormat == LCDIF_LCF_ARGB8888) || (CFormat == LCDIF_LCF_PARGB8888) || (GlobalAlpha != 0xFF))
                    LCDIF_LAYER[Layer]->LCDIF_LWINCON |= LCDIF_LALPHA(GlobalAlpha) | LCDIF_LALPHA_EN;

                LCDIF_LAYER[Layer]->LCDIF_LWINOFFS  = LCDIF_LWINOF_X(Offset.x) | LCDIF_LWINOF_Y(Offset.y);
                LCDIF_LAYER[Layer]->LCDIF_LWINADD   = (uint32_t)LCDScreen.VLayer[Layer].FrameBuffer;
                LCDIF_LAYER[Layer]->LCDIF_LWINSIZE  = LCDIF_LCOLS(SizeX) | LCDIF_LROWS(SizeY);
                LCDIF_LAYER[Layer]->LCDIF_LWINSCRL  = LCDIF_LSCCOL(0) | LCDIF_LSCROW(0);
                LCDIF_LAYER[Layer]->LCDIF_LWINMOFS  = LCDIF_LMOFCOL(0) | LCDIF_LMOFROW(0);
                LCDIF_LAYER[Layer]->LCDIF_LWINPITCH = LCDScreen.VLayer[Layer].BPP * SizeX;

                LCDScreen.VLayer[Layer].Initialized = true;
            }
        }
    }
    return LCDScreen.VLayer[Layer].Initialized;
}

boolean LCDIF_SetLayerEnabled(TVLINDEX Layer, boolean Enabled, boolean UpdateScreen)
{
    TRECT LayerRect;

    if ((Layer >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Layer].Initialized) return false;

    if (LCDScreen.VLayer[Layer].Enabled != Enabled)
    {
        if (Enabled) LCDIF_WROICON |= LCDScreen.VLayer[Layer].LayerEnMask;
        else LCDIF_WROICON &= ~LCDScreen.VLayer[Layer].LayerEnMask;

        LCDScreen.VLayer[Layer].Enabled = Enabled;

        if (UpdateScreen)
        {
            LayerRect = LCDScreen.VLayer[Layer].LayerRgn;
            LayerRect.l += LCDScreen.VLayer[Layer].LayerOffset.x - LCDScreen.ScreenOffset.x;
            LayerRect.r += LCDScreen.VLayer[Layer].LayerOffset.x - LCDScreen.ScreenOffset.x;
            LayerRect.t += LCDScreen.VLayer[Layer].LayerOffset.y - LCDScreen.ScreenOffset.y;
            LayerRect.b += LCDScreen.VLayer[Layer].LayerOffset.y - LCDScreen.ScreenOffset.y;
            if (GDI_ANDRectangles(&LayerRect, &LCDScreen.ScreenRgn))
                LCDIF_UpdateRectangle(LayerRect);
        }
    }
    return LCDScreen.VLayer[Layer].Enabled;
}

boolean LCDIF_GetLayerPosition(TVLINDEX Layer, pRECT Position)
{
    if ((Layer >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Layer].Initialized) return false;

    if (Position != NULL)
        *Position = GDI_LocalToGlobalRct(&LCDScreen.VLayer[Layer].LayerRgn,
                                         &LCDScreen.VLayer[Layer].LayerOffset);
    return true;
}

boolean LCDIF_SetLayerPosition(TVLINDEX Layer, TRECT Position, boolean UpdateScreen)
{
    if ((Layer < LCDIF_NUMLAYERS) && LCDScreen.VLayer[Layer].Initialized)
    {
        TRECT PrevLayerPosition = GDI_LocalToGlobalRct(&LCDScreen.VLayer[Layer].LayerRgn,
                                  &LCDScreen.VLayer[Layer].LayerOffset);

        if (memcmp(&PrevLayerPosition, &Position, sizeof(TRECT)) != 0)
        {
            uint32_t intflags = __disable_interrupts();

            LCDScreen.VLayer[Layer].LayerOffset = Position.lt;
            LCDScreen.VLayer[Layer].LayerRgn = GDI_GlobalToLocalRct(&Position, &LCDScreen.VLayer[Layer].LayerOffset);

            LCDIF_LAYER[Layer]->LCDIF_LWINOFFS = LCDIF_LWINOF_X(LCDScreen.VLayer[Layer].LayerOffset.x) |
                                                 LCDIF_LWINOF_Y(LCDScreen.VLayer[Layer].LayerOffset.y);
            LCDIF_LAYER[Layer]->LCDIF_LWINSIZE  = LCDIF_LCOLS(LCDScreen.VLayer[Layer].LayerRgn.r - 1) |
                                                  LCDIF_LROWS(LCDScreen.VLayer[Layer].LayerRgn.b - 1);
            __restore_interrupts(intflags);

            if (UpdateScreen)
            {
                pRLIST   UpdateRects = GDI_SUBRectangles(&PrevLayerPosition, &Position);

                Position = GDI_GlobalToLocalRct(&Position, &LCDScreen.ScreenOffset);
                LCDIF_UpdateRectangle(Position);
                if (UpdateRects != NULL)
                {
                    uint32_t i;

                    for (i = 0; i < UpdateRects->Count; i++)
                        LCDIF_UpdateRectangle(GDI_GlobalToLocalRct(&UpdateRects->Item[i], &LCDScreen.ScreenOffset));

                    GDI_DeleteRList(UpdateRects);
                }
            }
        }
        return true;
    }
    return false;
}

TRECT LCDIF_GetScreenPosition(void)
{
    return GDI_LocalToGlobalRct(&LCDScreen.ScreenRgn, &LCDScreen.ScreenOffset);
}

boolean LCDIF_SetScreenPosition(TRECT Position, boolean UpdateScreen)
{
    TRECT PrevPosition = GDI_LocalToGlobalRct(&LCDScreen.ScreenRgn, &LCDScreen.ScreenOffset);

    if (!LCDScreen.Initialized) return false;

    if (memcmp(&PrevPosition, &Position, sizeof(TRECT)) != 0)
    {
        uint32_t intflags = __disable_interrupts();

        LCDScreen.ScreenOffset = Position.lt;
        LCDScreen.ScreenRgn = GDI_GlobalToLocalRct(&Position, &LCDScreen.ScreenOffset);

        LCDIF_WROIOFS = LCDIF_WROIOFX(LCDScreen.ScreenOffset.x) |
                        LCDIF_WROIOFY(LCDScreen.ScreenOffset.y);
        LCDIF_WROISIZE = LCDIF_WROICOL(LCDScreen.ScreenRgn.r - 1) |
                         LCDIF_WROIROW(LCDScreen.ScreenRgn.b - 1);
        __restore_interrupts(intflags);

        if (UpdateScreen)
            LCDIF_UpdateRectangle(LCDScreen.ScreenRgn);
    }
    return true;
}

boolean LCDIF_IsLayerInitialized(TVLINDEX Layer)
{
    return (Layer < LCDIF_NUMLAYERS) && LCDScreen.VLayer[Layer].Initialized;
}

void LCDIF_UpdateRectangle(TRECT Rct)
{
    uint32_t *Commands, CmdCount;

    if (GDI_ANDRectangles(&Rct, &LCDScreen.ScreenRgn))
    {
        Commands = LCDDRV_SetOutputWindow(&Rct, &CmdCount, LCDIF_DATA, LCDIF_CMD);
        if (Commands != NULL)
            LCDIF_AddCommandToQueue(Commands, CmdCount, &Rct);
    }
}

void LCDIF_UpdateRectangleBlocked(pRECT Rct)
{
    if (Rct == NULL) return;

    LCDIF_UpdateRectangle(*Rct);
    while(LCDIF_IsQueueRunning());
}
