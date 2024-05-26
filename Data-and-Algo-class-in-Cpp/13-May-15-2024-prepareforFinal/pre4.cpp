#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> // For setw
// Define the binary tree node structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Function to insert a new node into the binary tree
TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->data) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}
// Function to create a binary tree with random numbers
TreeNode* createRandomTree(int numNodes) {
    TreeNode* root = nullptr;
    srand(time(nullptr));
    for (int i = 0; i < numNodes; ++i) {
        int val = rand() % 100; // Random numbers between 0 and 99
        root = insertNode(root, val);
    }
    return root;
}
// Preorder traversal: Root -> Left -> Right
void preorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
// Inorder traversal: Left -> Root -> Right
void inorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
// Postorder traversal: Left -> Right -> Root
void postorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
// Function to visualize binary tree structure
void visualizeTree(TreeNode* node, int space = 0, int gap = 5) {
    if (node == nullptr) {
        return;
    }
    space += gap;
    visualizeTree(node->right, space);
    cout << endl;
    for (int i = gap; i < space; ++i) {
        cout << " ";
    }
    cout << setw(2) << node->data << "\n";
    visualizeTree(node->left, space);
}
// Function to display all leaves of the tree
void displayLeaves(TreeNode* root) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        cout << root->data << " ";
    }
    displayLeaves(root->left);
    displayLeaves(root->right);
}
// Function to calculate tree height
int calculateTreeHeight(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftHeight = calculateTreeHeight(root->left);
    int rightHeight = calculateTreeHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}
