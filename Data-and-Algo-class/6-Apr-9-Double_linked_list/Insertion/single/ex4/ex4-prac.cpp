// Insert a single linked-list at any position
// With the given single linked-list 5 -> 7 -> 8 -> 6 -> 1 -> 4 -> 8 -> 5 -> 8 add 7 to the forth 

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// Create a global variable for the size of the Linked List
int listSize = 0;

void insertPosition(int pos, int data, Node** head) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;

    if (pos < 1 || pos > listSize + 1) {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
        listSize++; 
    } else {
        Node* temp = *head;
        while (--pos > 1) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        listSize++;
    }
}

void display(Node* node) {
    cout << "Linked List: ";
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout <<"nullptr" << endl;
}

int main() {
    Node* head = nullptr;
    // Insert some initial nodes
    insertPosition(1, 5, &head);
    insertPosition(2, 7, &head);
    insertPosition(3, 8, &head);
    insertPosition(4, 6, &head);
    insertPosition(5, 1, &head);
    insertPosition(6, 4, &head);
    insertPosition(7, 8, &head);
    insertPosition(8, 5, &head);
    cout <<"Original Linked list: " << endl;
    display(head);
    cout <<"Insert 7 at the fourth position: " << endl;
    insertPosition(4, 7, &head); // Insert 7 at the fourth position
    display(head);

    return 0;
}
