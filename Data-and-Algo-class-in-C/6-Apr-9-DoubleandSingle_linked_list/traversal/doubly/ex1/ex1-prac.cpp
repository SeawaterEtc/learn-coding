//write c double linked list and do traversal from left to right


#include <stdio.h>
#include <stdlib.h>



struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }

    return newNode;
}

void traverseLeftToRight(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    printf("Doubly Linked List (left to right): ");
    traverseLeftToRight(head);

    return 0;
}
