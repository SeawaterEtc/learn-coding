// Write a program to generate 10 random values. Add these values into the linked list in ascending order. 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;
};

//create node func
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

//insertSorted function
void insertSorted (Node** head, Node* newNode) {
    Node* current = *head;

    if (*head == nullptr || newNode->data <= (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        while (current->next != nullptr && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

}


//print node function
void printLink(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main () {
    srand(time(0));

    Node* head = nullptr;

    for (int i=0; i<10; i++) {
        int value = rand() % 100 +1;
        Node* newNode = createNode(value);
        insertSorted(&head, newNode);
    }

    cout << "Linked list in ascending order: ";
    printLink(head);

    return 0;
}