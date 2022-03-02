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
#ifndef _CHE_H_
#define _CHE_H_

/* Information from MT6229_MT6230.pdf */
#define CHE_START                   (*(volatile uint16_t *)(SEJ_BASE + 0x0000))
#define CHE_START_DONE              (0 << 0)
#define CHE_START_STUD              (1 << 0)
#define CHE_START_LAST              (1 << 1)
#define CHE_START_WSTAT             (1 << 2)
#define CHE_START_RSTAT             (1 << 3)
#define CHE_START_CLEAR             (1 << 4)
#define CHE_START_UPDES             (1 << 5)
#define CHE_START_WKEY              (1 << 6)
#define CHE_START_RKEY              (1 << 7)
#define CHE_START_UPIV01            (1 << 8)
#define CHE_START_UPIV23            (1 << 9)
#define CHE_START_UPK01             (1 << 10)
#define CHE_START_UPK23             (1 << 11)
#define CHE_START_UPK45             (1 << 12)
#define CHE_START_UPK67             (1 << 13)

#define CHE_CON                     (*(volatile uint16_t *)(SEJ_BASE + 0x0004))
#define CHE_CON_ATYPE               (((v) & 0x07) << 0)
#define CHE_CON_ATYPE_MD5           0x00
#define CHE_CON_ATYPE_SHA1          0x01
#define CHE_CON_ATYPE_DES           0x02
#define CHE_CON_ATYPE_3DES          0x03
#define CHE_CON_ATYPE_AES_128       0x04
#define CHE_CON_ATYPE_AES_192       0x05
#define CHE_CON_ATYPE_AES_256       0x06
#define CHE_CON_DECIPHER            (0 << 3)
#define CHE_CON_CIPHER              (1 << 3)
#define CHE_CON_SMODE_ECB           (0 << 4)
#define CHE_CON_SMODE_CBC           (1 << 4)
#define CHE_CON_DKEY1_64BIT         (0 << 5)
#define CHE_CON_DKEY1_56BIT         (1 << 5)
#define CHE_CON_DKEY2_64BIT         (0 << 6)
#define CHE_CON_DKEY2_56BIT         (1 << 6)
#define CHE_CON_DKEY3_64BIT         (0 << 7)
#define CHE_CON_DKEY3_56BIT         (1 << 7)

#define CHE_IN0                     (*(volatile uint32_t *)(SEJ_BASE + 0x0008))
#define CHE_IN0_MASK                0xFFFFFFFF

#define CHE_IN1                     (*(volatile uint32_t *)(SEJ_BASE + 0x000C))
#define CHE_IN1_MASK                0xFFFFFFFF

#define CHE_IN2                     (*(volatile uint32_t *)(SEJ_BASE + 0x0010))
#define CHE_IN2_MASK                0xFFFFFFFF

#define CHE_IN3                     (*(volatile uint32_t *)(SEJ_BASE + 0x0014))
#define CHE_IN3_MASK                0xFFFFFFFF

#define CHE_SDRAT                   (*(volatile uint16_t *)(SEJ_BASE + 0x0018))
#define CHE_SDRAT_MASK              0x00FF                                                          /* RW */

#define CHE_PCNT                    (*(volatile uint16_t *)(SEJ_BASE + 0x001C))                     /* RO */
#define CHE_PCNT_MASK               0x001F

#define CHE_STAT                    (*(volatile uint16_t *)(SEJ_BASE + 0x0020))                     /* RO */
#define CHE_STAT_VAL                ((CHE_STAT >> 0) & 0x0007)                                      /* RO */
#define CHE_STAT_OK                 0x00
#define CHE_STAT_CTRL_ERR           0x01
#define CHE_STAT_ZEROLEN            0x02
#define CHE_STAT_RESUME             0x03
#define CHE_STAT_BUSY               0x04

#define CHE_CDES                    (*(volatile uint32_t *)(SEJ_BASE + 0x0024))                     /* RO */
#define CHE_CDES_MASK               0xFFFFFFFF

#define CHE_INTSTA                  (*(volatile uint16_t *)(SEJ_BASE + 0x0028))                     /* RC */
#define CHE_INTSTA_OK_RESUME        0x01
#define CHE_INTSTA_FAIL             0x02

#define CHE_INTEN                   (*(volatile uint16_t *)(SEJ_BASE + 0x002C))                     /* RW */
#define CHE_INTEN_OK                0x01
#define CHE_INTEN_FAIL              0x02

#define CHE_BCON                    (*(volatile uint16_t *)(SEJ_BASE + 0x00C0))
#define CHE_BCON_DIS                (1 << 0)
#define CHE_BCON_PAR1               (1 << 1)
#define CHE_BCON_PAR2               (1 << 2)
#define CHE_BCON_PAR3               (1 << 3)

#define CHE_BSRC                    (*(volatile uint32_t *)(SEJ_BASE + 0x00C4))                     /* WO */
#define CHE_BSEED                   (*(volatile uint32_t *)(SEJ_BASE + 0x00C8))                     /* WO */
#define CHE_BENC                    (*(volatile uint32_t *)(SEJ_BASE + 0x00CC))                     /* RO */
#define CHE_BDEC                    (*(volatile uint32_t *)(SEJ_BASE + 0x00D0))                     /* RO */

#endif /* _CHE_H_ */
