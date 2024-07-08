//a program to convert a given binary search tree to a sorted doubly linked list
#include <bits/stdc++.h>
using namespace std;
// Definition of a binary tree node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
// Helper function to convert BST to DLL
TreeNode* bintree2listUtil(TreeNode* root) {
    if (root == nullptr)
        return root;
    // Convert left subtree
    if (root->left != nullptr) {
        TreeNode* left = bintree2listUtil(root->left);
        while (left->right != nullptr)
            left = left->right;
        left->right = root;
        root->left = left;
    }
    // Convert right subtree
    if (root->right != nullptr) {
        TreeNode* right = bintree2listUtil(root->right);
        while (right->left != nullptr)
            right = right->left;
        right->left = root;
        root->right = right;
    }
    return root;
}
// Main function to convert BST to DLL
TreeNode* bintree2list(TreeNode* root) {
    if (root == nullptr)
        return root;
    root = bintree2listUtil(root);
    // Find the head of the DLL (leftmost node)
    while (root->left != nullptr)
        root = root->left;
    return root;
}
// Create a new node with given data
TreeNode* newNode(int data) {
    TreeNode* new_node = new TreeNode();
    new_node->data = data;
    new_node->left = new_node->right = nullptr;
    return new_node;
}
// Print nodes in the doubly linked list
void printList(TreeNode* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->right;
    }
}
int main() {
    // Example usage
    TreeNode* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
    TreeNode* head = bintree2list(root);
    printList(head);
    return 0;
}