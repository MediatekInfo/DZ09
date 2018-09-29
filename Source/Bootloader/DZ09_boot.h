#ifndef _DZ09_BOOT_H_
#define _DZ09_BOOT_H_

#define SF_HEADER_ID    "SF_BOOT"
#define SF_HEADER_VER   1

typedef struct
{
    char            m_identifier[12];                                                               // including '\0'
    uint32_t        m_ver;
    uint32_t        m_dev_rw_unit;                                                                  /* NAND: in page
                                                                                                       NOR/eMMC/SFlash: in byte */
} SF_HEADER_v1;

#define MAX_BL_NUM      8
#define BRLYT_ID        "BRLYT"
#define BRLYT_VER       1
#define BL_EXIST_MAGIC  0x42424242

typedef struct
{
    uint32_t        m_bl_exist_magic;

#if defined(WIN32)
    uint8_t         m_bl_dev;
    uint16_t        m_bl_type;
#else
    GFH_FLASH_DEV   m_bl_dev;
    GFH_FILE_TYPE   m_bl_type;
#endif
    uint32_t        m_bl_begin_dev_addr;                                                            /* device addr that points to the beginning of BL
                                                                                                        NAND: page addr
                                                                                                              SEQUENTIAL: phy page addr
                                                                                                              TTBL: TTBL logic page addr
                                                                                                              FDM5: FDM5.0 logic page addr
                                                                                                              NOR/eMMC/SFlash: byte addr */

    uint32_t        m_bl_boundary_dev_addr;                                                         /* device addr that points to the boundary of BL
                                                                                                       boundary addr = BL addr + BL length
                                                                                                       NAND: page addr
                                                                                                             SEQUENTIAL: phy page addr
                                                                                                             TTBL: TTBL logic page addr
                                                                                                             FDM5: FDM5.0 logic page addr
                                                                                                             NOR/eMMC/SFlash: byte addr */

    uint32_t        m_bl_attribute;                                                                 // refer to GFH_BL_INFO
} BL_Descriptor;


typedef struct
{
    char            m_identifier[8];                                                                // including '\0'
    uint32_t        m_ver;                                                                          // this structure will directly export to others, version field is necessary
    uint32_t        m_boot_region_dev_addr;                                                         /* device addr that points to the beginning of the boot region
                                                                                                       NAND: page addr
                                                                                                             SEQUENTIAL: phy page addr
                                                                                                             TTBL: TTBL logic page addr
                                                                                                             FDM5: FDM5.0 logic page addr
                                                                                                             NOR/eMMC/SFlash: byte addr */

    uint32_t        m_main_region_dev_addr;                                                         /* device addr that points to the beginning of the main code region
                                                                                                       NAND: page addr
                                                                                                             SEQUENTIAL: phy page addr
                                                                                                             FDM5: FDM5.0 logic page addr
                                                                                                             NOR/eMMC/SFlash: byte addr */
    BL_Descriptor   m_bl_desc[MAX_BL_NUM];
} BR_Layout_v1;

#endif /* _DZ09_BOOT_H_ */
