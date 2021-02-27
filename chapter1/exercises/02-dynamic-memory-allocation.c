/*
** 编写一个程序，从标准输入读取几行输入。
** 每行输入都要打印到标准输出上，前面要加上行号。
** 在编写整个程序时要试图让程序能够处理的输入行的长度没有限制。
*/
#include <stdio.h>
#include <stdlib.h>

long long getlines(char** lines[]);
long long getline(char* line[]);
void freelines(char** lines[], long long nlines);
void freeline(char* line[]);
void printlines(char* lines[], long long nlines);

int main(void)
{
  char** lines = NULL;
  long long nlines = getlines(&lines);
  printlines(lines, nlines);
  freelines(&lines, nlines);

  return EXIT_SUCCESS;
}

long long getlines(char** lines[])
{
  *lines = (char**)calloc(1, sizeof(char*));
  long long nlines = 0;
  long long cap = 1;
  while (getline(&((*lines)[nlines])) > 0)
  {
    if (++nlines >= cap)
    {
      char** newlines = (char**)realloc(*lines, sizeof(char*) * (cap *= 2));
      if (newlines == NULL)
      {
        free(*lines);
        *lines = NULL;
        return -1;
      }
      *lines = newlines;
    }
  }
  return nlines;
}

long long getline(char* line[])
{
  *line = (char*)calloc(1 + 1, sizeof(char));
  if (*line == NULL)
    return -1;
  long long nchars = 0;
  long long cap = 1;
  while (((*line)[nchars] = getchar()) != EOF && (*line)[nchars++] != '\n')
  {
    if (nchars >= cap)
    {
      char* newline = (char*)realloc(*line, sizeof(char) * ((cap *= 2) + 1));
      if (newline == NULL)
      {
        free(*line);
        *line = NULL;
        return -1;
      }
      *line = newline;
    }
  }
  (*line)[nchars] = '\0';
  return nchars;
}

void freelines(char** lines[], long long nlines)
{
  while (nlines-- > 0)
  {
    freeline(*lines);
    *lines++ = NULL;
  }
}

void freeline(char* line[])
{
  if (line != NULL)
  {
    free(*line);
    *line = NULL;
  }
}

void printlines(char* lines[], long long nlines)
{
  for (int i = 0; i < nlines; ++i)
    printf("%d %s", i + 1, lines[i]);
}