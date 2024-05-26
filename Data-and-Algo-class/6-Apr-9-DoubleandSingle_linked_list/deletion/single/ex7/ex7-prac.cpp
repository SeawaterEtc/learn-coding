// write cpp single linked to Delete the last Node

#include <iostream>

// Define the linked list node
struct Node {
    int data;
    Node* next;
};

// Function to remove the last node of the linked list
Node* removeLastNode(Node* head) {
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Find the second-to-last node
    Node* second_last = head;
    while (second_last->next->next != nullptr)
        second_last = second_last->next;

    // Delete the last node
    delete (second_last->next);

    // Set the next of second-to-last node to nullptr
    second_last->next = nullptr;

    return head;
}

// Function to push a node at the head
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Driver code
int main() {
    Node* head = nullptr;

    // Construct the list: 8 -> 23 -> 11 -> 29 -> 12
    push(&head, 12);
    push(&head, 29);
    push(&head, 11);
    push(&head, 23);
    push(&head, 8);

    // Remove the last node
    head = removeLastNode(head);

    // Print the modified list
    for (Node* temp = head; temp != nullptr; temp = temp->next)
        std::cout << temp->data << " ";

    return 0;
}
