#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include "trans.h"

jmp_buf restart;

int main() {
  int value = setjmp(restart);
  Trans* transaction;

  switch (setjmp(restart)) {
  default:
    fputs("Fatal error.\n", stderr);
    break;

  case 1:
    fputs("Invalid transaction.\n", stderr);
    /* FALL THOUGH */

  case 0:
    while ((transaction = get_trans()) != NULL) {
      process_trans(transaction);
    }
  }

  write_data_to_file();

  return value == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
