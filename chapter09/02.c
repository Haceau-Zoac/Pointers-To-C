#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#define MAXSIZE 8

size_t my_strlen(char const* string, size_t length) {
  size_t count = 0;
  while (*string++ != '\0' && count < length)
    ++count;
  return count;
}

int main() {
  char string[MAXSIZE];
  strncpy(string, "Hello", MAXSIZE);
  printf("%u\n", my_strlen(string, MAXSIZE));
  strncpy(string, "Hello world!!", MAXSIZE);
  printf("%u\n", my_strlen(string, MAXSIZE));
}
