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
#ifndef _SDCMD_H_
#define _SDCMD_H_

// SD Memory Card bus commands
#define CMD0_GO_IDLE_STATE          0x00                                                            // Resets all cards to idle state
#define CMD1_SEND_OP_COND           0x01                                                            // Activates the card's initialization process (for MMC)
#define CMD2_ALL_SEND_CID           0x02                                                            // Asks any card to send the CID
#define CMD3_SEND_RELATIVE_ADDR     0x03                                                            // Ask the card to publish a new relative address (RCA)
#define CMD4_SET_DSR                0x04                                                            // Programs the DSR of all cards
#define CMD7_SELECT_CARD            0x07
#define CMD8_SEND_IF_COND           0x08                                                            // Sends SD Memory Card interface condition
#define CMD9_SEND_CSD               0x09                                                            // Addressed card sends its card-specific data (CSD)
#define CMD10_SEND_CID              0x0A                                                            // Addressed card sends its card identification (CID)
#define CMD11_VOLTAGE_SWITCH        0x0B                                                            // Switch to 1.8V bus signaling level
#define CMD12_STOP_TRANSMISSION     0x0C                                                            // Forces the card to stop transmission
#define CMD13_SEND_STATUS           0x0D                                                            // Addressed card sends its status register
#define CMD15_GO_INACTIVE_STATE     0x0F                                                            // Sends an addressed card into the Inactive State
#define CMD16_SET_BLOCKLEN          0x10                                                            // Selects a block length for all following block commands
#define CMD17_READ_SINGLE_BLOCK     0x11
#define CMD18_READ_MULTIPLE_BLOCK   0x12
#define CMD19_SEND_TUNING_BLOCK     0x13                                                            // 64 bytes tuning pattern is sent for SDR50 and SDR104
#define CMD20_SPEED_CLASS_CONTROL   0x14
#define CMD23_SET_BLOCK_COUNT       0x17                                                            // Specify block count for CMD18 and CMD25
#define CMD24_WRITE_SINGLE_BLOCK    0x18
#define CMD25_WRITE_MULTIPLE_BLOCK  0x19
#define CMD26_PROGRAM_CID           0x1A
#define CMD27_PROGRAM_CSD           0x1B                                                            // Programming of the programmable bits of the CSD
#define CMD28_SET_WRITE_PROT        0x1C                                                            // Sets the write protection bit if supported
#define CMD29_CLR_WRITE_PROT        0x1D                                                            // Clears the write protection bit if supported
#define CMD30_SEND_WRITE_PROT       0x1E                                                            // Asks the card to send status of write protection bit if supported
#define CMD32_ERASE_WR_BLK_START    0x20                                                            // Sets the address of the first write block to be erased
#define CMD33_ERASE_WR_BLK_END      0x21                                                            // Sets the address of the last write block to be erased
#define CMD38_ERASE                 0x26                                                            // Erases all previously selected write blocks
#define CMD42_LOCK_UNLOCK           0x2A                                                            // Used to set/reset the password or lock/unlock the card
#define CMD55_APP                   0x37                                                            // Indicates to the card the next cmd is an application specific command
#define CMD56_GEN                   0x38                                                            // Used either to transfer a data block or to get a data block form the card for general purpse */

// SD Memory Card application-specific commands
#define ACMD6_SET_BUS_WIDTH         0x06                                                            // Defines the data bus width ('00' = 1bit or '10' = 4 bits bus)
#define ACMD13_SD_STATUS            0x0D                                                            // Send the SD Status
#define ACMD22_SEND_NUM_WR_BLOCKS   0x16                                                            // Send the number of the written (without errors) write blocks
#define ACMD23_SET_WR_BLK_ERASE_CNT 0x17                                                            // Set the number of write blocks to be pre-erased before writing
#define ACMD41_SD_SEND_OP_COND      0x29
#define ACMD42_SET_CLR_CARD_DETECT  0x2A                                                            // Connect[1]/Disconnect[0] the 50 KOhm pull-up resistor on CD/DAT3 (pin 1) of the card
#define ACMD51_SEND_SCR             0x33                                                            // Reads the SD Configuration Register (SCR)

