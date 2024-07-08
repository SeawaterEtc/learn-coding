//a binary search try, write a program to find predecessor of nodes having value divisible by 3 or 5
#include <iostream>
using namespace std;
// Node structure for a Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};
// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
// Function to insert a node in the BST
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}
// Function to find the inorder predecessor
Node* findPredecessor(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->data > value) {
        // Move left to find a smaller value
        return findPredecessor(root->left, value);
    } else if (root->data < value) {
        // Move right and update the predecessor
        Node* pred = findPredecessor(root->right, value);
        return pred ? pred : root;
    }
    // If root->data == value, return the maximum value smaller than it
    return root->left ? root->left : nullptr;
}
int main() {
    Node* root = nullptr;
    // Insert nodes into the BST
    root = insertNode(root, 10);
    root = insertNode(root, 6);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 12);
    root = insertNode(root, 18);
    int targetValue = 15; // Example: find predecessor for value 15
    Node* predecessor = findPredecessor(root, targetValue);
    if (predecessor) {
        cout << "Predecessor of " << targetValue << " is " << predecessor->data << endl;
    } else {
        cout << "No predecessor found for " << targetValue << endl;
    }
    // Clean up memory (not shown in this example)
    return 0;
}
