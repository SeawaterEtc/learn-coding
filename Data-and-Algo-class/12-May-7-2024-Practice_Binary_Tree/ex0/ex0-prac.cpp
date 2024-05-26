// write cpp to create a Binary Tree, preorder traversal, inorder traversal, and postorder traversal
// Add 
// Function Display all leaves of the tree (meaning if node.left and node.right == NULL, display its data)
// Function to calculate tree height
// function to calculate sum value of each node and its childs
// function to sum the value of sub tree


#include <iostream>
#include <iomanip> // For setw


using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// function to create tree 
void createTree(Node** node, int data) {
    if (*node == NULL) {
        *node = new Node(data);
        return;
    }
    if (data < (*node)->data) {
        createTree(&(*node)->left, data);
    } else {
        createTree(&(*node)->right, data);
    }
}

// function to visualize binary tree structure
void visualizeTree(Node** node, int space = 0, int gap = 5) {
    if (*node == NULL) {
        return;
    }
    space += gap;
    visualizeTree(&(*node)->right, space);

    cout << endl;
    for (int i = gap; i < space; ++i) {
        cout << " ";
    }
    cout << setw(2) << (*node)->data << "\n";

    visualizeTree(&(*node)->left, space);
}

void preorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);

}

void inorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);

}

void postorderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

// Display all leaves of the tree (meaning if node.left and node.right == NULL, display its data)
void displayAllLeaves(Node* node) {
    if (node == NULL) {
        return;
    }
    displayAllLeaves(node->left);
    displayAllLeaves(node->right);
    if (node->left == NULL && node->right == NULL) {
        cout << node->data << " ";
    }    
}

// Function to calculate tree height
int calculateHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    int treeHeight = 1 + max(leftHeight, rightHeight);
    cout << "Tree height: " << treeHeight << endl;
}


// function to calculate sum value of each node and its childs
int calculateSum(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftSum = calculateSum(node->left);
    int rightSum = calculateSum(node->right);
    int totalSum = node->data + leftSum + rightSum;
    cout << "The sum: " << totalSum;
    return;
}

// function to sum the value of sub tree
int subtreeSum(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftSubtreeSum = subtreeSum(node->left);
    int rightSubtreeSum = subtreeSum(node->right);
    int totalSum = node->data + leftSubtreeSum + rightSubtreeSum;
    cout << "Sum of left sub trees: " << leftSubtreeSum << endl;
    cout << "Sum of right sub trees: " << rightSubtreeSum << endl;
    return totalSum;
}

int main() {
    Node* node = NULL;
    int n = 30;
    // int data;
    cout << "Enter the number of nodes: " << n << endl;
    // cin >> n;
    // cout << "Enter the number of the nodes: ";
    cout << "Number devided by 3 or 5: " ; 
    for (int i = 0; i < n; ++i) {
        int data;
        // cin >> data;
        data = 1 + (rand() % 100);


        createTree(&node, data);


        if (data % 3 == 0 || data % 5 == 0) {
            cout << data << " "; 
        }
    } cout << endl;

    cout << "Binary tree structure: " << endl;
    visualizeTree(&node);


    cout << "Preorder traversal: ";
    preorderTraversal(node);
    cout << endl;

    cout << "Inorder traversal: ";
    inorderTraversal(node);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(node);
    cout << endl;

    cout << "Display all leaves: ";
    displayAllLeaves(node);
    cout << endl;

    cout << "Display tree height: ";
    calculateHeight(node);
    cout << endl;

    cout << "Display sum value of each node and its tree: ";
    calculateSum(node);
    cout << endl;

    cout << "Display sum value of sub-tree: ";
    subtreeSum(node);
    cout << endl;



    return 0;

}