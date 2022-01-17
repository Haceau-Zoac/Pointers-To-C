#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define BUFFER_SIZE 100

void function(FILE* input) {
  char buffer[BUFFER_SIZE];

  while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
    int a, b, c, d, e;

    if (sscanf(buffer, "%d %d %d %d %d", &a, &b, &c, &d, &e) != 4) {
      fprintf(stderr, "Bad input skipped: %s", buffer);
      continue;
    }

    /* do something */
  }
}
