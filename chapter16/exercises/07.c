#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 52
#define TIMES 10000000

int main(void) {
  srand((unsigned)time(NULL));

  for (int i = 2; i <= MAX; ++i) {
    {
      int count[MAX] = { 0 };

      for (int j = 0; j < TIMES; ++j)
        ++count[rand() % i];
      for (int j = 0; j < i; ++j)
        printf("%d: %d\n", j, count[j]);
    }
    putchar('\n');
    putchar('\n');
    {
      int count[MAX][MAX] = { 0 };

      for (int j = 0, last = rand(), this = rand(); j < TIMES; ++j) {
        ++count[last % i][this % i];
        last = this;
        this = rand();
      }
      for (int j = 0; j < i; ++j) {
        for (int k = 0; k < i; ++k)
          printf("%3d ", count[j][k]);
        putchar('\n');
      }
    }
    putchar('\n');
    putchar('\n');
  }
  int last = rand(), this = rand();
  int mlast = last % 2, mthis = this % 2;
}
