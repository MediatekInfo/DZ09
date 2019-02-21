// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "gui.h"

static pDLIST GUIWinZOrder[LCDIF_NUMLAYERS];

boolean GUI_Initialize(void)
{
    uint32_t i;

    for(i = 0; i < LCDIF_NUMLAYERS; i++)
    {
// TODO (scorp#1#): May need to check for objects in the lists.
        if (GUIWinZOrder[i] == NULL) GUIWinZOrder[i] = DL_Create(0);
        if (GUIWinZOrder[i] == NULL)
        {
            while(i--)
            {
                free(GUIWinZOrder[i]);
                GUIWinZOrder[i] = NULL;
            }
            return false;
        }
    }
    /* ------------ */
}
