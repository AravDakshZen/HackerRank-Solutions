#include <stdio.h>
  inorder(root->right);
}

struct node *createNode(int value) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = value;
  newnode->right = newnode->left = NULL;
  return newnode;
}

struct node *search(struct node *root, int key) {
  if(root == NULL || root->data == key) {
    return root;
  }
  if(key < root->data) {
    return search(root->left, key);
  } else {
    return search(root->right, key);
  }
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

int main() {
  int n, val, key;
  scanf("%d", &n);
  struct node *root = NULL;
  for(int i = 0 ; i < n ; i++) {
    scanf("%d", &val);
    root = insert(root, val);
  }
  scanf("%d", &key);
  struct node *found = search(root, key);
  if(found != NULL) {
    printf("Book found! Subtree rooted at %d:\n", key);
    inorder(found);
  } else {
    printf("Book not found\n");
  }
  return 0;
}
