#include <stdio.h>
#include <stdlib.h>

int i = 0, nums[100];

struct node {
  int data;
  struct node *right;
  struct node *left;
};

struct node *createNode(int val) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = val;
  newnode->right = newnode->left = NULL;
  return newnode;
}

struct node *insert(struct node *root, int val) {
  if(root == NULL) {
  return createNode(val) ;
  if(val < root->data) {
  root->left = insert(root->left, val);
  } else if(val > root->data) {
  root->right = insert(root->right, val);
  return root;
}

void insertInArray(int val, int nums[]){
nums[i++] = val;

}

void inorder(struct node *root) {
  if(root == NULL) {
  return;
  inorder (root->left);
  insertInArray(root->data, nums);
  inorder (root->right);
}

int main() {
  int nodes;
  scanf("%d", &nodes);
  int value;
  scanf("%d", &value);
  struct node *root = createNode (value);
  for(int i = 1; i < nodes ; i++) {
    scanf("%d", &value);
    root = insert(root, value);
  }
  inorder (root);
  int num;
  scanf("%d", &num);
  int found = 0, j, idx;
  for(idx= 0; idx < i; idx++) {
    if(nums[idx] == num) {
      j = idx + 1;
      found = 1;
      break;
      }
  }
  if(found && j < i) {
    printf("%d", nums[j]);
  } else {
    printf("No Inorder Successor");
  }
  return 0;
}
