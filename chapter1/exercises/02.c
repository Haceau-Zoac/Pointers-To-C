/*
** 编写一个程序，从标准输入读取几行输入。
** 每行输入都要打印到标准输出上，前面要加上行号。
** 在编写整个程序时要试图让程序能够处理的输入行的长度没有限制。
*/
#include <stdio.h>

int main(void)
{
  char ch = 0;
  for (int i = 0; ch != EOF && (ch = getchar()) != EOF; ++i)
  {
    printf("%d ", i);
    do putchar(ch);
    while ((ch = getchar()) != '\n' && ch != EOF);
    putchar('\n');
  }
}