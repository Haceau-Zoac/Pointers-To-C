#include <stdio.h>

int gcd(int m, int n) {
  if (m <= 0 || n <= 0) return 0;
  if (m % n == 0) return n;
  return gcd(n, m % n);
}

int main() {
  printf("gcd(3, 0): %d\n", gcd(3, 0));
  printf("gcd(-111, 72): %d\n", gcd(-111, 72));
  printf("gcd(92, 92): %d\n", gcd(92, 92));
  printf("gcd(12, 36): %d\n", gcd(12, 36));
  printf("gcd(97, 31): %d\n", gcd(97, 31));
}
