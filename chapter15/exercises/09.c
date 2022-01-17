#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 512

void find_line(FILE* input, char const* string, char const* filename) {
  char line[MAX_LINE];
  while (fgets(line, MAX_LINE, input) != NULL)
    if (strstr(line, string) != NULL)
      printf("%s%c%s", filename ? filename : "", filename ? ':' : '\0', line);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <string> [file]", *argv);
    return EXIT_FAILURE;
  }
  char const* string = *++argv;
  int from_stdin = 1;
  char const* filename;
  while ((filename = *++argv) != NULL) {
    from_stdin = 0;
    FILE* input = fopen(filename, "r");
    if (input == NULL) {
      perror(filename);
      continue;
    }
    find_line(input, string, filename);
    fclose(input);
  }

  if (from_stdin) {
    find_line(stdin, string, NULL);
  }
}
