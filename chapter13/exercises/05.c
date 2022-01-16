#include <string.h>
#include <stdio.h>

int do_arg_call;
int illegal_arg_call;

char** do_args(int argc, char** argv, char const* control,
  void (*do_arg)(int ch, char* value), void (*illegal_arg)(int ch)) {
  while (*++argv != NULL && **argv == '-') {
    char ch;
    while ((ch = *++*argv) != '\0') {
      char* chr = strchr(control, ch);
      if (chr == NULL) {
        illegal_arg(ch);
      } else if (chr[1] != '+') {
        do_arg(ch, NULL);
      } else if (*++*argv != '\0') {
        do_arg(ch, *argv);
        break;
      } else if (*++argv == NULL) {
        illegal_arg(ch);
        goto ret;
      } else {
        do_arg(ch, *argv);
        break;
      } 
    }
  }
ret:
  return argv;
}

void do_arg(int ch, char* value) {
  ++do_arg_call;
  printf("DO_ARG: ch: %c, value: %s\n", ch, value ? value : "NULL");
}

void illegal_arg(int ch) {
  ++illegal_arg_call;
  printf("ILLEGAL_ARG: ch: %c\n", ch);
}

void test(int argc, char** argv, char const* control, int do_arg_expected, int illegal_arg_expected, char const* result_expected) {
  do_arg_call = 0; illegal_arg_call = 0;
  char* result = *do_args(argc, argv, control, do_arg, illegal_arg);
  printf("[%c] RETURNS: %s\n", result == result_expected ? 'v' : 'x', result ? result : "NULL");
  printf("[%c] do arg: %d, [%c] illegal arg: %d\n\n", do_arg_call == do_arg_expected ? 'v' : 'x', do_arg_call,
    illegal_arg_call == illegal_arg_expected ? 'v' : 'x', illegal_arg_call);
}

int main() {
  {
    char* argv[] = { "prog", "-x", "-y", "z", NULL };
    test(4, argv, "x", 1, 1, "z");
  }
  {
    char* argv[] = { "prog", "-x", "-y", "-z", NULL };
    test(4, argv, "x+y+z+", 1, 1, NULL);
  }
  {
    char* argv[] = { "prog", "-abcd", "-ef", "ghi", "jkl", NULL };
    test(5, argv, "ab+cdef+g", 4, 0, "jkl");
  }
  {
    char* argv[] = { "prog", "-a", "b", "-c", "-d", "-e", "-f", NULL };
    test(7, argv, "abcdef", 1, 0, "b");
  }
}
