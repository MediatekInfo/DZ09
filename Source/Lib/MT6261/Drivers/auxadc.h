/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2019 AJScorp
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
#ifndef _AUXADC_H_
#define _AUXADC_H_

#define ADC_VBAT                    0                                                               //3.2 ~ 4.2V
#define ADC_ISENSE                  1                                                               //3.2 ~ 4.2V
#define ADC_CHRIN                   2
#define ADC_BATON                   3                                                               //BATTemp 0 ~ AVDD28
#define ADC_AUXIN4                  4                                                               //0 ~ AVDD28
#define ADC_ACCDET                  5
#define ADC_ClassAB                 9
#define ADC_XP_Ext                  12
#define ADC_YP_Ext                  13
#define ADC_YM_Ext                  14
#define ADC_XM_Ext                  15

#define AUXADC_CON0                 (*(volatile uint16_t*)(AUXADC_base + 0x0000))                   //AuxiliaryADC Control Register 0
#define SYN0(i)                     ((1 << (i)) & 0xF23F)
#define AUXADC_CON1                 (*(volatile uint16_t*)(AUXADC_base + 0x0004))                   //AuxiliaryADC Control Register 1
#define IMM0(i)                     ((1 << (i)) & 0xF23F)
#define AUXADC_CON2                 (*(volatile uint16_t*)(AUXADC_base + 0x0008))                   //AuxiliaryADC Control Register 2
#define AUXADCEN                    (1 << 0)
#define AUXADC_CON3                 (*(volatile uint16_t*)(AUXADC_base + 0x000C))                   //AuxiliaryADC Control Register 3
#define AUXADCSTA                   (1 << 0)
#define ADC_BYPASS_SLP_ZCV          (1 << 4)
#define ADC_SOFT_RST                (1 << 7)
#define ADCAUTOCLR1                 (1 << 9)
#define ADCAUTOSET                  (1 << 15)
#define AUXADC_DAT(i)               (*(volatile uint16_t*)(AUXADC_base + 0x0010 + 4 * (i)))         //AuxiliaryADC Data channels
#define AUX_TS_CMD0                 (*(volatile uint16_t*)(AUXADC_base + 0x0054))                   //Touch Screen Sample Command 0
#define AUX_TS_CON                  (*(volatile uint16_t*)(AUXADC_base + 0x0058))                   //Touch Screen Control
#define AUX_TS_DAT0                 (*(volatile uint16_t*)(AUXADC_base + 0x005C))                   //Touch Screen Sample Data 0
#define AUXADC_DAT_ZCV              (*(volatile uint16_t*)(AUXADC_base + 0x0070))                   //Touch Screen Sample Data 0
#define AUXADC_CON4                 (*(volatile uint16_t*)(AUXADC_base + 0x00D0))                   //AuxiliaryADC Control Register 4
#define SYN0STA                     (1 << 0)
#define SYN1STA                     (1 << 1)
#define SYN2STA                     (1 << 2)
#define SYN3STA                     (1 << 3)
#define SYN4STA                     (1 << 4)
#define SYN5STA                     (1 << 5)
#define SYN9STA                     (1 << 9)
#define AUXADCSTA0                  (1 << 14)
#define TS_SPL_STA                  (1 << 15)
#define AUX_TS_CMD1                 (*(volatile uint16_t*)(AUXADC_base + 0x00D4))                   //Touch Screen Sample Command 1
#define AUX_TS_DAT1                 (*(volatile uint16_t*)(AUXADC_base + 0x00D8))                   //Touch Screen Sample Data 1

#endif /* _AUXADC_H_ */
