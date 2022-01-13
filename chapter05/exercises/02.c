#include <stdio.h>
#include <ctype.h>

int encryption(int ch) {
  return ch - (islower(ch) ? 'a' : 'A') < 13 ? ch + 13 : ch - 13;
}

int main() {
  int ch;
  while ((ch = getchar()) != EOF) {
    if (isalpha(ch)) putchar(encryption(ch));
    else putchar(ch);
  }
}
