#include <stdio.h>

#define MAX_LINE_LENGTH 1024

void copylines(FILE* input, FILE* output) {
  char buffer[MAX_LINE_LENGTH];

  while (fgets(buffer, MAX_LINE_LENGTH, input) != NULL) {
    fputs(buffer, output);
  }
}
