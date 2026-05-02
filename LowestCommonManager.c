/*Find the Lowest Common Manager in a BST
A company stores employee IDs in a Binary Search Tree (BST) to manage its hierarchy in an organized way.Sometimes, the company wants to find the lowest common manager of two employees. 
This means the lowest node in the tree from which both employee IDs can be reached.Your task is to build the BST using the given employee IDs and then find the Lowest Common Ancestor (LCA) of the two given employees.
Given n employee IDs, construct a Binary Search Tree (BST) by inserting the IDs in the given order. Then, for two given employee IDs p and q, find their Lowest Common Ancestor (LCA).
The Lowest Common Ancestor is the lowest node in the BST that has both p and q as descendants. A node can also be a descendant of itself.

Input Format
The first line contains an integer n, representing the number of employees.
The second line contains n space-separated integers representing the employee IDs.
The third line contains an integer p.
The fourth line contains an integer q.

Output Format
Print the employee ID of the Lowest Common Ancestor of p and q.

Sample Input 0
7
20 10 30 5 15 25 35
5
15
Sample Output 0
10
Explanation 0
The BST is formed by inserting the employee IDs in this order:
20 10 30 5 15 25 35
So the tree becomes
20
/ \
10 30
/ \ / \
5 15 25 35
The two employee IDs are p = 5, q = 15
Now check their common ancestor
5 is in the left subtree of 10
15 is in the right subtree of 10
So, the lowest node that has both 5 and 15 under it is 10.
Therefore, the output is:10

Sample Input 1
5
50 30 70 20 40
20
40
Sample Output 1
30
*/

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
