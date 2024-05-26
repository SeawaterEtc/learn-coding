// write c doubly linked to Delete node at the specific position of the doubly linked-list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to delete a node in a doubly linked list
void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

// Function to delete the node at the given position in the doubly linked list
void deleteNodeAtGivenPos(struct Node** head_ref, int n) {
    if (*head_ref == NULL || n <= 0)
        return;

    struct Node* current = *head_ref;
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;

    if (current == NULL)
        return;

    deleteNode(head_ref, current);
}

// Function to insert a node at the beginning of the doubly linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

// Function to print nodes in a given doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printf("Doubly linked list before deletion:\n");
    printList(head);

    int position_to_delete = 2; // Example: delete node at position 2
    deleteNodeAtGivenPos(&head, position_to_delete);

    printf("\nDoubly linked list after deletion of node at position %d:\n", position_to_delete);
    printList(head);

    return 0;
}
