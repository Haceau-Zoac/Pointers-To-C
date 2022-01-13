#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double sqrt(double n) {
  double s1 = 1, s2 = 0;
  while (s1 != s2) {
    s2 = s1;
    s1 = (s2 + n / s2) / 2;
  }
  return s1;
}

int main() {
  double n;
  scanf("%lf", &n);
  if (n < 0) {
    puts("Input cannot be a negative number.");
  }
  printf("sqrt: %lf", sqrt(n));
}
