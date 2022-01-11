#include <stdio.h>

enum coins
{
  PENNY  = 1,
  NICKEL = 5
};

void print_coin(enum coins coin)
{
  switch (coin)
  {
  case PENNY:
    printf("It's 1 cent.\n");
    break;
  case NICKEL:
    printf("It's 5 cent.\n");
    break;
  default:
    printf("Unknown coin.\n");
    break;
  }
}

int main(void) {
  enum coins coin = PENNY;
  print_coin(coin);

  coin = NICKEL;
  print_coin(coin);
}