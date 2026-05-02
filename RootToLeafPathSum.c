#include <stdio.h>
#include <stdlib.h>

int idx = 0;
int arr[100];

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode ->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void insertElm(int elm) {
    arr[idx++] = elm;
}

int findLeafNodes(struct node *root) {
    if(root == NULL) {
        return 0;
    } else if(root->left == NULL && root->right == NULL) {
        insertElm(root->data);
        return 1;
    }
    return findLeafNodes(root->left) + findLeafNodes(root->right);
}

int searchAndSum(struct node *root, int key, int sum) {
    if(root == NULL || root->data == key) {
        sum += root->data;
        return sum
    }
    if(key < root->data) {
        sum += root->data;
        return searchAndSum(root->left, key, sum);
    } else {
        sum += root->data;
        return searchAndSum(root->right, key, sum);
    }
}
struct node *insert(struct node *root, int val) {
    if(root == NULL) {
        return createNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    } else if(val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

int main() {
    int nodes, value;
    scanf("%d", &nodes);
    scanf("%d", &value);
    struct node *root = createNode(value);
    for(int i = 1 ; i < nodes ; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    findLeafNodes(root);
    int targetSum, found = 0;
    scanf("%d", &targetSum);
    for(int j = 0 ; j < idx ; j++) {
        int sum = 0;
        int result = searchAndSum(root, arr[j], sum);
        if(targetSum == result) {
            found = 1;
            break;
        }
    }
    if(found) {
        printf("true");

    } else {
        printf("false");
    }
}