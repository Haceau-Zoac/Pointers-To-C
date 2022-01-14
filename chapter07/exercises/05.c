#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

void print_integer(int value) {
  printf("%d", value);
}

void print_float(double value) {
  printf("%f", value);
}

void my_printf(char const* restrict format, ...) {
  // UNSUPPORT to return the number of characters transmitted to the output stream.
  va_list args;

  va_start(args, format);
  char ch;
  while ((ch = *format++) != '\0') {
    if (ch == '%') {
      switch ((ch = *format++)) {
      case 'd':
        print_integer(va_arg(args, int));
        break;
      case 'f':
        print_float(va_arg(args, double));
        break;
      case 's': {
        char const* str = va_arg(args, char const*);
        while (*str != '\0')
          putchar(*str++);
        break;
      }
      case 'c':
        putchar(va_arg(args, int));
        break;
      }
    }
    else putchar(ch);
  }
  va_end(args);
}

int main() {
  my_printf("Hello, %s!\n", "world");
  my_printf("There are %d people in %cy %s.\n", 4, 'm', "family");
  my_printf("%c%c%c%f\n", 'P', 'I', ':', 3.14);
  my_printf("\n%s\n", "Is it OK?");
  my_printf("%s.", "oh");
}
