#include <stdio.h>
#include <string.h>
void dollars(char* dest, char const* src) {
  char* head = dest;
  int length = 0;
  for (char const* last = src + strlen(src) - 1; last >= src; --last) {
    ++length;
    if (length == 3) *dest++ = '.';
    else if ((length - 3) % 3 == 0) *dest++ = ',';
    *dest++ = *last;
  }
  if (length < 3) {
    while (length++ < 2) {
      *dest++ = '0';
    }
    *dest++ = '.';
    *dest++ = '0';
  }
  *dest++ = '$';
  *dest = '\0';
  while (head < dest) {
    char tmp = *--dest;
    *dest = *head;
    *head++ = tmp;
  }
}

void test(char const* dollar, char const* expected) {
  static char dest[1024] = { 0 };
  dollars(dest, dollar);
  printf("[%c] %s: %s\n", strcmp(expected, dest) == 0 ? 'v' : 'x', dollar, dest);
}

int main() {
  test("", "$0.00");
  test("1", "$0.01");
  test("12", "$0.12");
  test("123", "$1.23");
  test("1234", "$12.34");
  test("12345", "$123.45");
  test("123456", "$1,234.56");
  test("1234567", "$12,345.67");
  test("12345678", "$123,456.78");
  test("123456789", "$1,234,567.89");
}
