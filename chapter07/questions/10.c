#include <stdio.h>

int count;

int fibonacci(int n) {
  ++count;
  if (n <= 2) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  for (int i = 1; i < 10; ++i) {
    count = 0;
    int res = fibonacci(i);
    printf("Fibonacci(%d): %d(%d)\n", i, res, count);
  }

  puts("-----------------");

  long long result = 1, prev = 2, next = 0;
  for (int i = 3; i <= 50; ++i) {
    result += prev + next;
    long long tmp = prev;
    prev = next;
    next += tmp;
    printf("Fibonacci(%d): %lld\n", i, result);
  }
}
