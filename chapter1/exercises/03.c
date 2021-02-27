/*
** 编写一个程序，从标准输入读取一些字符，并把它们写到标准输出上。
** 它同时应该计算 checksum 值，并且在字符的后面。
**
** checksum（校验和）用一个 signed char 类型的变量进行计算，它初始化为 -1。
** 当每个字符从标准输入读取时，它的值就被加到 checksum 中。
** 如果 checksum 变量产生了溢出，那么这些溢出就会被忽略。
** 当所有的字符均被写入后，程序以十进制整数的形式打印出 checksum 的值，他有可能是负值。
** 注意在 checksum 后面要添加一个换行符。
** 在使用 ASCII 码的计算机中，在包含 “Hello world!” 这几个词并以换行符结尾的文件上运行这个程序应该产生下列输出：
**   Hello world!
**   102
*/
#include <stdio.h>

int main(void)
{
  signed char checksum = -1;
  char ch = 0;
  while ((ch = getchar()) != EOF && ch != '\n')
  {
    checksum += ch;
    putchar(ch);
  }
  checksum += ch;
  printf("\n%d\n", checksum);

  return 0;
}