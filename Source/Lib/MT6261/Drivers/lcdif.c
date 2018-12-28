// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
        if (tmpItem->Data != NULL) free(tmpItem->Data);
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
    uint32_t flags = DisableInterrupts();

    if (!LCDIF_IsQueueRunning() && LCDIF_GetCommandFromQueue()) LCDIF_StartLCDTransfer();

    RestoreInterrupts(flags);
}

boolean LCDIF_AddCommandToQueue(uint32_t *CmdArray, uint32_t CmdCount, pRECT UpdateRect)
{
    pLCDCMD CMD;

    if (!CmdCount || (CmdArray == NULL)) return false;

    CMD = malloc(sizeof(TLCDCMD) + CmdCount * sizeof(uint32_t));
    if (CMD != NULL)
    {
        CMD->CMDCount = CmdCount;
        CMD->UpdateRect = (UpdateRect != NULL) ? *UpdateRect : Rect(0, 0, 0, 0);

        memcpy(CMD->Commands, CmdArray, CmdCount * sizeof(uint32_t));
        if (!DL_AddItem(LCDIFQueue, CMD))
        {
            free(CMD);
            return false;
        }

        LCDIF_RestartQueue();
        while(DL_GetItemsCount(LCDIFQueue) >= MAX_LCDQUEUE_SIZE);

        return true;
    }
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
    else DebugPrint("Unsolicited LCDIF interrupt code 0x%04X!)\r\n", IntID);
}

boolean RegisterLCDIF_ISR(void)
{
    return NVIC_RegisterIRQ(IRQ_LCD_CODE, LCDIF_ISR, IRQ_SENS_LEVEL, true);
}

boolean UnregisterLCDIF_ISR(void)
{
    return NVIC_UnregisterIRQ(IRQ_LCD_CODE);
}

void LCDIF_DisableInterface(void)
{
    LCDIF_INTEN = 0;                                                                                //Disable LCDIF interrupts
    LCDIF_START = LCDIF_INT_RESET;

    UnregisterLCDIF_ISR();

    LCDDRV_Sleep();
    PCTL_PowerDown(PD_LCD);                                                                         //Power down LCD controller
    PCTL_PowerDown(PD_SLCD);                                                                        //Power down serial interface
    LCDIFQueue = DL_Delete(LCDIFQueue, true);
}

boolean LCDIF_Initialize(void)
{
    memset(&LCDScreen, 0x00, sizeof(LCDScreen));

    LCDIF_SetClock(LCD_CLOCK_MPLL_DIV4);
    PCTL_PowerUp(PD_SLCD);                                                                          //Power up LCD serial interface
    PCTL_PowerUp(PD_LCD);                                                                           //Power up LCD controller

    LCDScreen.ScreenRgn = Rect(0, 0, LCD_XRESOLUTION - 1, LCD_YRESOLUTION - 1);
    LCDScreen.ScreenOffset = Point(0, 0);
    LCDScreen.ScreenCount = 1;
    LCDScreen.ScreenIndex = 0;

    LCDScreen.VLayer[0].LayerEnMask = LCDIF_L0EN;
    LCDScreen.VLayer[1].LayerEnMask = LCDIF_L1EN;
    LCDScreen.VLayer[2].LayerEnMask = LCDIF_L2EN;
    LCDScreen.VLayer[3].LayerEnMask = LCDIF_L3EN;

    LCDIF_INTEN = 0;                                                                                //Disable LCDIF interrupts
    LCDIF_START = LCDIF_INT_RESET;                                                                  //Assert LCD controller internal Reset
    LCDIF_START = 0;                                                                                //Release LCD controller internal Reset

    if (LCDIFQueue == NULL)  LCDIFQueue = DL_Create(0);
    if ((LCDIFQueue == NULL) || !RegisterLCDIF_ISR())
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

    LCDIF_RSTB = LCDIF_RESET0;                                                                      //Assert LCD panel reset
    USC_Pause_us(1000);                                                                             //Delay 1ms for reset
    LCDIF_RSTB = LCDIF_RESET1;                                                                      //Release LCD panel reset

    LCDIF_SIF0_TIMING = LCD_SIF_TIMINGS;                                                            //Setup SIF timing
    LCDIF_SIF_CON = LCD_SIF_CON;                                                                    //Setup interface configuration

    LCDIF_WROICON = LCD_SIF_WROI;                                                                   //Setup LCD data format
    LCDIF_WROICADD = LCDIF_CSIF0;                                                                   //MT6261 has only one serial interface
    LCDIF_WROIDADD = LCDIF_DSIF0;
    LCDIF_WROIOFS = LCDIF_WROIOFX(0) | LCDIF_WROIOFY(0);
    LCDIF_WROISIZE = LCDIF_WROICOL(LCD_XRESOLUTION) | LCDIF_WROIROW(LCD_YRESOLUTION);
    LCDIF_WROI_BGCLR = LCD_BACKCOLOR;

    if (LCDDRV_Initialize())
    {
        LCDIF_INTEN = LCDIF_CPL;                                                                    //Enable LCD interrupts
        DebugPrint("Complete.\r\n");
        return true;
    }

    LCDIF_DisableInterface();
    DebugPrint("Failed! (Can't initialize LCD driver)\r\n");
    return false;
}

