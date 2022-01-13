#include <stdio.h>

int store_bit_field(int original_value, int value_to_store,
    unsigned starting_bit, unsigned ending_bit) {
  unsigned mask = ~0;
  for (unsigned v = 1, i = 1; v != 0; v <<= 1) {
    if (i < ending_bit || i > starting_bit)
      mask &= 1;
    mask <<= 1;
  }

  original_value &= ~mask;
  value_to_store <<= ending_bit;
  value_to_store &= mask;
  return value_to_store | original_value;
}

int main() {
  printf("0x%x\n", store_bit_field(0x0, 0x1, 4, 4));
  printf("0x%x\n", store_bit_field(0xffff, 0x123, 15, 4));
  printf("0x%x\n", store_bit_field(0xffff, 0x123, 13, 9));
}
