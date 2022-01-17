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
#ifdef    OPTION_LONG
#define   OK 1
  print_ledger_long(arg);
#endif /* OPTION_LONG */
  
#ifdef    OPTION_DETAILED
#define   OK 1
  print_ledger_detailed(arg);
#endif /* OPTION_DETAILED */

#ifndef OK
  print_ledger_default(arg);
#endif
}

int main() {
  print_ledger(12);
}
