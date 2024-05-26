// Insert a double linked-list from front (head)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;

    if (*head_ref != nullptr) {
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head = nullptr;
    push(&head, 100);
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 60);

    cout << "Doubly linked list before inserting 50 at the front: ";
    printList(head);

    push(&head, 50);
    push(&head, 199);

    cout << "\nDoubly linked list after inserting 50 at the front: ";
    printList(head);

    return 0;
}
