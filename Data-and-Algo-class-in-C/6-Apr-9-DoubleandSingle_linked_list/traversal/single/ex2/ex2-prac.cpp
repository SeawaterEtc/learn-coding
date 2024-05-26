//write c single linked list and do traversal from right to left

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to traverse the linked list from right to left
void traverseRightToLeft(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    // Recursively traverse the rest of the list
    traverseRightToLeft(head->next);

    // Print the data of the current node
    printf("%d ", head->data);
}

int main() {
    struct Node* head = NULL;

    // Insert some elements into the linked list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    // Traverse the linked list from right to left
    printf("Traversing from right to left: ");
    traverseRightToLeft(head);
    printf("\n");

    // Free memory to avoid memory leaks
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
