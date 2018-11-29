#ifndef _LCDIF_H_
#define _LCDIF_H_

#define MAX_LCDQUEUE_SIZE           128

#define LCD_SERIAL_CLOCK_REG        (*(volatile uint32_t*)(CONFIG_base + 0x11C))
#define LCD_SERIAL_CLOCK_MASK       0x70
#define LCD_SERIAL_CLOCK(v)         (((v) & 0x07) << 4)
typedef enum
{
    LCD_CLOCK_MPLL_DIV4 = 0,
    LCD_CLOCK_MPLL_DIV5,
    LCD_CLOCK_MPLL_DIV6,
    LCD_CLOCK_MPLL_DIV7,
    LCD_CLOCK_MPLL_DIV8,
    LCD_CLOCK_13M
} TLCDSCLOCK;

#define LCDIF_STA                   (*(volatile uint16_t*)(LCDIF_Base + 0x0000))
#define LCDIF_RUNNING               (1 << 0)
#define LCDIF_WAIT_CMDQ             (1 << 1)
#define LCDIF_WAIT_HTT              (1 << 3)
#define LCDIF_TE_PEND               (1 << 4)
#define LCDIF_BUSY                  (1 << 5)
#define LCDIF_GMC                   (1 << 6)
#define LCDIF_INTEN                 (*(volatile uint16_t*)(LCDIF_Base + 0x0004))
#define LCDIF_CPL                   (1 << 0)
#define LCDIF_REG_CPL               (1 << 1)
#define LCDIF_CMDQ_CPL              (1 << 2)
#define LCDIF_HTT                   (1 << 4)
#define LCDIF_SYNC                  (1 << 5)
#define LCDIF_INTSTA                (*(volatile uint16_t*)(LCDIF_Base + 0x0008))
#define LCDIF_CPL                   (1 << 0)
#define LCDIF_START                 (*(volatile uint16_t*)(LCDIF_Base + 0x000C))
#define LCDIF_INT_RESET             (1 << 0)
#define LCDIF_RUN                   (1 << 15)
#define LCDIF_RSTB                  (*(volatile uint16_t*)(LCDIF_Base + 0x0010))
#define LCDIF_RESET1                (1 << 0)
#define LCDIF_RESET0                (0 << 0)
#define LCDIF_SIF_PIX_CON_REG       (*(volatile uint32_t*)(LCDIF_Base + 0x0018))

