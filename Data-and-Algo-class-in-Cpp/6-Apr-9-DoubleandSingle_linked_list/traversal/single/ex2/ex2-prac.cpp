//write cpp single linked list and do traversal from right to left

#include <iostream>

// Define a class to represent each element (node) of the linked list
class Node {
public:
    int data;       // Data stored in this node
    Node* next;     // Reference to the next node

    // Constructor for creating a node with given data
    Node(int data) {
        this->data = data;
        this->next = nullptr; // Initially, there is no next node
    }
};

// Recursive function to print elements in reverse order
void printReverse(Node* head) {
    if (head == nullptr) {
        return; // Base case: reached the end of the list
    }
    printReverse(head->next); // Recurse to the next node
    std::cout << head->data << " "; // Print the current node's data
}

int main() {
    // Create the head of the linked list
    Node* head = new Node(10);

    // Insert some elements into the list
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Print all elements of the singly linked list (right to left)
    printReverse(head);
    std::cout << std::endl;

    // Don't forget to free memory to avoid memory leaks
    Node* ptr = head;
    while (ptr != nullptr) {
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    return 0;
}
