#include "addrlist.h"
#include <stdio.h>

static char name[MAX_ADDRESSES][NAME_LENGTH];
static char address[MAX_ADDRESSES][ADDR_LENGTH];
static char phone[MAX_ADDRESSES][PHONE_LENGTH];

static int find_entry(char const* name_to_find) {
  for (int entry = 0; entry < MAX_ADDRESSES; ++entry)
    if (strcmp(name_to_find, name[entry]) == 0)
      return entry;
  return -1;
}

char const* lookup_address(char const* name) {
  int entry = find_entry(name);
  return entry == -1 ? NULL : address[entry];
}

char const* lookup_phone(char const* name) {
  int entry = find_entry(name);
  return entry == -1 ? NULL : address[entry];
}
