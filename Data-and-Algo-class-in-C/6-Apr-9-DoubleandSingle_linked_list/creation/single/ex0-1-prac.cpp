//write c to create single linked-list using struct

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single linked-list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create a linked-list with three nodes
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    // Link the nodes
    head->next = second;
    second->next = third;

    // Print the linked-list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Clean up: free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
