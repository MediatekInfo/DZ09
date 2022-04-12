#ifndef _SF_H_
#define _SF_H_

typedef struct tag_DFCONTEXT
{
    TSFI_CS CS;
} TDFCONTEXT, *pDFCONTEXT;

/* DF STATUS1 bits */
#define DF_BUSY                     (1 << 0)
#define DF_WEL                      (1 << 1)
/* DF STATUS2 bits */
#define DF_QE                       (1 << 1)

/* Generic DF commands */
#define DF_CMD_WRITE_SR             0X01
#define DF_CMD_PAGE_PROG            0X02
#define DF_CMD_READ                 0X03
#define DF_CMD_WRDIS                0X04
#define DF_CMD_READ_SR              0X05
#define DF_CMD_WREN                 0X06
#define DF_CMD_FAST_READ            0X0B
#define DF_CMD_RSTEN                0X66
#define DF_CMD_RST                  0X99
#define DF_CMD_ERASE_CHIP           0XC7
#define DF_CMD_ERASE_BLOCK64        0XD8
#define DF_CMD_ERASE_BLOCK32        0X52
#define DF_CMD_ERASE_SECTOR         0X20
#define DF_CMD_READ_ID              0X9F
#define DF_CMD_ENTER_DPD            0XB9
#define DF_CMD_LEAVE_DPD            0XAB

extern uint32_t SF_DevReadID(pDFCONTEXT DF);
extern void SF_WriteStatus(pDFCONTEXT DF, uint8_t *Data, uint32_t Count);
extern size_t SF_Read(pDFCONTEXT DF, uint32_t Address, uint8_t *Data, size_t Count);

#endif /* _SF_H_ */
