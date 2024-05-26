// write cpp single linked to Delete the starting Node 

#include <iostream>

// Define the singly linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to delete the starting node
void deleteStartingNode(Node*& head) {
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete starting node." << std::endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original linked list: ";
    printList(head);

    // Delete the starting node
    deleteStartingNode(head);

    std::cout << "Linked list after deleting the starting node: ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
