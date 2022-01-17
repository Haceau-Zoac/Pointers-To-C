#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  int exit_status = EXIT_SUCCESS;
  
  while (*++argv != NULL) {
    FILE* input = fopen(*argv, "r");
    if (input == NULL) {
      perror(*argv);
      exit_status = EXIT_FAILURE;
      continue;
    }

    // do something...

    if (fclose(input) != 0) {
      perror("fclose");
      exit(EXIT_FAILURE);
    }
  }

  return exit_status;
}
