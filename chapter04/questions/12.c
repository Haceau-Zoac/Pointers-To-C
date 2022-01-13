#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int leap_year = 0, year = 0;
  scanf("%d", &year);
  if (year % 400 == 0) {
    leap_year = 1;
  } else if (year % 100 == 0) {
    leap_year = 0;
  } else if (year % 4 == 0) {
    leap_year = 1;
  } else {
    leap_year = 0;
  }
  printf("leap_year: %d", leap_year);
}
