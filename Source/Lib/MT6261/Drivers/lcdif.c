// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "lcdif.h"

boolean FillLCDIFFromQueue(void);
boolean InitializeLCDIFDriver(void);
void SleepLCDIF(void);
void ResumeLCDIF(void);
/*
TDRVHEADER LCDIFHeader =
{
    &InitializeLCDIFDriver,
    &SleepLCDIF,
    &ResumeLCDIF
};
*/
pLAYER LCDIF_LAYER[LCDIF_NUMLAYERS] = {(volatile pLAYER) &LCDIF_LAYER0BASE,
                                       (volatile pLAYER) &LCDIF_LAYER1BASE,
                                       (volatile pLAYER) &LCDIF_LAYER2BASE,
                                       (volatile pLAYER) &LCDIF_LAYER3BASE
                                      };

//TLCDINF  LCDInf;
//TSCREEN  LCDScreen;
//volatile pDLIST LCDIFQueue;

void LCDIFWriteCommand(uint8_t Cmd)
{
    LCDIF_SCMD0 = Cmd;
}

void LCDIFWriteData(uint8_t Data)
{
    LCDIF_SDAT0 = Data;
}

uint8_t LCDIFReadData(void)
{
    return LCDIF_SDAT0;
}

void StartLCDTransfer(void)
{
//    uint16_t v = LCDIF_INTSTA;
//
//    if (v) DbgOutHEX(v, 4, "!!!!!!!!!!!!!!!!!!!!\r\n");
//
////    LCDIF_INTSTA = LCDIF_INTSTA;                                                                    //!!!!!!!!!!!!!!!!!!!!!!!!!
//    LCDIF_START = 0;
//    LCDIF_START = LCDIF_RUN;
}

boolean IsLCDIFRunning(void)
{
    return (LCDIF_STA & LCDIF_RUNNING);
}

void RestartLCDIF(void)
{
//    uint32_t intflags = DisableInterrupts();
//
//    if (!IsLCDIFRunning() && FillLCDIFFromQueue()) StartLCDTransfer();
//
//    RestoreInterrupts(intflags);
}

//boolean AddLCDIFCommand(uint32_t *CmdArray, uint32_t CmdCount, pRECT UpdRect)
//{
//    pLCDCMD LCDCMD;
//
//    if (!CmdCount || (CmdArray == NULL)) return false;
//
//    LCDCMD = malloc(sizeof(TLCDCMD) + CmdCount * sizeof(uint32));
//    if (LCDCMD == NULL) return false;
//
//    LCDCMD->CMDCount = CmdCount;
//    LCDCMD->Commands = (void *)((uint32)LCDCMD + sizeof(TLCDCMD));
//
//    if (UpdRect != NULL) LCDCMD->UpdateRect = *UpdRect;
//    else LCDCMD->UpdateRect = Rect(0, 0, 0, 0);
//
//    memcpy(LCDCMD->Commands, CmdArray, CmdCount * sizeof(uint32));
//
//    RestartLCDIF();
//    while(LCDIFQueue->Count >= MAX_LCDQUEUE_SIZE);
//
//    if (!AddDListItem(LCDIFQueue, LCDCMD))
//    {
//        free(LCDCMD);
//        return false;
//    }
//    RestartLCDIF();
//
//    return true;
//}

boolean DeleteLCDIFCommand(void)
{
//    uint32_t intflags = DisableInterrupts();
//
//    if (GetDListItemsCount(LCDIFQueue))
//    {
//        pLCDCMD CMD;
//
//        CMD = GetFirstDListItem(LCDIFQueue)->Data;
//        if (CMD != NULL) free(CMD);
//        DeleteDListItemByIndex(LCDIFQueue, 0);
//
//        RestoreInterrupts(intflags);
//        return true;
//    }
//
//    RestoreInterrupts(intflags);
//    return false;
}

