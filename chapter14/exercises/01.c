#include <stdio.h>

void print_ledger_long(int arg) {
  printf("print_ledger_long: %d\n", arg);
}

void print_ledger_detailed(int arg) {
  printf("print_ledger_detailed: %d\n", arg);
}

void print_ledger_default(int arg) {
  printf("print_ledger_default: %d\n", arg);
}

void print_ledger(int arg) {
#ifdef        OPTION_LONG
  print_ledger_long(arg);
#elif defined(OPTION_DETAILED)
  print_ledger_detailed(arg);
#else      /* OPTION_NO */
  print_ledger_default(arg);
#endif     /* OPTION_LONG */
}

int main() {
  print_ledger(12);
}
