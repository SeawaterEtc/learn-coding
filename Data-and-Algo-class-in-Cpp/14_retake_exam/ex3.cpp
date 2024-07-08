// program to check if a binary tree is a binary search tree
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int maxValue(TreeNode* node) {
    if (node == nullptr) {
        return INT16_MIN;
    }
    int value = node->data;
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);
    return max(value, max(leftMax, rightMax));
}

int minValue(TreeNode* node) {
    if (node == nullptr) {
        return INT16_MAX;
    }
    int value = node->data;
    int leftMin = minValue(node->left);
    int rightMin = minValue(node->right);
    return min(value, min(leftMin, rightMin));
}

bool isBST(TreeNode* node) {
    if (node == nullptr) {
        return true;
    }
    if (node->left != nullptr && maxValue(node->left) >= node->data) {
        return false;
    }
    if (node->right != nullptr && minValue(node->right) <= node->data) {
        return false;
    }
    return isBST(node->left) && isBST(node->right);
}
int main() {
    TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    if (isBST(root)) {
        cout << "Is BST" << endl;
    } else {
        cout << "Not a BST" << endl;
    }

    return 0;
}