boolean FillLCDIFFromQueue(void)
{
//    uint32_t i;
//    pLCDCMD  LCDCMD;
//
//    if (GetDListItemsCount(LCDIFQueue))
//    {
//        LCDCMD = GetFirstDListItem(LCDIFQueue)->Data;
//        if (LCDCMD != NULL)
//        {
//            LCDIF_WROIOFS  = LCDIF_WROIOFX(LCDCMD->UpdateRect.R.l + LCDScreen.ScreenOffset.x) |
//                             LCDIF_WROIOFY(LCDCMD->UpdateRect.R.t + LCDScreen.ScreenOffset.y);
//            LCDIF_WROISIZE = LCDIF_WROICOL(LCDCMD->UpdateRect.R.r + 1 - LCDCMD->UpdateRect.R.l) |
//                             LCDIF_WROIROW(LCDCMD->UpdateRect.R.b + 1 - LCDCMD->UpdateRect.R.t);
//
//            if (LCDCMD->CMDCount)
//            {
//                for(i = 0; i < LCDCMD->CMDCount; i++) LCDIF_COMD(i) = LCDCMD->Commands[i];
//                LCDIF_WROICON &= ~LCDIF_COMMAND_MASK;
//                LCDIF_WROICON |= LCDIF_COMMAND(LCDCMD->CMDCount - 1) | LCDIF_ENC;
//            }
//            else LCDIF_WROICON &= ~LCDIF_ENC;
//        }
//        DeleteLCDIFCommand();
//        return true;
//    }
//    return false;
}


void LCDIF_ISR(void)
{
//    uint16_t intID;
//    LCDIF_START = 0;
//
//    intID = LCDIF_INTSTA;                                                                           //Read register to clear LCD Interrupt.
//
//    if (intID & LCDIF_CPL)
//    {
//        if (FillLCDIFFromQueue()) StartLCDTransfer();
//    }
//    else DbgOutHEX(intID, 4, "????????????????\r\n");
}

boolean RegisterLCDIF_ISR(void)
{
    return NVIC_RegisterIRQ(IRQ_LCD_CODE, LCDIF_ISR, IRQ_SENS_LEVEL/*IRQ_SENS_EDGE*/, true);
}

boolean UnregisterLCDIF_ISR(void)
{
    return NVIC_UnregisterIRQ(IRQ_LCD_CODE);
}

void DisableLCDIFController(void)
{
//    LCDIF_INTEN = 0;                                                                                //Disable interrupts
//    while(LCDIFQueue->Count || (LCDIF_STA & LCDIF_RUNNING));                                        //Need to set timeout !!!!!!
//
//    UnregisterLCDIF_ISR();
//
//    if (LCDInf.HW_LCD_Sleep != NULL) LCDInf.HW_LCD_Sleep();
//    CLockGatePowerDown(PD_LCD);                                                                     //Power down LCD controller
//    CLockGatePowerDown(PD_SLCD);                                                                    //Power down serial interface
//    LCDIFQueue = DeleteDList(LCDIFQueue, true);
//    return;
}

