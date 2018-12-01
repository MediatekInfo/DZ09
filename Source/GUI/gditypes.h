#ifndef _GDITYPES_H_
#define _GDITYPES_H_

#define clBlack         0x00000000
#define clBrown         0x00003366
#define clMaroon        0x00000080
#define clGreen         0x00008000
#define clOlive         0x00008080
#define clDarkBlue      0x00400000
#define clDarkGray      0x00404040
#define clNavy          0x00800000
#define clPurple        0x00800080
#define clTeal          0x00808000
#define clGray          0x00808080
#define clSilver        0x00C0C0C0
#define clRed           0x000000FF
#define clMidGreen      0x0000C000
#define clLime          0x0000FF00
#define clYellow        0x0000FFFF
#define clBlue          0x00FF0000
#define clFuchsia       0x00FF00FF
#define clAqua          0x00FFFF00
#define clWhite         0x00FFFFFF
#define clMoneyGreen    0x00C0DCC0
#define clSkyBlue       0x00F0C8A4
#define clCream         0x00F0F8FC
#define clMedGray       0x00A4A0A0
#define clBtnFace       0x00C8D0D4

typedef enum
{
    CF_8IDX,                                                                                        //1BPP
    CF_RGB565,                                                                                      //2BPP
    CF_YUYV422,                                                                                     //Not supported
    CF_RGB888,                                                                                      //3BPP
    CF_ARGB8888,                                                                                    //4BPP
    CF_PARGB8888,                                                                                   //4BPP
    CF_xRGB8888,                                                                                    //4BPP
    CF_NUM
} TCFORMAT, *pCFORMAT;

#define clAlpha(v)      ((((uint32)v) & 0xFF) << 24)

typedef struct
{
    int16_t x;
    int16_t y;
} TPOINT, *pPOINT;

typedef union
{
    struct
    {
        TPOINT  lt;
        TPOINT  rb;
    };
    struct
    {
        int16_t l;
        int16_t t;
        int16_t r;
        int16_t b;
    };
} TRECT, *pRECT;

typedef struct
{
    int16_t sx;
    int16_t sy;
} TSIZEXY, *pSIZEXY;

#endif /* _GDITYPES_H_ */
