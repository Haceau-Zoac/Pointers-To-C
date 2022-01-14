#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int del_substr(char* str, char const* substr) {
  if (substr == NULL || *substr == '\0') {
    return 1;
  }

  for (char* sub = str; *str != '\0' ; ++str) {
    char const* finds = substr;
    int found = 1;
    while (*finds != '\0') {
      if (*sub++ != *finds++) {
        found = 0;
        break;
      }
    }
    if (found) {
      while (*sub != '\0') {
        *str++ = *sub++;
      }
      *str = '\0';
      return 1;
    }
  }
  return 0;
}

void test(char const* str, char const* substr) {
  char mstr[1024];
  strcpy(mstr, str);
  printf("str: %s, substr: %s\n", str, substr);
  int res = del_substr(mstr, substr);
  printf("return: %d, str: %s\n", res, mstr);
}

int main() {
  test("ABCDEFG", "FGH");
  test("ABCDEFG", "CDF");
  test("ABCDEFG", "XABC");
  test("ABCDEFG", "CDE");
}
