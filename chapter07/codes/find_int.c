#include <stdio.h>

int* find_int(int key, int array[], int array_len) {
  for (int i = 0; i < array_len; ++i) 
    if (array[i] == key)
      return &array[i];
  return NULL;
}
