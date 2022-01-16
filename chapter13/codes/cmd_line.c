#include <stdio.h>
#include <stdbool.h>

void process_standard_input(void);
void process_file(char* file_name);

struct {
  bool a;
  bool b;
} options;

int main(int argc, char* argv[]) {
  while (*++argv != NULL && **argv == '-') {
    switch (*++*argv) {
    case 'a':
      options.a = true;
      break;
    case 'b':
      options.b = true;
      break;
    }
  }

  if (*argv == NULL) {
    process_standard_input();
  } else {
    do {
      process_file(*argv);
    } while (*++argv != NULL);
  }
}
