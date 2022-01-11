/*
 * 在你的机器上，各种不同类型的浮点数的范围是怎样的？
 */
#include <float.h>
#include <stdio.h>

int main(void) {
  printf("      float: %f~%f\n", FLT_MIN, FLT_MAX);
  printf("     double: %lf~%lf\n", DBL_MIN, DBL_MAX);
  printf("long double: %llf~%llf\n", LDBL_MIN, LDBL_MAX);
}