#include <stdio.h>

int main(void)
{
  int count = 0;
  int c = 0;
  while ((c = getchar()) != EOF)
    if (c == '{')
      --count;
    else if (c == '}')
      ++count;
  if (count != 0)
    puts("WRONG!");
}