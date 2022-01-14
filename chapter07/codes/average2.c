#include <stdarg.h>

float average(int n_values, ...) {
  va_list var_arg;
  float sum = 0;

  va_start(var_arg, n_values);
  for (int count = 0; count < n_values; ++count) {
    sum += va_arg(var_arg, int);
  }

  va_end(var_arg);

  return sum / n_values;
}
