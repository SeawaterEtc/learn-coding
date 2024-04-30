#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void createTree(Node* &root, int value) {
    if (root == NULL) {
        root = new Node(value);
        return;
    }
    if (value < root->data) {
        createTree(root->left, value);
    } else {
        createTree(root->right, value);
    }
}

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        createTree(root, value);
    }

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
