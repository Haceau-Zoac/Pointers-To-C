#include <stdio.h>

#define MAX_LINE 80

int main() {
  char buffer[MAX_LINE + 2];

  while (fgets(buffer, MAX_LINE, stdin) != NULL) {
    puts(buffer);
  }
}
