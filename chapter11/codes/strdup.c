#include <stdlib.h>
#include <string.h>

char* strdup(char const* string) {
  char* new_string = malloc(strlen(string) + 1);

  if (new_string != NULL)
    strcpy(new_string, string);
  return new_string;
}
