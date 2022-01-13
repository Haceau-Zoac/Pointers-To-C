#include <stdio.h>
#include <time.h>

inline void iffunc(int a, int b, int c, int i) {
  if (a > 3)
    i = b + 1;
  else
    i = c * 5;
}

inline void sfunc(int a, int b, int c, int i) {
  i = a > 3 ? b + 1 : c * 5;
}

int main() {
  clock_t start = clock();
  for (size_t i = 0; i < 200000000; ++i)
    iffunc(i * 2, i - 2, i + 5, i);
  clock_t end = clock();
  double elpased = (double)(end - start) / CLK_TCK;
  printf("sfunc: %lf\n", elpased);

  start = clock();
  for (size_t i = 0; i < 200000000; ++i)
    iffunc(i * 2, i - 2, i + 5, i);
  end = clock();
  elpased = (double)(end - start) / CLK_TCK;
  printf("iffunc: %lf", elpased);
}
