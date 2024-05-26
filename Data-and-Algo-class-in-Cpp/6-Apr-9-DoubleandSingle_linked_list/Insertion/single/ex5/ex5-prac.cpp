// Insert a single linked-list at the end of the list
// With the given single linked-list 5 -> 7 -> 8 -> 6 -> 1 -> 4 -> 8 -> 5 -> 8 add 7 to the end of the list

#include <iostream>
using namespace std;

// Define the Node structure
class Node {
public:
    int data;
    Node* next;
};

// Function to insert a new node at the end of the linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    // If the linked list is empty, make the new node the head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node
    Node* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }

    // Update the next pointer of the last node
    last->next = new_node;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout <<"nullptr" << endl;
}

int main() {
    Node* head = nullptr;
    append(&head, 5);
    append(&head, 7);
    append(&head, 8);
    append(&head, 6);
    append(&head, 1);
    append(&head, 4);
    append(&head, 8);
    append(&head, 5);

    cout << "Linked list before inserting 7 at the end: ";
    printList(head);

    // Insert 7 at the end
    append(&head, 7);

    cout << "\nLinked list after inserting 7 at the end: ";
    printList(head);

    return 0;
}
