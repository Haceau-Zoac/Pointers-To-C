#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ask(int which_word) {
  if (which_word < 1 || which_word > 5) {
    puts("don't know");
    return;
  }
  char const* questions[5] = { "who", "what", "when", "where", "why" };
  puts(questions[which_word - 1]);
}

int main() {
  int which_word;
  scanf("%d", &which_word);
  ask(which_word);
}
  
