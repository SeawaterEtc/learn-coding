// write c single linked to Delete the specific position of the single linked-list

#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the front of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to delete a node at the given position
void deleteNode(struct Node** head_ref, int position) {
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;

    // If the node to be deleted is the root
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Traverse to the previous node
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is out of bounds
    if (temp == NULL || temp->next == NULL)
        return;

    // Update the next pointer to skip the node at the given position
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);

    printf("Created Linked List: ");
    printList(head);

    deleteNode(&head, 4); // Delete node at position 4

    printf("\nLinked List after Deletion at position 4: ");
    printList(head);

    return 0;
}
