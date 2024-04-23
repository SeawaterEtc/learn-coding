//...  
/*
I'd be glad to explain the code line by line:

**1. Header Inclusion (`#include <iostream>`)**

- This line includes the `iostream` header file, which provides functionalities for input/output operations in C++. It's necessary for using `cout` (console output) in the code.

**2. Namespace (`using namespace std;`)**

- This line brings the `std` (standard) namespace into scope, allowing you to use standard C++ objects like `cout` without the `std::` prefix.

**3. Node Class Definition (`class Node { ... }`)**

- This defines a structure called `Node` that represents a node in the doubly linked list.
    - `data`: An integer member variable to store the data value held by the node.
    - `next`: A pointer to the next node in the list.
    - `prev`: A pointer to the previous node in the list. This enables traversing the list in both directions (forward and backward).

**4. push Function (`void push(Node** head_ref, int new_data)`)**

   - This function inserts a new node with the given `new_data` at the front (beginning) of the doubly linked list.
     - `head_ref`: A double pointer to the head of the list. This allows the function to modify the `head` pointer in the `main` function.
     - `new_data`: The data to be inserted into the new node.
   - Steps performed by `push`:
     1. Creates a new node using `new Node()`.
     2. Assigns the `new_data` to the `data` member of the new node.
     3. Sets the `next` pointer of the new node to the current head (`*head_ref`). This makes the new node the first node in the list.
     4. Sets the `prev` pointer of the new node to `nullptr` as it becomes the new head (the first node has no previous node).
     5. If the current list is not empty (`*head_ref != nullptr`):
        - Updates the `prev` pointer of the previous head node (`(*head_ref)->prev`) to point to the newly inserted node. This establishes the doubly linked connection between the new head and the old head.
     6. Updates the `head_ref` (the double pointer) to point to the new node, making it the new head of the list.

**5. printList Function (`void printList(Node* node)`)**

   - This function traverses and prints the contents of the doubly linked list.
     - `node`: A pointer to the starting node of the list to be printed.
   - Steps performed by `printList`:
     1. Uses a `while` loop to iterate as long as `node` is not `nullptr` (not the end of the list).
        - Prints the data (`node->data`) of the current node.
        - Moves to the next node by updating `node` to `node->next`.

**6. main Function (`int main() { ... }`)**

   - This is the main function where the program execution begins.
   - Steps performed by `main`:
     1. Creates a `head` pointer to a `Node` and initializes it to `nullptr` (empty list).
     2. Calls `push` six times to insert nodes with values 100, 10, 20, 30, 40, and 60 at the front of the list, creating the doubly linked list 100 -> 10 -> 20 -> 30 -> 40 -> 60.
     3. Prints "Doubly linked list before inserting 50 at the front: " followed by the current list using `printList`.
     4. Calls `push` twice more to insert nodes with values 50 and 199 at the front, resulting in the modified list 199 -> 50 -> 100 -> 10 -> 20 -> 30 -> 40 -> 60.
     5. Prints "Doubly linked list after inserting 50 at the front: " followed by the modified list using `printList`.
     6. Returns 0 to indicate successful program termination.

In essence, this code demonstrates how to create a doubly linked list in C++ and insert new nodes at the front (head) of the list while maintaining the doubly linked connections between nodes.
*/