// Write c to insert a 5 element doubly linked-list at any position

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a given position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Invalid position. List size is smaller than the specified position.\n");
        return;
    }
    newNode->prev = current->prev;
    newNode->next = current;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    } else {
        *head = newNode;
    }
    current->prev = newNode;
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
    // Inserting elements at different positions
    insertAtPosition(&head, 10, 1); // Insert 10 at position 1
    insertAtPosition(&head, 20, 2); // Insert 20 at position 2
    insertAtPosition(&head, 30, 3); // Insert 30 at position 3
    insertAtPosition(&head, 40, 2); // Insert 40 at position 2
    insertAtPosition(&head, 50, 4); // Insert 50 at position 4

    printf("Doubly linked list: ");
    printList(head);

    return 0;
}
