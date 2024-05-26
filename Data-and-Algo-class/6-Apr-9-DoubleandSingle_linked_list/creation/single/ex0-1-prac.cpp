//create single linked-list using struct

#include <iostream>

// Define the node structure
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
};

// Function to traverse and print the elements of the linked list
void traverseLinkedList(Node* head) {
    Node* current = head;  // Start from the head of the linked list
    while (current != nullptr) {
        std::cout << current->data << " ";  // Print the data of the current node
        current = current->next;            // Move to the next node
    }
    std::cout << std::endl;
}

int main() {
    // Create nodes
    Node* head = new Node{1};
    Node* second = new Node{2};
    Node* third = new Node{3};

    // Connect nodes
    head->next = second;
    second->next = third;

    // Call the traverseLinkedList function to print the linked list elements
    traverseLinkedList(head);

    // Memory cleanup (free allocated memory)
    delete head;
    delete second;
    delete third;

    return 0;
}
