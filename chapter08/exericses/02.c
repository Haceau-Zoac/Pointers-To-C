#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float signle_tex(float income) {
  if (income < 23350) return income * 0.15;
  if (income < 56550) return 3502.50 + (income - 23350) * 0.28;
  if (income < 117950) return 12798.50 + (income - 56550) * 0.31;
  if (income < 256500) return 31832.50 + (income - 117950) * 0.36;
  return 81710.50 + (income - 256500) * 0.396;
}

int main() {
  float income;
  scanf("%f", &income);
  printf("%f", signle_tex(income));
}
