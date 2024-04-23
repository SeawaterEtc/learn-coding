// Insert a single linked-list from front (head)
// With the single linked-list 10 -> 20 -> 30 -> 40 -> 50 -> 60 add 7 to the front

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Create the initial linked list: 10 -> 20 -> 30 -> 40 -> 50 -> 60
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    cout <<"Original linked list: " << endl;
    printList(head);


    // Insert 7 at the front
    insertAtFront(head, 7);

    cout << "Modified linked list: ";
    printList(head);

    return 0;
}
