#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool find_char(char** strings, int value) {
  assert(strings != NULL);

  while (*strings != NULL) {
    while (**strings != '\0') {
      if (*(*strings)++ == value) {
        return true;
      }
    }
  }
  return false;
}
