int count_one_bits(unsigned value) {
  int ones;
  for (ones = 0; value != 0; value >>= 1) {
    if (value % 2 != 0) {
      ones += 1;
    }
  }
  return ones;
}
