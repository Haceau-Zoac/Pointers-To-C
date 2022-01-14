#include <stdio.h>

int hermite_polynomials(int n, int x) {
  if (n <= 0) return 1;
  if (n == 1) return 2 * x;
  if (n >= 2) return 2 * x * hermite_polynomials(n - 1, x)
    - 2 * (n - 1) * hermite_polynomials(n - 2, x);
  return 0;
}

int main() {
  printf("H3(2): %d", hermite_polynomials(3, 2));
}
