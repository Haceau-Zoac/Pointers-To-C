#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void weather(int precipitating, int temperature) {
  if (precipitating) {
    if (temperature < 32) {
      puts("snowing");
    } else {
      puts("raining");
    }
  } else {
    if (temperature < 60) {
      puts("cold");
    } else {
      puts("warm");
    }
  }
}

int main() {
  int precipitating, temperature;
  scanf("%d, %d", &precipitating, &temperature);
  weather(precipitating, temperature);
}
