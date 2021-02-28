/*
** 这个程序从标准输入中读取输入行并在标准输出中打印这些输入行。
** 每个输入行的后面一行是该行内容的一部分。
**
** 输入的第 1 行是一串列标号，串的最后以一个负数结尾。
** 这些列标号成对出现，说明需要打印的输入行的列的范围。
** 例如，0 3 10 12 -1 表示第 0 列到第 3 列，第 10 列到第 12 列的内容将被打印。
**
**
** 修改 rearrange 程序，去处输入中列表号的个数必须是偶数的限制。
** 如果读入的列标号为奇数个，函数就会把最后一个列范围设置为最后一个列标号所指定的列到行尾之间的距离。
** 从最后一个列标号直至行尾的所有字符都将被复制到输出字符串。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS  20
#define MAX_INPUT 1000

int read_column_numbers(int columns[], int max);
void rearrange(char* output, char const* input,
    int n_columns, int const columns[]);

int main(void)
{
  int n_columns;          /* 进行处理的列标号 */
  int columns[MAX_COLS];  /* 需要处理的列数   */
  char input[MAX_INPUT];  /* 容纳输入行的数组 */
  char output[MAX_INPUT]; /* 容纳输入行的数组 */

  /*
  ** 读取该串列标号
  */
  n_columns = read_column_numbers(columns, MAX_COLS);

  /*
  ** 读取、处理和打印剩余的输入行。
  */
  while (fgets(input, MAX_INPUT, stdin) != NULL)
  {
    printf("Original input: %s\n", input);
    rearrange(output, input, n_columns, columns);
    printf("Rearranged line: %s\n", output);
  }

  return EXIT_SUCCESS;
}

/*
** 读取列标号，如果超出规定范围则不予理会。
*/
int read_column_numbers(int columns[], int max)
{
  int num = 0;
  int ch = 0;

  /*
  ** 取得列标号，如果所读取的数小于 0 则停止。
  */
  while (num < max && scanf_s("%d", &columns[num]) == 1
      && columns[num] >= 0)
    ++num;

  /*
  ** 确认已经读取的标号为偶数个，因为他们是以对的形式出现的。
  */
  if (!(num ^ 1))
  {
    columns[++num] = MAX_INPUT;
    exit(EXIT_FAILURE);
  }

  /*
  ** 丢弃该行中包含最后一个数字的那部分内容。
  */
  while ((ch = getchar()) != EOF && ch != '\n')
    ;

  return num;
}

/*
** 处理输入行，将指定列的字符连接在一起，输出行以 NUL 结尾。
*/
void rearrange(char* output, char const* input,
    int n_columns, int const columns[])
{
  int len = strlen(input);
  int output_col = 0;

  /*
  ** 处理每对列标号
  */
  for (int col = 0;
        col < n_columns
     && columns[col] < len
     && output_col != MAX_INPUT - 1;
       col += 2)
  {
    int nchars = columns[col + 1] - columns[col] + 1;

    /*
    ** 如果输入行数据空间不不够，只复制可以容纳的数据。
    */
    if (output_col + nchars > MAX_INPUT - 1)
      nchars = MAX_INPUT - output_col - 1;
    
    /*
    ** 复制相关的数据。
    */
    strncpy_s(output + output_col, MAX_INPUT - output_col,
      input + columns[col], nchars);
    output_col += nchars;
  }
  output[output_col] = '\0';
}