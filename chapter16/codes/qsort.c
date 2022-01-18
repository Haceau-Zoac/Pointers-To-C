#include <stdlib.h>
#include <string.h>

typedef struct {
  char key[10];
  int  other_data;
} Record;

int r_compare(void const* a, void const* b) {
  return strcmp(((Record*)a)->key, ((Record*)b)->key);
}

int main() {
  Record array[50];

  qsort(array, 50, sizeof(Record), r_compare);

  return EXIT_SUCCESS;1
}
