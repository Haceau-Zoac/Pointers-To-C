#include <stdio.h>
#include "student_info.h"

int read_random_record(FILE* f, size_t rec_number, StudentInfo* buffer) {
  fseek(f, (long)rec_number * sizeof(StudentInfo), SEEK_SET);
  return fread(buffer, sizeof(StudentInfo), 1, f);
}