#define LCDIF_SIF0_TIMING           (*(volatile uint32_t*)(LCDIF_Base + 0x001C))
#define LCDIF_WR_2ND(v)             (((v) & 0x000F) << 0)
#define LCDIF_WR_1ST(v)             (((v) & 0x000F) << 4)
#define LCDIF_RD_2ND(v)             (((v) & 0x000F) << 8)
#define LCDIF_RD_1ST(v)             (((v) & 0x000F) << 12)
#define LCDIF_CSH(v)                (((v) & 0x000F) << 16)
#define LCDIF_CSS(v)                (((v) & 0x000F) << 20)
#define LCDIF_SIF1_TIMING           (*(volatile uint32_t*)(LCDIF_Base + 0x0020))
#define LCDIF_WR_2ND(v)             (((v) & 0x000F) << 0)
#define LCDIF_WR_1ST(v)             (((v) & 0x000F) << 4)
#define LCDIF_RD_2ND(v)             (((v) & 0x000F) << 8)
#define LCDIF_RD_1ST(v)             (((v) & 0x000F) << 12)
#define LCDIF_CSH(v)                (((v) & 0x000F) << 16)
#define LCDIF_CSS(v)                (((v) & 0x000F) << 20)
#define LCDIF_SIF_CON               (*(volatile uint32_t*)(LCDIF_Base + 0x0028))
#define LCDIF_SIF0_SIZE8B           (0 << 0)
#define LCDIF_SIF0_SIZE9B           (1 << 0)
#define LCDIF_SIF0_SIZE16B          (2 << 0)
#define LCDIF_SIF0_SIZE18B          (3 << 0)
#define LCDIF_SIF0_SIZE24B          (4 << 0)
#define LCDIF_SIF0_SIZE32B          (5 << 0)
#define LCDIF_SIF0_4WIRE            (0 << 3)
#define LCDIF_SIF0_3WIRE            (1 << 3)
#define LCDIF_SIF0_SDI              (1 << 4)
#define LCDIF_SIF0_1ST_POL          (1 << 5)
#define LCDIF_SIF0_SCK_DEF          (1 << 6)
#define LCDIF_SIF0_DIV2             (1 << 7)
#define LCDIF_SIF1_SIZE8B           (0 << 8)
#define LCDIF_SIF1_SIZE9B           (1 << 8)
#define LCDIF_SIF1_SIZE16B          (2 << 8)
#define LCDIF_SIF1_SIZE18B          (3 << 8)
#define LCDIF_SIF1_SIZE24B          (4 << 8)
#define LCDIF_SIF1_SIZE32B          (5 << 8)
#define LCDIF_SIF1_4WIRE            (0 << 11)
#define LCDIF_SIF1_3WIRE            (1 << 11)
#define LCDIF_SIF1_SDI              (1 << 12)
#define LCDIF_SIF1_1ST_POL          (1 << 13)
#define LCDIF_SIF1_SCK_DEF          (1 << 14)
#define LCDIF_SIF1_DIV2             (1 << 15)
#define LCDIF_SIF0_HW_CS            (1 << 24)
#define LCDIF_SIF1_HW_CS            (1 << 28) //Maybe
#define LCDIF_SIF_CS                (*(volatile uint32_t*)(LCDIF_Base + 0x002C))
#define LCDIF_CS0                   (1 << 0)
#define LCDIF_CS1                   (1 << 1)
#define LCDIF_PCNF0                 (*(volatile uint32_t*)(LCDIF_Base + 0x0030))
#define LCDIF_WST(v)                (((v) & 0x003F) << 0)
#define LCDIF_C2WS(v)               (((v) & 0x000F) << 8)
#define LCDIF_C2WH(v)               (((v) & 0x000F) << 12)
#define LCDIF_RLT(v)                (((v) & 0x003F) << 16)
#define LCDIF_C2RS(v)               (((v) & 0x000F) << 24)
#define LCDIF_C2RH(v)               (((v) & 0x000F) << 28)
#define LCDIF_PCNF1                 (*(volatile uint32_t*)(LCDIF_Base + 0x0034))
#define LCDIF_WST(v)                (((v) & 0x003F) << 0)
#define LCDIF_C2WS(v)               (((v) & 0x000F) << 8)
#define LCDIF_C2WH(v)               (((v) & 0x000F) << 12)
#define LCDIF_RLT(v)                (((v) & 0x003F) << 16)
#define LCDIF_C2RS(v)               (((v) & 0x000F) << 24)
#define LCDIF_C2RH(v)               (((v) & 0x000F) << 28)
#define LCDIF_PDW                   (*(volatile uint32_t*)(LCDIF_Base + 0x003C))
#define LCDIF_P0_DW(v)              (((v) & 0x0007) << 0)
#define LCDIF_P1_DW(v)              (((v) & 0x0007) << 4)
#define LCDIF_PDW_8B                0
#define LCDIF_PDW_9B                1
#define LCDIF_PDW_16B               2
#define LCDIF_PDW_18B               3
#define LCDIF_P0_CHW(v)             (((v) & 0x000F) << 16)
#define LCDIF_P1_CHW(v)             (((v) & 0x000F) << 20)
#define LCDIF_CALC_HTT              (*(volatile uint32_t*)(LCDIF_Base + 0x0044))
#define LCDIF_TIMEOUT(v)            (((v) & 0x0FFF) << 0)
#define LCDIF_COUNT(v)              (((v) & 0x0FFF) << 16)
#define LCDIF_SYNC_LCM_SIZE         (*(volatile uint32_t*)(LCDIF_Base + 0x0048))
#define LCDIF_HTTSZ(v)              (((v) & 0x03FF) << 0)
#define LCDIF_VTTSZ(v)              (((v) & 0x0FFF) << 16)
#define LCDIF_SYNC_CNT              (*(volatile uint32_t*)(LCDIF_Base + 0x004C))
#define LCDIF_WAITLINE(v)           (((v) & 0x0FFF) << 0)
#define LCDIF_SCANLINE(v)           (((v) & 0x0FFF) << 16)
#define LCDIF_TECON                 (*(volatile uint32_t*)(LCDIF_Base + 0x0050))
#define LCDIF_SYNC_EN               (1 << 0)
#define LCDIF_TE_EDGE_SEL           (1 << 1)
#define LCDIF_SYNC_MODE             (1 << 2)
#define LCDIF_TE_REPEAT             (1 << 3)
#define LCDIF_SW_TE                 (1 << 15)
#define LCDIF_GMCCON                (*(volatile uint32_t*)(LCDIF_Base + 0x0054))
#define LCDIF_MAX_BURST(v)          (((v) & 0x0007) << 0)
#define LCDIF_MB_4B                 0
#define LCDIF_MB_16B                2
#define LCDIF_MB_32B                3
#define LCDIF_MB_64B                4
#define LCDIF_TROTTLE_EN            (1 << 4)
#define LCDIF_TROTTLE_PERIOD(v)     (((v) & 0xFFFF) << 16)

