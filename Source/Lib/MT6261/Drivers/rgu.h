#ifndef _RGU_H_
#define _RGU_H_

#define RGUINTERVAL_MAX             31                                                              //Max interval in seconds

#define WDT_MODE                    (*(volatile uint16_t*)(RGU_Base + 0x0000))
#define ENABLE                      (1 << 0)
#define EXTPOL                      (1 << 1)
#define EXTEN                       (1 << 2)
#define WDIRQ                       (1 << 3)
#define WDAUTOR                     (1 << 4)
#define WDMKEY                      0x2200
#define WDT_LENGTH                  (*(volatile uint16_t*)(RGU_Base + 0x0004))
#define TIMEOUT(v)                  (((((v) * 32768) / 512) & 0x07FF) << 5)
#define WDLKEY                      0x0008
#define WDT_RESTART                 (*(volatile uint16_t*)(RGU_Base + 0x0008))
#define WDTRKEY                     0x1971
#define WDT_STA                     (*(volatile uint16_t*)(RGU_Base + 0x000C))
#define HW_WDT                      (1 << 15)
#define SW_WDT                      (1 << 14)
#define SW_PERIPH_RSTN              (*(volatile uint16_t*)(RGU_Base + 0x0010))
#define DMARST                      (1 << 14)
#define SWPRKEY                     0x0037
#define SW_DSP_RSTN                 (*(volatile uint16_t*)(RGU_Base + 0x0014))
#define SWDRESET                    (1 << 15)
#define SWDRKEY                     0x0048
#define WDT_RSTINTERVAL             (*(volatile uint16_t*)(RGU_Base + 0x0018))
#define WDRLENGTH(v)                (((v) & 0x0FFF) << 0)
#define WDT_SWRST                   (*(volatile uint16_t*)(RGU_Base + 0x001C))
#define WDSWRKEY                    0x1209

typedef enum tag_WDTREASON
{
    WDT_REASON_NONE,
    WDT_REASON_HW,
    WDT_REASON_SW
} TWDTREASON;

extern void RGU_SetWDTInterval(uint8_t Interval, boolean Enable);
extern void RGU_EnableWDT(void);
extern void RGU_DisableWDT(void);
extern TWDTREASON RGU_ReadWDTStatus(void);
extern void RGU_RestartWDT(void);
extern void RGU_RaiseWDTSWReset(void);

#endif /* _RGU_H_ */
