// write c to Insert a double linked-list from front (head)

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the front (head) of the doubly linked list
struct Node* insertFront(struct Node* head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = head;

    // Update the previous pointer of the current head (if it exists)
    if (head != NULL) {
        head->prev = newNode;
    }

    // Set the new node as the head
    head = newNode;
    return head;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Initialize an empty doubly linked list
    struct Node* head = NULL;

    // Insert nodes at the front
    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertFront(head, 30);

    // Print the list
    printf("Doubly linked list: ");
    printList(head);

    return 0;
}
