//create doubly linked-list using class
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
};
class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() {
        head = nullptr;
    }
    void insertFront(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
    }
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList myList;
    myList.insertFront(3);
    myList.insertFront(2);
    myList.insertFront(1);
    cout << "Doubly linked list: ";
    myList.printList();

    return 0;
}
