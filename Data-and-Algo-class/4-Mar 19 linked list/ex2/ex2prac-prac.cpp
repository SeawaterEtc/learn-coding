// Write a program to generate 10 random values. Add these values into the linked list in ascending order. 

// <iostream>: For input/output operations like printing to the console.
// <cstdlib>: For random number generation functions (rand() and srand()).
// <ctime>: For time functions (time() used for seeding the random number generator).
#include <iostream>
#include <cstdlib>
#include <ctime>

// Brings elements of the std namespace into scope, avoiding repetitive std:: prefixes for standard library elements.
using namespace std;

// Defines a structure called Node representing a node in the linked list:
struct Node {
  //data: An integer to store the node's data value.
  int data;
  //next: A pointer to the next node in the list, initially set to nullptr (null) for a new node.
  Node* next;
};

//(createNode Function):Creates a new node with the given value:
Node* createNode(int value) {
  //Allocates memory for a new Node using new.
  Node* newNode = new Node;
  //Sets the data field of the new node to the provided value.
  newNode->data = value;
  //Sets the next pointer of the new node to nullptr (initially the last node).
  newNode->next = nullptr;
  //Returns a pointer to the newly created node.
  return newNode;
}

// (insertSorted Function): Inserts a new node (newNode) into a linked list (head) in a sorted manner:
  //Initializes a current pointer to iterate through the list.
  
  //Handles insertion at the beginning:
  //If the list is empty (*head == nullptr) or the new node's data is less than the head's data (newNode->data < (*head)->data):
    //Links the new node's next pointer to the current head.
    //Updates the head pointer to point to the new node.
  
  //Handles insertion elsewhere:
    //Traverses the list using a while loop until it finds the appropriate position for insertion (current->next != nullptr && current->next->data <= newNode->data).
    //Links the new node's next pointer to the node after the current one (current->next = newNode->next).
    //Updates the next pointer of the current node to point to the new node (current->next = newNode).


//(printList Function): Prints the data values of all nodes in the linked list (head):
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
