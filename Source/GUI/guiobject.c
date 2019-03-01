// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "guiobject.h"

int32_t GIU_GetWindowZIndex(pWIN Win)
{
    int32_t ZL = -1;

    if ((Win != NULL) && (Win->Head.Type == GO_WINDOW) && (Win->Layer < LCDIF_NUMLAYERS))
    {
        DL_FindItemByData(GUIWinZOrder[Win->Layer], Win, &ZL);
    }
    return ZL;
}

pWIN GUI_GetTopWindow(uint32_t Layer, boolean Topmost)
{
    pWIN    tmpWIN, Res = NULL;
    pDLITEM tmpItem;

    if (Layer >= LCDIF_NUMLAYERS) return NULL;

    if (Topmost)
    {
        tmpItem = DL_GetLastItem(GUIWinZOrder[Layer]);
        tmpWIN = (tmpItem == NULL) ? NULL : (pWIN)tmpItem->Data;
        Res = ((tmpWIN == NULL) || !tmpWIN->Topmost) ? NULL : tmpWIN;
    }
    else
    {
        tmpItem = DL_GetLastItem(GUIWinZOrder[Layer]);
        while(tmpItem != NULL)
        {
            tmpWIN = (pWIN)tmpItem->Data;
            if ((tmpWIN != NULL) && !tmpWIN->Topmost)
            {
                Res = tmpWIN;
                break;
            }
            tmpItem = DL_GetPrevItem(tmpItem);
        }
    }
    return Res;
}

pWIN GUI_GetWindowFromPoint(pPOINT pt, int32_t *ZIndex)
{
    int32_t i;
    pWIN    Win;

    for(i = LCDIF_NUMLAYERS - 1; i >= 0; i--)
    {
        pDLITEM tmpItem;
        int32_t ItemIndex;
        TPOINT  lp = GDI_GlobalToLocal(pt, &LCDScreen.VLayer[i].LayerOffset);

        tmpItem = DL_GetLastItem(GUIWinZOrder[i]);
        ItemIndex = DL_GetItemsCount(GUIWinZOrder[i]) - 1;
        while(tmpItem != NULL)
        {
            Win = tmpItem->Data;
            if ((Win != NULL) && IsPointInRect(lp.x, lp.y, &Win->Head.Position) && Win->Head.Visible)
            {
                if (ZIndex != NULL) *ZIndex = ItemIndex;
                return Win;
            }
            ItemIndex--;
            tmpItem = DL_GetPrevItem(tmpItem);
        }
    }
    if (ZIndex != NULL) *ZIndex = -1;
    return NULL;
}

