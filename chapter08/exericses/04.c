#include <stddef.h>
int identity_matrix(int** matrix, size_t size) {
  for (size_t i = 0; i < size; ++i)
    if (matrix[i][i] != 1)
      return 0;
  return 1;
}
