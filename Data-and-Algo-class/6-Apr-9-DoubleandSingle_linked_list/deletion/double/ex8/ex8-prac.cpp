// write cpp doubly linked to Delete node at the specific position of the doubly linked-list
#include <bits/stdc++.h>
using namespace std;

// Define a node structure for the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to delete a node in a Doubly Linked List
void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == nullptr || del == nullptr)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != nullptr)
        del->next->prev = del->prev;

    if (del->prev != nullptr)
        del->prev->next = del->next;

    free(del); // Free the memory occupied by the deleted node
}

// Function to delete the node at the given position in the doubly linked list
void deleteNodeAtGivenPos(struct Node** head_ref, int n) {
    if (*head_ref == nullptr || n <= 0)
        return;

    struct Node* current = *head_ref;
    for (int i = 1; current != nullptr && i < n; i++)
        current = current->next;

    if (current == nullptr)
        return;

    deleteNode(head_ref, current);
}

// Function to insert a node at the beginning of the Doubly Linked List
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = nullptr;
    new_node->next = (*head_ref);

    if ((*head_ref) != nullptr)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

// Function to print nodes in a given doubly linked list
void printList(struct Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    struct Node* head = nullptr;
    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    cout << "Doubly linked list before deletion:\n";
    printList(head);

    int positionToDelete = 2; // Example: Delete node at position 2
    deleteNodeAtGivenPos(&head, positionToDelete);

    cout << "\nDoubly linked list after deletion of node at position " << positionToDelete << ":\n";
    printList(head);

    return 0;
}
