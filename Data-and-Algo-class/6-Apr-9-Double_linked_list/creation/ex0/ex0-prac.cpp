//Create doubly link list using struct

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
void insertFront(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = nullptr;

    if (*head != nullptr) {
        (*head)->prev = newNode;
    }

    *head = newNode;
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

    insertFront(&head, 3);
    insertFront(&head, 2);
    insertFront(&head, 1);
    cout << "Doubly linked list: ";
    printList(head);

    return 0;
}
