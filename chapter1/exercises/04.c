/*
** 编写一个程序，一行行地读取输入行，直至到达文件尾。
** 算出每行输入行的长度，然后把最长的那行打印出来。
** 为了简单起见，你可以假定所有的输入行均不超过 1000 个字符。
*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1001

int getline(char* line, int lim);

int main(void)
{
  int len = MAXLINE;
  int tlen = 0;
  char line[MAXLINE] = "";
  char tline[MAXLINE];
  while ((tlen = getline(tline, MAXLINE)) >= 0)
    if (tlen < len)
      strcpy_s(line, MAXLINE, tline);
  puts(line);

  return 0;
}

int getline(char* line, int lim)
{
  while (lim-- > 1 && (*line = getchar()) != EOF && *line != '\n')
    ++line;
  if (*line == '\n')
    ++line;
  else if (*line == EOF)
    lim = -1;
  *line = '\0';
  return lim;
}