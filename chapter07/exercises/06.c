#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void written_amount(unsigned amount, char* buffer);

char const* number_to_string(unsigned number) {
  static char const* ones[] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE",
  "TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN",
  "EIGHTEEN", "NINETEEN"
  };
  static char const* tens[] = {
    "TEN", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY",
  };
  if (number < 20) return ones[number];
  if (number >= 20 && number < 100) return tens[number / 10 - 1];
  if (number >= 100 && number < 1000) return "HUNDRED";
  if (number >= 1000 && number < 1000000) return "THOUSAND";
  return "MILLION";
}

void ten_to_string(unsigned number, char* buffer) {
  strcat(buffer, number_to_string(number));
  if (number % 10 != 0) {
    strcat(buffer, "-");
    strcat(buffer, number_to_string(number % 10));
  }
}

void hundred_to_string(unsigned number, char* buffer) {
  written_amount(number / 100, buffer);
  strcat(buffer, " HUNDRED");
  if (number % 100 != 0) {
    strcat(buffer, " ");
    written_amount(number % 100, buffer);
  }
}

void thousand_to_string(unsigned number, char* buffer) {
  written_amount(number / 1000, buffer);
  strcat(buffer, " THOUSAND");
  if (number % 1000 != 0) {
    strcat(buffer, " ");
    written_amount(number % 1000, buffer);
  }
}

void million_to_string(unsigned number, char* buffer) {
  written_amount(number / 1000000, buffer);
  strcat(buffer, " MILLION");
  if (number % 1000000 != 0) {
    strcat(buffer, " ");
    written_amount(number % 1000000, buffer);
  }
}

void written_amount(unsigned amount, char* buffer) {
  if (amount <= 20) {
    strcat(buffer, number_to_string(amount));
  } else if (amount < 100) {
    ten_to_string(amount, buffer);
  } else if (amount < 1000) {
    hundred_to_string(amount, buffer);
  } else if (amount < 1000000) {
    thousand_to_string(amount, buffer);
  } else {
    million_to_string(amount, buffer);
  }
}

void test(unsigned amount) {
  char buffer[1024] = { '\0' };
  written_amount(amount, buffer);
  printf("%u: %s\n", amount, buffer);
}

int main() {
  test(0);
  test(15);
  test(19);
  test(18);
  test(20);
  test(1);
  test(7);
  test(21);
  test(99);
  test(40);
  test(78);
  test(60);
  test(100);
  test(999);
  test(747);
  test(375);
  test(300);
  test(345);
  test(700);
  test(919);
  test(1000);
  test(9999);
  test(1114);
  test(9876);
  test(5000);
  test(11416);
  test(11418);
  test(50000);
  test(114514);
  test(114519);
  test(100000);
  test(999999);
  test(919810);
  test(1919810);
  test(1919811);
  test(16312);
  test(1200);
  unsigned val;
  scanf("%u", &val);
  test(val);
}
