#ifndef _MTKTYPES_H_
#define _MTKTYPES_H_

#define SF_HEADER_ID    "SF_BOOT"
#define SF_HEADER_VER   1

#define MAX_BL_NUM      8
#define BRLYT_ID        "BRLYT"
#define BRLYT_VER       1
#define BL_EXIST_MAGIC  0x42424242

/* MTK file types */
#define ARM_BL          0x0001                                                                      // 1st bootloader
#define ARM_EXT_BL      0x0002                                                                      // 2nd bootloader

/* MTK Flash device type */
#define F_SF            7

/* MTK signature types */
#define SIG_NONE        0
#define SIG_PHASH       1                                                                           //SHA-1 hash


typedef struct tag_GFH_Header
{
    uint32_t    magic;
    uint16_t    size;
    uint16_t    type;
} GFH_Header;

typedef struct tag_FILE_INFO_v1_
{
    GFH_Header  hdr;
    char        identifier[12];                                                                     // including '\0'
    uint32_t    file_ver;

    uint16_t    file_type;
    uint8_t     flash_dev;
    uint8_t     sig_type;

    uint32_t    load_addr;
    uint32_t    file_len;
    uint32_t    max_size;
    uint32_t    offset;
    uint32_t    sig_len;
    uint32_t    jump_offset;
    uint32_t    attr;
} FILE_INFO_v1;

typedef struct
{
    GFH_Header  m_gfh_hdr;
    uint8_t     _reserved[92];
} GFH_BROM_CFG_v3;

typedef struct tag_GFH_BL_INFO_v1
{
    GFH_Header  hdr;
    uint32_t    bl_attr;
} GFH_BL_INFO_v1;

typedef struct GFH_ARM_BL_INFO_v1
{
    GFH_Header  m_gfh_hdr;
    uint32_t    m_bl_maui_paired_ver;
    uint32_t    m_feature_combination;
    uint32_t    m_feature_combination_ex;
    uint8_t     m_nand_fdm_dal_ver[8];
} GFH_ARM_BL_INFO_v1;

typedef struct
{
    char        m_identifier[12];                                                                   // including '\0'
    uint32_t    m_ver;
    uint32_t    m_dev_rw_unit;                                                                      /* NAND: in page
                                                                                                       NOR/eMMC/SFlash: in byte */
} SF_HEADER_v1, *pSF_HEADER_v1;

typedef struct
{
    uint32_t    m_bl_exist_magic;

    uint8_t     m_bl_dev;
    uint16_t    m_bl_type;

    uint32_t    m_bl_begin_dev_addr;                                                                /* device addr that points to the beginning of BL
                                                                                                        NAND: page addr
                                                                                                              SEQUENTIAL: phy page addr
                                                                                                              TTBL: TTBL logic page addr
                                                                                                              FDM5: FDM5.0 logic page addr
                                                                                                              NOR/eMMC/SFlash: byte addr */

    uint32_t    m_bl_boundary_dev_addr;                                                             /* device addr that points to the boundary of BL
                                                                                                       boundary addr = BL addr + BL length
                                                                                                       NAND: page addr
                                                                                                             SEQUENTIAL: phy page addr
                                                                                                             TTBL: TTBL logic page addr
                                                                                                             FDM5: FDM5.0 logic page addr
                                                                                                             NOR/eMMC/SFlash: byte addr */

    uint32_t    m_bl_attribute;                                                                     // refer to GFH_BL_INFO
} BL_Descr, *pBL_Descr;

typedef struct
{
    char        m_identifier[8];                                                                    // including '\0'
    uint32_t    m_ver;                                                                              // this structure will directly export to others, version field is necessary
    uint32_t    m_boot_region_dev_addr;                                                             /* device addr that points to the beginning of the boot region
                                                                                                       NAND: page addr
                                                                                                             SEQUENTIAL: phy page addr
                                                                                                             TTBL: TTBL logic page addr
                                                                                                             FDM5: FDM5.0 logic page addr
                                                                                                             NOR/eMMC/SFlash: byte addr */

    uint32_t    m_main_region_dev_addr;                                                             /* device addr that points to the beginning of the main code region
                                                                                                       NAND: page addr
                                                                                                             SEQUENTIAL: phy page addr
                                                                                                             FDM5: FDM5.0 logic page addr
                                                                                                             NOR/eMMC/SFlash: byte addr */
    BL_Descr    m_bl_desc[MAX_BL_NUM];
} BR_Layout_v1, *pBR_Layout_v1;

#endif /* _MTKTYPES_H_ */
