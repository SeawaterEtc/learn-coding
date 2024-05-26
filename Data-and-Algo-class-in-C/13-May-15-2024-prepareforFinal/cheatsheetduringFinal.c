// write c to Create a binary tree of 30 nodes with random numbers. 
// Create function to do preorder traversal, inorder traversal, and postorder traversal
// Function to visulize the tree structure 
// Function Display all leaves of the tree. 
// Function to calculate tree height. 
// function to calculate sum value of each node and its childs. 
// function to sum the value of all sub tree. 
// Function to display all elements having node values divisible by 3 or 5. 
// Function to display the predecessor of nodes having value divisible by 3 or 5. 
// function to Sum all values of the tree. 

// function to Calculate average of all tree leaves. 
// function to Calculate average of the tree. 
// function to Display node value and its Childs's value. 

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Preorder traversal: Root -> Left -> Right
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Inorder traversal: Left -> Root -> Right
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Postorder traversal: Left -> Right -> Root
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Display all leaves of the tree
void displayLeaves(struct TreeNode* root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            printf("%d ", root->data);
        }
        displayLeaves(root->left);
        displayLeaves(root->right);
    }
}

// Calculate tree height
int calculateHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Calculate sum value of each node and its children
int calculateSum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftSum = calculateSum(root->left);
    int rightSum = calculateSum(root->right);
    return root->data + leftSum + rightSum;
}

// Compute the sum of all subtree values
int sumSubtree(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftSum = sumSubtree(root->left);
    int rightSum = sumSubtree(root->right);

    return root->data + leftSum + rightSum;
}

// Display nodes with values divisible by 3 or 5
void displayDivisibleNodes(struct TreeNode* root) {
    if (root == NULL)
        return;

    if (root->data % 3 == 0 || root->data % 5 == 0)
        printf("%d ", root->data);

    displayDivisibleNodes(root->left);
    displayDivisibleNodes(root->right);
}

// Function to find the predecessor of a given node
struct TreeNode* findPredecessor(struct TreeNode* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value) {
        // Node found, return its predecessor
        // (Assuming the tree has parent pointers; adjust accordingly)
        return root->left; // In this example, we assume left child is predecessor
    } else if (value < root->data) {
        // Search in the left subtree
        return findPredecessor(root->left, value);
    } else {
        // Search in the right subtree
        return findPredecessor(root->right, value);
    }
}

// Function to display the predecessor of nodes divisible by 3 or 5
void displayPredecessor(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->data % 3 == 0 || root->data % 5 == 0) {
        printf("Node %d: Predecessor is ", root->data);
        struct TreeNode* pred = findPredecessor(root, root->data);
        if (pred) {
            printf("%d\n", pred->data);
        } else {
            printf("N/A\n");
        }
    }
    displayPredecessor(root->left);
    displayPredecessor(root->right);
}

// Function to calculate the sum of all values in the tree
int sumTree(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sumTree(root->left) + sumTree(root->right);
}

// Function to calculate the average of all leaf nodes
double averageLeaf(struct TreeNode* root, int* leafCount) {
    if (root == NULL) {
        return 0.0;
    }
    if (root->left == NULL && root->right == NULL) {
        // Leaf node
        (*leafCount)++;
        return root->data;
    }
    double leftSum = averageLeaf(root->left, leafCount);
    double rightSum = averageLeaf(root->right, leafCount);
    return leftSum + rightSum;
}

// Function to calculate the average of the entire tree
double averageTree(struct TreeNode* root, int* nodeCount) {
    if (root == NULL) {
        return 0.0;
    }
    (*nodeCount)++;
    double leftSum = averageTree(root->left, nodeCount);
    double rightSum = averageTree(root->right, nodeCount);
    return root->data + leftSum + rightSum;
}

// Function to display node value and its children's values
void displayNodeAndChildren(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("Node %d: Left child = ", root->data);
    if (root->left) {
        printf("%d", root->left->data);
    } else {
        printf("N/A");
    }
    printf(", Right child = ");
    if (root->right) {
        printf("%d", root->right->data);
    } else {
        printf("N/A");
    }
    printf("\n");

    displayNodeAndChildren(root->left);
    displayNodeAndChildren(root->right);
}



