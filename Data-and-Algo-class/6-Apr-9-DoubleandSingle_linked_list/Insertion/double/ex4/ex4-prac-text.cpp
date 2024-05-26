/*
**1. Header Inclusion (`#include <iostream>`)**

- This line includes the `iostream` header file, which provides functionalities for input/output operations in C++. It's necessary for using `cout` (console output) in the code.

**2. Namespace (`using namespace std;`)**

- This line brings the `std` (standard) namespace into scope, allowing you to use standard C++ objects like `cout` without the `std::` prefix.

**3. Node Structure Definition (`struct Node { ... }`)**

- This defines a structure called `Node` that represents a node in the doubly linked list.
    - `data`: An integer member variable to store the data value held by the node.
    - `next`: A pointer to the next node in the list.
    - `prev`: A pointer to the previous node in the list. This enables traversing the list in both directions (forward and backward).

**4. DoublyLinkedList Class Definition (`class DoublyLinkedList { ... }`)**

- This defines a class called `DoublyLinkedList` that manages a doubly linked list.
    - **Private Members:**
        - `head`: A pointer to the first node (head) of the list. This is kept private because it's the internal representation of the list.

    - **Public Members (Member Functions):**
        - **Constructor (`DoublyLinkedList() { ... }`)**
            - Initializes the `head` pointer to `nullptr`, indicating an empty list.
        - **insertAt(int newElement, int position)**
            - Inserts a new node with the given `newElement` at the specified `position` in the list.
            - `newElement`: The data value to be inserted.
            - `position`: The position where the new node should be inserted (starting from 1).
            - Steps performed by `insertAt`:
                1. Creates a new `Node` using `new Node()`.
                2. Assigns the `newElement` to the `data` member of the new node.
                3. Sets both `next` and `prev` pointers of the new node to `nullptr` initially.
                4. Handles invalid positions:
                   - If `position < 1`, prints an error message and exits.
                5. Handles inserting at the head (position 1):
                   - Sets the `next` pointer of the new node to the current `head`.
                   - If the current list is not empty (`head != nullptr`):
                       - Updates the `prev` pointer of the previous head node to point to the newly inserted node.
                   - Updates the `head` pointer to point to the new node, making it the new head.
                6. Handles inserting at other positions:
                   - Uses a temporary pointer `temp` to traverse the list until reaching the node before the desired position.
                   - Checks for positions beyond the existing list length:
                       - If `temp` becomes `nullptr` before reaching the desired position, prints an error message and exits.
                   - Connects the new node with the surrounding nodes:
                       - Sets the `next` pointer of the new node to the current `next` of the previous node.
                       - Sets the `prev` pointer of the new node to the previous node.
                       - Updates the `next->prev` pointer of the node after the insertion point to point to the new node (if there's a next node).
                       - Updates the `prev` pointer of the previous node to point to the new node.
                7. Handles a null previous node (potential edge case):
                   - If `temp` (the previous node) is `nullptr` after iterating, prints an error message.
        - **display()**
            - Traverses and prints the contents of the doubly linked list.
            - Uses a temporary pointer `current` to start from the `head` and iterate through the list.
            - While `current` is not `nullptr` (not the end of the list):
                - Prints the `data` of the current node.
                - Moves to the next node by updating `current` to `current->next`.
            - Prints a newline character (`endl`) at the end.

**5. main Function (`int main() { ... }`)**

- This is the main function where the program execution begins.
   - Steps performed by `main`:
     1. Creates an object `myList` of the `DoublyLinkedList` class.
     2. Calls `insertAt` on `myList` multiple times to insert nodes with various values at different positions, creating a doubly linked list.
     3. Prints "Original doubly
*/