#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  int count = 0;
  int c = 0;
  int in = 0;
  bool slash = false;
  while ((c = getchar()) != EOF)
  {
    if (in)
    {
      if ((in == '*' && (c = getchar()) == '//')
       || (in == c))
        in = 0;
      continue;
    }
    if (c == '//')
      slash = true;
    else if (slash)
      if (c == '*')
        in = '*';
      else
        slash = false;
    
    if (c == '{')
      --count;
    else if (c == '}')
      ++count;
  }
  if (count != 0)
    puts("WRONG!");
}