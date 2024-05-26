// write cpp single linked to Delete the specific position of the doubly linked-list

#include <iostream>

// Define the singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to delete a node at a specific position
void deleteNodeAtPosition(Node*& head, int position) {
    if (head == nullptr || position < 0) {
        std::cout << "Invalid position or empty list." << std::endl;
        return;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;
    int count = 0;

    while (curr != nullptr && count < position) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        std::cout << "Position exceeds list length." << std::endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    std::cout << "Original list: ";
    printList(head);

    int positionToDelete = 2; // Change this to the desired position
    deleteNodeAtPosition(head, positionToDelete);

    std::cout << "List after deleting position " << positionToDelete << ": ";
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
