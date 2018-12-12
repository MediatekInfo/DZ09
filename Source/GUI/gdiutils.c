// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "gdiutils.h"

TPOINT Point(int16_t x, int16_t y)
{
    TPOINT Result = {x, y};

    return Result;
}

TRECT Rect(int16_t l, int16_t t, int16_t r, int16_t b)
{
    TRECT Result = {l, t, r, b};

    return Result;
}
