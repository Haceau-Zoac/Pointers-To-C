#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define DELTA 100

int* read_ints() {
  int size = DELTA;
  int* array = malloc((size + 1) * sizeof(int));
  if (array != NULL) {
    int count = 0;
    int value;
    while (scanf("%d", &value) == 1) {
      ++count;
      if (count > size) {
        size += DELTA;
        array = realloc(array,
          (size + 1) * sizeof(int));
        if (array == NULL)
          break;
      }
      array[count] = value;
    }
    if (count < size)
      array = realloc(array, (count + 1) * sizeof(int));
    if (array != NULL)
      array[0] = count;
  }
  return array;
}
