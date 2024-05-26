// write cpp doubly linked to Delete the last Node

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

// Function to delete a node in a Doubly Linked List
void deleteNode(Node** head_ref, Node* del) {
    if (*head_ref == nullptr || del == nullptr)
        return;

    // If the node to be deleted is the head node
    if (*head_ref == del)
        *head_ref = del->next;

    // Update the next pointer of the previous node
    if (del->next != nullptr)
        del->next->prev = del->prev;

    // Update the prev pointer of the next node
    if (del->prev != nullptr)
        del->prev->next = del->next;

    // Finally, free the memory occupied by del
    free(del);
}

// Function to insert a node at the beginning of the Doubly Linked List
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->prev = nullptr;
    new_node->next = (*head_ref);

    if ((*head_ref) != nullptr)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

// Function to print nodes in a given doubly linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head = nullptr;

    // Create a sample doubly linked list: 10 <-> 8 <-> 4 <-> 2
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    cout << "Original Linked list: ";
    printList(head);

    // Delete nodes (you can modify this part as needed)
    deleteNode(&head, head);        // Delete the head node
    deleteNode(&head, head->next);  // Delete the second node
    deleteNode(&head, head->next);  // Delete the third node

    cout << "\nModified Linked list: ";
    printList(head);

    return 0;
}
