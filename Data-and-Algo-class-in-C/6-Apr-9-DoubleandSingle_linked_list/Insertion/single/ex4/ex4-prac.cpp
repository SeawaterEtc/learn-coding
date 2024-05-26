//Write c to Insert a single linked-list at any position


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at a given position
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        // Insert at the beginning
        newNode->next = *head;
        *head = newNode;
    } else {
        // Traverse to the (position-1)th node
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; ++i) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position. List size is smaller than the specified position.\n");
            return;
        }

        // Insert after the (position-1)th node
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Example usage
    insertAtPosition(&head, 10, 1); // Insert 10 at the beginning
    insertAtPosition(&head, 20, 2); // Insert 20 after the first node
    insertAtPosition(&head, 30, 3); // Insert 30 after the second node

    printf("Linked list after insertion: ");
    printList(head);

    return 0;
}
