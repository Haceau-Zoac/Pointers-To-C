#include <stdio.h>
#include <ctype.h>

int ascii_to_integer(char* string) {
  int result = 0;
  int ch;
  while ((ch = *string++) != '\0') {
    if (!isdigit(ch)) {
      return 0;
    }
    result = result * 10 + ch - '0';
  }

  return result;
}

int main() {
  char s1[] = "114514";
  printf("114514: %d\n", ascii_to_integer(s1));
  char s2[] = "1145I4";
  printf("1145I4: %d\n", ascii_to_integer(s2));
  char s3[] = "1919810";
  printf("1919810: %d\n", ascii_to_integer(s3));
}
