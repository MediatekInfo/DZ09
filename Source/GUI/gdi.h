#ifndef _GDI_H_
#define _GDI_H_

extern void GDI_FillRectangle(uint8_t Index, TRECT Rct, uint32_t Color);
extern void GDI_DrawLine(uint8_t Index, TPOINT P0, TPOINT P1, uint32_t Color);
extern void GDI_SetPixel(uint8_t Index, TPOINT P, uint32_t Color);

#endif /* _GDI_H_ */
