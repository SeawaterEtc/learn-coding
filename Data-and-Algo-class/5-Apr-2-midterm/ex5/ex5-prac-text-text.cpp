/*
This code implements a linked list and a function to split it into separate lists containing odd and even numbers. Let's break it down line by line:

**1-2. Header Inclusions:**

- : Includes the standard input/output library for printing (`cout`).
- : Includes the standard library for random number generation (`rand`, `srand`).

**3. :**

- Avoids writing `std::` before standard library elements like `cout` and `rand`. (Use cautiously in larger projects to avoid naming conflicts.)

**4. ``:**

- Defines a structure named `Node` to represent a node in the linked list.
    - : Stores the integer data value held by the node.
    - : A pointer to the next node in the list, or `nullptr` if it's the last node.

**5-11.  Function:**

    - This function inserts a new node with the given data at the beginning of the linked list.
        - : A reference to the head pointer of the list (allows modifying the head).
        - : The data value to insert in the new node.

            - : Creates a new node dynamically allocated using `new`.
            - : Initializes the new node's data and sets its `next` pointer to the current head.
            - : Updates the head pointer to point to the newly inserted node.

**12-18.  Function:**

    - This function prints the contents of the linked list.
    - : A pointer to the head of the list.
        - : Creates a temporary pointer (`current`) to traverse the list.
        - : A loop that continues as long as `current` is not `nullptr` (not pointing to the end).
            - : Prints the data value of the current node.
            - : Moves `current` to the next node in the list.
        - : Prints a newline after the list is printed.

**19-44.  Function:**

    - This function splits the original linked list into two separate lists: one containing odd numbers and the other containing even numbers.
        - : Pointer to the head of the original list.
        - : Reference to a pointer that will store the head of the odd list (modified within the function).
        - : Reference to a pointer that will store the head of the even list (modified within the function).
    - : Creates dummy nodes for the odd and even lists (these nodes won't hold data).
    - : Creates pointers (`odd_tail` and `even_tail`) that will point to the last nodes in the odd and even lists, respectively (initially pointing to the dummies).
    - : Creates a temporary pointer (`current`) to traverse the original list.
    - : Loop iterates through each node in the original list.
        - : Checks if the current node's data is even.
            - : If even, add the node to the even list by updating `even_tail`'s `next` pointer and moving `even_tail` to the newly added node.
        - : If not even (odd).
            - : Add the node to the odd list similarly.
        - : Move `current` to the next node in the original list.
    - : Sets the `next` pointers of the last nodes in both odd and even lists to `nullptr` to terminate them properly.
    - : Assigns the actual heads of the odd and even lists (the nodes after the dummy nodes) to the `oddHead` and `evenHead` references, respectively. The dummy nodes themselves don't hold data and are not part of the actual lists.

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