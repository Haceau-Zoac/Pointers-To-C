#include <stdio.h>
#include <stdlib.h>

#define DELTA 100

char* read_string() {
  int size = DELTA;
  char* string = malloc(DELTA + 1);

  if (string != NULL) {
    int ch;
    int count = 0;
    while ((ch = getchar()) != EOF) {
      if (size <= count) {
        string = realloc(string, (size += DELTA) + 1);
        if (string == NULL) {
          break;
        }
      }
      string[count++] = (char)ch;
    }
    string[count] = '\0';
  }

  return string;
}

int main() {
  char* string = read_string();
  puts(string);
  free(string);
}
