#include <stdio.h>
#include <string.h>

int numeric_palindrome(int value) {
  char buf[64] = { 0 };
  sprintf(buf, "%d", value);

  char* begin = buf;
  char* end = begin + strlen(begin) - 1;
  while (begin < end)
    if (*end-- != *begin++)
      return 0;

  return 1;
}

void test(int value, int expected) {
  int result = numeric_palindrome(value);
  printf("[%c] %d: %d(%d)\n", result == expected ? 'v' : 'x', value, result, expected);
}

int main() {
  test(245, 0);
  test(14741, 1);
}
