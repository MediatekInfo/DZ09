/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2020, 2019 AJScorp
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
#ifndef _MTKTYPES_H_
#define _MTKTYPES_H_

#define SF_HEADER_ID    "SF_BOOT"
#define SF_HEADER_VER   1

#define MAX_BL_NUM      8
#define BRLYT_ID        "BRLYT"
#define BRLYT_VER       1
#define BL_EXIST_MAGIC  0x42424242

/* MTK file types */
#define GFH_HDR_MAGIC   0x004D4D4D
#define GFH_GETMAGIC(m) ((m) & 0x00FFFFFF)
#define MAGIC_MASK      0x00FFFFFF
#define ARM_BL          0x0001                                                                      // 1st bootloader
#define ARM_EXT_BL      0x0002                                                                      // 2nd bootloader

/* MTK Flash device type */
#define F_SF            7

/* MTK signature types */
#define SIG_NONE        0
#define SIG_PHASH       1                                                                           // SHA-1 hash
#define MTK_FEND        0x454E4400                                                                  // "END" in reversed order

typedef enum
{
    GFH_FILE_INFO          = 0x0000,
    GFH_BL_INFO            = 0x0001,
    GFH_ANTI_CLONE         = 0x0002,
    GFH_BL_SEC_KEY         = 0x0003,
    GFH_SCTRL_CERT         = 0x0004,
    GFH_TOOL_AUTH          = 0x0005,
    GFH_MTK_RESERVED1      = 0x0006,
    GFH_BROM_CFG           = 0x0007,
    GFH_BROM_SEC_CFG       = 0x0008,
    GFH_MTK_RESERVED2      = 0x0009,
    GFH_MTK_RESERVED3      = 0x000a,
    GFH_ROOT_CERT          = 0x000b,
    GFH_EXP_CHK            = 0x000c,
    GFH_EPP_PARAM          = 0x000d,
    GFH_CHIP_VER           = 0x000e,
    GFH_MTK_RESERVED4      = 0x000f,
    GFH_MD_SEC_CFG         = 0x0010,

    GFH_EPP_INFO           = 0x0100,
    GFH_EMI_LIST           = 0x0101,
    GFH_CMEM_ID_INFO       = 0x0102,
    GFH_CMEM_NOR_INFO      = 0x0103,
    GFH_DSP_INFO           = 0x0104,

    GFH_MAUI_INFO          = 0x0200,
    GFH_MAUI_SEC           = 0x0201,
    GFH_MAUI_CODE_KEY      = 0x0202,                                                                // MAUI_SEC_KEY for code part
    GFH_MAUI_SECURE_RO_KEY = 0x0203,                                                                // MAUI_SEC_KEY for secure ro part
    GFH_MAUI_RESOURCE_KEY  = 0x0204,                                                                // MAUI_SEC_KEY for resource part

    GFH_SECURE_RO_INFO     = 0x0205,

    GFH_DL_PACKAGE_INFO    = 0x0206,
    GFH_FLASH_INFO         = 0x0207,
    GFH_MACR_INFO          = 0x0208,
    GFH_ARM_BL_INFO        = 0x0209,
    GFH_EMMC_BOOTING_INFO  = 0x020A,
    GFH_FOTA_INFO          = 0x020B,
    GFH_CBR_RECORD_INFO    = 0x020C,
    GFH_CONFIDENTIAL_BIN_INFO = 0x020D,
    GFH_CBR_INFO           = 0x020E,
    GFH_MBA_INFO           = 0x020F,
    GFH_BINARY_LOCATION    = 0x0210,

    GFH_BOOT_CERT_CTRL_CONTENT = 0x0300,

    GFH_TYPE_NUM,
    GFH_TYPE_END           = (uint16_t)0xffff
} GFH_TYPE;

typedef struct
{
    uint32_t    H0;
    uint32_t    H1;
    uint32_t    H2;
    uint32_t    H3;
    uint32_t    H4;
    uint32_t    Reserved[3];
} MTK_PHASH, *pMTK_PHASH;

typedef struct tag_GFH_Header
{
    uint32_t    magic;
    uint16_t    size;
    GFH_TYPE    type;
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
} FILE_INFO_v1, *pFILE_INFO_v1;

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
