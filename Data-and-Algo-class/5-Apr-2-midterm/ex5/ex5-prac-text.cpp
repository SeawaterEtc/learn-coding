/*
This code implements a linked list and a function to split it into separate lists containing odd and even numbers. Let's break it down line by line:

**1-2. Header Inclusions:**

- `#include <iostream>`: Includes the standard input/output library for printing (`cout`).
- `#include <cstdlib>`: Includes the standard library for random number generation (`rand`, `srand`).

**3. `using namespace std;`:**

- Avoids writing `std::` before standard library elements like `cout` and `rand`. (Use cautiously in larger projects to avoid naming conflicts.)

**4. `struct Node { ... };`:**

- Defines a structure named `Node` to represent a node in the linked list.
    - `int data`: Stores the integer data value held by the node.
    - `Node* next`: A pointer to the next node in the list, or `nullptr` if it's the last node.

**5-11. `insert(Node* &head, int data)` Function:**

    - This function inserts a new node with the given data at the beginning of the linked list.
        - `Node* &head`: A reference to the head pointer of the list (allows modifying the head).
        - `int data`: The data value to insert in the new node.

            - `Node* newNode = new Node;`: Creates a new node dynamically allocated using `new`.
            - `newNode->data = data; newNode->next = head;`: Initializes the new node's data and sets its `next` pointer to the current head.
            - `head = newNode;`: Updates the head pointer to point to the newly inserted node.

**12-18. `printList(Node* head)` Function:**

    - This function prints the contents of the linked list.
    - `Node* head`: A pointer to the head of the list.
        - `Node* current = head;`: Creates a temporary pointer (`current`) to traverse the list.
        - `while (current != nullptr) { ... }`: A loop that continues as long as `current` is not `nullptr` (not pointing to the end).
            - `cout << current->data << " ";`: Prints the data value of the current node.
            - `current = current->next;`: Moves `current` to the next node in the list.
        - `cout << endl;`: Prints a newline after the list is printed.

**19-44. `splitOddEven(Node* head, Node* &oddHead, Node* &evenHead)` Function:**

    - This function splits the original linked list into two separate lists: one containing odd numbers and the other containing even numbers.
        - `Node* head`: Pointer to the head of the original list.
        - `Node* &oddHead`: Reference to a pointer that will store the head of the odd list (modified within the function).
        - `Node* &evenHead`: Reference to a pointer that will store the head of the even list (modified within the function).
    - `Node* odd_dummy = new Node(); Node* even_dummy = new Node();`: Creates dummy nodes for the odd and even lists (these nodes won't hold data).
    - `Node* odd_tail = odd_dummy; Node* even_tail = even_dummy;`: Creates pointers (`odd_tail` and `even_tail`) that will point to the last nodes in the odd and even lists, respectively (initially pointing to the dummies).
    - `Node* current = head;`: Creates a temporary pointer (`current`) to traverse the original list.
    - `while (current) { ... }`: Loop iterates through each node in the original list.
        - `if (current->data % 2 == 0) { ... }`: Checks if the current node's data is even.
            - `even_tail->next = current; even_tail = even_tail->next;`: If even, add the node to the even list by updating `even_tail`'s `next` pointer and moving `even_tail` to the newly added node.
        - `else { ... }`: If not even (odd).
            - `odd_tail->next = current; odd_tail = odd_tail->next;`: Add the node to the odd list similarly.
        - `current = current->next;`: Move `current` to the next node in the original list.
    - `odd_tail->next = nullptr; even_tail->next = nullptr;`: Sets the `next` pointers of the last nodes in both odd and even lists to `nullptr` to terminate them properly.
    - `oddHead = odd_dummy->next; evenHead = even_dummy->next;`: Assigns the actual heads of the odd and even lists (the nodes after the dummy nodes) to the `oddHead` and `evenHead` references, respectively. The dummy nodes themselves don't hold data and are not part of the actual lists.

**47-58. `main()` Function:**

    - This is the program's entry point where execution begins.
    - `Node* head = nullptr;`: Initializes the `head` pointer of the original list to `nullptr` (empty list).
    - `Node* oddHead = nullptr; Node* evenHead = nullptr;`: Initializes pointers for odd and even list heads to `nullptr`.
    - `srand(time(0));`: Seeds the random number generator (`rand`) with the current time to get different random values each time the program runs.
    - `for (int i = 0; i < 10; i++) { ... }`: Loop inserts 10 random numbers (between 1 and 100) into the original list using the `insert` function.
    - `cout << "Original List:" << endl;`: Prints a message indicating the original list.
    - `printList(head);`: Prints the contents of the original list.
    - `splitOddEven(head, oddHead, evenHead);`: Calls the `splitOddEven` function to split the original list into odd and even lists.
    - `cout << "Odd List: " << endl;`: Prints a message indicating the odd list.
    - `printList(oddHead);`: Prints the contents of the odd list.
    - `cout << "Even List: " << endl;`: Prints a message indicating the even list.
    - `printList(evenHead);`: Prints the contents of the even list.
    - `return 0;`: Indicates successful program termination.

In summary, this code demonstrates linked list manipulation by:

1. Defining a `Node` structure to represent nodes in the list.
2. Implementing functions to insert nodes and print the list contents.
3. Implementing a function to split a linked list into two separate lists based on odd and even numbers.
4. Creating a random list, splitting it, and printing both the original and split lists.

*/