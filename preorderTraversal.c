#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct noed *right;
};

void preorder(struct node *root) {
  if(root == NULL) {
    return;
  } 
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

struct node *createnode(int value) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = value;
  newnode->right = newnode->left = NULL;
  return newnode;
}

struct node *insert(struct node *root, int value) {
  if(root == NULL) {
    return createnode(value);
  } else if(value < root->data) {
    root->left = insert(root->left, value);
  } else if(value > root->data) {
    root->right = insert(root->right, value);
  }
  return root;
}

int main() {
  int num, val;
  scanf("%d", &num);
  scanf("%d", &val);

  struct node *root = createnode(val);
  for(int i = 1 ; i < num ; i++) {
    scanf("%d", &val);
    root = insert(root, val);
  }
  preorder(root);
  return 0;
}
