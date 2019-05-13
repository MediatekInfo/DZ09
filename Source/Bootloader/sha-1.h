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
#ifndef _SHA_1_H_
#define _SHA_1_H_

#define SHA1BLOCKSIZE   64

typedef struct
{
    uint32_t    H0;
    uint32_t    H1;
    uint32_t    H2;
    uint32_t    H3;
    uint32_t    H4;
} TSHA1, *pSHA1;

extern pSHA1 SHA1_ProcessData(uint8_t *Data, uint32_t Length);

#endif /* _SHA-1_H_ */