// Function to calculate the sum of values in the subtree rooted at 'node'
int sumSubtree(TreeNode* node) {
    if (!node) {
        return 0;
    }
    return node->data + sumSubtree(node->left) + sumSubtree(node->right);
}
// Function to calculate the sum of all nodes and their children
int sumAllNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int subtreeSum = sumSubtree(root);
    return root->data + sumAllNodes(root->left) + sumAllNodes(root->right) - subtreeSum;
}
// New function: Display nodes with values divisible by 3 or 5
void displayDivisibleNodes(TreeNode* root) {
    if (!root) {
        return;
    }
    if (root->data % 3 == 0 || root->data % 5 == 0) {
        cout << root->data << " ";
    }
    displayDivisibleNodes(root->left);
    displayDivisibleNodes(root->right);
}
// Function to find the predecessor of nodes having value divisible by 3 or 5
void displayPredecessor(TreeNode* root, int target) {
    if (!root) {
        return;
    }
    displayPredecessor(root->left, target); // Recurse on the left subtree
    if (root->data % 3 == 0 || root->data % 5 == 0) {
        cout << "Node with value " << root->data << ": ";
        if (root->left) {
            cout << "Predecessor: " << root->left->data;
        } else {
            cout << "No predecessor (root node)";
        }
        cout << endl;
    }
    displayPredecessor(root->right, target); // Recurse on the right subtree
}
// Function to calculate the sum of all values in the binary tree
int sumTreeValues(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftSum = sumTreeValues(root->left); // Sum of left subtree
    int rightSum = sumTreeValues(root->right); // Sum of right subtree
    return root->data + leftSum + rightSum; // Sum of current node and subtrees
}
// Function to calculate the sum of leaf nodes and count of leaf nodes
void calculateLeafSumAndCount(TreeNode* root, int& leafCount, int& sum) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        // Node is a leaf
        leafCount++;
        sum += root->data;
    }
    calculateLeafSumAndCount(root->left, leafCount, sum);
    calculateLeafSumAndCount(root->right, leafCount, sum);
}
// Function to calculate the sum of all nodes in the binary tree
int calculateSum(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftSum = calculateSum(root->left); // Sum of left subtree
    int rightSum = calculateSum(root->right); // Sum of right subtree
    return root->data + leftSum + rightSum; // Sum of current node and subtrees
}
// Function to count the total number of nodes in the binary tree
int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftCount = countNodes(root->left); // Count in left subtree
    int rightCount = countNodes(root->right); // Count in right subtree
    return 1 + leftCount + rightCount; // Count of current node and subtrees
}
// Function to display node value and its children's values
void displayNodeAndChildren(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << "Node value: " << root->data;
    if (root->left) {
        cout << ", Left child: " << root->left->data;
    } else {
        cout << ", No left child";
    }
    if (root->right) {
        cout << ", Right child: " << root->right->data;
    } else {
        cout << ", No right child";
    }
    cout << endl;
    displayNodeAndChildren(root->left); // Recurse on the left subtree
    displayNodeAndChildren(root->right); // Recurse on the right subtree
}
int main() {
    TreeNode* root = createRandomTree(30);
    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;
    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;
    cout << "Visual representation of the tree:" << endl;
    visualizeTree(root);
    cout << "Leaves of the tree: ";
    displayLeaves(root);
    cout << endl;
    cout << "Tree height: " << calculateTreeHeight(root) << endl;
    cout << "Sum of value of subtree: " << sumSubtree(root) << endl;
    cout << "Sum of all nodes (including children): " << sumAllNodes(root) << endl;
    cout << "Nodes divisible by 3 or 5: ";
    displayDivisibleNodes(root);
    cout << endl;
    cout << "Sum of all values in the binary tree: " << sumTreeValues(root) << endl;
    cout << "Predecessors of nodes with values divisible by 3 or 5:" << endl;
    displayPredecessor(root, 0); 
    int leafCount = 0;
    int sum = 0;
    calculateLeafSumAndCount(root, leafCount, sum);
    double average = static_cast<double>(sum) / leafCount;
    cout << "Number of leaf nodes: " << leafCount << endl;
    cout << "Sum of leaf node values: " << sum << endl;
    cout << "Average value of leaf nodes: " << average << endl;
    int totalSum = calculateSum(root);
    int totalNodes = countNodes(root);
    double average1 = static_cast<double>(totalSum) / totalNodes;
    cout << "Total number of nodes in the binary tree: " << totalNodes << endl;
    cout << "Sum of all node values: " << totalSum << endl;
    cout << "Average value of all nodes: " << average << endl;
    cout << "Node values and their children:" << endl;
    displayNodeAndChildren(root);
    return 0;
}
//Create doubly link list using struct
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
void insertFront(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = nullptr;
    if (*head != nullptr) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    insertFront(&head, 3);
    insertFront(&head, 2);
    insertFront(&head, 1);
    cout << "Doubly linked list: ";
    printList(head);
    return 0;
}
//create single linked-list using struct
#include <iostream>
// Define the node structure
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
};
// Function to traverse and print the elements of the linked list
void traverseLinkedList(Node* head) {
    Node* current = head;  // Start from the head of the linked list
    while (current != nullptr) {
        cout << current->data << " ";  // Print the data of the current node
        current = current->next;            // Move to the next node
    }
    cout << endl;
}
int main() {
    // Create nodes
    Node* head = new Node{1};
    Node* second = new Node{2};
    Node* third = new Node{3};
    // Connect nodes
    head->next = second;
    second->next = third;
    // Call the traverseLinkedList function to print the linked list elements
    traverseLinkedList(head);
    // Memory cleanup (free allocated memory)
    delete head;
    delete second;
    delete third;
    return 0;
}
// write cpp doubly linked to Delete the starting Node
#include <iostream>
// Define the structure for a doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
};
// Function to delete the starting node
void deleteStartingNode(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete starting node." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}
// Function to print the doubly linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    // Create a sample doubly linked list
    Node* head = new Node{1, nullptr, nullptr};
    head->next = new Node{2, head, nullptr};
    head->next->next = new Node{3, head->next, nullptr};
    cout << "Original list: ";
    printList(head);
    // Delete the starting node
    deleteStartingNode(head);
    cout << "List after deleting starting node: ";
    printList(head);
    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
// write cpp doubly linked to Delete the last Node
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
};
// Function to delete a node in a Doubly Linked List
void deleteNode(Node** head_ref, Node* del) {
    if (*head_ref == nullptr || del == nullptr)
        return;
    // If the node to be deleted is the head node
    if (*head_ref == del)
        *head_ref = del->next;
    // Update the next pointer of the previous node
    if (del->next != nullptr)
        del->next->prev = del->prev;
    // Update the prev pointer of the next node
    if (del->prev != nullptr)
        del->prev->next = del->next;
    // Finally, free the memory occupied by del
    free(del);
}
// Function to insert a node at the beginning of the Doubly Linked List
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->prev = nullptr;
    new_node->next = (*head_ref);
    if ((*head_ref) != nullptr)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
