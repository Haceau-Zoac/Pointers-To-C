#include <ctype.h>
#include <string.h>
#include <stdio.h>

int palindrome(char* string) {
  for (char* last = string + strlen(string) - 1; last > string;) {
    if (!isalpha(*last)) {
      --last;
      continue;
    }
    if (!isalpha(*string)) {
      ++string;
      continue;
    }
    if (tolower(*last--) != tolower(*string++))
      return 0;
  }
  return 1;
}

int main() {
  printf("%d\n", palindrome((char*)"adam, I'm Ada"));
  printf("%d\n", palindrome((char*)"dam, I'm Ad"));
  printf("%d\n", palindrome((char*)"m, I'm "));
  printf("%d\n", palindrome((char*)"am, I'm Ada"));
  printf("%d\n", palindrome((char*)", I'"));
  printf("%d\n", palindrome((char*)"Madam, I'm Adam"));
  printf("%d\n", palindrome((char*)"Hello, Olleh"));
  printf("%d\n", palindrome((char*)"这's 是 a pas'"));
  printf("%d\n", palindrome((char*)"It's not a palindrome."));
  printf("%d\n", palindrome((char*)"a"));
}
