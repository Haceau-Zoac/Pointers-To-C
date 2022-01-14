#include <stdio.h>

char* find_char(char const* source, char const* chars) {
  if (source == NULL || chars == NULL) {
    return NULL;
  }

  for (; *source != '\0'; ++source) {
    for (char const* finds = chars; *finds != '\0';) {
      if (*source == *finds++) {
        return (char*)source;
      }
    }
  }
  return NULL;
}

void test(char const* source, char const* chars) {
  printf("source: %s, chars: %s\n", source ? source : "NULL", chars ? chars : "NULL");
  char* result = find_char(source, chars);
  printf("result: %s\n\n", result ? result : "NULL");
}

int main() {
  test("ABCDEF", "XYZ");
  test("ABCDEF", "JURY");
  test("ABCDEF", "QQQQ");
  test("ABCDEF", "XRCQEF");
}
