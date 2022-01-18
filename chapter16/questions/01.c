#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("%ld", strtol("12345", NULL, -5));
}
