//write c language to create a linked list of 20 elements where each element contains random values from 1 to 20. Remove elements having value divisible by 3 or 5. 

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

// Define the linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
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

// Function to remove nodes with values divisible by 3 or 5
void removeDivisibleNodes(struct Node** head) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data % 3 == 0 || current->data % 5 == 0) {
            if (prev == NULL) {
                *head = current->next;
                free(current);
                current = *head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    srand(time(NULL));

    // Create a linked list with 20 random values
    for (int i = 0; i < 20; ++i) {
        int randomValue = rand() % 20 + 1;
        insertNode(&head, randomValue);
    }

    printf("Original linked list:\n");
    displayList(head);

    // Remove nodes with values divisible by 3 or 5
    removeDivisibleNodes(&head);

    printf("Linked list after removing divisible elements:\n");
    displayList(head);

    // Free memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
