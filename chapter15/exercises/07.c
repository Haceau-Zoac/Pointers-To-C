#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_family_average_age(FILE* input) {
  char buf[64];

  while (fgets(buf, 64, input) != NULL) {
    int age[10] = { 0 }, count = 0;
    float ave = 0;

    for (char* token = strtok(buf, " \n\r\t");
               token!= NULL;
               token = strtok(NULL, " \n\r\t"), ++count) {
      age[count] = *token - '0';

      while (*++token != '\0') {
        age[count] = age[count] * 10 + *token - '0';
      }

      ave = (ave + age[count]) / (count + 1);
    }

    printf("%5.2f: ", ave);
    for (int i = 0; i < count; ++i)
      printf("%d ", age[i]);
    putchar('\n');
  }
}

int main() {
  FILE* input = fopen("07.txt", "r");
  if (input == NULL) {
    perror("07.txt");
    return EXIT_FAILURE;
  }
  
  print_family_average_age(input);

  fclose(input);
}
