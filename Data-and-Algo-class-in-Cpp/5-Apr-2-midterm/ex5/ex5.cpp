#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " "; 
        current = current->next;
    }
    cout << endl;
}

void splitOddEven(Node* head, Node* &oddHead, Node* evenHead) {
    Node* odd_dummy = new Node();
    Node* even_dummy = new Node();
    Node* odd_tail = odd_dummy;
    Node* even_tail = even_dummy;

    Node* current = head;
    while (current) {
        if (current->data % 2 == 0) {
            even_tail->next = current;
            even_tail = even_tail->next;
        } else {
            odd_tail->next = current;
            odd_tail = odd_tail->next;
        }
        current = current->next;
    }
    odd_tail->next = nullptr;
    even_tail->next = nullptr;

    oddHead = odd_dummy->next; 
    evenHead = even_dummy->next;
}

int main() {
    Node* head = nullptr;
    Node* oddHead = nullptr;
    Node* evenHead = nullptr;

    srand(time(0));

    for (int i = 0; i < 10; i++) {
        insert(head, rand() % 100 + 1);
    }
    cout << "Original List: " << endl;
    printList(head);
    splitOddEven(head, oddHead, evenHead);
    cout << "Odd list: " << endl;
    printList(oddHead);
    cout << "Even list: " << endl;
    printList(evenHead);
    return 0;
}