int main() {
    struct TreeNode* root = NULL;
    int i, data;

    for (i = 0; i < 30; ++i) {
        data = rand() % 100; 
        root = insert(root, data);
    }

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Leaves of the tree: ");
    displayLeaves(root);
    printf("\n");

    printf("Tree height: %d\n", calculateHeight(root));

    printf("Sum of all nodes: %d\n", calculateSum(root));


    int totalSum = sumSubtree(root);
    printf("Sum of all subtree values: %d\n", totalSum);

    printf("Nodes with values divisible by 3 or 5: ");
    displayDivisibleNodes(root);
    printf("\n");


    printf("predecessor of nodes divisible by 3 or 5");
    displayPredecessor(root);
    printf("\n");

    int totalSum1 = sumTree(root);
    printf("Sum of all values in the tree: %d\n", totalSum);
    printf("\n");

    int leafCount = 0;
    double leafSum = averageLeaf(root, &leafCount);
    double leafAverage = leafSum / leafCount;
    printf("Average of leaf nodes: %.2lf\n", leafAverage);

    int totalNodeCount = 0;
    double totalSum2 = averageTree(root, &totalNodeCount);
    double totalAverage = totalSum / totalNodeCount;
    printf("Average of all nodes in the tree: %.2lf\n", totalAverage);

    printf("Node values and their children:\n");
    displayNodeAndChildren(root);

    return 0;
}
//write c to Create doubly link list using struct
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to display the doubly linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Display the doubly linked list
    printf("Doubly linked list: ");
    display(head);

    // Clean up memory (optional)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
//write c to create single linked-list using struct

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single linked-list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create a linked-list with three nodes
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    // Link the nodes
    head->next = second;
    second->next = third;

    // Print the linked-list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Clean up: free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
// write c doubly linked to Delete the starting Node

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printf("Original Linked list: ");
    printList(head);

    deleteNode(&head, head); // Delete the first node
    deleteNode(&head, head->next); // Delete the second node
    deleteNode(&head, head->next); // Delete the third node

    printf("\nModified Linked list: ");
    printList(head);

    return 0;
}
// write c doubly linked to Delete the last Node

// write c doubly linked to Delete the starting Node

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printf("Original Linked list: ");
    printList(head);

    deleteNode(&head, head); // Delete the first node
    deleteNode(&head, head->next); // Delete the second node
    deleteNode(&head, head->next); // Delete the third node

    printf("\nModified Linked list: ");
    printList(head);

    return 0;
}
// write c doubly linked to Delete node at the specific position of the doubly linked-list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to delete a node in a doubly linked list
void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

// Function to delete the node at the given position in the doubly linked list
void deleteNodeAtGivenPos(struct Node** head_ref, int n) {
    if (*head_ref == NULL || n <= 0)
        return;

    struct Node* current = *head_ref;
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;

    if (current == NULL)
        return;

    deleteNode(head_ref, current);
}

// Function to insert a node at the beginning of the doubly linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

// Function to print nodes in a given doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printf("Doubly linked list before deletion:\n");
    printList(head);

    int position_to_delete = 2; // Example: delete node at position 2
    deleteNodeAtGivenPos(&head, position_to_delete);

    printf("\nDoubly linked list after deletion of node at position %d:\n", position_to_delete);
    printList(head);

    return 0;
}
// write c single linked to Delete the starting Node 

#include <stdio.h>
#include <stdlib.h>

// Define the singly linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to delete the starting node
void deleteStartingNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Starting node deleted successfully.\n");
}

// Example usage
int main() {
    struct Node* head = NULL; // Initialize an empty list

    // Add some nodes (you can modify this part as needed)
    // ...

    // Call the deleteStartingNode function
    deleteStartingNode(&head);

    // Print the updated list (if needed)
    // ...

    return 0;
}
// write c single linked to Delete the last Node

#include <iostream>
using namespace std;

// Linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to remove the last node of the linked list
Node* removeLastNode(struct Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    // Find the second-to-last node
    Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    // Delete the last node
    delete (second_last->next);

    // Change next of second-to-last node
    second_last->next = NULL;

    return head;
}

