/* 
A school maintains student roll numbers in a Binary Search Tree (BST) to keep them organized.The administration wants to find the Kth smallest roll number from the list. 
This helps them identify students based on ranking or order.Your task is to build the BST using the given roll numbers and find the Kth smallest element.
Given the root node of a Binary Search Tree (BST) and an integer k, return the Kth smallest element in the BST, where k is 1-indexed.

Input Format
First, enter the number of elements (n).
Then, enter n unique integers to insert into the BST.
Finally, enter the integer k.

Constraints
NA

Output Format
Display the Kth smallest element or a message indicating that the value of k is out of range.

Sample Input 0
6
50 30 70 20 40 60
3
Sample Output 0
40
Explanation 0
Step 1: Insert the values into the BST:
50, 30, 70, 20, 40, 60
Step 2: Perform In-Order Traversal (Left → Root → Right), which gives sorted order:
20 30 40 50 60 70
Step 3: The 3rd smallest element is 40
Hence, the output is:40

Sample Input 1
5
15 10 20 8 12
2
Sample Output 1
10 */

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
