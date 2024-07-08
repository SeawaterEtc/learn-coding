//the give array, write a program to create a sorted double linked list
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
Node* sortedList(Node* head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else if (value < head->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data < value) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {
    int arr[] = {5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = nullptr;
    for (int i = 0; i < n; ++i) {
        head = sortedList(head, arr[i]);
    }
    cout << "Sorted doubly linked list: ";
    printList(head);
    return 0;
}