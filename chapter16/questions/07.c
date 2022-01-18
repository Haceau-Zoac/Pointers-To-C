#include <stdio.h>
#include <signal.h>

void on_sigfpe(int code) {
  puts("SIGFPE!!");
}

int main(void) {
  signal(SIGFPE, on_sigfpe);
  int a = 1 / 0;
  double b = 1.0 / 0;
  printf("a: %d, b: %lf", a, b);
}