#define LCDIF_WROICON               (*(volatile uint32_t*)(LCDIF_Base + 0x0080))
#define LCDIF_F_BGR                 (0 << 0)
#define LCDIF_F_RGB                 (1 << 0)
#define LCDIF_F_SIGNIF              (1 << 1)
#define LCDIF_F_PADDLSB             (0 << 2)
#define LCDIF_F_PADDMSB             (1 << 2)
#define LCDIF_F_RGB332              (0 << 3)
#define LCDIF_F_RGB444              (1 << 3)
#define LCDIF_F_RGB565              (2 << 3)
#define LCDIF_F_RGB666              (3 << 3)
#define LCDIF_F_RGB888              (4 << 3)
#define LCDIF_F_ITF_8B              (0 << 6)
#define LCDIF_F_ITF_16B             (1 << 6)
#define LCDIF_F_ITF_9B              (2 << 6)
#define LCDIF_F_ITF_18B             (3 << 6)
#define LCDIF_COMMAND(v)            (((v) & 0x003F) << 8)
#define LCDIF_COMMAND_MASK          (0x3F << 8)
#define LCDIF_W2M                   (1 << 14)
#define LCDIF_ENC                   (1 << 15)
#define LCDIF_PERIOD(v)             (((v) & 0x00FF) << 16)
#define LCDIF_SEND_RES_MODE         (1 << 24)
#define LCDIF_FCNT                  (1 << 26)
#define LCDIF_L3EN                  (1 << 28)
#define LCDIF_L2EN                  (1 << 29)
#define LCDIF_L1EN                  (1 << 30)
#define LCDIF_L0EN                  (1UL << 31)
#define LCDIF_WROIOFS               (*(volatile uint32_t*)(LCDIF_Base + 0x0084))
#define LCDIF_WROIOFX(v)            (((v) & 0x03FF) << 0)
#define LCDIF_WROIOFY(v)            (((v) & 0x03FF) << 16)
#define LCDIF_WROICADD              (*(volatile uint32_t*)(LCDIF_Base + 0x0088))
#define LCDIF_CPIF0                 (0x00 << 4)
#define LCDIF_CPIF1                 (0x02 << 4)
#define LCDIF_CSIF0                 (0x08 << 4)
#define LCDIF_CSIF1                 (0x0A << 4)
#define LCDIF_WROIDADD              (*(volatile uint32_t*)(LCDIF_Base + 0x008C))
#define LCDIF_DPIF0                 (0x01 << 4)
#define LCDIF_DPIF1                 (0x03 << 4)
#define LCDIF_DSIF0                 (0x09 << 4)
#define LCDIF_DSIF1                 (0x0B << 4)
#define LCDIF_WROISIZE              (*(volatile uint32_t*)(LCDIF_Base + 0x0090))
#define LCDIF_WROICOL(v)            (((v) & 0x07FF) << 0)
#define LCDIF_WROIROW(v)            (((v) & 0x07FF) << 16)
#define LCDIF_WROI_BGCLR            (*(volatile uint32_t*)(LCDIF_Base + 0x009C))

