// Write c program to generate 10 random element and add them into the linked list in ascending order. 

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to swap two nodes
struct Node* swap(struct Node* ptr1, struct Node* ptr2) {
    struct Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

// Function to sort the list using Bubble Sort
void bubbleSort(struct Node** head, int count) {
    struct Node** h;
    int i, j, swapped;
    for (i = 0; i < count; i++) {
        h = head;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++) {
            struct Node* p1 = *h;
            struct Node* p2 = p1->next;
            if (p1->data > p2->data) {
                // Update the link after swapping
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h)->next;
        }
        // Break if the loop ended without any swap
        if (swapped == 0)
            break;
    }
}

// Function to print the list
void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of a linked list
void insertAtTheBegin(struct Node** start_ref, int data) {
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}

// Driver Code
int main() {
    int arr[] = { 78, 20, 10, 32, 1, 5 };
    int list_size, i;
    struct Node* start = NULL;
    list_size = sizeof(arr) / sizeof(arr[0]);

    // Create linked list from the array arr[]
    for (i = list_size - 1; i >= 0; i--)
        insertAtTheBegin(&start, arr[i]);

    // Print list before sorting
    printf("Linked list before sorting:\n");
    printList(start);

    // Sort theinked list
    bubbleSort(&start, list_size);

    // Print list after sorting
    printf("Linked list after sorting:\n");
    printList(start);

    return 0;
}
