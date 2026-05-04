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

struct node *insert(struct node *root, int value) {
  if(root == NULL) {
    return createNode(value);
  } else if(value < root->data) {
    root->left = insert(root->left, value);
  } else if(value > root->data) {
    root->right = insert(root->right, value);
  }
  return root;
}

void inorder(struct node *root) {
  struct node *temp = root;
  if(root == NULL)
    return;
  inorder(root->left);
  printf("%d ", temp->data);
  inorder(root->right);
}

int main() {
  int num;
  scanf("%d", &num);
  int value;
  scanf("%d", &value);
  struct node *root = createNode(value);
  for(int i = 1 ; i < num ; i++){
    scanf("%d", &value);
    root = insert(root, value);
  }
  inorder(root);
  return 0;
}
