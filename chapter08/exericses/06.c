#include <stdio.h>
#include <stdarg.h>

int fails = 0;

int array_offset(int arrayinfo[], ...) {
  if (arrayinfo[0] < 1 || arrayinfo[0] > 10)
    return -1;

  va_list args;
  va_start(args, arrayinfo);
  int ix = va_arg(args, int);
  int loc = 0;
  for (int i = 1; i <= arrayinfo[0]; (ix = va_arg(args, int)), ++i) {
    int lo = arrayinfo[2 * i - 1];
    int hi = arrayinfo[2 * i];
    if (ix < lo || lo > hi) return -1;
    loc = loc * (hi - lo + 1) + ix - lo;
  }
  va_end(args);

  return loc;
}

void test(int result, int expected) {
  static int count = 0;
  printf("[%d] \033[3%s\033[0m.\n", ++count, result == expected ? "2mPASSED" : "1mFAILED");
  if (result != expected) ++fails;
}

int main() {
  {
    int arrayinfo[] = { 3, 4, 6, 1, 5, -3, 3 }; 
    test(array_offset(arrayinfo, 4, 1, -3), 0);
    test(array_offset(arrayinfo, 4, 1, -2), 1);
    test(array_offset(arrayinfo, 4, 1,  3), 6);
    test(array_offset(arrayinfo, 4, 2, -3), 7);
    test(array_offset(arrayinfo, 5, 1, -3), 35);
    test(array_offset(arrayinfo, 6, 3,  1), 88);
  }
  {
    int arrayinfo[] = { 2, 1, 5 };
    test(array_offset(arrayinfo), -1);
  }
  {
    int arrayinfo[] = { 10, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10 };
    test(array_offset(arrayinfo, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 0);
  }
  {
    int arrayinfo[] = { 0 };
    test(array_offset(arrayinfo), -1);
  }
  {
    int arrayinfo[] = { 11, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 66 };
    test(array_offset(arrayinfo), -1);
  }
  {
    int arrayinfo[] = { 1, 2, -1 };
    test(array_offset(arrayinfo, 1), -1);
  }
  {
    int arrayinfo[] = { 1, -1, 2 };
    test(array_offset(arrayinfo, -4), -1);
  }
  if (fails != 0)
    printf("\033[31m%d ERRORS.\n", fails);
  else
    printf("\033[32mALL PASSED.\n");
}
