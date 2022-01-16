#include <stdio.h>
#include "singly_linked_list_node.h"

Node* node_find(Node* node, int value) {
  for (; node != NULL; node = node->link)
    if (node->value == value)
      return node;
  return NULL;
}

int main() {
  Node n1 = { NULL, 12 };
  Node n2 = { &n1, 23 };
  Node n3 = { &n2, 34 };
  Node* found = node_find(&n3, 23);
  printf("%sfound: %d", found ? "" : "not ", found ? found->value : 0);
}
