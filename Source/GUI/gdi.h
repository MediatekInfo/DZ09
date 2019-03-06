#ifndef _GDI_H_
#define _GDI_H_

extern void GDI_FillRectangle(TVLINDEX Layer, TRECT Rct, uint32_t Color);
extern void GDI_DrawLine(TVLINDEX Layer, TPOINT P0, TPOINT P1, uint32_t Color);
extern void GDI_SetPixel(TVLINDEX Layer, TPOINT P, uint32_t Color);

#endif /* _GDI_H_ */