// Function to print nodes in a given doubly linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}
int main() {
    Node* head = nullptr;
    // Create a sample doubly linked list: 10 <-> 8 <-> 4 <-> 2
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
    cout << "Original Linked list: ";
    printList(head);
    // Delete nodes (you can modify this part as needed)
    deleteNode(&head, head);        // Delete the head node
    deleteNode(&head, head->next);  // Delete the second node
    deleteNode(&head, head->next);  // Delete the third node
    cout << "\nModified Linked list: ";
    printList(head);
    return 0;
}
// write cpp doubly linked to Delete node at the specific position of the doubly linked-list
#include <bits/stdc++.h>
using namespace std;
// Define a node structure for the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
// Function to delete a node in a Doubly Linked List
void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == nullptr || del == nullptr)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != nullptr)
        del->next->prev = del->prev;
    if (del->prev != nullptr)
        del->prev->next = del->next;
    free(del); // Free the memory occupied by the deleted node
}
// Function to delete the node at the given position in the doubly linked list
void deleteNodeAtGivenPos(struct Node** head_ref, int n) {
    if (*head_ref == nullptr || n <= 0)
        return;
    struct Node* current = *head_ref;
    for (int i = 1; current != nullptr && i < n; i++)
        current = current->next;
    if (current == nullptr)
        return;
    deleteNode(head_ref, current);
}
// Function to insert a node at the beginning of the Doubly Linked List
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = nullptr;
    new_node->next = (*head_ref);
    if ((*head_ref) != nullptr)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
