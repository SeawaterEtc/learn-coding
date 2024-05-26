// write c to Create a binary tree of 30 nodes with random numbers. 
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

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Preorder traversal: Root -> Left -> Right
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Inorder traversal: Left -> Root -> Right
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Postorder traversal: Left -> Right -> Root
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Display all leaves of the tree
void displayLeaves(struct TreeNode* root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            printf("%d ", root->data);
        }
        displayLeaves(root->left);
        displayLeaves(root->right);
    }
}

// Calculate tree height
int calculateHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Calculate sum value of each node and its children
int calculateSum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftSum = calculateSum(root->left);
    int rightSum = calculateSum(root->right);
    return root->data + leftSum + rightSum;
}

// Compute the sum of all subtree values
int sumSubtree(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftSum = sumSubtree(root->left);
    int rightSum = sumSubtree(root->right);

    return root->data + leftSum + rightSum;
}

// Display nodes with values divisible by 3 or 5
void displayDivisibleNodes(struct TreeNode* root) {
    if (root == NULL)
        return;

    if (root->data % 3 == 0 || root->data % 5 == 0)
        printf("%d ", root->data);

    displayDivisibleNodes(root->left);
    displayDivisibleNodes(root->right);
}

// Function to find the predecessor of a given node
struct TreeNode* findPredecessor(struct TreeNode* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value) {
        // Node found, return its predecessor
        // (Assuming the tree has parent pointers; adjust accordingly)
        return root->left; // In this example, we assume left child is predecessor
    } else if (value < root->data) {
        // Search in the left subtree
        return findPredecessor(root->left, value);
    } else {
        // Search in the right subtree
        return findPredecessor(root->right, value);
    }
}

// Function to display the predecessor of nodes divisible by 3 or 5
void displayPredecessor(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->data % 3 == 0 || root->data % 5 == 0) {
        printf("Node %d: Predecessor is ", root->data);
        struct TreeNode* pred = findPredecessor(root, root->data);
        if (pred) {
            printf("%d\n", pred->data);
        } else {
            printf("N/A\n");
        }
    }
    displayPredecessor(root->left);
    displayPredecessor(root->right);
}

// Function to calculate the sum of all values in the tree
int sumTree(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sumTree(root->left) + sumTree(root->right);
}

// Function to calculate the average of all leaf nodes
double averageLeaf(struct TreeNode* root, int* leafCount) {
    if (root == NULL) {
        return 0.0;
    }
    if (root->left == NULL && root->right == NULL) {
        // Leaf node
        (*leafCount)++;
        return root->data;
    }
    double leftSum = averageLeaf(root->left, leafCount);
    double rightSum = averageLeaf(root->right, leafCount);
    return leftSum + rightSum;
}

// Function to calculate the average of the entire tree
double averageTree(struct TreeNode* root, int* nodeCount) {
    if (root == NULL) {
        return 0.0;
    }
    (*nodeCount)++;
    double leftSum = averageTree(root->left, nodeCount);
    double rightSum = averageTree(root->right, nodeCount);
    return root->data + leftSum + rightSum;
}

// Function to display node value and its children's values
void displayNodeAndChildren(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("Node %d: Left child = ", root->data);
    if (root->left) {
        printf("%d", root->left->data);
    } else {
        printf("N/A");
    }
    printf(", Right child = ");
    if (root->right) {
        printf("%d", root->right->data);
    } else {
        printf("N/A");
    }
    printf("\n");

    displayNodeAndChildren(root->left);
    displayNodeAndChildren(root->right);
}



int main() {
    struct TreeNode* root = NULL;
    int i, data;

    for (i = 0; i < 30; ++i) {
        data = rand() % 100; 
        root = insert(root, data);
    }

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Leaves of the tree: ");
    displayLeaves(root);
    printf("\n");

    printf("Tree height: %d\n", calculateHeight(root));

    printf("Sum of all nodes: %d\n", calculateSum(root));


    int totalSum = sumSubtree(root);
    printf("Sum of all subtree values: %d\n", totalSum);

    printf("Nodes with values divisible by 3 or 5: ");
    displayDivisibleNodes(root);
    printf("\n");


    printf("predecessor of nodes divisible by 3 or 5");
    displayPredecessor(root);
    printf("\n");

    int totalSum1 = sumTree(root);
    printf("Sum of all values in the tree: %d\n", totalSum);
    printf("\n");

    int leafCount = 0;
    double leafSum = averageLeaf(root, &leafCount);
    double leafAverage = leafSum / leafCount;
    printf("Average of leaf nodes: %.2lf\n", leafAverage);

    int totalNodeCount = 0;
    double totalSum2 = averageTree(root, &totalNodeCount);
    double totalAverage = totalSum / totalNodeCount;
    printf("Average of all nodes in the tree: %.2lf\n", totalAverage);

    printf("Node values and their children:\n");
    displayNodeAndChildren(root);

    return 0;
}