boolean LCDIF_SetupLayer(uint32_t Index, TPOINT Offset, uint32_t SizeX, uint32_t SizeY,
                         TCFORMAT CFormat, uint8_t Alpha)
{
    if (Index >= LCDIF_NUMLAYERS) return false;

    LCDScreen.VLayer[Index].Enabled = false;
    LCDScreen.VLayer[Index].Initialized = false;
    LCDIF_WROICON &= ~LCDScreen.VLayer[Index].LayerEnMask;
    if (LCDScreen.VLayer[Index].FrameBuffer != NULL)
    {
        free(LCDScreen.VLayer[Index].FrameBuffer);
        LCDScreen.VLayer[Index].FrameBuffer = NULL;
    }

    if (SizeX && SizeY && (CFormat < CF_NUM))
    {
        uint32_t n;

        LCDScreen.VLayer[Index].LayerRgn = Rect(0, 0, SizeX - 1, SizeY - 1);
        LCDScreen.VLayer[Index].LayerOffset = Offset;
        LCDScreen.VLayer[Index].ColorFormat = CFormat;
        LCDScreen.VLayer[Index].BPP = CFormatToBPP[CFormat];

        n = SizeX * SizeY * LCDScreen.VLayer[Index].BPP;
        if (n)
        {
            LCDScreen.VLayer[Index].FrameBuffer = malloc(n);
            if (LCDScreen.VLayer[Index].FrameBuffer != NULL)
            {
                LCDIF_LAYER[Index]->LCDIF_LWINCON = LCDIF_LROTATE(LCDIF_LR_NO) | LCDIF_LCF(CFormat);
                if ((CFormat == LCDIF_LCF_ARGB8888) || (CFormat == LCDIF_LCF_PARGB8888) || (Alpha != 0xFF))
                    LCDIF_LAYER[Index]->LCDIF_LWINCON |= LCDIF_LALPHA(Alpha) | LCDIF_LALPHA_EN;

                LCDIF_LAYER[Index]->LCDIF_LWINOFFS  = LCDIF_LWINOF_X(Offset.x) | LCDIF_LWINOF_Y(Offset.y);
                LCDIF_LAYER[Index]->LCDIF_LWINADD   = (uint32_t)LCDScreen.VLayer[Index].FrameBuffer;
                LCDIF_LAYER[Index]->LCDIF_LWINSIZE  = LCDIF_LCOLS(SizeX) | LCDIF_LROWS(SizeY);
                LCDIF_LAYER[Index]->LCDIF_LWINSCRL  = LCDIF_LSCCOL(0) | LCDIF_LSCROW(0);
                LCDIF_LAYER[Index]->LCDIF_LWINMOFS  = LCDIF_LMOFCOL(0) | LCDIF_LMOFROW(0);
                LCDIF_LAYER[Index]->LCDIF_LWINPITCH = LCDScreen.VLayer[Index].BPP * SizeX;

                LCDScreen.VLayer[Index].Initialized = true;
            }
        }
    }
    return LCDScreen.VLayer[Index].Initialized;
}

boolean LCDIF_SetLayerEnabled(uint32_t Index, boolean Enabled, boolean UpdateScreen)
{
    TRECT LayerRect;

    if ((Index >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[Index].Initialized) return false;

    if (LCDScreen.VLayer[Index].Enabled != Enabled)
    {
        if (Enabled) LCDIF_WROICON |= LCDScreen.VLayer[Index].LayerEnMask;
        else LCDIF_WROICON &= ~LCDScreen.VLayer[Index].LayerEnMask;

        LCDScreen.VLayer[Index].Enabled = Enabled;

        if (UpdateScreen)
        {
            LayerRect = LCDScreen.VLayer[Index].LayerRgn;
            LayerRect.l += LCDScreen.VLayer[Index].LayerOffset.x - LCDScreen.ScreenOffset.x;
            LayerRect.r += LCDScreen.VLayer[Index].LayerOffset.x - LCDScreen.ScreenOffset.x;
            LayerRect.t += LCDScreen.VLayer[Index].LayerOffset.y - LCDScreen.ScreenOffset.y;
            LayerRect.b += LCDScreen.VLayer[Index].LayerOffset.y - LCDScreen.ScreenOffset.y;
//            if (ANDRects(&LayerRect, &LCDScreen.ScreenRgn))
                LCDIF_UpdateRectangle(LayerRect);
        }
    }
    return LCDScreen.VLayer[Index].Enabled;
}

void LCDIF_UpdateRectangle(TRECT Rct)
{
    uint32_t *Commands, CmdCount;

//    if (ANDRects(&Rct, &LCDScreen.ScreenRgn))
//    {
        Commands = LCDDRV_SetOutputWindow(&Rct, &CmdCount, LCDIF_DATA, LCDIF_CMD);
        if (Commands != NULL)
        {
            LCDIF_AddCommandToQueue(Commands, CmdCount, &Rct);
        }
//    }
}

void LCDIF_UpdateRectangleBlocked(pRECT Rct)
{
    if (Rct == NULL) return;

    LCDIF_UpdateRectangle(*Rct);
    while(LCDIF_IsQueueRunning());
}
