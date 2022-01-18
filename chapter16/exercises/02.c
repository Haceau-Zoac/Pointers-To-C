#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void) {
  static bool first_in = true;
  if (first_in) {
    first_in = false;
    srand((unsigned)time(NULL));
  }

  int value = rand();
  while (value > (int)(((long)RAND_MAX + 1) / 6 * 6 - 1)) {
    value = rand();
  }

  return value % 6 + 1;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s times", *argv);
    return EXIT_FAILURE;
  }

  int times = atoi(*++argv);
  while (times-- > 0) {
    printf("POINT: %d\n", roll_dice());
  }
}
