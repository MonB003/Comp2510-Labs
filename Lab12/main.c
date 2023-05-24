#include <stdio.h>
#include <stdlib.h>

#define TEN 10


// Definition for a binary tree node.
struct node {
    int data;
    struct node *left;
    struct node *right;
};


// Creates a new node
struct node *new_node(int value) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("No memory was allocated.");
        exit(0);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


// Displays a binary tree in pre-order form
void display_preorder(struct node *binary_tree) {
    if (binary_tree) {
        printf("%d\n", binary_tree->data);
        display_preorder(binary_tree->left);
        display_preorder(binary_tree->right);
    }
}


// Helper function to calculate the sum of nodes recursively
int calculateSum(struct node *root, int currentSum) {
    if (root == NULL) {
        return 0;
    }

    // Add the current node value to the sum
    currentSum = currentSum * TEN + root->data;

    // If left and right are null, return the current sum
    if (root->left == NULL && root->right == NULL) {
        return currentSum;
    }

    // Left and right have values, so calculate the total sums of both nodes
    int total = calculateSum(root->left, currentSum) + calculateSum(root->right, currentSum);
    return total;
}


/*
 * Function creates a variable to store the sum of a binary tree, and calls the calculateSum() method to
 * calculate the sums of each root to leaf path.
 */
int sumNumbers(struct node *root) {
    int sum = 0;
    int totalSum = calculateSum(root, sum);

    return totalSum;
}


int main() {
    // Create binary tree
    struct node *input = new_node(4);
    input->left = new_node(9);
    input->left->left = new_node(5);
    input->left->right = new_node(1);
    input->right = new_node(0);

    // Display node values
    printf("Pre Order: \n");
    display_preorder(input);

    // Sum of numbers method
    int inputSum = sumNumbers(input);
    printf("Sum of numbers: %d\n", inputSum);

    free(input);

    return 0;
}
