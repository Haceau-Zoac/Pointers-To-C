#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(void* array, size_t count, size_t length, int (*callback)(void* lhs, void* rhs)) {
  for (int i = 0; i < count - 1; ++i) {
    for (int j = i + 1; j < count; ++j) {
      if (callback(array + i * length, array + j * length) > 0) {
        void* tmp = malloc(length);
        if (tmp == NULL) return;
        memcpy(tmp, array + i * length, length);
        memcpy(array + i * length, array + j * length, length);
        memcpy(array + j * length, tmp, length);
        free(tmp);
      }
    }
  }
}

int compare(void* lhs, void* rhs) {
  return *(int*)lhs - *(int*)rhs;
}

int main() {
  int ints[] = { 1, 9, 8, 0, -9, 56, 33 };
  sort(ints, sizeof(ints) / sizeof(ints[0]), sizeof(int), compare);
  for (int i = 0; i < sizeof(ints) / sizeof(ints[0]); ++i)
    printf("%d ", ints[i]);
}
