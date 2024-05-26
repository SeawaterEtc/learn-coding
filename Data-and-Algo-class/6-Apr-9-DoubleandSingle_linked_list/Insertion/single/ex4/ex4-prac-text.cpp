#include <iostream>

// Define the doubly linked list node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert a new node after a given node
void insertAfter(Node* prevNode, int newData) {
    if (prevNode == nullptr) {
        std::cout << "Invalid previous node!" << std::endl;
        return;
    }

    // Create a new node
    Node* newNode = new Node();
    newNode->data = newData;

    // Adjust pointers
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample doubly linked list: 5, 7, 8, 6, 1, 4, 8, 5, 8
    Node* head = new Node();
    head->data = 5;
    head->prev = nullptr;
    head->next = nullptr;

    // Insert 7 after the fourth node (position 4)
    insertAfter(head, 7);
    insertAfter(head->next->next->next, 7);

    // Print the modified list
    std::cout << "Doubly linked list after insertion: ";
    printList(head);

    return 0;
}
