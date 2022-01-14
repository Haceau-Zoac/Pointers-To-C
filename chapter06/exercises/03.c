#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse_string(char* string) {
  char* end = string;
  while (*end != '\0')
    ++end;
  while (end > string) {
    char tmp = *string;
    *string++ = *--end;
    *end = tmp;
  }
}

void test(char const* str) {
  char mstr[1024];
  strcpy(mstr, str);
  printf("str: %s\n", str);
  reverse_string(mstr);
  printf("str: %s\n\n", mstr);
}

int main() {
  test("");
  test("A");
  test("AB");
  test("ABC");
  test("ABCDEFG");
}
