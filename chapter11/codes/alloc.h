#include <stdlib.h>

#define malloc Don't call malloc directly!
#define MALLOC(num, type) (type*)alloc((num)*sizeof(type))
extern void* alloc(size_t size);
