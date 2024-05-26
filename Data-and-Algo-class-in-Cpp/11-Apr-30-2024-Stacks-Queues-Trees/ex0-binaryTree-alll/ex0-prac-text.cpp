#include <iostream>
#include <iomanip> // For setw
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

void printTree(Node* root, int space = 0, int gap = 5) {
    if (root == NULL) {
        return;
    }
    space += gap;
    printTree(root->right, space);

    cout << endl;
    for (int i = gap; i < space; ++i) {
        cout << " ";
    }
    cout << setw(2) << root->data << "\n";

    printTree(root->left, space);
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

    cout << "Binary tree structure:" << endl;
    printTree(root);

    return 0;
}
