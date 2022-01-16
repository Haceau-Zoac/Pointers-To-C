#include <stdlib.h>
#include <string.h>

void* my_calloc(unsigned size, unsigned count) {
  void* memory = malloc(size * count);
  if (memory != NULL)
    memset(memory, 0, size * count);
  return memory;
}
