#ifndef GUARD_ALLOC_H
#define GUARD_ALLOC_H


#define FREE_AND_SET_NULL(ptr)          \
{                                       \
    Free(ptr);                          \
    ptr = NULL;                         \
}

#define TRY_FREE_AND_SET_NULL(ptr) if (ptr != NULL) FREE_AND_SET_NULL(ptr)

#define HEAP_SIZE 0x1C000
extern u8 gHeap[HEAP_SIZE];

#if TESTING || !defined(NDEBUG)

#define Alloc(size) Alloc_(size, __FILE__ ":" STR(__LINE__))
#define AllocZeroed(size) AllocZeroed_(size, __FILE__ ":" STR(__LINE__))

#else

#define Alloc(size) Alloc_(size, NULL)
#define AllocZeroed(size) AllocZeroed_(size, NULL)

#endif

void *Alloc_(u32 size, const char *location);
void *AllocZeroed_(u32 size, const char *location);
void Free(void *pointer);
void InitHeap(void *pointer, u32 size);

const struct MemBlock *HeapHead(void);
const char *MemBlockLocation(const struct MemBlock *block);

#endif // GUARD_ALLOC_H
