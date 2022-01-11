#include <stdio.h>

void fun(void)
{
  int x = 0;
  printf("x1: %d\n", x);

  printf("x2: %d\n", x);
}

int main(void)
{
  fun(), fun();
}