#include <stdio.h>

typedef struct Node {
  struct Node* link;
  int value;
} Node;

int node_count(Node* node) {
  int count = 0;
  while (node != NULL) {
    ++count;
    node = node->link;
  }
  return count;
}

int main() {
  Node n1 = { NULL, 22 };
  Node n2 = { &n1, 23 };
  Node n3 = { &n2, 24 };
  printf("%d", node_count(&n3));
}