// Function to push a node at the head
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Driver code
int main() {
    Node* head = NULL;
    push(&head, 12);
    push(&head, 29);
    push(&head, 11);
    push(&head, 23);
    push(&head, 8);

    head = removeLastNode(head);

    for (Node* temp = head; temp != NULL; temp = temp->next)
        cout << temp->data << " ";

    return 0;
}
// write c single linked to Delete the specific position of the single linked-list

#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the front of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to delete a node at the given position
void deleteNode(struct Node** head_ref, int position) {
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;

    // If the node to be deleted is the root
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Traverse to the previous node
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is out of bounds
    if (temp == NULL || temp->next == NULL)
        return;

    // Update the next pointer to skip the node at the given position
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);

    printf("Created Linked List: ");
    printList(head);

    deleteNode(&head, 4); // Delete node at position 4

    printf("\nLinked List after Deletion at position 4: ");
    printList(head);

    return 0;
}
// write c to Insert a double linked-list from front (head)

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the front (head) of the doubly linked list
struct Node* insertFront(struct Node* head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = head;

    // Update the previous pointer of the current head (if it exists)
    if (head != NULL) {
        head->prev = newNode;
    }

    // Set the new node as the head
    head = newNode;
    return head;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Initialize an empty doubly linked list
    struct Node* head = NULL;

    // Insert nodes at the front
    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertFront(head, 30);

    // Print the list
    printf("Doubly linked list: ");
    printList(head);

    return 0;
}
// Write c to insert a 5 element doubly linked-list at any position

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a given position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Invalid position. List size is smaller than the specified position.\n");
        return;
    }
    newNode->prev = current->prev;
    newNode->next = current;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    } else {
        *head = newNode;
    }
    current->prev = newNode;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    // Inserting elements at different positions
    insertAtPosition(&head, 10, 1); // Insert 10 at position 1
    insertAtPosition(&head, 20, 2); // Insert 20 at position 2
    insertAtPosition(&head, 30, 3); // Insert 30 at position 3
    insertAtPosition(&head, 40, 2); // Insert 40 at position 2
    insertAtPosition(&head, 50, 4); // Insert 50 at position 4

    printf("Doubly linked list: ");
    printList(head);

    return 0;
}
// Write c to Insert a 5 element doubly linked-list at the end of the list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Otherwise, traverse to the end of the list
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Attach the new node to the end
    current->next = newNode;
    newNode->prev = current;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert 5 elements at the end
    for (int i = 1; i <= 5; ++i) {
        insertAtEnd(&head, i);
    }

    // Print the list
    printf("Doubly linked list: ");
    printList(head);

    return 0;
}
//Write c to Insert a single linked-list from front (head)

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the front (head) of the linked list
struct Node* insertAtFront(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert nodes at the front
    head = insertAtFront(head, 10);
    head = insertAtFront(head, 20);
    head = insertAtFront(head, 30);

    // Print the linked list
    printf("Linked list after insertion:\n");
    printList(head);

    // Clean up memory (free nodes)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
//Write c to Insert a single linked-list at any position


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at a given position
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        // Insert at the beginning
        newNode->next = *head;
        *head = newNode;
    } else {
        // Traverse to the (position-1)th node
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; ++i) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position. List size is smaller than the specified position.\n");
            return;
        }

        // Insert after the (position-1)th node
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Example usage
    insertAtPosition(&head, 10, 1); // Insert 10 at the beginning
    insertAtPosition(&head, 20, 2); // Insert 20 after the first node
    insertAtPosition(&head, 30, 3); // Insert 30 after the second node

    printf("Linked list after insertion: ");
    printList(head);

    return 0;
}
//Write c to Insert a single linked-list at the end of the list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node at the end
    current->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Print the linked list
    printf("Linked list: ");
    printList(head);

    return 0;
}
//write c double linked list and do traversal from left to right


#include <stdio.h>
#include <stdlib.h>



struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }

    return newNode;
}

