#include <stdio.h>

int func(void) {
  static int counter = 1;
  return ++counter;
}

int main() {
  int answer;

  answer = func() - func() * func();
  printf("%d\n", answer);
}

/*
 * OUTPUT: -10(Clang)
 * 结果由实现定义
 * */
