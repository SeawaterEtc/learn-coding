// create a linked list of 20 elements where each element contains random values from 1 to 20. Remove elements having value divisible by 3 or 5. 

#include <iostream> 
#include <cstdlib>
#include <ctime> 

using namespace std; 

struct Node {
  int data;
  Node* next;
}; 

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
  return rand() % (max - min + 1) + min;
}
// Function to create a new node with a random value
Node* createNode() {
  Node* newNode = new Node;
  newNode->data = getRandomNumber(1, 20);
  newNode->next = nullptr;
  return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node** head, Node* newNode) {
  newNode->next = *head;
  *head = newNode;
}

// Function to remove a node from the linked list
void removeNode(Node** head, int value) {
  if (*head == nullptr) {
    return; // List is empty
  }

  Node* current = *head;
  Node* previous = nullptr;

  while (current != nullptr && current->data == value) {
    *head = current->next;
    delete current;
    current = *head;
  }

  while (current != nullptr) {
    if (current->data == value) {
      if (previous != nullptr) {
        previous->next = current->next;
      }
      delete current;
      current = (previous != nullptr) ? previous->next : *head;
    } else {
      previous = current;
      current = current->next;
    }
  }
}

// Function to print the linked list
void printList(Node* head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}


// int main()
int main() {
  srand(time(0));

  Node* head = nullptr;

  // Create 20 nodes with random values
  for (int i = 0; i < 20; i++) {
    insertAtBeginning(&head, createNode());
  }
  // Creates 20 nodes with random values using a for


  cout << "Original list: ";
  printList(head);
  // print original list

  // Remove nodes divisible by 3 or 5
  removeNode(&head, 3);
  removeNode(&head, 5);

  cout << "List after removing elements divisible by 3 or 5: ";
  printList(head);
  // print after removal

  // Free the allocated memory for nodes
  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  head = nullptr;

  return 0;
}