void traverseLeftToRight(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    printf("Doubly Linked List (left to right): ");
    traverseLeftToRight(head);

    return 0;
}
//write c double linked list to do traversal from right to left

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to traverse the doubly linked list from right to left
void traverseRightToLeft(struct Node* head) {
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Traverse the doubly linked list from right to left
    printf("Traversal from right to left: ");
    traverseRightToLeft(head);

    // Clean up memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
//write c single linked list and do traversal from left to right

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to traverse and print the elements of the linked list
void traverse(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some elements into the linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Print all elements of the singly linked list
    traverse(head);

    // Free memory to avoid memory leaks
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
//write c single linked list and do traversal from right to left

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to traverse the linked list from right to left
void traverseRightToLeft(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    // Recursively traverse the rest of the list
    traverseRightToLeft(head->next);

    // Print the data of the current node
    printf("%d ", head->data);
}

int main() {
    struct Node* head = NULL;

    // Insert some elements into the linked list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    // Traverse the linked list from right to left
    printf("Traversing from right to left: ");
    traverseRightToLeft(head);
    printf("\n");

    // Free memory to avoid memory leaks
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
//write c language to create a linked list of 20 elements where each element contains random values from 1 to 20. Remove elements having value divisible by 3 or 5. 

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

// Define the linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove nodes with values divisible by 3 or 5
void removeDivisibleNodes(struct Node** head) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data % 3 == 0 || current->data % 5 == 0) {
            if (prev == NULL) {
                *head = current->next;
                free(current);
                current = *head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    srand(time(NULL));

    // Create a linked list with 20 random values
    for (int i = 0; i < 20; ++i) {
        int randomValue = rand() % 20 + 1;
        insertNode(&head, randomValue);
    }

    printf("Original linked list:\n");
    displayList(head);

    // Remove nodes with values divisible by 3 or 5
    removeDivisibleNodes(&head);

    printf("Linked list after removing divisible elements:\n");
    displayList(head);

    // Free memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
// Write c program to generate 10 random element and add them into the linked list in ascending order. 

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to swap two nodes
struct Node* swap(struct Node* ptr1, struct Node* ptr2) {
    struct Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

// Function to sort the list using Bubble Sort
void bubbleSort(struct Node** head, int count) {
    struct Node** h;
    int i, j, swapped;
    for (i = 0; i < count; i++) {
        h = head;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++) {
            struct Node* p1 = *h;
            struct Node* p2 = p1->next;
            if (p1->data > p2->data) {
                // Update the link after swapping
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h)->next;
        }
        // Break if the loop ended without any swap
        if (swapped == 0)
            break;
    }
}

// Function to print the list
void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of a linked list
void insertAtTheBegin(struct Node** start_ref, int data) {
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}

// Driver Code
int main() {
    int arr[] = { 78, 20, 10, 32, 1, 5 };
    int list_size, i;
    struct Node* start = NULL;
    list_size = sizeof(arr) / sizeof(arr[0]);

    // Create linked list from the array arr[]
    for (i = list_size - 1; i >= 0; i--)
        insertAtTheBegin(&start, arr[i]);

    // Print list before sorting
    printf("Linked list before sorting:\n");
    printList(start);

    // Sort theinked list
    bubbleSort(&start, list_size);

    // Print list after sorting
    printf("Linked list after sorting:\n");
    printList(start);

    return 0;
}
//write c program to Create a Matrix of 4 rows and 4 column.
//Then Initialize the Matrix with random value from 0 to 99.
//function to show values in diagonal of the matrix
//function to sum all values of each row
//function to sum all value of each column
//function to find highest value in the Matrix
//function to sum all items of the matrix which value is divisible by 3 or 7
//function to mirror the matrix

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the diagonal elements of the matrix
void displayDiagonal(int matrix[4][4]) {
    printf("Diagonal elements: ");
    for (int i = 0; i < 4; ++i) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

// Function to calculate the sum of each row
void sumRows(int matrix[4][4]) {
    printf("Sum of each row:\n");
    for (int i = 0; i < 4; ++i) {
        int rowSum = 0;
        for (int j = 0; j < 4; ++j) {
            rowSum += matrix[i][j];
        }
        printf("Row %d: %d\n", i + 1, rowSum);
    }
}

// Function to calculate the sum of each column
void sumColumns(int matrix[4][4]) {
    printf("Sum of each column:\n");
    for (int j = 0; j < 4; ++j) {
        int colSum = 0;
        for (int i = 0; i < 4; ++i) {
            colSum += matrix[i][j];
        }
        printf("Column %d: %d\n", j + 1, colSum);
    }
}

// Function to find the highest value in the matrix
int findHighestValue(int matrix[4][4]) {
    int highest = matrix[0][0];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] > highest) {
                highest = matrix[i][j];
            }
        }
    }
    return highest;
}

// Function to sum items divisible by 3 or 7
int sumDivisibleBy3Or7(int matrix[4][4]) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] % 3 == 0 || matrix[i][j] % 7 == 0) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

