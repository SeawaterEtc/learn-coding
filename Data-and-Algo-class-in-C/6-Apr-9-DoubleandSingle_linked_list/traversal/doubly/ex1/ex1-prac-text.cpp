/*
I'd be glad to explain the code line by line:

**1. Header Inclusion (`#include <iostream>`)**
- This line includes the `iostream` header file, which provides functionalities for input/output operations like `cout` (used for printing to the console).

**2. Namespace (`using namespace std;`)**
- This line brings the `std` namespace into scope, allowing you to use standard C++ objects like `cout` without the `std::` prefix.

**3. Node Structure Definition (`struct Node`)**
   - This code defines a structure named `Node` that serves as the building block of the doubly linked list.
     - `data`: An integer member variable to store the actual data value of a node.
     - `next`: A pointer to a `Node` object, representing the next element in the linked list.
     - `prev`: Another pointer to a `Node` object, pointing to the previous element in the linked list, enabling traversal in both directions.

**4. DoublyLinkedList Class (`class DoublyLinkedList`)**
   - This code defines a class named `DoublyLinkedList` that manages the doubly linked list operations.
     - `private:`: This section declares member variables that are accessible only within the class.
       - `head`: A pointer to a `Node` object, acting as the head (beginning) of the linked list. It's initialized to `nullptr` (null pointer) to indicate an empty list at the start.
     - `public:`: This section declares member functions that can be accessed and used from outside the class.
       - `DoublyLinkedList()`: The constructor is called when an object of this class is created. It initializes the `head` pointer to `nullptr`.
       - `push_back(int newElement)`: This function adds a new element (specified by `newElement`) to the end of the linked list.
           - `Node* newNode = new Node()`: A new `Node` object is dynamically allocated in memory using `new`.
           - `newNode->data = newElement`: The data field (`data`) of the new node is assigned the value of `newElement`.
           - `newNode->next = nullptr`: Since this node is being added at the end, its `next` pointer is initially set to `nullptr` (no next element yet).
           - `newNode->prev = nullptr`: Initially, the new node doesn't have a previous element, so `prev` is set to `nullptr` as well.
           - `if (head == nullptr)`: Checks if the list is empty (head is `nullptr`).
             - `head = newNode`: If empty, the new node becomes both the head and the tail (since there's only one element).
           - `else`: If the list is not empty, we need to find the last node and update its `next` and the new node's `prev` pointers.
             - `Node* temp = head`: A temporary pointer `temp` is created to traverse the list. It starts at the head.
             - `while (temp->next != nullptr)`: A loop continues as long as `temp->next` is not `nullptr` (not the last node yet). Inside the loop, `temp` is moved to the next node in the list.
             - `temp->next = newNode`: Once `temp` reaches the last node, its `next` pointer is set to point to the new node.
             - `newNode->prev = temp`: The new node's `prev` pointer is set to point to the last node, establishing the two-way link.
       - `PrintList()`: This function prints the contents of the linked list to the console.
           - `Node* temp = head`: A temporary pointer `temp` is created to traverse the list, starting at the head.
           - `if (temp != nullptr)`: Checks if the list is empty.
             - `cout << "The list contains: ";`: If not empty, a message is printed indicating the contents.
             - `while (temp != nullptr)`: A loop continues as long as `temp` is not `nullptr` (not the end of the list yet). Inside the loop:
               - `cout << temp->data << " ";`: The data of the current node pointed to by `temp` is printed.
               - `temp = temp->next;`: `temp` is moved to the next node for traversal.
             - `cout << endl;`: A newline character is printed after the list elements.
           - `else`: If the list is empty, a message indicating that the list is empty is printed.

**5. main() Function**
   - This is the entry point of the program execution
*/