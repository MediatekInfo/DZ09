#ifndef _MEMORY_H_
#define _MEMORY_H_

extern size_t InitializeMemoryPool(void);
extern void *malloc(size_t size);
extern void free(void *ptr);
extern void *realloc(void *ptr, size_t size);
extern void *calloc(size_t nelem, size_t elem_size);
extern uint32_t GetSysMemoryAddress(void);
extern boolean IsDynamicMemory(void *Memory);
extern size_t GetTotalUsedMemory(void);

#endif /* _MEMORY_H_ */
