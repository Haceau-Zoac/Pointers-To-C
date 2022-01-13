#include <stdio.h>
#include <string.h>

void copy_n(char dst[], char src[], int n) {
  while ((*dst++ = *src++) != '\0' && (--n > 0))
    ;
  while (n-- > 0)
    *dst++ = '\0';
}

int main() {
  char dst[1024];
  copy_n(dst, "123456789", 5);
  dst[5] = '\0';
  printf("%d\n", strcmp(dst, "12345"));
  copy_n(dst, "1", 5);
  printf("%d, %d, %d, %d, %d\n", dst[0] == '1', dst[1] == 0, dst[2] == 0,
      dst[3] == 0, dst[4] == 0);
}
