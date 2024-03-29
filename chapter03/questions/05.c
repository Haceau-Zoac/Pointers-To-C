#include <stdio.h>

// 不同编译器结果可能不同

int main(void) {
  double d = 1.0;
  float f = d;
  printf("%f\n", f);

  d = 1145141919810.;
  f = d;
  printf("%f\n", f);

  d = 179769313486231570814527423731704356798070567525844996598917.;
  f = d;
  printf("%f\n", f);
}

/* 编译（/W3）：
 * (8): warning C4242: “初始化”: 从“double”转换到“float”，可能丢失数据
 * (12): warning C4242: “=”: 从“double”转换到“float”，可能丢失数据
 * (15): warning C4244: “=”: 从“double”转换到“float”，可能丢失数据
*/

/* 运行：溢出
 * 1.000000
 * 1145141985280.000000
 * inf
*/