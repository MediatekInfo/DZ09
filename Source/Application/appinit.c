// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "appinit.h"

boolean APP_Initialize(void)
{
    boolean Result = true;

    GUI_Initialize();

    return Result;
}
