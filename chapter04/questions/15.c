#include <stdio.h>

int hungry_value = 0;

void eat_hamburger(void) {
  hungry_value += 10;
  printf("eat a hamburger, hungry_value: %d\n", hungry_value);
}

int hungry(void) {
  return hungry_value < 100;
}

int main() {
  do {
    eat_hamburger();
  } while (hungry());
  puts("FULL!");
}
