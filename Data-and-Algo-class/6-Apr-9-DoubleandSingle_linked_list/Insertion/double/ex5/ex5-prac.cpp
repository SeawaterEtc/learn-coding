// Insert a doubly linked-list at the end of the list
// With the given doubly linked-list nullptr <- 5 <-> 7 <-> 8 <-> 6 <-> 1 <-> 4 <-> 8 <-> 5 <-> 8 -> nullptr, add 7 to the end of the list

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int Data;
    struct Node* next;
    struct Node* prev;
};

void insertNodeAtEnd(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Data = val;
    newNode->next = nullptr;

    if (*head == nullptr) {
        // If the list is empty, make the new node the head
        newNode->prev = nullptr;
        *head = newNode;
    } else {
        // Traverse to the last node
        struct Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Change the next pointer of the last node
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != nullptr) {
        cout << temp->Data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    struct Node* head = nullptr;

    // Create a doubly linked list with the given elements
    int elements[] = {5, 7, 8, 6, 1, 4, 8, 5, 8};
    int numElements = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < numElements; ++i) {
        insertNodeAtEnd(&head, elements[i]);
    }

    cout << "Original list: ";
    displayList(head);

    // Insert 7 at the end
    insertNodeAtEnd(&head, 7);

    cout << "List after inserting 7 at the end: ";
    displayList(head);

    return 0;
}
