unsigned int reverse_bits(unsigned int value) {
  unsigned ans = 0;
  for (unsigned i = 1; i != 0; i <<= 1) {
    ans <<= 1;
    if (value & 1)
      ans |= 1;
    value >>= 1;
  }
  return ans;
}
