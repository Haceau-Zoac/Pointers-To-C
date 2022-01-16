#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
  int count = 0;
  char input[128] = { 0 };
  fgets(input, 128, stdin);
  if (strcmp(strtok(input, " \t\n\r"), "the") == 0)
    ++count;
  char* token = NULL;
  while ((token = strtok(NULL, " \t\r\n")) != NULL)
    if (strcmp(token, "the") == 0)
      ++count;
  printf("%d\n", count);
}