// Commands interpretation for MSDC
#define MSDC_CMD0                   (SDC_RSPTYP(SDC_NO_RSP) | CMD0_GO_IDLE_STATE)
#define MSDC_CMD1                   (SDC_RSPTYP(SDC_RSP_R3) | CMD1_SEND_OP_COND)
#define MSDC_CMD2                   (SDC_IDRT | SDC_RSPTYP(SDC_RSP_R1) | CMD2_ALL_SEND_CID)
#define MSDC_CMD3                   (SDC_RSPTYP(SDC_RSP_R3) | CMD3_SEND_RELATIVE_ADDR)
#define MSDC_CMD4                   (SDC_RSPTYP(SDC_NO_RSP) | CMD4_SET_DSR)
#define MSDC_CMD7                   (SDC_RSPTYP(SDC_RSP_R1B) | CMD7_SELECT_CARD)
#define MSDC_CMD8                   (SDC_RSPTYP(SDC_RSP_R1) | CMD8_SEND_IF_COND)
#define MSDC_CMD9                   (SDC_RSPTYP(SDC_RSP_R2) | CMD9_SEND_CSD)
#define MSDC_CMD10                  (SDC_RSPTYP(SDC_RSP_R2) |  CMD10_SEND_CID)
#define MSDC_CMD11                  (SDC_RSPTYP(SDC_RSP_R1) | CMD11_VOLTAGE_SWITCH)
#define MSDC_CMD12                  (SDC_CMD_STOP | SDC_RSPTYP(SDC_RSP_R1B) | CMD12_STOP_TRANSMISSION)
#define MSDC_CMD13                  (SDC_RSPTYP(SDC_RSP_R1) | CMD13_SEND_STATUS)
#define MSDC_CMD15                  (SDC_RSPTYP(SDC_NO_RSP) | CMD15_GO_INACTIVE_STATE)
#define MSDC_CMD16                  (SDC_RSPTYP(SDC_RSP_R1) | CMD16_SET_BLOCKLEN)
#define MSDC_CMD17                  (SDC_DTYPE(SDC_DTYPE_SINGLE) | SDC_RSPTYP(SDC_RSP_R1) | CMD17_READ_SINGLE_BLOCK)
#define MSDC_CMD18                  (SDC_DTYPE(SDC_DTYPE_MULTIPLE) | SDC_RSPTYP(SDC_RSP_R1) | CMD18_READ_MULTIPLE_BLOCK)
#define MSDC_CMD19                  (SDC_RSPTYP(SDC_RSP_R1) | CMD19_SEND_TUNING_BLOCK)
#define MSDC_CMD20                  (SDC_RSPTYP(SDC_RSP_R1B) | CMD20_SPEED_CLASS_CONTROL)
#define MSDC_CMD23                  (SDC_RSPTYP(SDC_RSP_R1) | CMD23_SET_BLOCK_COUNT)
#define MSDC_CMD24                  (SDC_CMD_WRITE | SDC_DTYPE(SDC_DTYPE_SINGLE) | SDC_RSPTYP(SDC_RSP_R1) | CMD24_WRITE_SINGLE_BLOCK)
#define MSDC_CMD25                  (SDC_CMD_WRITE | SDC_DTYPE(SDC_DTYPE_MULTIPLE) | SDC_RSPTYP(SDC_RSP_R1) | CMD25_WRITE_MULTIPLE_BLOCK)
#define MSDC_CMD26                  (SDC_RSPTYP(SDC_RSP_R1) | CMD26_PROGRAM_CID)
#define MSDC_CMD27                  (SDC_RSPTYP(SDC_RSP_R1) | CMD27_PROGRAM_CSD)
#define MSDC_CMD28                  (SDC_RSPTYP(SDC_RSP_R1B) | CMD28_SET_WRITE_PROT)
#define MSDC_CMD29                  (SDC_RSPTYP(SDC_RSP_R1B) | CMD29_CLR_WRITE_PROT)
#define MSDC_CMD30                  (SDC_DTYPE(SDC_DTYPE_SINGLE) | SDC_RSPTYP(SDC_RSP_R1) | CMD30_SEND_WRITE_PROT)
#define MSDC_CMD32                  (SDC_RSPTYP(SDC_RSP_R1) | CMD32_ERASE_WR_BLK_START)
#define MSDC_CMD33                  (SDC_RSPTYP(SDC_RSP_R1) | CMD33_ERASE_WR_BLK_END)
#define MSDC_CMD38                  (SDC_RSPTYP(SDC_RSP_R1B) | CMD38_ERASE)
#define MSDC_CMD42                  (SDC_CMD_WRITE | SDC_DTYPE(SDC_DTYPE_SINGLE) | SDC_RSPTYP(SDC_RSP_R1) | CMD42_LOCK_UNLOCK)
#define MSDC_CMD55                  (SDC_RSPTYP(SDC_RSP_R1) | CMD55_APP)
#define MSDC_CMD56                  (SDC_RSPTYP(SDC_RSP_R1) | CMD56_GEN)

#define MSDC_ACMD6                  (SDC_RSPTYP(SDC_RSP_R1) | ACMD6_SET_BUS_WIDTH)
#define MSDC_ACMD13                 (SDC_DTYPE(SDC_DTYPE_SINGLE) | SDC_RSPTYP(SDC_RSP_R1) | ACMD13_SD_STATUS)
#define MSDC_ACMD22                 (SDC_DTYPE(SDC_DTYPE_SINGLE) | SDC_RSPTYP(SDC_RSP_R1) | ACMD22_SEND_NUM_WR_BLOCKS)
#define MSDC_ACMD23                 (SDC_RSPTYP(SDC_RSP_R1) | ACMD23_SET_WR_BLK_ERASE_CNT)
#define MSDC_ACMD41                 (SDC_RSPTYP(SDC_RSP_R3) | ACMD41_SD_SEND_OP_COND)
#define MSDC_ACMD42                 (SDC_RSPTYP(SDC_RSP_R1) | ACMD42_SET_CLR_CARD_DETECT)
#define MSDC_ACMD51                 (SDC_DTYPE(SDC_DTYPE_SINGLE) | SDC_RSPTYP(SDC_RSP_R1) | ACMD51_SEND_SCR)

#endif /* _SDCMD_H_ */