// Function to mirror the matrix
void mirrorMatrix(int matrix[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][3 - j];
            matrix[i][3 - j] = temp;
        }
    }
}

int main() {
    srand(time(NULL));
    int matrix[4][4];

    // Initialize the matrix with random values
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    displayDiagonal(matrix);
    sumRows(matrix);
    sumColumns(matrix);
    printf("Highest value in the matrix: %d\n", findHighestValue(matrix));
    printf("Sum of items divisible by 3 or 7: %d\n", sumDivisibleBy3Or7(matrix));

    mirrorMatrix(matrix);
    printf("Mirrored Matrix:\n");
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*
write c program to Create a Matrix of 28 rows x 28 column. Then Initialize the Matrix with random value of 0 or 1. Next add a function to calculate convolution on that matrix using the convolution kernel given below.
Stride Length = 1
Kernel
1 0 1
0 1 0
1 0 1
// Then add function to calculate max pooling on that matrix returned by convolutional function. Stride Length = 1. Pooling dimension 3x3. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 28
#define COLS 28

// Function to initialize the matrix with random 0s and 1s
void initializeMatrix(int matrix[ROWS][COLS]) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 2; // Generate random 0 or 1
        }
    }
}

// Assuming the kernel is a 3x3 matrix
#define KERNEL_SIZE 3

// Function to perform convolution
void performConvolution(int inputMatrix[ROWS][COLS], int outputMatrix[ROWS][COLS]) {
    int kernel[KERNEL_SIZE][KERNEL_SIZE] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    // Apply convolution
    for (int i = 1; i < ROWS - 1; ++i) {
        for (int j = 1; j < COLS - 1; ++j) {
            int sum = 0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    sum += inputMatrix[i + x][j + y] * kernel[x + 1][y + 1];
                }
            }
            outputMatrix[i][j] = sum;
        }
    }
}

// Function to perform max pooling
void performMaxPooling(int inputMatrix[ROWS][COLS], int pooledMatrix[ROWS/3][COLS/3]) {
    for (int i = 0; i < ROWS; i += 3) {
        for (int j = 0; j < COLS; j += 3) {
            int maxVal = inputMatrix[i][j];
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    maxVal = (inputMatrix[i + x][j + y] > maxVal) ? inputMatrix[i + x][j + y] : maxVal;
                }
            }
            pooledMatrix[i/3][j/3] = maxVal;
        }
    }
}


