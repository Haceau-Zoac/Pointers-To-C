#include <stdio.h>

int identity_matrix(int matrix[][10]) {
  for (int i = 0; i < 10; ++i)
    if (matrix[i][i] != 1)
      return 0;
  return 1;
}

void test(int matrix[][10], int expected) {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      printf("%d ", matrix[i][j]);
    }
    putchar('\n');
  }
  printf("%c.\n", identity_matrix(matrix) == expected ? 'v' : 'x');
}

int main() {
  {
    int matrix[][10] = {
      { 1 },
      { 0, 1 },
      { 0, 0, 1 },
      { 0, 0, 0, 1 },
      { 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    };
    test(matrix, 1);
  }
  {
    int matrix[][10] = { 0 };
    test(matrix, 0);
  }
  {
    int matrix[][10] = {
      { 1 },
      { 0, 1 },
      { 0, 0, 1 },
      { 0, 0, 0, 1 },
      { 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 1 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
    };
    test(matrix, 0);
  }
}
