#include <stdio.h>

int main() {
  int val = -1;
  val >>= 1;
  if (val == -1) {
    puts("算术移位");
  } else {
    puts("逻辑移位");
  }
}