int main() {
    int matrix[ROWS][COLS];
    initializeMatrix(matrix);

    // Print the matrix (optional)
    printf("Initialized Matrix:\n");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    int inputMatrix[ROWS][COLS];
    initializeMatrix(inputMatrix);

    int outputMatrix[ROWS][COLS];

    // Perform convolution
    performConvolution(inputMatrix, outputMatrix);

    int pooledMatrix[ROWS/3][COLS/3];


    // Perform max pooling
    performMaxPooling(outputMatrix, pooledMatrix);

    // Print the pooled matrix
    printf("Pooled Matrix after max pooling:\n");
    for (int i = 0; i < ROWS/3; ++i) {
        for (int j = 0; j < COLS/3; ++j) {
            printf("%d ", pooledMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
// write c program to Create an array of 5 integer elements. Create pointer ptr1 that points to the 3rd element of the array. Modify the value pointed by ptr1 by multiplying it by 10. Show the array value.

#include <stdio.h>

int main() {
    // Create an array of 5 integer elements
    int arr[5] = {1, 2, 3, 4, 5};

    // Create a pointer ptr1 that points to the 3rd element of the array
    int *ptr1 = &arr[2];

    // Modify the value pointed by ptr1 by multiplying it by 10
    *ptr1 *= 10;

    // Show the array values
    printf("Array values after modification:\n");
    for (int i = 0; i < 5; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
// write c program that finds the sum of all elements in an integer array using pointers

#include <stdio.h>

int main() {
    int arr[100], size;
    int *ptr, sum = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Set address of first array element to *ptr
    ptr = arr;
    for (int i = 0; i < size; i++) {
        sum = sum + *ptr;
        ptr++; // Increment pointer by one to get next element
    }

    printf("The sum of array elements is: %d\n", sum);

    return 0;
}
// write c program that reverses the elements of an array using pointers

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tmp, size, i, j, *arr;

    printf("Enter size of array: ");
    scanf("%d", &size);

    arr = (int*)calloc(size, sizeof(int));

    printf("Enter elements in array: ");
    for (i = 0; i < size; i++)
        scanf("%d", arr + i);

    for (i = 0, j = size - 1; i < j; i++, j--) {
        tmp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = tmp;
    }

    printf("After reversing the array: ");
    for (i = 0; i < size; i++)
        printf("%d ", *(arr + i));

    free(arr); // Don't forget to free the allocated memory!

    return 0;
}
// write c program that multiplies each element of an array by 2 using pointers 

#include <stdio.h>

#define SIZE 5

/* Function declarations */
void arrayInput(int arr[], int size);
void arrayPrint(int arr[], int size);
void arrayMultiply(int arr[], int size);


/* Function to input elements in an array from the user */
void arrayInput(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

/* Function to print elements in an array */
void arrayPrint(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to multiply each element in the array by 2 */
void arrayMultiply(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}


int main() {
    int myArray[SIZE];

    /* Input elements in the array */
    printf("Enter %d elements in the array:\n", SIZE);
    arrayInput(myArray, SIZE);

    // Multiply each element by 2
    arrayMultiply(myArray, SIZE);

    // Print the modified array
    printf("Modified array after multiplying each element by 2:\n");
    arrayPrint(myArray, SIZE);

    return 0;
}
/*
write c program to create an array of 5 integer elements. Use 2 pointers to propagate from left to right and right to left. 
If the value is an odd, the pointer jump by one. 
If the value is even, the pointer jumps by two.
Show the array and address of each element.
When pointers point to the same value, print the value.
When pointers pass by each other, print the values and address both pointer pointed to.
*/

#include <stdio.h>

int main() {
    int arr[5] = {1, 3, 5, 7, 9}; // Initialize an array with 5 odd integer elements
    int *leftPtr = &arr[0];      // Pointer starting from the left (beginning of array)
    int *rightPtr = &arr[4];     // Pointer starting from the right (end of array)

    // Print the array and addresses of each element
    printf("Array elements and addresses:\n");
    for (int i = 0; i < 5; ++i) {
        printf("arr[%d] = %d (address: %p)\n", i, arr[i], &arr[i]);
    }

    // Traverse the array using the two pointers
    while (leftPtr <= rightPtr) {
        // Print the value when pointers point to the same element
        if (leftPtr == rightPtr) {
            printf("\nPointers meet at arr[%d] = %d\n", (int)(leftPtr - &arr[0]), *leftPtr);
        } else {
            // Print values and addresses when pointers pass by each other
            printf("\nLeft pointer (arr[%d]) = %d (address: %p)\n", (int)(leftPtr - &arr[0]), *leftPtr, leftPtr);
            printf("Right pointer (arr[%d]) = %d (address: %p)\n", (int)(rightPtr - &arr[0]), *rightPtr, rightPtr);
        }

        // Update pointers based on odd/even values
        if (*leftPtr % 2 == 0) {
            leftPtr += 2; // Jump by two if even
        } else {
            leftPtr += 1; // Jump by one if odd
        }

        if (*rightPtr % 2 == 0) {
            rightPtr -= 2; // Jump by two if even
        } else {
            rightPtr -= 1; // Jump by one if odd
        }
    }

    return 0;
}
