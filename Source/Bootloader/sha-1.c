// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
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
#include "systemconfig.h"
#include "sha-1.h"

#define Rol(word, bits) (((word) << bits) | ((word) >> (32 - (bits))))
#define K1  0x5A827999
#define K2  0x6ED9EBA1
#define K3  0x8F1BBCDC
#define K4  0xCA62C1D6

#define HC0 = 0x67452301;
#define HC1 = 0xEFCDAB89;
#define HC2 = 0x98BADCFE;
#define HC3 = 0x10325476;
#define HC4 = 0xC3D2E1F0;

TSHA1   Hash;

void SHA1_Initialize(void)
{
    Hash.H0 = 0x67452301;
    Hash.H1 = 0xEFCDAB89;
    Hash.H2 = 0x98BADCFE;
    Hash.H3 = 0x10325476;
    Hash.H4 = 0xC3D2E1F0;
}

void SHA1_ProcessBlock(uint8_t Data[SHA1BLOCKSIZE])
{
    uint32_t i, W[16], A, B, C, D, E, tempVar;

    for(i = 0; i < SHA1BLOCKSIZE; i += 4)
        W[i >> 2] = (Data[i] << 24) | (Data[i + 1] << 16) | (Data[i + 2] << 8) | Data[i + 3];

    A = Hash.H0;
    B = Hash.H1;
    C = Hash.H2;
    D = Hash.H3;
    E = Hash.H4;

    for(i = 0; i < 20; i++)
    {
        if (i < 16) tempVar = Rol(A, 5) + (D ^ (B & (C ^ D))) + E + K1 + W[i];
        else
        {
            W[i & 0x0F] = Rol(W[(i - 3) & 0x0F] ^ W[(i - 8) & 0x0F] ^ W[(i - 14) & 0x0F] ^ W[i & 0x0F], 1);
            tempVar = Rol(A, 5) + (D ^ (B & (C ^ D))) + E + K1 + W[i & 0x0F];
        }
        E = D;
        D = C;
        C = Rol(B, 30);
        B = A;
        A = tempVar;
    }

    for(i = 20; i < 40; i++)
    {
        W[i & 0x0F] = Rol(W[(i - 3) & 0x0F] ^ W[(i - 8) & 0x0F] ^ W[(i - 14) & 0x0F] ^ W[i & 0x0F], 1);
        tempVar = Rol(A, 5) + (B ^ C ^ D) + E + K2 + W[i & 0x0F];

        E = D;
        D = C;
        C = Rol(B, 30);
        B = A;
        A = tempVar;
    }

    for(i = 40; i < 60; i++)
    {
        W[i & 0x0F] = Rol(W[(i - 3) & 0x0F] ^ W[(i - 8) & 0x0F] ^ W[(i - 14) & 0x0F] ^ W[i & 0x0F], 1);
        tempVar = Rol(A, 5) + ((B & C) | (D & (B | C))) + E + K3 + W[i & 0x0F];

        E = D;
        D = C;
        C = Rol(B, 30);
        B = A;
        A = tempVar;
    }

    for(i = 60; i < 80; i++)
    {
        W[i & 0x0F] = Rol(W[(i - 3) & 0x0F] ^ W[(i - 8) & 0x0F] ^ W[(i - 14) & 0x0F] ^ W[i & 0x0F], 1);
        tempVar = Rol(A, 5) + (B ^ C ^ D) + E + K4 + W[i & 0x0F];

        E = D;
        D = C;
        C = Rol(B, 30);
        B = A;
        A = tempVar;
    }

    Hash.H0 += A;
    Hash.H1 += B;
    Hash.H2 += C;
    Hash.H3 += D;
    Hash.H4 += E;
}

pSHA1 SHA1_ProcessData(uint8_t *Data, uint32_t Length)
{
    if ((Data != NULL) && Length)
    {
        uint32_t SourceLength = Length;

        SHA1_Initialize();
        while(Length)
        {
            uint8_t dbytes = (Length >= SHA1BLOCKSIZE) ? SHA1BLOCKSIZE : Length;

            if (Length > SHA1BLOCKSIZE) SHA1_ProcessBlock(Data);
            else
            {
                uint8_t  i, tmpArray[SHA1BLOCKSIZE];
                uint64_t MessageBitSize;

                if (Length == SHA1BLOCKSIZE)
                {
                    SHA1_ProcessBlock(Data);
                    Length -= SHA1BLOCKSIZE;
                    Data += SHA1BLOCKSIZE;
                }

                memcpy(tmpArray, Data, Length);
                tmpArray[Length] = 0x80;
                memset(&tmpArray[Length + 1], 0x00, sizeof(tmpArray) - Length - 1);
                if (Length > 55)
                {
                    SHA1_ProcessBlock(tmpArray);
                    memset(tmpArray, 0x00, sizeof(tmpArray));
                }

                MessageBitSize = SourceLength * 8;
                for(i = 63; (i >= 56) && MessageBitSize; i--)
                {
                    tmpArray[i] = MessageBitSize & 0xFF;
                    MessageBitSize >>= 8;
                }
                SHA1_ProcessBlock(tmpArray);
                break;
            }
            Length -= SHA1BLOCKSIZE;
            Data += SHA1BLOCKSIZE;
        }
        return &Hash;
    }
    return NULL;
}

