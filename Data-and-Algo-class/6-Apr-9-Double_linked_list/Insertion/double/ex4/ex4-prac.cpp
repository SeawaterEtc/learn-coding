// Insert a doubly linked-list at any position
// With the given doubly linked-list 5,7,8,6,1,4,8,5,8 add 7 to the forth Node

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

    void insertAt(int newElement, int position) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        if (position == 1) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1; ++i) {
                if (temp == nullptr) {
                    cout << "The specified position does not exist." << endl;
                    return;
                }
                temp = temp->next;
            }
            if (temp != nullptr) {
                newNode->next = temp->next;
                newNode->prev = temp;
                if (newNode->next != nullptr) {
                    newNode->next->prev = newNode;
                }
                temp->next = newNode;
            } else 
            {
                cout << "The previous node is null. Index outoff bound" << endl;
            }
        }
    }
    void display() {
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
    myList.insertAt(5, 1);
    myList.insertAt(7, 2);
    myList.insertAt(8, 3);
    myList.insertAt(6, 4);
    myList.insertAt(1, 5);
    myList.insertAt(4, 6);
    myList.insertAt(8, 7);
    myList.insertAt(5, 8);
    myList.insertAt(8, 9);

    cout << "Original doubly linked list: ";
    myList.display();
    myList.insertAt(7, 11);
    cout << "Modified doubly linked list: ";
    myList.display();

    return 0;
}
