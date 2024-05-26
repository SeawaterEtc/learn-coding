// Write c to Insert a 5 element doubly linked-list at the end of the list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Otherwise, traverse to the end of the list
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Attach the new node to the end
    current->next = newNode;
    newNode->prev = current;
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
    struct Node* head = NULL;

    // Insert 5 elements at the end
    for (int i = 1; i <= 5; ++i) {
        insertAtEnd(&head, i);
    }

    // Print the list
    printf("Doubly linked list: ");
    printList(head);

    return 0;
}
