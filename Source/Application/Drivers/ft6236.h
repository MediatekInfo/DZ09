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
#ifndef _FT6236_H_
#define _FT6236_H_

#define FT6236_ADDRESS              0x38
#define FT6236_NUMPOFOINTS          2

#define DEV_MODE                    0x00
#define FT_MODE(v)                  (((v) & 0x07) << 0)
#define MODE_WORK                   0x00
#define GEST_ID                     0x01
typedef enum tag_GESTID
{
    GID_No = 0x00,
    GID_MU = 0x10,
    GID_MR = 0x14,
    GID_MD = 0x18,
    GID_ML = 0x1C,
    GID_ZI = 0x48,
    GID_ZO = 0x49
} TGESTID;
#define TD_STATUS                   0x02                                                            //[3:0] The detected point number, 1-2 is valid
#define TP_NUM(v)                   ((v) & 0x0F)
#define P1_XH                       0x03
#define P1_XL                       0x04
#define P1_YH                       0x05
#define P1_YL                       0x06
#define P1_WEIGHT                   0x07
#define P1_MISC                     0x08
#define P2_XH                       0x09
#define PXHigh(v)                   (((v) & 0x0F) << 8)                                             //v - Value from P_XH
typedef enum tag_PEVENT
{
    PE_PRESS   = 0x00,
    PE_LIFTUP  = 0x01,
    PE_CONTACT = 0x02,
    PE_NOEVENT = 0x03
} TPEVENT;
#define PEventVal(v)                (((v) & 0xC0) >> 6)                                             //v - Value from P_XH
#define P2_XL                       0x0A
#define P2_YH                       0x0B
#define PYHigh(v)                   (((v) & 0x0F) << 8)                                             //v - Value from P_YH
#define TP_ID(v)                    (((v) & 0xF0) >> 4)
#define P2_YL                       0x0C
#define P2_WEIGHT                   0x0D
#define P2_MISC                     0x0E
#define TouchArea(v)                (((v) & 0xF0) >> 4)

#define TH_GROUP                    0x80                                                            //[7:0] Threshold for touch detection
#define TH_DIFF                     0x85                                                            //[7:0] Filter function coefficient
#define CTRL                        0x86
#define ActiveNoTouch               (0 << 0)                                                        //Will keep the Active mode when there is no touching
#define MonModeNoTouch              (1 << 0)                                                        //Switching from Active mode to Monitor mode automatically when there is no touching
#define TIMEENTERMONITOR            0x87                                                            //[7:0] The time period of switching from Active mode to Monitor mode when there is no touching
#define PERIODACTIVE                0x88                                                            //[7:0] Report rate in Active mode.
#define PERIODMONITOR               0x89                                                            //[7:0] Report rate in Monitor mode.
#define RADIAN_VALUE                0x91                                                            //[7:0] The value of the minimum allowed angle while Rotating gesture mode
#define OFFSET_LEFT_RIGHT           0x92                                                            //[7:0] Maximum offset while Moving Left and Moving Right gesture
#define OFFSET_UP_DOWN              0x93                                                            //[7:0] Maximum offset while Moving Up and Moving Down gesture
#define DISTANCE_LEFT_RIGHT         0x94                                                            //[7:0] Minimum  distance  while  Moving  Left  and Moving Right gesture
#define DISTANCE_UP_DOWN            0x95                                                            //[7:0] Minimum  distance  while  Moving  Up  and Moving Down gesture
#define DISTANCE_ZOOM               0x96                                                            //[7:0] Maximum  distance  while  Zoom  In  and  Zoom Out gesture

#define LIB_VER_H                   0xA1                                                            //[7:0] High 8-bit of LIB Version info
#define LIB_VER_L                   0xA2                                                            //[7:0] Low 8-bit of LIB Version info
#define CIPHER                      0xA3                                                            //Chip vendor ID
#define G_MODE                      0xA4
#define G_MODE_IPOLL                (0 << 0)                                                        //Interrupt Polling mode
#define G_MODE_ITRIG                (1 << 0)                                                        //Interrupt Trigger mode
#define PWR_MODE                    0xA5
#define PMODE_ACT                   0x00
#define PMODE_MON                   0x01
#define PMODE_HIB                   0x03                                                            //Hibernate
#define FT_STATE                    0xBC

extern boolean FT6236_Initialize(void);
extern void FT6236_Sleep(void);
extern void FT6236_Resume(void);

#endif /* _FT6236_H_ */
