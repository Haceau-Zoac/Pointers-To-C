#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NodeTag {
  struct NodeTag* next;
  int data;
} Node;

bool append(Node* list, int const data) {
  while (list->next != NULL) {
    list = list->next;
  }
  list->next = malloc(sizeof(Node));
  if (list->next != NULL) {
    list->next->data = data;
    list->next->next = NULL;
    return true;
  } else {
    return false;
  }
}

int at(Node const* list, int index) {
  while (index-- > 0) {
    list = list->next;
  }
  return list->data;
}

Node* create_list(int data) {
  Node* list = malloc(sizeof(Node));
  if (list != NULL) {
    list->data = data;
    list->next = NULL;
  }
  return list;
}

void free_list(Node* list) {
  if (list->next != NULL) {
    free_list(list->next);
  }
  free(list);
}

int main() {
  Node* list = create_list(12);
  append(list, 55);
  append(list, 99);
  printf("%d\n", at(list, 1));
  free_list(list);
}
