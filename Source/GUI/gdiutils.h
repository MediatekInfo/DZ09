#ifndef _GDIUTILS_H_
#define _GDIUTILS_H_

#define RGB_565(v)    ((((v) & 0xF80000) >> 8) | (((v) & 0xFC00) >> 5) | ((v) & 0x1F))

extern TPOINT Point(int16_t x, int16_t y);
extern TRECT Rect(int16_t l, int16_t t, int16_t r, int16_t b);
extern boolean IsRectsOverlaps(pRECT a, pRECT b);
extern boolean GDI_ANDRectangles(pRECT a, pRECT b);
extern pDLIST GDI_ADDRectangles(pRECT a, pRECT b);
extern pDLIST GDI_SUBRectangles(pRECT a, pRECT b);
extern void GDI_FillRectangle16(pLCONTEXT lc, pRECT Rct, uint32_t Color);
extern void GDI_FillRectangle32(pLCONTEXT lc, pRECT Rct, uint32_t Color);

#endif /* _GDIUTILS_H_ */
