#include <stdio.h>
#include <stddef.h>
char* my_strrchr(char const* str, int ch) {
  char* chr = NULL;
  while (*str != '\0') {
    if (*str == ch)
      chr = (char*)str;
    ++str;
  }
  return chr;
}

int main() {
  puts(my_strrchr("1234", '3'));
  puts(my_strrchr("123432347767683243263452353665687", '5'));
}
