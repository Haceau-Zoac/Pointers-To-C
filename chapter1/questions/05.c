/*
** 编写一条 scanf 语句，他需要读取两个整数，
** 分别保存于 quantity 和 price 变量，
** 然后再读取一个字符串，
** 保存在一个名叫 department 的字符数组中。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define DEPARTMENT_LEN 1024

int main(void)
{
  int quantity = 0, price = 0;
  char department[DEPARTMENT_LEN] = { 0 };

  scanf("%d %d", &quantity, &price);
  printf("%d %d %s\n", quantity, price,
    (fgets(department, DEPARTMENT_LEN, stdin) == NULL) ? "" : department);
}