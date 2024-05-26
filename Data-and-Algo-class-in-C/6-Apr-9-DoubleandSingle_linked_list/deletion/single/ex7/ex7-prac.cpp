// write c single linked to Delete the last Node

#include <iostream>
using namespace std;

// Linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to remove the last node of the linked list
Node* removeLastNode(struct Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    // Find the second-to-last node
    Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    // Delete the last node
    delete (second_last->next);

    // Change next of second-to-last node
    second_last->next = NULL;

    return head;
}

// Function to push a node at the head
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Driver code
int main() {
    Node* head = NULL;
    push(&head, 12);
    push(&head, 29);
    push(&head, 11);
    push(&head, 23);
    push(&head, 8);

    head = removeLastNode(head);

    for (Node* temp = head; temp != NULL; temp = temp->next)
        cout << temp->data << " ";

    return 0;
}
