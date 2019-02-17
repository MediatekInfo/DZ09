#ifndef _GDITYPES_H_
#define _GDITYPES_H_

#define clBlack         0xFF000000
#define clBrown         0xFF003366
#define clMaroon        0xFF000080
#define clGreen         0xFF008000
#define clOlive         0xFF008080
#define clDarkBlue      0xFF400000
#define clDarkGray      0xFF404040
#define clNavy          0xFF800000
#define clPurple        0xFF800080
#define clTeal          0xFF808000
#define clGray          0xFF808080
#define clSilver        0xFFC0C0C0
#define clRed           0xFF0000FF
#define clMidGreen      0xFF00C000
#define clLime          0xFF00FF00
#define clYellow        0xFF00FFFF
#define clBlue          0xFFFF0000
#define clFuchsia       0xFFFF00FF
#define clAqua          0xFFFFFF00
#define clWhite         0xFFFFFFFF
#define clMoneyGreen    0xFFC0DCC0
#define clSkyBlue       0xFFF0C8A4
#define clCream         0xFFF0F8FC
#define clMedGray       0xFFA4A0A0
#define clBtnFace       0xFFC8D0D4

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

#define clAlpha(c, alpha)   (((c) & 0x00FFFFFF) | (((alpha) & 0xFF) << 24))

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
