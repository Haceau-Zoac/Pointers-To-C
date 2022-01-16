#include <stddef.h>

size_t strlen(char const* string) {
  int length;
  for (length = 0; *string++ != '\0';) {
    length += 1;
  }
  return length;
}