typedef struct tag_LAYER
{
    uint32_t LCDIF_LWINCON;
    uint32_t LCDIF_LWINKEY;
    uint32_t LCDIF_LWINOFFS;
    uint32_t LCDIF_LWINADD;
    uint32_t LCDIF_LWINSIZE;
    uint32_t LCDIF_LWINSCRL;
    uint32_t LCDIF_LWINMOFS;
    uint16_t LCDIF_LWINPITCH;
} TLAYER, *pLAYER;

//TLAYER - LCDIF_LWINCON
#define LCDIF_LALPHA(v)             (((v) & 0x00FF) << 0)
#define LCDIF_LALPHA_EN             (1 << 8)
#define LCDIF_LROTATE(v)            (((v) & 0x0007) << 11)
#define LCDIF_LR_NO                 0x00
#define LCDIF_LR_90                 0x01
#define LCDIF_LR_180                0x02
#define LCDIF_LR_270                0x03
#define LCDIF_LHFR_NO               0x04
#define LCDIF_LHFR_90               0x05
#define LCDIF_LHFR_180              0x06
#define LCDIF_LHFR_270              0x07
#define LCDIF_LSRCKEY_EN            (1 << 14)
#define LCDIF_LBYTE_SWP             (1 << 16)
#define LCDIF_LSCRL_EN              (1 << 17)
#define LCDIF_LDITHER_EN            (1 << 18)
#define LCDIF_LCF(v)                (((v) & 0x07) << 20)
#define LCDIF_LCF_8BIdx             0x00
#define LCDIF_LCF_RGB565            0x01
#define LCDIF_LCF_YUYV422           0x02
#define LCDIF_LCF_RGB888            0x03
#define LCDIF_LCF_ARGB8888          0x04
#define LCDIF_LCF_PARGB8888         0x05
#define LCDIF_LCF_xRGB8888          0x06
#define LCDIF_LDSTKEY_EN            (1 << 24)
#define LCDIF_LRGB_SWP              (1 << 26)
//TLAYER - LCDIF_LWINOFFS
#define LCDIF_LWINOF_X(v)           (((v) & 0x07FF) << 0)
#define LCDIF_LWINOF_Y(v)           (((v) & 0x07FF) << 16)
//TLAYER - LCDIF_LWINSIZE
#define LCDIF_LCOLS(v)              (((v) & 0x07FF) << 0)
#define LCDIF_LROWS(v)              (((v) & 0x07FF) << 16)
//TLAYER - LCDIF_LWINSCRL
#define LCDIF_LSCCOL(v)             (((v) & 0x07FF) << 0)
#define LCDIF_LSCROW(v)             (((v) & 0x07FF) << 16)
//TLAYER - LCDIF_LWINMOFS
#define LCDIF_LMOFCOL(v)            (((v) & 0x07FF) << 0)
#define LCDIF_LMOFROW(v)            (((v) & 0x07FF) << 16)

#define LCDIF_LAYER0BASE            (*(volatile TLAYER*)(LCDIF_Base + 0x00B0))
#define LCDIF_LAYER1BASE            (*(volatile TLAYER*)(LCDIF_Base + 0x00E0))
#define LCDIF_LAYER2BASE            (*(volatile TLAYER*)(LCDIF_Base + 0x0110))
#define LCDIF_LAYER3BASE            (*(volatile TLAYER*)(LCDIF_Base + 0x0140))

typedef enum tag_LAYNUM
{
    LCDIF_LAYER0,
    LCDIF_LAYER1,
    LCDIF_LAYER2,
    LCDIF_LAYER3,
    LCDIF_NUMLAYERS
} LAYNUM;

#define LCDIF_DITHER_CON_REG        (*(volatile uint32_t*)(LCDIF_Base + 0x0170)

