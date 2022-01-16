#include <stdio.h>
char* my_strcpy_end(char* dest, char const* src) {
  while ((*dest++ = *src++) != '\0')
    ;
  return --dest;
}

int main() {
  char buf[1024] = { 0 };
  my_strcpy_end(my_strcpy_end(my_strcpy_end(buf, "1234"), "5678"), "9012");
  puts(buf);
}
