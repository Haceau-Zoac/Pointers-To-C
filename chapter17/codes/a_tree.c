#include "tree.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE + 1)

typedef struct TREE_NODE {
  TREE_TYPE value;
  struct TREE_NODE* left;
  struct TREE_NODE* right;
} TreeNode;

static TreeNode tree[ARRAY_SIZE];

static int left_child(int current) {
  return current * 2;
}

static int right_child(int current) {
  return current * 2 + 1;
}

void insert(TREE_TYPE value) {
  TreeNode* current;
  TreeNode** link = (TreeNode**)&tree;

  while ((current = *link) != NULL) {
    if (value < current->value) {
      link = &current->left;
    } else {
      assert(value != current->value);
      link = &current->right;
    }
  }

  current = malloc(sizeof(TreeNode));
  assert(current != NULL);
  current->value = value;
  current->left = NULL;
  current->right = NULL;
  *link = current;
}

TREE_TYPE* find(TREE_TYPE value) {
  TreeNode* current = tree;

  while (current != NULL && current->value != value) {
    if (value < current->value) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  return current ? &current->value : NULL;
}

static void do_pre_order_traverse(TreeNode* current, void (*callback)(TREE_TYPE value)) {
  if (current != NULL) {
    callback(current->value);
    do_pre_order_traverse(current->left, callback);
    do_pre_order_traverse(current->right, callback);
  }
}

void pre_order_traverse(void (*callback)(TREE_TYPE value)) {
  do_pre_order_traverse(tree, callback);
}
