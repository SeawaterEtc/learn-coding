//...  
/*
I'd be glad to explain the code line by line:

**1. `#include <iostream>`**
   - This line includes the `iostream` header file, which provides functionalities for input/output operations in C++. It's necessary for using `cout` and `endl` later in the code.

**2. `using namespace std;`**
   - This line brings the `std` namespace into scope, allowing you to use standard C++ objects like `cout` and `endl` without having to prefix them with `std::`.

**3. `struct Node { ... };`**
   - This defines a structure (user-defined data type) named `Node`. A structure is a way to group variables of potentially different data types under a single name.
     - `int data;`: This member variable of the `Node` structure will hold an integer value representing the data stored in the node.
     - `Node* next;`: This member variable is a pointer to another `Node` structure. It will point to the next node in the doubly linked list.
     - `Node* prev;`: This member variable is another pointer to a `Node` structure. However, it points to the previous node in the doubly linked list, making it doubly linked.

**4. `void insertFront(Node** head, int data) { ... }`**
   - This function is named `insertFront` and it's likely intended to insert a new node with the given `data` at the beginning (front) of the doubly linked list.
     - `Node** head`: This is a double pointer to a `Node` structure. It's used to modify the `head` pointer of the linked list within the function.
     - `int data`: This is the integer value to be stored in the new node's `data` member.
     - `Node* newNode = new Node;`: Creates a new node dynamically on the heap using `new` and assigns its address to `newNode`.
     - `newNode->data = data;`: Sets the `data` member of the newly created `newNode` to the provided `data` value.
     - `newNode->next = *head;`: Sets the `next` pointer of `newNode` to point to the current `head` node (the first node in the list before insertion).
     - `newNode->prev = nullptr;`: Sets the `prev` pointer of `newNode` to `nullptr` since it will be the new first node and won't have a previous node.
     - `if (*head != nullptr) { ... }`: Checks if the list wasn't empty before insertion (`*head != nullptr`). If it wasn't empty:
         - `(*head)->prev = newNode;`: Sets the `prev` pointer of the current `head` (which will become the second node after insertion) to point to the newly inserted `newNode`.
     - `*head = newNode;`: Updates the `head` pointer to point to the newly inserted `newNode`, making it the new first node.

**5. `void printList(Node* head) { ... }`**
   - This function is named `printList` and it's likely intended to traverse the doubly linked list and print the data of each node.
     - `Node* head`: This is a pointer to a `Node` structure, representing the head of the list to be printed.
     - `Node* current = head;`: Creates a temporary pointer `current` and initializes it to the `head` to start traversing from the beginning.
     - `while (current != nullptr) { ... }`: This loop continues as long as `current` is not `nullptr` (meaning it hasn't reached the end of the list).
         - `std::cout << current->data << " ";`: Prints the data stored in the current node using `cout`.
         - `current = current->next;`: Moves the `current` pointer to the next node in the list.
     - `std::cout << std::endl;`: Prints a newline character after the list is printed.

**6. `int main() { ... }`**
   - This is the main function where the program execution begins.
     - `Node* head = nullptr;`: Creates a `head` pointer to a `Node` structure and initializes it to `nullptr`, indicating an empty list initially.
     - `insertFront(&head, 3);`: Calls the `insertFront` function three times to insert nodes with values 3, 2, and 1 at the front of the list, creating a list with 1 -> 2 -> 3.
     - `cout << "Doubly linked list: ";`: Prints a message "Doubly linked list:
*/