#define LCDIF_FRAMECOUNTER_CON      (*(volatile uint32_t*)(LCDIF_Base + 0x0220))
#define LCDIF_FCSTART               (1 << 0)
#define LCDIF_FCSTOP                (1 << 1)
#define LCDIF_FRAMECOUNTER          (*(volatile uint32_t*)(LCDIF_Base + 0x0224))
#define LCDIF_ULTRA_CTRL            (*(volatile uint16_t*)(LCDIF_Base + 0x0240))
#define LCDIF_ULTRADBI_EN           (1 << 0)
#define LCDIF_ULTRAGMC_EN           (1 << 1)
#define LCDIF_CONSUME_RATE          (*(volatile uint16_t*)(LCDIF_Base + 0x0244))
#define LCDIF_CONS_RATE(v)          (((v) & 0x03FF) << 0)
#define LCDIF_DBI_TH                (*(volatile uint32_t*)(LCDIF_Base + 0x0248))
#define LCDIF_DBI_THL(v)            (((v) & 0xFFFF) << 0)
#define LCDIF_DBI_THH(v)            (((v) & 0xFFFF) << 16)
#define LCDIF_GMC_TH                (*(volatile uint32_t*)(LCDIF_Base + 0x024C))
#define LCDIF_GMC_THL(v)            (((v) & 0xFFFF) << 0)
#define LCDIF_GMC_THH(v)            (((v) & 0xFFFF) << 16)

#define LCDIF_COMD(v)               (*(volatile uint32_t*)(LCDIF_Base + 0x0C00 + 4 * (v)))
#define LCDIF_COMM(v)               (((v) & 0x7FFFFF) << 0)
#define LCDIF_C0                    (1 << 23)
#define LCDIF_D0                    (0 << 23)
#define LCDIF_PCMD0                 (*(volatile uint32_t*)(LCDIF_Base + 0x0F00))
#define LCDIF_PDAT0                 (*(volatile uint32_t*)(LCDIF_Base + 0x0F10))
#define LCDIF_PCMD1                 (*(volatile uint32_t*)(LCDIF_Base + 0x0F20))
#define LCDIF_PDAT1                 (*(volatile uint32_t*)(LCDIF_Base + 0x0F30))
#define LCDIF_SCMD0                 (*(volatile uint32_t*)(LCDIF_Base + 0x0F80))
#define LCDIF_SDAT0                 (*(volatile uint32_t*)(LCDIF_Base + 0x0F90))
#define LCDIF_SCMD1                 (*(volatile uint32_t*)(LCDIF_Base + 0x0FA0))
#define LCDIF_SDAT1                 (*(volatile uint32_t*)(LCDIF_Base + 0x0FB0))

typedef struct
{
    uint32_t HWLCD_XMax;
    uint32_t HWLCD_YMax;
    void     (*HWLCD_Command)(uint8_t);
    void     (*HWLCD_WRData)(uint8_t);
    uint8_t  (*HWLCD_RDData)(void);
} TLCDINFO, *pLCDINFO;

typedef struct
{
    boolean  Enabled;
    boolean  Initialized;
    TRECT    LayerRgn;
    TPOINT   LayerOffset;
    uint32_t LayerEnMask;
    uint8_t  BPP;
    TCFORMAT ColorFormat;
    void     *VideoBuf;
} TLCONTEXT, *pLCONTEXT;

typedef struct
{
    TRECT     ScreenRgn;                                                                            //TFT screen resolution
    TPOINT    ScreenOffset;
    uint32_t  ScreenCount;
    uint32_t  ScreenIndex;
    TLCONTEXT VLayer[LCDIF_NUMLAYERS];
} TSCREEN, *pSCREEN;

/*

typedef struct
{
    uint32_t CMDCount;
    uint32_t *Commands;
    TRECT    UpdateRect;
} TLCDCMD, *pLCDCMD;





extern TDRVHEADER LCDIFHeader;
extern TLCDINF    LCDInf;
extern TSCREEN    LCDScreen;

extern void UpdateLCDRectangle(TRECT Rct);
extern void UpdateLCDRectangleBlocked(pRECT Rct);
extern boolean SetupVLayer(uint8_t LIndex, TPOINT LOffset, uint32_t SizeX, uint32_t SizeY, TCFORMAT CFormat, uint8_t Alpha);
extern boolean SetVLayerEnabled(uint8_t LIndex, boolean Enabled, boolean UpdateScreen);
extern void SetVLayerOffset(uint8_t LIndex, TPOINT LOffset, boolean UpdateScreen);
extern boolean SetVLayerAlpha(uint8_t LIndex, uint8_t Alpha, boolean UpdateScreen);
*/
#endif /* _LCDIF_H_ */
