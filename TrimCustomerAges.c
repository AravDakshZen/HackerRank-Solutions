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

void preorder(struct node *root, int minValue, int maxValue) {
    if(root == NULL) {
        return;
    }
    if(root->data >= minValue && root->data <= maxValue) {
        printf("%d ", root->data);
    }
    preorder(root->left, minValue, maxValue);
    preorder(root->right, minValue, maxValue);
}

int main() {
    int nodes, value;
    scanf("%d %d", &nodes, &value);
    struct node *root = createNode(value);
    for(int i = 1 ; i < nodes ; i ++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    int minValue, maxValue;
    scanf("%d %d", &minValue, &maxValue);
    preorder(root, minValue, maxValue);
    return 0;
}