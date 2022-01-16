#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list_node.h"

int dll_insert(Node* rootp, int value) {
  Node* this = rootp;
  Node* next = NULL;
  
  for (; (next = this->fwd) != NULL; this = next)
    if (next->value == value) return 0;
    else if (next->value > value) break;
  
  Node* newnode = (Node*)malloc(sizeof(Node));
  if (newnode == NULL) {
    return -1;
  }
  newnode->value = value;

  newnode->fwd = next;
  newnode->bwd = this == rootp ? NULL : this;
  this->fwd = newnode;
  (next ? next : rootp)->bwd = newnode;
  return 1;
}
