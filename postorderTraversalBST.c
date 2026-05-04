#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int value) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = value;
  newnode->left = newnode->right = NULL;
  return newnode;
}

struct node *insert(struct node *root, int val) {
  if(root == NULL) {
    return createNode(val);
  } else if(val < root->data) {
    root->left = insert(root->left, val);
  } else if(val > root->data) {
    root->right = insert(root->right,  val);
  }
  return root;
}
void postorder(struct node *root) {
  if(root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

int main() {
  int num;
  scanf("%d", &num);
  int val;
  scanf("%d", &val);
  struct node *root = createNode(val);
  for(int i = 1 ; i < num  ; i++) {
    scanf("%d", &val);
    root = insert(root, val);
  }
  postorder(root);
  return 0;
}
