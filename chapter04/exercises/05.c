#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int ch, ix = 0, another_line = 0, print = 0;
  char buf[128];
  while ((ch = getchar()) != EOF) {
    if (ch == '\n') {
      buf[ix] = 0;
      if (another_line) print = 1;
      else another_line = 1;
      ix = 0;
      continue;
    }
    if (another_line) {
      if (ch != buf[ix]) {
        if (print) {
          puts(buf);
          print = 0;
        }
        buf[ix] = ch;
        another_line = 0;
      }
      ++ix;
    } else {
      buf[ix++] = ch;
    }
  }
  if (print) {
    puts(buf);
  }
}
