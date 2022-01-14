long fibonacci(int n) {
  long result = 1, previous_result = 1;

  while (n-- > 2) {
    long next_older_result = previous_result;
    previous_result = result;
    result = previous_result + next_older_result;
  }

  return result;
}
