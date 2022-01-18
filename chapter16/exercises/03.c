#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main(void) {
  time_t now = time(NULL); 
  struct tm* tm = localtime(&now);

  printf("时针在 %d 上面，分针在 %d 上面", (tm->tm_hour + 1) % 2, (tm->tm_min + 1) / 5);
}