boolean InitializeLCDIFDriver(void)
{
//    memset(&LCDInf, 0x00, sizeof(TLCDINF));
//    memset(&LCDScreen, 0x00, sizeof(LCDScreen));

//    SetLCDIFClock(MPLL_DIV4);
//    CLockGatePowerUp(PD_SLCD);                                                                      //Power up LCD serial interface
//    CLockGatePowerUp(PD_LCD);                                                                       //Power up LCD controller
//
//    LCDInf.HWLCD_XMax = TFTXResolution - 1;
//    LCDInf.HWLCD_YMax = TFTYResolution - 1;
//    LCDInf.HWLCD_Command = LCDIFWriteCommand;
//    LCDInf.HWLCD_WRData  = LCDIFWriteData;
//    LCDInf.HWLCD_RDData  = LCDIFReadData;
//
//    LCDScreen.ScreenRgn = Rect(0, 0, LCDInf.HWLCD_XMax, LCDInf.HWLCD_YMax);
//    LCDScreen.ScreenOffset = Point(0, 0);
//    LCDScreen.ScreenCount = 1;
//    LCDScreen.ScreenIndex = 0;
//
//    LCDScreen.VLayer[0].LayerEnMask = LCDIF_L0EN;
//    LCDScreen.VLayer[1].LayerEnMask = LCDIF_L1EN;
//    LCDScreen.VLayer[2].LayerEnMask = LCDIF_L2EN;
//    LCDScreen.VLayer[3].LayerEnMask = LCDIF_L3EN;
//
//    LCDIF_INTEN = 0;                                                                                //Disable interrupts
//    LCDIF_START = LCDIF_INT_RESET;                                                                  //Assert LCD controller internal Reset
//    LCDIF_START = 0;                                                                                //Release LCD controller internal Reset
//
//    if (LCDIFQueue == NULL)  LCDIFQueue = CreateDList(0);
//    if ((LCDIFQueue == NULL) || !RegisterLCDIF_ISR())
//    {
//        DisableLCDIFController();
//        return false;
//    }
//
//    GPIO_SETMODE(GPIO45, M45LSRSTB);                                                                //LCDIF Reset
//    GPIO_SETMODE(GPIO46, M46LSCE_B0);                                                               //LCDIF Chip Select
//    GPIO_SETMODE(GPIO47, M47LSCK0);                                                                 //LCDIF Clock
//    GPIO_SETMODE(GPIO48, M48LSDA0);                                                                 //LCDIF Data IO line 0
////    GPIO_SETMODE(GPIO49, M49LSA0DA0);                                                               //LCDIF Data IO line 1
////    GPIO_SETMODE(GPIO50, M50LPTE);                                                                  //LCDIF Tearing sync
//
//    LCDIF_RSTB = LCDIF_RESET0;                                                                      //Assert TFT panel reset
//    Delay_ms(1);                                                                                    //Delay 1ms for reset
//    LCDIF_RSTB = LCDIF_RESET1;                                                                      //Release TFT panel reset
//
//    LCDIF_SIF0_TIMING = LCDIF_WR_2ND(0) | LCDIF_WR_1ST(0) | LCDIF_RD_2ND(0) |
//                        LCDIF_RD_1ST(0) | LCDIF_CSH(0) | LCDIF_CSS(0);                              //Setup SIF timing
//    LCDIF_SIF_CON = LCDIF_SIF0_SIZE8B | LCDIF_SIF0_3WIRE | LCDIF_SIF0_DIV2 | LCDIF_SIF0_HW_CS;      //Setup interface configuration
//
//    LCDIF_WROICON = LCDIF_F_RGB | LCDIF_F_PADDLSB | LCDIF_F_RGB888 | LCDIF_F_ITF_8B;
//    LCDIF_WROICADD = LCDIF_CSIF0;
//    LCDIF_WROIDADD = LCDIF_DSIF0;
//    LCDIF_WROIOFS = LCDIF_WROIOFX(0) | LCDIF_WROIOFY(0);
//    LCDIF_WROISIZE = LCDIF_WROICOL(LCDInf.HWLCD_XMax + 1) | LCDIF_WROIROW(LCDInf.HWLCD_YMax + 1);
//    LCDIF_WROI_BGCLR = LCDBackColor;
//
//    InitializeLCD(&LCDInf);
//
//    LCDIF_INTEN = LCDIF_CPL;                                                                        //Enable LCD interrupts
//    return true;
}

boolean IsLCDQueueRunning(void)
{
//    return (!GetDListItemsCount(LCDIFQueue) && !(LCDIF_STA & LCDIF_RUNNING)) ? false : true;
}

/*
    Rct - local LCDScreen coordinates
*/
//void UpdateLCDRectangle(TRECT Rct)
//{
//    uint32_t *Commands;
//    uint32_t CmdCount;
//
//    if (ANDRects(&Rct, &LCDScreen.ScreenRgn))
//    {
//        Commands = SetLCDWindow(&Rct, &CmdCount, LCDIF_D0, LCDIF_C0);
//        if (Commands != NULL)
//        {
//            AddLCDIFCommand(Commands, CmdCount, &Rct);
//            free(Commands);
//        }
//    }
//}

//void UpdateLCDRectangleBlocked(pRECT Rct)
//{
//    if (Rct == NULL) return;
//
//    UpdateLCDRectangle(*Rct);
//    while(IsLCDQueueRunning());
//}

void SleepLCDIF(void)
{
//    LCDIF_INTEN = 0;                                                                                //Disable LCD interrupts
//    while (LCDIFQueue->Count || (LCDIF_STA & LCDIF_RUNNING) || (LCDIF_STA & LCDIF_BUSY));           //Wait while queue free
//
//    DisableIRQ(IRQ_LCD_CODE);
//
//    if (LCDInf.HW_LCD_Sleep != NULL) LCDInf.HW_LCD_Sleep();                                         //Power down TFT panel
//
//    CLockGatePowerDown(PD_LCD);                                                                     //Power down LCD controller
//    CLockGatePowerDown(PD_SLCD);                                                                    //Power down serial interface
}

void ResumeLCDIF(void)
{
//    CLockGatePowerUp(PD_SLCD);                                                                      //Power up LCD serial interface
//    CLockGatePowerUp(PD_LCD);                                                                       //Power up LCD controller
//
//    if (LCDInf.HW_LCD_Resume != NULL) LCDInf.HW_LCD_Resume();                                       //Power up TFT panel
//
//    EnableIRQ(IRQ_LCD_CODE);
//    LCDIF_INTEN = LCDIF_CPL;                                                                        //Enable LCD interrupt
}


