/*
 * 在你的机器上，字符的范围有多大？有哪些不同的整数类型？他们的范围又是如何？
 */

#include <limits.h>
#include <stdio.h>

int main(void) {
  printf("         char: %d~%d\n", CHAR_MIN, CHAR_MAX);
  printf("signed   char: %d~%d\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned char:  0~%u\n", UCHAR_MAX);

  printf("signed   short: %d~%d\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short:  0~%u\n", USHRT_MAX);
  printf("signed   int  : %d~%d\n", INT_MIN, INT_MAX);
  printf("unsigned int  :  0~%u\n", UINT_MAX);
  printf("signed   long : %d~%d\n", LONG_MIN, LONG_MAX);
  printf("unsigned long :  0~%u\n", ULONG_MAX);
  printf("signed   long long : %lld~%lld\n", LLONG_MIN, LLONG_MAX);
  printf("unsigned long long :    0~%llu\n", ULLONG_MAX);
}