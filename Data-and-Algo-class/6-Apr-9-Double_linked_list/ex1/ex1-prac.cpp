//double linked list 
// traversal from left to right
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }
    void push_back(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    void PrintList() {
        Node* temp = head;
        if (temp != nullptr) {
            cout << "The list contains: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        } else {
            cout << "The list is empty." << endl;
        }
    }
};

int main() {
    DoublyLinkedList myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.PrintList();
    return 0;
}
