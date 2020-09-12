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
#ifndef _RTC_H_
#define _RTC_H_

#define RTC_INITIAL_YEAR            2000

#define RTC_BBPU                    (*(volatile uint16_t *)(RTC_Base + 0x0000))
#define KEY_BBPU                    0x4300
#define PWREN                       (1 << 0)
#define BBPU                        (1 << 2)
#define AUTO                        (1 << 3)
#define CLRPKY                      (1 << 4)
#define RELOAD                      (1 << 5)
#define CBUSY                       (1 << 6)
#define RTC_IRQ_STA                 (*(volatile uint16_t *)(RTC_Base + 0x0004))
#define ALSTA                       (1 << 0)
#define TCSTA                       (1 << 1)
#define LPSTA                       (1 << 3)
#define RTC_IRQ_EN                  (*(volatile uint16_t *)(RTC_Base + 0x0008))
#define AL_EN                       (1 << 0)
#define TC_EN                       (1 << 1)
#define ONESHOT                     (1 << 2)
#define LP_EN                       (1 << 3)
#define RTC_CII_EN                  (*(volatile uint16_t *)(RTC_Base + 0x000C))
#define SECCII                      (1 << 0)
#define MINCII                      (1 << 1)
#define MOUCII                      (1 << 2)
#define DOMCII                      (1 << 3)
#define DOWCII                      (1 << 4)
#define MTHCII                      (1 << 5)
#define YEACII                      (1 << 6)
#define SECCII1_2                   (1 << 7)
#define SECCII1_4                   (1 << 8)
#define SECCII1_8                   (1 << 9)
#define RTC_AL_MASK                 (*(volatile uint16_t *)(RTC_Base + 0x0010))
#define SEC_MSK                     (1 << 0)
#define MIN_MSK                     (1 << 1)
#define HOU_MSK                     (1 << 2)
#define DOM_MSK                     (1 << 3)
#define DOW_MSK                     (1 << 4)
#define MTH_MSK                     (1 << 5)
#define YEA_MSK                     (1 << 6)
#define RTC_TC_SEC                  (*(volatile uint16_t *)(RTC_Base + 0x0014))
#define RTC_TC_MIN                  (*(volatile uint16_t *)(RTC_Base + 0x0018))
#define RTC_TC_HOU                  (*(volatile uint16_t *)(RTC_Base + 0x001C))
#define RTC_TC_DOM                  (*(volatile uint16_t *)(RTC_Base + 0x0020))
#define RTC_TC_DOW                  (*(volatile uint16_t *)(RTC_Base + 0x0024))
#define RTC_TC_MTH                  (*(volatile uint16_t *)(RTC_Base + 0x0028))
#define RTC_TC_YEA                  (*(volatile uint16_t *)(RTC_Base + 0x002C))
#define RTC_AL_SEC                  (*(volatile uint16_t *)(RTC_Base + 0x0030))
#define RTC_AL_MIN                  (*(volatile uint16_t *)(RTC_Base + 0x0034))
#define RTC_AL_HOU                  (*(volatile uint16_t *)(RTC_Base + 0x0038))
#define RTC_AL_DOM                  (*(volatile uint16_t *)(RTC_Base + 0x003C))
#define RTC_AL_DOW                  (*(volatile uint16_t *)(RTC_Base + 0x0040))
#define RTC_AL_MTH                  (*(volatile uint16_t *)(RTC_Base + 0x0044))
#define RTC_AL_YEA                  (*(volatile uint16_t *)(RTC_Base + 0x0048))
#define RTC_OSC32CON                (*(volatile uint16_t *)(RTC_Base + 0x004C))
#define OSC32_RSV                   0x0400
#define XOSCCALI(v)                 (((v) & 0x1F) << 0)
#define XOSC32_ENB                  (1 << 5)
#define EMB_MODE(v)                 (((v) & 0x07) << 6)
#define OSC32KEY1                   0x1A57
#define OSC32KEY2                   0x2B68
#define RTC_POWERKEY1               (*(volatile uint16_t *)(RTC_Base + 0x0050))
#define POWERKEY1                   0xA357
#define RTC_POWERKEY2               (*(volatile uint16_t *)(RTC_Base + 0x0054))
#define POWERKEY2                   0x67D2
#define RTC_PDN1                    (*(volatile uint16_t *)(RTC_Base + 0x0058))
#define RTC_PDN2                    (*(volatile uint16_t *)(RTC_Base + 0x005C))
#define RTC_SPAR0                   (*(volatile uint16_t *)(RTC_Base + 0x0060))
#define RTC_SPAR1                   (*(volatile uint16_t *)(RTC_Base + 0x0064))
#define RTC_PROT                    (*(volatile uint16_t *)(RTC_Base + 0x0068))
#define PROT1                       0x586A
#define PROT2                       0x9136
#define RTC_DIFF                    (*(volatile uint16_t *)(RTC_Base + 0x006C))
#define DIFF(v)                     (((v) & 0x0FFF) << 0)
#define RTC_CALI                    (*(volatile uint16_t *)(RTC_Base + 0x0070))
#define CALI(v)                     (((v) & 0x3FFF) << 0)
#define RTC_WRTGR                   (*(volatile uint16_t *)(RTC_Base + 0x0074))
#define WRTGR                       (1 << 0)
#define RTC_CON                     (*(volatile uint16_t *)(RTC_Base + 0x0078))
#define VBAT_LPSTA_RAW              (1 << 0)
#define LPEN(v)                     (((v) & 0x03) << 1)
#define LPRST                       (1 << 3)
#define LPSTA_RAW                   (1 << 15)

typedef struct tag_TIME
{
    uint8_t Sec;
    uint8_t Min;
    uint8_t Hour;
} TTIME, *pTIME;

typedef struct tag_DATE
{
    uint8_t Day;
    uint8_t DoW;
    uint8_t Month;
    uint16_t Year;
} TDATE, *pDATE;

typedef struct tag_DATETIME
{
    TTIME Time;
    TDATE Date;
} TDATETIME, *pDATETIME;

extern boolean RTC_LockBBPower(void);
extern boolean RTC_UnlockBBPower(void);
extern boolean RTC_EnablePowerUp(void);
extern boolean RTC_DisablePowerUp(void);
extern boolean RTC_IsValidState(void);
extern boolean RTC_IsAlarmActive(void);
extern boolean RTC_Initialize(void);
extern TDATETIME RTC_GetDateTime(void);
extern boolean RTC_SetTime(pTIME Time);
extern boolean RTC_SetDate(pDATE Date);
extern TDATETIME RTC_GetAlarmDateTime(void);
extern boolean RTC_SetAlarmDateTime(pDATETIME DateTime, boolean UseInterrupt);
extern void RTC_Sleep(void);
extern void RTC_Resume(void);

#endif /* _RTC_H_ */
