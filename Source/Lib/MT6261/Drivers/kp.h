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
#ifndef _KP_H_
#define _KP_H_

#define KP_STATUS                   (*(volatile uint16_t *)(KP_BASE + 0x0000))
#define KP_STA                      (1 << 0)
#define KP_MEM1                     (*(volatile uint16_t *)(KP_BASE + 0x0004))
#define KP_MEM2                     (*(volatile uint16_t *)(KP_BASE + 0x0008))
#define KP_MEM3                     (*(volatile uint16_t *)(KP_BASE + 0x000C))
#define KP_MEM4                     (*(volatile uint16_t *)(KP_BASE + 0x0010))
#define KP_MEM5                     (*(volatile uint16_t *)(KP_BASE + 0x0014))
#define KP_DEBOUNCE                 (*(volatile uint16_t *)(KP_BASE + 0x0018))
#define KP_DEB(v)                   (((v) & 0x3FFF) << 0)
#define KP_SCAN_TIMING              (*(volatile uint16_t *)(KP_BASE + 0x001C))
#define KP_ROW_SCAN(v)              (((v) & 0x0F) << 0)
#define KP_COL_SCAN(v)              (((v) & 0x0F) << 4)
#define KP_ROW_INTERVAL(v)          (((v) & 0x0F) << 8)
#define KP_COL_INTERVAL(v)          (((v) & 0x0F) << 12)
#define KP_SEL                      (*(volatile uint16_t *)(KP_BASE + 0x0020))
#define KP_SEL_TRIPLE               (0 << 0)
#define KP_SEL_DOUBLE               (1 << 0)
#define KP_SAMPLE(v)                (((v) & 0x1F) << 1)
#define KP_COL0                     (1 << 11)
#define KP_COL1                     (1 << 12)
#define KP_COL2                     (1 << 13)
#define KP_COL3                     (1 << 14)
#define KP_COL4                     (1 << 15)
#define KP_EN                       (*(volatile uint16_t *)(KP_BASE + 0x0024))
#define KP_ENABLE                   (1 << 0)

#endif /* _KP_H_ */
