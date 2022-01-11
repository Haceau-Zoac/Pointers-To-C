#include <stdio.h>

enum Liquid { OUNCE = 1, CUP = 8, PINT = 16,
  QUART = 32, GALLON = 128 };
enum Liquid jar;

int main(void)
{
  jar = QUART;
  printf("%s\n", jar);
  jar = jar + PINT;
  printf("%s\n", jar);
}

// NO OUTPUT.