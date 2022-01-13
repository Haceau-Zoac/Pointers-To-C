#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int a1, a2, a3;
  scanf("%d %d %d", &a1, &a2, &a3);

  if ((a1 + a2 <= a3) || (a1 + a3 <= a2) || (a2 + a3 <= a1)) {
    puts("not a triangle");
  } else if (a1 == a2 && a2 == a3) {
    puts("equilateral triangle");
  } else if (a1 != a2 && a1 != a3 && a2 != a3) {
    puts("scalene triangle");
  } else {
    puts("isosceles triangle");
  }
}
