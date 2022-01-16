#include <string.h>

char* my_strrstr(char const* s1, char const* s2) {
  register char* last = NULL;
  register char* current;

  if (*s2 != '\0') {
    current = strstr(s1, s2);
    while (current != NULL) {
      last = current;
      current = strstr(last + 1, s2);
    }
  }

  return last;
}
