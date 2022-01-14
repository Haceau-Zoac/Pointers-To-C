#include <stdio.h>

int main(void) {
  int lst[1000] = { 0 };
  for (int i = 3, *finds = lst; i <= 2001; i += 2, ++finds)
    if (!*finds)
      for (int* arr = finds + i; arr < &lst[1000]; arr += i)
        *arr = 1;
  puts("2");
  for (int* finds = lst; finds != &lst[1000]; ++finds)
    if (!*finds)
      printf("%d\n", (finds - lst + 1) * 2 + 1);
}
