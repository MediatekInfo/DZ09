#ifndef _SHA_1_H_
#define _SHA_1_H_

#define SHA1BLOCKSIZE   64

typedef struct
{
    uint32_t    H0;
    uint32_t    H1;
    uint32_t    H2;
    uint32_t    H3;
    uint32_t    H4;
} TSHA1, *pSHA1;

extern pSHA1 SHA1_ProcessData(uint8_t *Data, uint32_t Length);

#endif /* _SHA-1_H_ */
