#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf jbuf;

void set_buffer() {
  setjmp(jbuf);
}

int main(int argc, char* argv[]) {
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  set_buffer();
  printf("%d plus %d equals %d\n", a, b, a + b);
  longjmp(jbuf, 1);
  printf("After longjmp\n");
  return EXIT_SUCCESS;
}
