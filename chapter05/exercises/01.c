#include <stdio.h>
#include <ctype.h>

int main() {
  int ch;
  while ((ch = getchar()) != EOF) 
    putchar(isupper(ch) ? tolower(ch) : ch);
}
