//creating a Binary Trees, visualize the tree and do traversal

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
void printTree(Node** node, int space = 0, int gap = 5) {
    if (*node == NULL) {
        return;
    }
    space += gap;
    printTree(&(*node)->right, space);

    cout << endl;
    for (int i = gap; i < space; ++i) {
        cout << " ";
    }
    cout << setw(2) << (*node)->data << "\n";

    printTree(&(*node)->left, space);
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

int main() {
    Node* node = NULL;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of the nodes: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        createTree(&node, data);
    }

    cout << "Binary tree structure: " << endl;
    printTree(&node);


    cout << "Preorder traversal: ";
    preorderTraversal(node);
    cout << endl;

    cout << "Inorder traversal: ";
    inorderTraversal(node);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(node);
    cout << endl;

    return 0;

}