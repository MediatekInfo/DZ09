// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <stdint.h>
#include "mtktypes.h"

typedef struct tag_APP_HEADER
{
    FILE_INFO_v1    file_info;
    GFH_BL_INFO_v1  bl_info;
} APP_HEADER;

extern uint32_t __app_header_base;
extern uint32_t __app_header_size;

volatile const APP_HEADER app_header __attribute__ ((section (".app_header"))) =
{
    {
        {0x014D4D4D, sizeof(FILE_INFO_v1), 0},
        "FILE_INFO",
        1,
        0x0002,
        7,
        1,
        (uint32_t)(&__app_header_base),
        0xffffffff,
        0xffffffff,
        (uint32_t)(&__app_header_size),
        0x00000020,
        (uint32_t)(&__app_header_size),
        3
    },
    {
        {0x014D4D4D, sizeof(GFH_BL_INFO_v1), 1},
        0
    }
};