//uint8_t CFormatToBPP(TCFORMAT CFormat)
//{
//    uint8_t Res;
//
//    switch (CFormat)
//    {
//    case CF_8IDX:
//        Res = 1;
//        break;
//    case CF_RGB565:
//        Res = 2;
//        break;
//    case CF_YUYV422:
//        Res = 0;
//        break;
//    case CF_RGB888:
//        Res = 3;
//        break;
//    case CF_ARGB8888:
//        Res = 4;
//        break;
//    case CF_PARGB8888:
//        Res = 4;
//        break;
//    case CF_xRGB8888:
//        Res = 4;
//        break;
//    default:
//        Res = 0;
//        break;
//    }
//    return Res;
//}

//boolean SetupVLayer(uint8_t LIndex, TPOINT LOffset, uint32_t SizeX, uint32_t SizeY,
//                    TCFORMAT CFormat, uint8_t Alpha)
//{
//    uint32_t n;
//
//    if (LIndex >= LCDIF_NUMLAYERS) return false;
//
//    LCDScreen.VLayer[LIndex].Enabled = false;
//    LCDScreen.VLayer[LIndex].Initialized = false;
//    LCDIF_WROICON &= ~LCDScreen.VLayer[LIndex].LayerEnMask;                                         //Disable layer
//    if (LCDScreen.VLayer[LIndex].VideoBuf != NULL)
//        LCDScreen.VLayer[LIndex].VideoBuf = free(LCDScreen.VLayer[LIndex].VideoBuf);
//
//    if (SizeX && SizeY)
//    {
//        LCDScreen.VLayer[LIndex].LayerRgn = Rect(0, 0, SizeX - 1, SizeY - 1);
//        LCDScreen.VLayer[LIndex].LayerOffset = LOffset;
//        LCDScreen.VLayer[LIndex].ColorFormat = CFormat;
//        LCDScreen.VLayer[LIndex].BPP = CFormatToBPP(CFormat);
//
//        n = SizeX * SizeY * LCDScreen.VLayer[LIndex].BPP;                                           //Memory size for Frame buffer
//        if (n)
//        {
//            LCDScreen.VLayer[LIndex].VideoBuf = malloc(n);
//            if (LCDScreen.VLayer[LIndex].VideoBuf != NULL)
//            {
//                LCDIF_LAYER[LIndex]->LCDIF_LWINCON = LCDIF_LROTATE(LCDIF_LR_NO) | LCDIF_LCF(CFormat);
//                if ((CFormat == LCDIF_LCF_ARGB8888) || (CFormat == LCDIF_LCF_PARGB8888) || (Alpha != 0xFF))
//                    LCDIF_LAYER[LIndex]->LCDIF_LWINCON |= LCDIF_LALPHA(Alpha) | LCDIF_LALPHA_EN;
//
//                LCDIF_LAYER[LIndex]->LCDIF_LWINOFFS = LCDIF_LWINOF_X(LOffset.x) | LCDIF_LWINOF_Y(LOffset.y);
//                LCDIF_LAYER[LIndex]->LCDIF_LWINADD =  (uint32)LCDScreen.VLayer[LIndex].VideoBuf;
//                LCDIF_LAYER[LIndex]->LCDIF_LWINSIZE = LCDIF_LCOLS(SizeX) | LCDIF_LROWS(SizeY);
//                LCDIF_LAYER[LIndex]->LCDIF_LWINSCRL = LCDIF_LSCCOL(0) | LCDIF_LSCROW(0);
//                LCDIF_LAYER[LIndex]->LCDIF_LWINMOFS = LCDIF_LMOFCOL(0) | LCDIF_LMOFROW(0);
//                LCDIF_LAYER[LIndex]->LCDIF_LWINPITCH = LCDScreen.VLayer[LIndex].BPP * SizeX;
//
//                LCDScreen.VLayer[LIndex].Initialized = true;
//            }
//        }
//    }
//    return LCDScreen.VLayer[LIndex].Initialized;                                                    //Return previous enabled state
//}