// Function to print nodes in a given doubly linked list
void printList(struct Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}
int main() {
    struct Node* head = nullptr;
    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
    cout << "Doubly linked list before deletion:\n";
    printList(head);
    int positionToDelete = 2; // Example: Delete node at position 2
    deleteNodeAtGivenPos(&head, positionToDelete);
    cout << "\nDoubly linked list after deletion of node at position " << positionToDelete << ":\n";
    printList(head);
    return 0;
}
// write cpp single linked to Delete the starting Node 
#include <iostream>
// Define the singly linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
// Function to delete the starting node
void deleteStartingNode(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete starting node." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}
// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Original linked list: ";
    printList(head);
    // Delete the starting node
    deleteStartingNode(head);
    cout << "Linked list after deleting the starting node: ";
    printList(head);
    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
// write cpp single linked to Delete the last Node
#include <iostream>
// Define the linked list node
struct Node {
    int data;
    Node* next;
};
// Function to remove the last node of the linked list
Node* removeLastNode(Node* head) {
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    // Find the second-to-last node
    Node* second_last = head;
    while (second_last->next->next != nullptr)
        second_last = second_last->next;
    // Delete the last node
    delete (second_last->next);
    // Set the next of second-to-last node to nullptr
    second_last->next = nullptr;
    return head;
}
// Function to push a node at the head
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
// Driver code
int main() {
    Node* head = nullptr;
    // Construct the list: 8 -> 23 -> 11 -> 29 -> 12
    push(&head, 12);
    push(&head, 29);
    push(&head, 11);
    push(&head, 23);
    push(&head, 8);
    // Remove the last node
    head = removeLastNode(head);
    // Print the modified list
    for (Node* temp = head; temp != nullptr; temp = temp->next)
        cout << temp->data << " ";
    return 0;
}
// write cpp single linked to Delete the specific position of the doubly linked-list
#include <iostream>
// Define the singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
// Function to delete a node at a specific position
void deleteNodeAtPosition(Node*& head, int position) {
    if (head == nullptr || position < 0) {
        cout << "Invalid position or empty list." << endl;
        return;
    }
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = nullptr;
    Node* curr = head;
    int count = 0;
    while (curr != nullptr && count < position) {
        prev = curr;
        curr = curr->next;
        count++;
    }
    if (curr == nullptr) {
        cout << "Position exceeds list length." << endl;
        return;
    }
    prev->next = curr->next;
    delete curr;
}
// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main() {
    // Example usage
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    cout << "Original list: ";
    printList(head);
    int positionToDelete = 2; // Change this to the desired position
    deleteNodeAtPosition(head, positionToDelete);
    cout << "List after deleting position " << positionToDelete << ": ";
    printList(head);
    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
// Insert a double linked-list from front (head)
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
};
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;
    if (*head_ref != nullptr) {
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}
int main() {
    Node* head = nullptr;
    push(&head, 100);
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 60);
    cout << "Doubly linked list before inserting 50 at the front: ";
    printList(head);
    push(&head, 50);
    push(&head, 199);
    cout << "\nDoubly linked list after inserting 50 at the front: ";
    printList(head);
    return 0;
}
// Insert a doubly linked-list at any position
// With the given doubly linked-list 5,7,8,6,1,4,8,5,8 add 7 to the forth Node
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }
    void insertAt(int newElement, int position) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }
        if (position == 1) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1; ++i) {
                if (temp == nullptr) {
                    cout << "The specified position does not exist." << endl;
                    return;
                }
                temp = temp->next;
            }
            if (temp != nullptr) {
                newNode->next = temp->next;
                newNode->prev = temp;
                if (newNode->next != nullptr) {
                    newNode->next->prev = newNode;
                }
                temp->next = newNode;
            } else 
            {
                cout << "The previous node is null. Index outoff bound" << endl;
            }
        }
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main() {
    DoublyLinkedList myList;
    myList.insertAt(5, 1);
    myList.insertAt(7, 2);
    myList.insertAt(8, 3);
    myList.insertAt(6, 4);
    myList.insertAt(1, 5);
    myList.insertAt(4, 6);
    myList.insertAt(8, 7);
    myList.insertAt(5, 8);
    myList.insertAt(8, 9);
    cout << "Original doubly linked list: ";
    myList.display();
    myList.insertAt(7, 11);
    cout << "Modified doubly linked list: ";
    myList.display();
    return 0;
}
// Insert a doubly linked-list at the end of the list
#include <iostream>
#include <cstdlib>
using namespace std;
struct Node {
    int Data;
    struct Node* next;
    struct Node* prev;
};
void insertNodeAtEnd(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Data = val;
    newNode->next = nullptr;
    if (*head == nullptr) {
        // If the list is empty, make the new node the head
        newNode->prev = nullptr;
        *head = newNode;
    } else {
        // Traverse to the last node
        struct Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Change the next pointer of the last node
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != nullptr) {
        cout << temp->Data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    struct Node* head = nullptr;
    // Create a doubly linked list with the given elements
    int elements[] = {5, 7, 8, 6, 1, 4, 8, 5, 8};
    int numElements = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < numElements; ++i) {
        insertNodeAtEnd(&head, elements[i]);
    }
    cout << "Original list: ";
    displayList(head);
    // Insert 7 at the end
    insertNodeAtEnd(&head, 7);
    cout << "List after inserting 7 at the end: ";
    displayList(head);
    return 0;
}
// Insert a single linked-list from front (head)
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
void insertAtFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
int main() {
    // Create the initial linked list: 10 -> 20 -> 30 -> 40 -> 50 -> 60
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    cout <<"Original linked list: " << endl;
    printList(head);
    // Insert 7 at the front
    insertAtFront(head, 7);
    cout << "Modified linked list: ";
    printList(head);
    return 0;
}
// Insert a single linked-list at any position
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
// Create a global variable for the size of the Linked List
int listSize = 0;
void insertPosition(int pos, int data, Node** head) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    if (pos < 1 || pos > listSize + 1) {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
        listSize++; 
    } else {
        Node* temp = *head;
        while (--pos > 1) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        listSize++;
    }
}
void display(Node* node) {
    cout << "Linked List: ";
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout <<"nullptr" << endl;
}
int main() {
    Node* head = nullptr;
    // Insert some initial nodes
    insertPosition(1, 5, &head);
    insertPosition(2, 7, &head);
    insertPosition(3, 8, &head);
    insertPosition(4, 6, &head);
    insertPosition(5, 1, &head);
    insertPosition(6, 4, &head);
    insertPosition(7, 8, &head);
    insertPosition(8, 5, &head);
    cout <<"Original Linked list: " << endl;
    display(head);
    cout <<"Insert 7 at the fourth position: " << endl;
    insertPosition(4, 7, &head); // Insert 7 at the fourth position
    display(head);
    return 0;
}
// Insert a single linked-list at the end of the list
#include <iostream>
using namespace std;
// Define the Node structure
class Node {
public:
    int data;
    Node* next;
};
// Function to insert a new node at the end of the linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;
    // If the linked list is empty, make the new node the head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    // Traverse to the last node
    Node* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }
    // Update the next pointer of the last node
    last->next = new_node;
}
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout <<"nullptr" << endl;
}
int main() {
    Node* head = nullptr;
    append(&head, 5);
    append(&head, 7);
    append(&head, 8);
    append(&head, 6);
    append(&head, 1);
    append(&head, 4);
    append(&head, 8);
    append(&head, 5);
    cout << "Linked list before inserting 7 at the end: ";
    printList(head);
    // Insert 7 at the end
    append(&head, 7);
    cout << "\nLinked list after inserting 7 at the end: ";
    printList(head);
    return 0;
}
//double linked list traversal from left to right
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }
    void push_back(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    void PrintList() {
        Node* temp = head;
        if (temp != nullptr) {
            cout << "The list contains: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        } else {
            cout << "The list is empty." << endl;
        }
    }
};
int main() {
    DoublyLinkedList myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.PrintList();
    return 0;
}
//double linked list traversal from right to left
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
void addNode(Node*& head, int key) {
    Node* newNode = new Node;
    newNode->data = key;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    addNode(head, 3);
    addNode(head, 5);
    addNode(head, 8);
    addNode(head, 2);
    cout << "Doubly linked list (right to left): ";
    printList(head);
    return 0;
}
//write cpp single linked list and do traversal from left to right
#include <iostream>
// Define the structure for a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
// Function to traverse and print the linked list
void traverseLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    // Traverse the linked list and print its elements
    cout << "Linked list elements (left to right): ";
    traverseLinkedList(head);
    // Clean up memory (delete nodes)
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
//write cpp single linked list and do traversal from right to left
#include <iostream>
// Define a class to represent each element (node) of the linked list
class Node {
public:
    int data;       // Data stored in this node
    Node* next;     // Reference to the next node
    // Constructor for creating a node with given data
    Node(int data) {
        this->data = data;
        this->next = nullptr; // Initially, there is no next node
    }
};
// Recursive function to print elements in reverse order
void printReverse(Node* head) {
    if (head == nullptr) {
        return; // Base case: reached the end of the list
    }
    printReverse(head->next); // Recurse to the next node
    cout << head->data << " "; // Print the current node's data
}
int main() {
    // Create the head of the linked list
    Node* head = new Node(10);
    // Insert some elements into the list
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    // Print all elements of the singly linked list (right to left)
    printReverse(head);
    cout << endl;
    // Don't forget to free memory to avoid memory leaks
    Node* ptr = head;
    while (ptr != nullptr) {
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    return 0;
}
// Write a program to generate 10 random values. Add these values into the linked list in ascending order. 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node {
    int data;
    Node* next;
};
//create node func
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}
//insertSorted function
void insertSorted (Node** head, Node* newNode) {
    Node* current = *head;
    if (*head == nullptr || newNode->data <= (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        while (current->next != nullptr && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
//print node function
void printLink(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main () {
    srand(time(0));
    Node* head = nullptr;
    for (int i=0; i<10; i++) {
        int value = rand() % 100 +1;
        Node* newNode = createNode(value);
        insertSorted(&head, newNode);
    }
    cout << "Linked list in ascending order: ";
    printLink(head);
    return 0;
}
// create a linked list of 20 elements where each element contains random values from 1 to 20. Remove elements having value divisible by 3 or 5. 
#include <iostream> 
#include <cstdlib>
#include <ctime> 
using namespace std; 
struct Node {
  int data;
  Node* next;
}; 
// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
  return rand() % (max - min + 1) + min;
}
// Function to create a new node with a random value
Node* createNode() {
  Node* newNode = new Node;
  newNode->data = getRandomNumber(1, 20);
  newNode->next = nullptr;
  return newNode;
}
// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node** head, Node* newNode) {
  newNode->next = *head;
  *head = newNode;
}
// Function to remove a node from the linked list
void removeNode(Node** head, int value) {
  if (*head == nullptr) {
    return; // List is empty
  }
  Node* current = *head;
  Node* previous = nullptr;
  while (current != nullptr && current->data == value) {
    *head = current->next;
    delete current;
    current = *head;
  }
  while (current != nullptr) {
    if (current->data == value) {
      if (previous != nullptr) {
        previous->next = current->next;
      }
      delete current;
      current = (previous != nullptr) ? previous->next : *head;
    } else {
      previous = current;
      current = current->next;
    }
  }
}
// Function to print the linked list
void printList(Node* head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}
// int main()
int main() {
  srand(time(0));
  Node* head = nullptr;
  // Create 20 nodes with random values
  for (int i = 0; i < 20; i++) {
    insertAtBeginning(&head, createNode());
  }
  // Creates 20 nodes with random values using a for
  cout << "Original list: ";
  printList(head);
  // print original list
  // Remove nodes divisible by 3 or 5
  removeNode(&head, 3);
  removeNode(&head, 5);
  cout << "List after removing elements divisible by 3 or 5: ";
  printList(head);
  // print after removal
  // Free the allocated memory for nodes
  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  head = nullptr;
  return 0;
}
// Create a Matrix of 4 rows and 4 column
#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;
const int MATRIX_SIZE = 4;
// Function to initialize the matrix with random values from 0 to 99
void initializeMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    srand(time(nullptr));
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}
// Function to display the diagonal elements of the matrix
void displayDiagonal(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    cout << "Diagonal elements: ";
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        cout << matrix[i][i] << " ";
    }
    cout << endl;
}
// Function to sum the values of each row
void sumRows(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        int rowSum = 0;
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            rowSum += matrix[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }
}
// Function to sum the values of each column (sumColumns)
void sumColumns(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int j = 0; j < MATRIX_SIZE; ++j) {
        int colSum = 0;
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            colSum += matrix[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }
}
// Function to find the highest value in the matrix (findHighestValue)
int findHighestValue(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    int highest = matrix[0][0];
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            if (matrix[i][j] > highest) {
                highest = matrix[i][j];
            }
        }
    }
    return highest;
}
// Function to sum items divisible by 3 or 7
int sumDivisibleBy3Or7(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    int sum = 0;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            if (matrix[i][j] % 3 == 0 || matrix[i][j] % 7 == 0) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}
// Function to mirror the matrix
void mirrorMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE / 2; ++j) {
            swap(matrix[i][j], matrix[i][MATRIX_SIZE - 1 - j]);
        }
    }
}
//int main() 
int main() {
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    initializeMatrix(matrix);
    cout << "Original Matrix:" << endl;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    displayDiagonal(matrix);
    sumRows(matrix);
    sumColumns(matrix);
    cout << "Highest value in the matrix: " << findHighestValue(matrix) << endl;
    cout << "Sum of items divisible by 3 or 7: " << sumDivisibleBy3Or7(matrix) << endl;
    // Mirror the matrix
    mirrorMatrix(matrix);
    cout << "Mirrored Matrix:" << endl;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MATRIX_SIZE = 28;
const vector<vector<int>> KERNEL = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
const int KERNEL_SIZE = 3;
const int POOL_SIZE = 3;
// Function to initialize the matrix with random values of 0 or 1
void initializeMatrix(vector<vector<int>>& matrix) {
    srand(time(nullptr));
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            matrix[i][j] = rand() % 2;
        }
    }
}
// Function to perform convolution on the matrix
vector<vector<int>> convolution(const vector<vector<int>>& matrix) {
    int convSize = MATRIX_SIZE - KERNEL_SIZE + 1;
    vector<vector<int>> convMatrix(convSize, vector<int>(convSize, 0));
    for (int i = 0; i <= MATRIX_SIZE - KERNEL_SIZE; ++i) {
        for (int j = 0; j <= MATRIX_SIZE - KERNEL_SIZE; ++j) {
            for (int ki = 0; ki < KERNEL_SIZE; ++ki) {
                for (int kj = 0; kj < KERNEL_SIZE; ++kj) {
                    convMatrix[i][j] += matrix[i + ki][j + kj] * KERNEL[ki][kj];
                }
            }
        }
    }
    return convMatrix;
}
// Function to perform max pooling on the matrix
vector<vector<int>> maxPooling(const vector<vector<int>>& matrix) {
    int pooledSize = matrix.size() - POOL_SIZE + 1;
    vector<vector<int>> pooledMatrix(pooledSize, vector<int>(pooledSize, 0));
    for (int i = 0; i <= matrix.size() - POOL_SIZE; ++i) {
        for (int j = 0; j <= matrix[0].size() - POOL_SIZE; ++j) {
            int maxVal = 0;
            for (int pi = 0; pi < POOL_SIZE; ++pi) {
                for (int pj = 0; pj < POOL_SIZE; ++pj) {
                    maxVal = max(maxVal, matrix[i + pi][j + pj]);
                }
            }
            pooledMatrix[i][j] = maxVal;
        }
    }
    return pooledMatrix;
}
// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {
    // Step 1: Create and initialize the matrix
    vector<vector<int>> matrix(MATRIX_SIZE, vector<int>(MATRIX_SIZE));
    initializeMatrix(matrix);
    // Step 2: Perform convolution
    auto convMatrix = convolution(matrix);
    cout << "Convolution Result:" << endl;
    printMatrix(convMatrix);
    // Step 3: Perform max pooling
    auto pooledMatrix = maxPooling(convMatrix);
    cout << "Max Pooling Result:" << endl;
    printMatrix(pooledMatrix);
    return 0;
}
// 1. Create an array of 5 integer elements. Create pointer ptr1 that points to the 3rd element of the array. Modify the value pointed by ptr1 by multiplying it by 10. Show the array value.
#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 4, 5}; // create the arr int arr[5] = {&0, &1, &2, &3, &4}
    int *ptr1 = &arr[2]; // create a pointer to point to address 2
    cout << "Original array value: "; 
    for (int i=0; i<5; ++i) {
        cout << arr[i] << " "; 
    } // print out the array
    cout << endl;
    cout << "test cout << arr << endl; on array: ";
    cout <<  arr << endl;
    cout << "Pointer pointing to address 2 (value): ";
    cout <<  *ptr1 << endl;
    cout << "Pointer pointing to address 2 (address): ";
    cout <<  &ptr1 << endl;
    cout << "Pointer pointing to address 2 (address): ";
    cout <<  ptr1  << endl;
    *ptr1 *= 10;
    cout << "Modified array value: "; 
    for (int i=0; i<5; ++i) {
        cout << arr[i] << " "; 
    } // print out the array
    cout << endl;
}
// 2. Write a program that finds the sum of all elements in an integer array using pointers
#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]); 
    int *ptr = arr;
    int sum = 0;
    while (ptr < arr + size) {
        sum += *ptr;
        ptr++;
    }
    cout << "Sum of array elements: " << sum << endl;
    return 0;
}
// 3. Write a program that reverses the elements of an array using pointers
#include <iostream>
using namespace std;
void swapArray(int arr[], int size) {
    int *start = arr;
    int *end = arr + size - 1;
    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before swap: ";
        for (int i=0; i<size; ++i) {
        cout << arr[i] << " " ;
    }
    
    cout << endl;
    swapArray(arr, size);
    cout << "Array after swap: ";
    for (int i=0; i<size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
    
}
// 4. Write a program that multiplies each element of an array by 2 using pointers 
#include <iostream>
using namespace std;
void mutiBy2(int arr[], int size) {
    int *ptr = arr;
    while (ptr < arr + size) {
        *ptr *= 2;
        ptr++; 
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i=0; i<5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    mutiBy2(arr, size);
    cout << "Modified array: ";
    for (int i=0; i<5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// 5 array and do traversal left to right
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5}; 
    for (int i = 0; i < n; ++i) {arr[i] = i + 1; }
    cout << "Original array: ";
    for (int i=0; i<n; ++i) {cout << arr[i] << " ";} cout << endl; 
    int leftPtr = 0;
    int rightPtr = n - 1;
    cout << "Traversing through array: " << endl;
    while (leftPtr <= rightPtr) {
        cout << "Left Pointer: arr[" << leftPtr << "] = " << arr[leftPtr]
                  << " (Address: " << &arr[leftPtr] << ")" << endl;
        cout << "Right Pointer: arr[" << rightPtr << "] = " << arr[rightPtr]
                  << " (Address: " << &arr[rightPtr] << ")" << endl;
        if (leftPtr == rightPtr) {
            cout << "Pointers meet! Value: " << arr[leftPtr] << endl;
        }
        if (arr[leftPtr] % 2 == 0) {
            leftPtr += 2; 
        } else {
            leftPtr += 1; 
        }
        if (arr[rightPtr] % 2 == 0) {
            rightPtr -= 2; 
        } else {
            rightPtr -= 1; 
        }
    }
    return 0;
}
