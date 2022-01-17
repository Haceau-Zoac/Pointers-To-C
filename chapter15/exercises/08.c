#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s filename", *argv);
    return EXIT_FAILURE;
  }

  char const* filename = *++argv;
  FILE* input = fopen(filename, "rb");
  if (input == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }

  while (feof(input) != 1) {
    printf("%06lX ", (unsigned long)ftell(input));
    unsigned char buffer[16];
    for (int i = 0; i < 4; ++i) {
      fread(buffer + i * 4, sizeof(unsigned char), 4, input);
      for (int j = 0; j < 4; ++j) {
        printf("%02X", buffer[i * 4 + j]);
      }
      putchar(' ');
    }
    putchar('*');
    for (int i = 0; i < 16; ++i) {
      if (!isprint(buffer[i])) {
        putchar('.');
      } else {
        putchar(buffer[i]);
      }
    }
    putchar('*');
    putchar('\n');
  }

  fclose(input);
}
