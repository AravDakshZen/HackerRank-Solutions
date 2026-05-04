#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int val) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = val;
  newnode->left = newnode->right = NULL;
  return newnode;
}

/* void leftview(struct node *root, int level, int *maxLevel) {
  if(root == NULL)
    return;
  if(level > *maxLevel) {
    printf("%d\n", root->data);
    *maxLevel = level;
  }
  leftview(root->left, level + 1, maxLevel);
  leftview(root->right, level + 1, maxLevel);
} */

struct node *insert(struct node *root, int val) {
  if(root == NULL) {
    return createNode(val);
  }
  if(val < root->data) {
    root->left = insert(root->left, val);
  } else if(val > root->data) {
    root->right = insert(root->right, val);
  }
  return root;
}

int main() {
  int num, val;
  scanf("%d", &num);
  scanf("%d", &val);
  struct node *root = createNode(val);
  for(int i = 1 ; i < num ; i++) {
    scanf("%d", &val);
    root = insert(root, val);
  }
  // int maxLevel = 0;
  // leftview(root, 1, &maxLevel);
  while(root != NULL) {
    printf("%d\n", root->data);
    root = root->left;
  }
  return 0;
}
