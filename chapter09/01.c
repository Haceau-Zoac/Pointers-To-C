#include <stdio.h>
#include <ctype.h>

int main() {
  int control = 0, space = 0, digit = 0, lower = 0, upper = 0, punct = 0,
      unprint = 0, chars = 0;
  int ch = 0;
  while ((ch = getchar()) != EOF) {
    ++chars;
    if (iscntrl(ch)) ++control;
    if (isspace(ch)) ++space;
    if (isdigit(ch)) ++digit;
    if (islower(ch)) ++lower;
    if (isupper(ch)) ++upper;
    if (ispunct(ch)) ++punct;
    if (!isprint(ch)) ++unprint;
  }
  printf("char: %d\n", chars);
  printf("control: %.2f%%\n", (double)control / chars * 100);
  printf("space: %.2f%%\n", (double)space / chars * 100);
  printf("digit: %.2f%%\n", (double)digit / chars * 100);
  printf("lower: %.2f%%\n", (double)lower / chars * 100);
  printf("upper: %.2f%%\n", (double)upper / chars * 100);
  printf("punct: %.2f%%\n", (double)punct / chars * 100);
  printf("unprint: %.2f%%\n", (double)unprint / chars * 100);
}
