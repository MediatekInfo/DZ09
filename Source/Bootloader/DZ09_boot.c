// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "systemconfig.h"
#include "mtktypes.h"
#include "dz09_boot.h"

extern uint32_t ROM_Image_Base, ROM_Image_Limit;

void *BL_CheckFileByDescriptor(BL_Descr File)
{
    File.m_bl_begin_dev_addr += ROM_Image_Base;
    File.m_bl_boundary_dev_addr += ROM_Image_Base;

    if ((File.m_bl_begin_dev_addr < ROM_Image_Limit) &&
            (File.m_bl_boundary_dev_addr < ROM_Image_Limit))
    {
/* Oops, SFC is deinitialized immediately after loading into memory. We'll have to go deeper. */
    }
return NULL;

}

int main(void)
{
    pSF_HEADER_v1 sf_header = (pSF_HEADER_v1)ROM_Image_Base;

    DBG_Initialize();                                                                               // Setup debug interface
    DebugPrint("\r\n--1st bootloader runs--\r\n");

    if (sf_header == NULL) return 0;

    /* Check SF header for validity */
    if (!strcmp(sf_header->m_identifier, SF_HEADER_ID) &&
            (sf_header->m_ver == SF_HEADER_VER))
    {
        pBR_Layout_v1 BR_Layout;

        /* Check boot regions layout for validity */
        BR_Layout = (pBR_Layout_v1)(sf_header->m_dev_rw_unit + ROM_Image_Base);
        if (!strcmp(BR_Layout->m_identifier, BRLYT_ID) &&
                (BR_Layout->m_ver == BRLYT_VER))
        {
            uint32_t i;
            void    (*Run2ndBoot)(void);

            /* Try to find descriptor of 2nd bootloader */
            for(i = 0; i < MAX_BL_NUM; i++)
            {
                if ((BR_Layout->m_bl_desc[i].m_bl_exist_magic == BL_EXIST_MAGIC) &&
                        (BR_Layout->m_bl_desc[i].m_bl_dev == F_SF) &&
                        (BR_Layout->m_bl_desc[i].m_bl_type == ARM_EXT_BL) &&
                        ((Run2ndBoot = BL_CheckFileByDescriptor(BR_Layout->m_bl_desc[i])) != NULL))
                {
                    Run2ndBoot();
                }
            }
        }
    }
    return 0;
}
