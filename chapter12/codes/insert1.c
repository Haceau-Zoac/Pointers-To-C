#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sll_node.h"

bool sll_insert(Node* current, int new_value) {
  Node* previous = NULL;

  while (current->value < new_value) {
    previous = current;
    current = current->link;
  }

  Node* new = (Node*)malloc(sizeof(Node));
  if (new == NULL) {
    return false;
  }
  new->value = new_value;

  new->link = current;
  previous->link = new;
  return true;
}

