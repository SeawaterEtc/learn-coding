//double linked list traversal from right to left
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};


void addNode(Node*& head, int key) {
    Node* newNode = new Node;
    newNode->data = key;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}



void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    addNode(head, 3);
    addNode(head, 5);
    addNode(head, 8);
    addNode(head, 2);

    cout << "Doubly linked list (right to left): ";
    printList(head);

    return 0;
}
