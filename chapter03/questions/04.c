#include <limits.h>
#include <stdio.h>

// 不同编译器结果可能不同

int main(void)
{
  long l = 10;
  short s = l;
  printf("%d\n", s);
  l = LONG_MAX;
  s = l;
  printf("%d\n", s);
}

/* 编译（/W3）：
 * (9): warning C4242: “初始化”: 从“long”转换到“short”，可能丢失数据
 * (12): warning C4242: “=”: 从“long”转换到“short”，可能丢失数据
*/

/* 运行：溢出
 * 10
 * -1
*/