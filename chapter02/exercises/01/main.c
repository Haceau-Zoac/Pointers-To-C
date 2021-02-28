#include <stdio.h>
#include "increment.h"
#include "negate.h"

int main(void)
{
  long long ret = increment(10);
  printf("[increment] %c | num: 10 | output: %lld\n", 
    (ret == 11) ? 'v' : 'x', ret);
  ret = increment(0);
  printf("[increment] %c | num: 0 | output: %lld\n", 
    (ret == 1) ? 'v' : 'x', ret);
  ret = increment(-10);
  printf("[increment] %c | num: -10 | output: %lld\n\n", 
    (ret == -9) ? 'v' : 'x', ret);
  
  ret = negate(10);
  printf("[negate] %c | num: 10 | output: %lld\n", 
    (ret == -10) ? 'v' : 'x', ret);
  ret = negate(0);
  printf("[negate] %c | num: 0 | output: %lld\n", 
    (ret == 0) ? 'v' : 'x', ret);
  ret = negate(-10);
  printf("[negate] %c | num: -10 | output: %lld\n\n", 
    (ret == 10) ? 'v' : 'x', ret);
}