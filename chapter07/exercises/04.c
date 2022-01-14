#include <stdio.h>
#include <stdarg.h>

int max_list(int v1, ...) {
  int max = v1;
  va_list args;

  va_start(args, v1);
  int value = 0;
  while ((value = va_arg(args, int)) >= 0)
    if (value > max)
      max = value;
  va_end(args);

  return max;
}

int main() {
  printf("max_list(1, 1, 4, 5, 1, -4): %d\n", max_list(1, 1, 4, 5, 1, -4));
  printf("max_list(1, 9, 1, 9, 8, 1, 0, 99, 199, -99, 382, 995, 10086): %d",
      max_list(1, 9, 1, 9, 8, 1, 0, 99, 199, -99, 382, 995, 10086));
}
