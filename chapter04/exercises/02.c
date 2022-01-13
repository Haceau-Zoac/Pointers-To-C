#include <stdio.h>

int main() {
  for (int i = 1; i <= 100; ++i) {
    int is_prime = 1;
    for (int j = 2; j < i; ++j) {
      if (i % j == 0) {
        is_prime = 0;
      }
    }
    if (is_prime) {
      printf("%d ", i);
    }
  }
}
