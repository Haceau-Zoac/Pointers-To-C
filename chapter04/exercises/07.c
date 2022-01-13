#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void deblank(char string[]) {
  int blank = 0;
  for (char* s = string; *s != 0; ++s) {
    if (*s == ' ') {
      if (!blank) {
        blank = 1;
        *string++ = ' ';
      }
    }
    else {
      *string++ = *s;
      if (blank) {
        blank = 0;
      }
    }
  }
  *string = 0;
}

int main() {
  char string[1024];
  strcpy(string, "hello world");
  deblank(string);
  puts(string);

  strcpy(string, "fuck    thecp   p");
  deblank(string);
  puts(string);
}
