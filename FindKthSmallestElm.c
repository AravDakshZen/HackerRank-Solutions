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
        return createNode(val);
    }
    if(val < root->data) {
        root->left = insert(root->left, val);
    } else if(val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

void insertInArray(int val, int nums[]){
    nums[i++] = val;
}

void inorder(struct node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    insertInArray(root->data, nums);
    inorder(root->right);
}

int main() {
    int nodes;
    scanf("%d", &nodes);
    int value;
    scanf("%d", &value);
    struct node *root = createNode(value);
    for(int i = 1 ; i < nodes ; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    int pos;
    scanf("%d", &pos);
    inorder(root);
    printf("%d", nums[pos - 1]);
    return 0;
}