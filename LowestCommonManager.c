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

struct node *insert(struct node *root, int value) {
    if(root == NULL) {
        return createNode(value);
    }
    if(value < root->data) {
        root->left = insert(root->left, value);
    } else if(value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

struct node *search(struct node *root, int leftValue, int rightValue) {
    if(root == NULL) {
        return NULL;
    }
    if(leftValue < root->data && rightValue < root->data) {
        return search(root->left, leftValue, rightValue);
    }
    if(leftValue > root->data && rightValue > root->data) {
        return search(root->right, leftValue, rightValue);
    }
    return root;
}

int main() {
    int nodes, value;
    scanf("%d %d", &nodes, &value);
    struct node *root = createNode(value);
    for(int i = 1 ; i < nodes ; i ++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    int leftValue, rightValue;
    scanf("%d %d", &leftValue, &rightValue);
    struct node *least = search(root, leftValue, rightValue);
    printf("%d", least->data);
    return 0;
}