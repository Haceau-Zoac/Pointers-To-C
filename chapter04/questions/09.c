#include <stdio.h>

int main() {
  for (int i = 1; i <= 4; i += 1) {
    switch (i % 2) {
    case 0:
      printf("even\n");
    case 1:
      printf("odd\n");
    }
  }
}

/*
odd
even
odd
odd
even
odd
*/
