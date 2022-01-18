#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s age\n", *argv);
    return EXIT_FAILURE;
  }

  int age = atoi(*++argv);
  int base = 10;
  while ((base <= 36) && (2 * base + 9 != age)) {
    ++base;
  }

  if (base > 36) {
    puts("Not found.");
  } else {
    printf("Base: %d\n", base);
  }
}
