// write cpp to create a Binary Tree, preorder traversal, inorder traversal, and postorder traversal
// Add 
// Function Display all leaves of the tree
// Function to calculate tree height
// function to calculate sum value of each node and its childs
// function to sum the value of sub tree

#include <iostream>
#include <iomanip> // For setw

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform preorder traversal
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    std::cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform inorder traversal
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

// Function to perform postorder traversal
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->val << " ";
}

// Function to display all leaves of the tree
void displayLeaves(TreeNode* root) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        std::cout << root->val << " ";
    }
    displayLeaves(root->left);
    displayLeaves(root->right);
}

// Function to calculate the height of the tree
int treeHeight(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + std::max(leftHeight, rightHeight);
}

// Function to calculate the sum value of each node and its children
int sumValues(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftSum = sumValues(root->left);
    int rightSum = sumValues(root->right);
    return root->val + leftSum + rightSum;
}

// Function to calculate the sum value of a subtree rooted at a given node
int subtreeSum(TreeNode* root) {
    if (root == nullptr) return 0;
    return root->val + subtreeSum(root->left) + subtreeSum(root->right);
}

// Function to visualize binary tree structure
void visualizeTree(TreeNode* node, int space = 0, int gap = 5) {
    if (node == nullptr) {
        return;
    }
    space += gap;
    visualizeTree(node->right, space);

    std::cout << std::endl;
    for (int i = gap; i < space; ++i) {
        std::cout << " ";
    }
    std::cout << std::setw(2) << node->val << "\n";

    visualizeTree(node->left, space);
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Preorder traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Leaves of the tree: ";
    displayLeaves(root);
    std::cout << std::endl;

    std::cout << "Tree height: " << treeHeight(root) << std::endl;
    std::cout << "Sum value of nodes: " << sumValues(root) << std::endl;
    std::cout << "Sum value of subtree rooted at node 2: " << subtreeSum(root->left) << std::endl;

    std::cout << "Binary tree structure:" << std::endl;
    visualizeTree(root);

    // Clean up memory (not shown in this example)
    return 0;
}
