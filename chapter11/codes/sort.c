#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

// call by "qsort"
int compare_integers(void const* a, void const* b) {
  register int const* pa = a;
  register int const* pb = b;

  return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}

int total_number_of_values() {
  int n_values;
  printf("How many values are there?");
  if (scanf("%d", &n_values) != 1 || n_values <= 0) {
    printf("Illegal number of values.\n");
    exit(EXIT_FAILURE);
  }
  return n_values;
}

int* alloc_memory(int n_values) {
  int* array = malloc(n_values * sizeof(int));
  if (array == NULL) {
    printf("Can't get memory for that many values.\n");
    exit(EXIT_FAILURE);
  }
  return array;
}

void read_values(int* array, int n_values) {
  for (int i = 0; i < n_values; ++i) {
    printf("? ");
    if (scanf("%d", array + i) != 1) {
      printf("Error reading value #%d\n", i);
      free(array);
      exit(EXIT_FAILURE);
    }
  }
}

void sort_values(int* array, int n_values) {
  qsort(array, n_values, sizeof(int), compare_integers);
}

void print_values(int* array, int n_values) {
  for (int i = 0; i < n_values; ++i)
    printf("%d\n", array[i]);
}

int main() {
  int n_values = total_number_of_values();
  int* values = alloc_memory(n_values);

  read_values(values, n_values);
  sort_values(values, n_values);
  print_values(values, n_values);

  free(values);
  return EXIT_SUCCESS;
}
