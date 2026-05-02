#include <stdio.h>
#include <stdlib.h>

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

struct node *findLeast(struct node *root) {
    while(1) {
        if(root->left != NULL) {
            root = root->left;
        } else {
            break;
        }
    }
    return root;
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
    struct node *leastElm = findLeast(root);
    printf("%d", leastElm->data);
    return 0;
}