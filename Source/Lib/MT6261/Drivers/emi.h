#ifndef _EMI_H_
#define _EMI_H_

typedef enum
{
    MR_BOOTCODE = 0,                                                                                //Boot jump code
    MR_FB0RB1   = 2,                                                                                //Flash - Bank0, RAM - Bank1
    MR_FB1RB0   = 3                                                                                 //Flash - Bank1, RAM - Bank0
} MREMAP;


#define EMI_REMAP                   (*(volatile uint16_t*)(BOOT_ENG_base))


extern void EMI_MemoryRemap(MREMAP Mode);

#endif /* _EMI_H_ */