boolean SetVLayerEnabled(uint8_t LIndex, boolean Enabled, boolean UpdateScreen)
{
//    TRECT   LayerRect;
//
//    if ((LIndex >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[LIndex].Initialized) return false;
//
//    if (LCDScreen.VLayer[LIndex].Enabled != Enabled)
//    {
//        if (Enabled) LCDIF_WROICON |= LCDScreen.VLayer[LIndex].LayerEnMask;
//        else LCDIF_WROICON &= ~LCDScreen.VLayer[LIndex].LayerEnMask;
//
//        LCDScreen.VLayer[LIndex].Enabled = Enabled;
//
//        if (UpdateScreen)
//        {
//            LayerRect = LCDScreen.VLayer[LIndex].LayerRgn;
//            LayerRect.R.l += LCDScreen.VLayer[LIndex].LayerOffset.x - LCDScreen.ScreenOffset.x;     //ѕреобразовываем Rct к локальным координатам LCDScreen
//            LayerRect.R.r += LCDScreen.VLayer[LIndex].LayerOffset.x - LCDScreen.ScreenOffset.x;
//            LayerRect.R.t += LCDScreen.VLayer[LIndex].LayerOffset.y - LCDScreen.ScreenOffset.y;
//            LayerRect.R.b += LCDScreen.VLayer[LIndex].LayerOffset.y - LCDScreen.ScreenOffset.y;
//            if (ANDRects(&LayerRect, &LCDScreen.ScreenRgn)) UpdateLCDRectangle(LayerRect);
//        }
//    }
//    return LCDScreen.VLayer[LIndex].Enabled;
}

//void SetVLayerOffset(uint8_t LIndex, TPOINT LOffset, boolean UpdateScreen)
//{
//    if ((LIndex >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[LIndex].Initialized) return;
//
//    if (LCDScreen.VLayer[LIndex].Enabled)
//    {
//        LCDIF_WROICON &= ~LCDScreen.VLayer[LIndex].LayerEnMask;
//        LCDScreen.VLayer[LIndex].LayerOffset = LOffset;
//        LCDIF_LAYER[LIndex]->LCDIF_LWINOFFS = LCDIF_LWINOF_X(LOffset.x) | LCDIF_LWINOF_Y(LOffset.y);
//        LCDIF_WROICON |= LCDScreen.VLayer[LIndex].LayerEnMask;
//
//        if (UpdateScreen) UpdateLCDRectangle(LCDScreen.ScreenRgn);
//    }
//    else
//    {
//        LCDScreen.VLayer[LIndex].LayerOffset = LOffset;
//        LCDIF_LAYER[LIndex]->LCDIF_LWINOFFS = LCDIF_LWINOF_X(LOffset.x) | LCDIF_LWINOF_Y(LOffset.y);
//    }
//}

boolean SetVLayerAlpha(uint8_t LIndex, uint8_t Alpha, boolean UpdateScreen)
{
//    TCFORMAT    CFormat;
//    TRECT       LayerRect;
//
//    if ((LIndex >= LCDIF_NUMLAYERS) || !LCDScreen.VLayer[LIndex].Initialized) return false;
//
//    LCDIF_LAYER[LIndex]->LCDIF_LWINCON &= ~(LCDIF_LALPHA(0xFF) | LCDIF_LALPHA_EN);
//    CFormat = LCDScreen.VLayer[LIndex].ColorFormat;
//    if ((CFormat == LCDIF_LCF_ARGB8888) || (CFormat == LCDIF_LCF_PARGB8888) || (Alpha != 0xFF))
//        LCDIF_LAYER[LIndex]->LCDIF_LWINCON |= LCDIF_LALPHA(Alpha) | LCDIF_LALPHA_EN;
//
//    if (UpdateScreen)
//    {
//        LayerRect = LCDScreen.VLayer[LIndex].LayerRgn;
//        LayerRect.R.l += LCDScreen.VLayer[LIndex].LayerOffset.x - LCDScreen.ScreenOffset.x;         //ѕреобразовываем Rct к локальным координатам LCDScreen
//        LayerRect.R.r += LCDScreen.VLayer[LIndex].LayerOffset.x - LCDScreen.ScreenOffset.x;
//        LayerRect.R.t += LCDScreen.VLayer[LIndex].LayerOffset.y - LCDScreen.ScreenOffset.y;
//        LayerRect.R.b += LCDScreen.VLayer[LIndex].LayerOffset.y - LCDScreen.ScreenOffset.y;
//        if (ANDRects(&LayerRect, &LCDScreen.ScreenRgn)) UpdateLCDRectangle(LayerRect);
//    }
//    return true;
}
