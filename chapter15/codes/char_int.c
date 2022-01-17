#include <stdio.h>
#include <ctype.h>

int read_int() {
  int value = 0, ch;

  while ((ch = getchar()) != EOF && isdigit(ch)) {
    value *= 10;
    value += ch - '0';
  }

  ungetc(ch, stdin);
  return value;
}
