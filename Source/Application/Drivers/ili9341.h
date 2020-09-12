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
#ifndef _ILI9341_H_
#define _ILI9341_H_

#define ILI9341_ROWSHIFT            0x00
#define ILI9341_SETWINCMDSIZE       11

#define ILI9341_NOP                 0x00
#define ILI9341_SWRESET             0x01
#define ILI9341_RDDID               0x04                                                            // Read Display ID
#define ILI9341_RDDST               0x09                                                            // Read Display status
#define ILI9341_RDDPM               0x0A                                                            // Read Display power
#define ILI9341_RDDMADCTL           0x0B                                                            // Read Display MADCTL
#define ILI9341_RDDPIXFMT           0x0C                                                            // Read Display pixel format
#define ILI9341_RDDIMFMT            0x0D                                                            // Read Display image format
#define ILI9341_RDDSM               0x0E                                                            // Read Display signal mode
#define ILI9341_RDDSDR              0x0F                                                            // Read Display diag result
#define ILI9341_SLPIN               0x10                                                            // Enter sleep mode
#define ILI9341_SLPOUT              0x11                                                            // Sleep out
#define ILI9341_PTLON               0x12                                                            // Partial mode ON
#define ILI9341_NORON               0x13                                                            // Normal Display mode ON
#define ILI9341_INVOFF              0x20                                                            // Display inversion OFF
#define ILI9341_INVON               0x21                                                            // Display inversion ON
#define ILI9341_GAMSET              0x26                                                            // Gamma set
#define GAM(v)                      (((v) & 0x0F) << 0)
#define GC0                         0x01
#define GC1                         0x02
#define GC2                         0x04
#define GC3                         0x08
#define ILI9341_DISPOFF             0x28                                                            // Display OFF
#define ILI9341_DISPON              0x29                                                            // Display ON
#define ILI9341_CASET               0x2A                                                            // Column address set
#define CASSH(v)                    (((v) & 0xFF00) >> 8)                                           // Column start high
#define CASSL(v)                    ((v) & 0xFF)                                                    // Column start low
#define CASEH(v)                    (((v) & 0xFF00) >> 8)                                           // Column end high
#define CASEL(v)                    ((v) & 0xFF)                                                    // Column end low
#define ILI9341_RASET               0x2B                                                            // Page address set
#define RASSH(v)                    (((v) & 0xFF00) >> 8)                                           // Row start high
#define RASSL(v)                    ((v) & 0xFF)                                                    // Row start low
#define RASEH(v)                    (((v) & 0xFF00) >> 8)                                           // Row end high
#define RASEL(v)                    ((v) & 0xFF)                                                    // Row end low
#define ILI9341_RAMWR               0x2C                                                            // Memory Write
#define ILI9341_CLRSET              0x2D                                                            // Color Set
#define ILI9341_RAMRD               0x2E                                                            // Memory read
#define ILI9341_PTLAR               0x30                                                            // Partial area
#define PTLSH(v)                    (((v) & 0xFF00) >> 8)                                           // Partial start high
#define PTLSL(v)                    ((v) & 0xFF)                                                    // Partial start low
#define PTLEH(v)                    (((v) & 0xFF00) >> 8)                                           // Partial end high
#define PTLEL(v)                    ((v) & 0xFF)                                                    // Partial end low
#define ILI9341_VSDEF               0x33                                                            // Vertical scrolling definition
#define ILI9341_TEOFF               0x34                                                            // Tearing Effect Line OFF
#define ILI9341_TEON                0x35                                                            // Tearing Effect Line ON
#define TELOM                       (1 << 0)
#define ILI9341_MADCTL              0x36                                                            // Memory Access control
#define MC_MH                       (1 << 2)
#define MC_RGB                      (0 << 3)
#define MC_BGR                      (1 << 3)
#define MC_ML                       (1 << 4)
#define MC_MV                       (1 << 5)
#define MC_MX                       (1 << 6)
#define MC_MY                       (1 << 7)
#define ILI9341_VSSADDR             0x37                                                            // Vertical Scrolling start address
#define ILI9341_IDMOFF              0x38                                                            // Idle mode OFF
#define ILI9341_IDMON               0x39                                                            // Idle mode ON
#define ILI9341_PIXFMT              0x3A                                                            // Pixel format set
#define DBI(v)                      (((v) & 0x07) << 0)
#define DBI16bit                    0x05
#define DBI18bit                    0x06
#define DPI(v)                      (((v) & 0x07) << 4)
#define DPI16bit                    0x05
#define DPI18bit                    0x06
#define ILI9341_RAMWRCONT           0x3C
#define ILI9341_RAMRDCONT           0x3E
#define ILI9341_SETTEARSL           0x44                                                            // Set tear scanline
#define ILI9341_GETSL               0x45                                                            // Get scanline
#define ILI9341_DISBRGHT            0x51                                                            // Set display brightness
#define ILI9341_RDDISBRGHT          0x52                                                            // Get display brightness
#define ILI9341_CTRLDISP            0x53                                                            // Set CTRL display
#define CTBL                        (1 << 2)
#define CTDD                        (1 << 3)
#define CTBCTRL                     (1 << 5)
#define ILI9341_RDCTRLDISP          0x54                                                            // Get CTRL display
#define CTBL                        (1 << 2)
#define CTDD                        (1 << 3)
#define CTBCTRL                     (1 << 5)
#define ILI9341_CABCTRL             0x55                                                            // Write content adaptive brightness control
#define CACTRL(v)                   (((v) & 0x03) << 0)
#define ILI9341_RDCABCTRL           0x56                                                            // Read content adaptive brightness control
#define ILI9341_CABCMIN             0x5E                                                            // Write CABC minimum brightness
#define ILI9341_RDCABCMIN           0x5F                                                            // Read CABC minimum brightness
#define ILI9341_FRAMERATE           0xB1
#define DIVA(v)                     (((v) & 0x03) << 0)
#define RTNA(v)                     (((v) & 0x1F) << 0)
#define ILI9341_DFUNCCONTROL        0xB6
/* 1st parameter */
#define PT(v)                       (((v) & 0x03) << 0)
#define PTG(v)                      (((v) & 0x03) << 2)
/* 2nd parameter */
#define ISC(v)                      (((v) & 0x0F) << 0)
#define SM                          (1 << 4)
#define SS                          (1 << 5)
#define GS                          (1 << 6)
#define REV                         (1 << 7)
/* 3rd parameter */
#define NL(v)                       (((v) & 0x3F) << 0)
/* 4th parameter */
#define PCDIV(v)                    (((v) & 0x3F) << 0)
#define ILI9341_PCONTROL1           0xC0
#define VRH(v)                      (((v) & 0x3F) << 0)
#define ILI9341_PCONTROL2           0xC1
#define BT(v)                       (((v) & 0x07) << 0)
#define ILI9341_VCOMCONTROL1        0xC5
#define VMH(v)                      (((v) & 0x7F) << 0)
#define VML(v)                      (((v) & 0x7F) << 0)
#define ILI9341_VCOMCONTROL2        0xC7
#define VMF(v)                      (((v) & 0x7F) << 0)
#define nVM                         (1  <<  7)
#define ILI9341_RDID1               0xDA
#define ILI9341_RDID2               0xDB
#define ILI9341_RDID3               0xDC

extern boolean ILI9341_Initialize(void);
extern void ILI9341_SleepLCD(void);
extern void ILI9341_ResumeLCD(void);
extern uint32_t *ILI9341_SetOutputWindow(pRECT Rct, uint32_t *Count, uint32_t DataAttr, uint32_t CmdAttr);

#endif /* _ILI9341_H_ */
