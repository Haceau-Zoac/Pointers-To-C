#include <stdio.h>

void mystery(int n) {
  n += 5;
  n /= 10;
  printf("%s\n", (char const*)"**********" + 10 - n);
}
