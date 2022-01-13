#include <stdio.h>
#include <string.h>

int substr(char dst[], char src[], int start, int len) {
  if (strlen(src) < start || start < 0 || len < 0) {
    dst[0] = '\0';
    return 0;
  }
  src += start;
  for (int i = 0; i < len; ++i) {
    *dst++ = *src++;
  }
  *dst = 0;
  return len;
}

int main() {
  char dst[1024];
  substr(dst, "1234567890", 5, 4);
  puts(dst);
  substr(dst, "12", -1, 99);
  puts(dst);
  substr(dst, "12345", 0, 5);
  puts(dst);
}
