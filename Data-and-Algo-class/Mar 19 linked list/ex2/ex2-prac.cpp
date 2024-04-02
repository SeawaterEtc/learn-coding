#include <iostream>
#include <cstdlib> 
#include <ctime>  
// <iostream>: For input/output operations like printing to the console.
// <cstdlib>: For random number generation functions (rand() and srand()).
// <ctime>: For time functions (time() used for seeding the random number generator).

using namespace std;
// Brings elements of the std namespace into scope, avoiding repetitive std:: prefixes for standard library elements.


struct Node {
  int data;
  Node* next;
};
// Defines a structure called Node representing a node in the linked list:
  //data: An integer to store the node's data value.
  //next: A pointer to the next node in the list, initially set to nullptr (null) for a new node.

Node* createNode(int value) {
  Node* newNode = new Node;
  newNode->data = value;
  newNode->next = nullptr;
  return newNode;
}
//13-18 (createNode Function):
//Creates a new node with the given value:
  //Allocates memory for a new Node using new.
  //Sets the data field of the new node to the provided value.
  //Sets the next pointer of the new node to nullptr (initially the last node).
  //Returns a pointer to the newly created node.


void insertSorted(Node** head, Node* newNode) {
  Node* current = *head;

  if (*head == nullptr || newNode->data < (*head)->data) {
    newNode->next = *head;
    *head = newNode;
  } else {
    while (current->next != nullptr && current->next->data <= newNode->data) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}
// 20-32 (insertSorted Function): //Inserts a new node (newNode) into a linked list (head) in a sorted manner:
  //Initializes a current pointer to iterate through the list.
  
  //Handles insertion at the beginning:
  //If the list is empty (*head == nullptr) or the new node's data is less than the head's data (newNode->data < (*head)->data):
    //Links the new node's next pointer to the current head.
    //Updates the head pointer to point to the new node.
  
  //Handles insertion elsewhere:
    //Traverses the list using a while loop until it finds the appropriate position for insertion (current->next != nullptr && current->next->data <= newNode->data).
    //Links the new node's next pointer to the node after the current one
    //Updates the next pointer of the current node to point to the new node 


void printList(Node* head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}
// 34-41 (printList Function): Prints the data values of all nodes in the linked list (head):
  // Uses a while loop to iterate through the list.
  // Prints the data value of the current node (cout << head->data << " ").
  // Advances the head pointer to the next node in each iteration.
  // Prints a newline character (endl) at the end.

// int main ()
  // Seeds the random number generator using srand(time(0)).
  // Initializes a head pointer to nullptr for the empty linked list.
  //Creates 10 nodes with random values between 1 and 100:
  //Generates a random value (value = rand() % 100 + 1).
  //Creates a new node with that value using createNode.
  //Inserts the node into the linked list in sorted order using insertSorted.
  //Prints the linked list with "Linked list in ascending order: ".
  //Deallocates memory for all nodes in the list
int main() {
  srand(time(0)); 

  Node* head = nullptr; 

  for (int i = 0; i < 10; i++) {
    int value = rand() % 100 + 1; 
    Node* newNode = createNode(value);
    insertSorted(&head, newNode);
  }

  cout << "Linked list in ascending order: ";
  printList(head);

  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }

  return 0;
}
