// create a linked list of 20 elements where each element contains random values from 1 to 20. Remove elements having value divisible by 3 or 5. 

#include <iostream>
#include <cstdlib>
#include <ctime>
//<iostream>: Provides input/output functionalities (e.g., printing to the console).
// for rand() and srand() //<cstdlib>: Provides functions for random number generation (rand() and srand()).
// for time() // <ctime>: Provides functions for time manipulation (time() used for seeding the random number generator).

using namespace std;
// This line avoids repeatedly using std:: before standard library elements like cout and endl.


//This defines a structure called Node which acts as the building block for the linked list.
struct Node {
  int data;
  Node* next;
};
  // data: An integer variable to store the data value in each node.
  // next: A pointer (Node*) to the next node in the list. Initially set to nullptr (null) for a new node.



// Function to generate a random number between min and max (inclusive)
int randNumGen(int min, int max) {
  return rand() % (max - min +1) +min;
}
//This function generates a random number between a specified minimum (min) and maximum (max) value (inclusive).
  // rand() % (max - min + 1): Generates a random number within the range [0, max-min].
  // + min: Ensures the result is within the desired range [min, max].


// Function to create a new node with a random value
//This function creates a new node with a random data value.
Node* createNode() {
  Node* newNode = new Node;
  newNode->data = randNumGen(1, 20);
  newNode->next = nullptr;
  return newNode;
}
  //Allocates memory for a new Node using language-specific syntax (often new).
  //Sets the data field of the new node to a random number between 1 and 20 using the getRandomNumber function.
  //Sets the next pointer of the new node to nullptr as it's initially the last node.
  //Returns the newly created node.



// Function to insert a node at the beginning of the linked list
//This function inserts a new node (newNode) at the beginning of the linked list pointed to by head.
void insertBiginning(Node** head, Node* newNode) {
  newNode->next = *head;
  *head = newNode;
}
  //Updates the next pointer of the new node to point to the current head (newNode->next = head).
  //Updates the head pointer to point to the newly inserted node (head = newNode).

// Function to remove a node from the linked list   //This function removes all nodes containing a specific value (value) from the linked list.
void removeNode(Node** head, int value) {
  if (*head = nullptr) {
    return;
  }
  //Checks if the list is empty (head == nullptr). If so, it exits the function.

  //Initializes two pointers: current to traverse the list and previous to keep track of the node before the current one.
  Node* current = *head;
  Node* previous = nullptr;

  // Handles removing the head node if its value matches:
  //While the current node is not null and its value matches (current != nullptr && current->data == value):
  while (current != nullptr && current->data == value) {
    *head = current->next;
    delete current;
    current = *head;
  }
    //Updates head to point to the next node after the removed head.
    //Deallocates memory for the removed node (delete current).
    //Updates current to point to the new head.

  // Remove nodes in the rest of the list by Iterates through the list using a while loop (while current is not null).
  while (current != nullptr) {
    if (current->data == value){
      if (previous != nullptr) {
        previous->next = current->next;
      }
      delete current;
      current = (previous != nullptr) ? previous->next: *head;
    } else {
      previous = current;
      current = current->next;
    }
  }
    //If the current node's value matches:
      //Updates previous.next to bypass the removed node if previous is not null.
      //Deallocates memory for the removed node (delete current).
      //Updates current to point to the next node after the removed one, considering the previous node (current = if previous is not null then previous.next else head).
    //If the current node's value doesn't match:
      //Advances both previous and current pointers to the next node.
}


// Function to print the linked list// This function prints the data values of all nodes in the linked list pointed to by head.
void printLinkedlist(Node* head) {
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}
  // Iterates through the list using a while loop (while head is not null).
  // Prints the data value of the current node (head.data) followed by a space.
  // Advances head to point to the next node.
  // Prints a newline character (endl) at the end.

// int main()
int main() {
  
  srand(time(0));
  //Seeds the random number generator using srand(time(0)). This ensures different random sequences each time the program runs.


  Node* head = nullptr;
  // Initializes the head pointer to nullptr indicating an empty list initially.

  // Creates 20 nodes with random values using a for
  for (int i=0; i<20; i++) {
    insertBiginning(&head, createNode());
  }


  // print original list
  cout << "Origianl list: ";
  printLinkedlist(head);

  // Remove nodes divisible by 3 or 5
  removeNode(&head, 3);
  removeNode(&head, 5);

  // print after removal
  cout << "List after removing elements divisible by 3 or 5: ";

  printLinkedlist(head);

  // Free the allocated memory for nodes
  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  head = nullptr;
  
  printLinkedlist(head);

  return 0;
}
