// Insert a doubly linked-list from front (head)

#include <iostream>
struct Node {
    int data;
    Node* prev;
    Node* next;
};
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;
    if ((*head_ref) != nullptr)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

int main() {
    Node* head = nullptr;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    return 0;
}
