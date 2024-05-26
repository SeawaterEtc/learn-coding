// write cpp doubly linked to Delete the starting Node

#include <iostream>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to delete the starting node
void deleteStartingNode(Node*& head) {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete starting node." << std::endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample doubly linked list
    Node* head = new Node{1, nullptr, nullptr};
    head->next = new Node{2, head, nullptr};
    head->next->next = new Node{3, head->next, nullptr};

    std::cout << "Original list: ";
    printList(head);

    // Delete the starting node
    deleteStartingNode(head);

    std::cout << "List after deleting starting node: ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
