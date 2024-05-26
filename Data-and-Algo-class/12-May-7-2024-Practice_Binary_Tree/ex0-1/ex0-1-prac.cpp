// write cpp to Create a binary tree of 30 nodes with random numbers. 
// Create function to do preorder traversal, inorder traversal, and postorder traversal
// Function to visulize the tree structure
// Function Display all leaves of the tree. 
// Function to calculate tree height. 
// function to calculate sum value of each node and its childs. 
// function to sum the value of all sub tree. 
// Function to display all elements having node values divisible by 3 or 5. 
// Function to display the predecessor of nodes having value divisible by 3 or 5. 
// function to Sum all values of the tree. 
// function to Calculate average of all tree leaves. 
// function to Calculate average of the tree. 
// function to Display node value and its Childs's value. 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> // For std::setw

// Define the binary tree node structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary tree
TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->data) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

// Function to create a binary tree with random numbers
TreeNode* createRandomTree(int numNodes) {
    TreeNode* root = nullptr;
    std::srand(std::time(nullptr));
    for (int i = 0; i < numNodes; ++i) {
        int val = std::rand() % 100; // Random numbers between 0 and 99
        root = insertNode(root, val);
    }
    return root;
}

// Preorder traversal: Root -> Left -> Right
void preorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    std::cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Inorder traversal: Left -> Root -> Right
void inorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

// Postorder traversal: Left -> Right -> Root
void postorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->data << " ";
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
    std::cout << std::setw(2) << node->data << "\n";

    visualizeTree(node->left, space);
}

// Function to display all leaves of the tree
void displayLeaves(TreeNode* root) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        std::cout << root->data << " ";
    }
    displayLeaves(root->left);
    displayLeaves(root->right);
}

// Function to calculate tree height
int calculateTreeHeight(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftHeight = calculateTreeHeight(root->left);
    int rightHeight = calculateTreeHeight(root->right);
    return 1 + std::max(leftHeight, rightHeight);
}

// Function to calculate the sum of values in the subtree rooted at 'node'
int sumSubtree(TreeNode* node) {
    if (!node) {
        return 0;
    }
    return node->data + sumSubtree(node->left) + sumSubtree(node->right);
}

// Function to calculate the sum of all nodes and their children
int sumAllNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int subtreeSum = sumSubtree(root);
    return root->data + sumAllNodes(root->left) + sumAllNodes(root->right) - subtreeSum;
}

// New function: Display nodes with values divisible by 3 or 5
void displayDivisibleNodes(TreeNode* root) {
    if (!root) {
        return;
    }
    if (root->data % 3 == 0 || root->data % 5 == 0) {
        std::cout << root->data << " ";
    }
    displayDivisibleNodes(root->left);
    displayDivisibleNodes(root->right);
}


// Function to find the predecessor of nodes having value divisible by 3 or 5
void displayPredecessor(TreeNode* root, int target) {
    if (!root) {
        return;
    }
    displayPredecessor(root->left, target); // Recurse on the left subtree

    if (root->data % 3 == 0 || root->data % 5 == 0) {
        std::cout << "Node with value " << root->data << ": ";
        if (root->left) {
            std::cout << "Predecessor: " << root->left->data;
        } else {
            std::cout << "No predecessor (root node)";
        }
        std::cout << std::endl;
    }

    displayPredecessor(root->right, target); // Recurse on the right subtree
}

// Function to calculate the sum of all values in the binary tree
int sumTreeValues(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftSum = sumTreeValues(root->left); // Sum of left subtree
    int rightSum = sumTreeValues(root->right); // Sum of right subtree
    return root->data + leftSum + rightSum; // Sum of current node and subtrees
}
// Function to calculate the sum of leaf nodes and count of leaf nodes
void calculateLeafSumAndCount(TreeNode* root, int& leafCount, int& sum) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        // Node is a leaf
        leafCount++;
        sum += root->data;
    }
    calculateLeafSumAndCount(root->left, leafCount, sum);
    calculateLeafSumAndCount(root->right, leafCount, sum);
}

// Function to calculate the sum of all nodes in the binary tree
int calculateSum(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftSum = calculateSum(root->left); // Sum of left subtree
    int rightSum = calculateSum(root->right); // Sum of right subtree
    return root->data + leftSum + rightSum; // Sum of current node and subtrees
}

// Function to count the total number of nodes in the binary tree
int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftCount = countNodes(root->left); // Count in left subtree
    int rightCount = countNodes(root->right); // Count in right subtree
    return 1 + leftCount + rightCount; // Count of current node and subtrees
}

// Function to display node value and its children's values
void displayNodeAndChildren(TreeNode* root) {
    if (!root) {
        return;
    }
    std::cout << "Node value: " << root->data;
    if (root->left) {
        std::cout << ", Left child: " << root->left->data;
    } else {
        std::cout << ", No left child";
    }
    if (root->right) {
        std::cout << ", Right child: " << root->right->data;
    } else {
        std::cout << ", No right child";
    }
    std::cout << std::endl;

    displayNodeAndChildren(root->left); // Recurse on the left subtree
    displayNodeAndChildren(root->right); // Recurse on the right subtree
}


int main() {
    TreeNode* root = createRandomTree(30);

    std::cout << "Preorder traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Visual representation of the tree:" << std::endl;
    visualizeTree(root);

    std::cout << "Leaves of the tree: ";
    displayLeaves(root);
    std::cout << std::endl;

    std::cout << "Tree height: " << calculateTreeHeight(root) << std::endl;

    std::cout << "Sum of value of subtree: " << sumSubtree(root) << std::endl;

    std::cout << "Sum of all nodes (including children): " << sumAllNodes(root) << std::endl;

    std::cout << "Nodes divisible by 3 or 5: ";
    displayDivisibleNodes(root);
    std::cout << std::endl;


    std::cout << "Sum of all values in the binary tree: " << sumTreeValues(root) << std::endl;


    std::cout << "Predecessors of nodes with values divisible by 3 or 5:" << std::endl;
    displayPredecessor(root, 0); 




    int leafCount = 0;
    int sum = 0;
    calculateLeafSumAndCount(root, leafCount, sum);
    double average = static_cast<double>(sum) / leafCount;
    std::cout << "Number of leaf nodes: " << leafCount << std::endl;
    std::cout << "Sum of leaf node values: " << sum << std::endl;
    std::cout << "Average value of leaf nodes: " << average << std::endl;




    int totalSum = calculateSum(root);
    int totalNodes = countNodes(root);
    double average1 = static_cast<double>(totalSum) / totalNodes;
    std::cout << "Total number of nodes in the binary tree: " << totalNodes << std::endl;
    std::cout << "Sum of all node values: " << totalSum << std::endl;
    std::cout << "Average value of all nodes: " << average << std::endl;


    std::cout << "Node values and their children:" << std::endl;
    displayNodeAndChildren(root);


    return 0;
}
