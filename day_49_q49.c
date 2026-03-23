#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert function
struct Node* insert(struct Node* root, int value) {
    // If tree is empty
    if (root == NULL) {
        return createNode(value);
    }

    // If value is smaller, go left
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If value is greater, go right
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder traversal (to check BST)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert elements
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}