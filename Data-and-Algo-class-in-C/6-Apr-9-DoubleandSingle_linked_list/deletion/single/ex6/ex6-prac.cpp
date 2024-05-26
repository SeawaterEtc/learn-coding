// write c single linked to Delete the starting Node 

#include <stdio.h>
#include <stdlib.h>

// Define the singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to delete the starting node
void deleteStartingNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Starting node deleted successfully.\n");
}

// Example usage
int main() {
    struct Node* head = NULL; // Initialize an empty list

    // Add some nodes (you can modify this part as needed)
    // ...

    // Call the deleteStartingNode function
    deleteStartingNode(&head);

    // Print the updated list (if needed)
    // ...

    return 0;
}
