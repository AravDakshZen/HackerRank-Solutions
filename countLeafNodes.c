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

struct node *insert(struct node *root, int val) {
  if(root == NULL) {
    return createNode(val);
  }
  if(val < root->data) {
    root->left = insert(root->left, val);
  } else if( val > root->data) {
    root->right = insert(root->right, val);
  }
  return root;
}

int countLeafNodes(struct node *root) {
  if(root == NULL) {
    return 0;
  } else if(root->left == NULL && root->left == NULL) {
    return 1;
  }
  return countLeafNodes(root->left) + countLeafNodes(root->right);
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
  printf("%d", countLeafNodes(root));
  return 0;
}
