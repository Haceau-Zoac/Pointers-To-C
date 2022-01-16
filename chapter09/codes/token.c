#include <stdio.h>
#include <string.h>

void print_tokens(char* line) {
  static char whitespace[] = " \t\f\r\v\n";
  
  for (char* token = strtok(line, whitespace);
    token != NULL;
    token = strtok(NULL, whitespace))
    printf("Next token is %s\n", token);
}

int main() {
  char line[1024];
  fgets(line, 1024, stdin);
  print_tokens(line);
}
