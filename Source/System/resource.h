/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2020 AJScorp
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
#ifndef _RESOURCE_H_
#define _RESOURCE_H_

typedef enum tag_RESTYPE
{
    RT_UNKNOWN,
    RT_FONT,
    RT_IMAGE,
    RT_AUDIO,
    RT_BLOB,
    RT_MAXNUM
} TRESTYPE, *pRESTYPE;

typedef struct tag_RESOURCE
{
    TRESTYPE Type;
} TRESOURCE, *pRESOURCE;

typedef struct tag_RESFONT
{
    TRESTYPE Type;
    BFC_FONT *Font;
} TRESFONT, *pRESFONT;

#endif /* _RESOURCE_H_ */
