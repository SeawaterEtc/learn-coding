// creates a doubly linked list to store elements greater than or equal to the mean value of a given array:
#include <iostream>
#include <cstdlib>
using namespace std;
// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
// Function to create a doubly linked list
void createDoublyLinkedList(Node** head, int arr[], int n) {
    Node* current = nullptr;
    Node* prevNode = nullptr;
    for (int i = 0; i < n; ++i) {
        Node* newNode = new Node;
        newNode->data = arr[i];
        newNode->prev = prevNode;
        newNode->next = nullptr;
        if (prevNode) {
            prevNode->next = newNode;
        } else {
            *head = newNode;
        }
        prevNode = newNode;
    }
}
// Function to calculate the mean value of the array
double calculateMean(int arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum / n;
}
// Function to print the doubly linked list
void displayDoublyLinkedList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    int arr[] = { 10, 20, 30, 40, 50 }; // Replace with your array
    int n = sizeof(arr) / sizeof(arr[0]);
    double mean = calculateMean(arr, n);
    cout << "Mean value: " << mean << endl;
    Node* head = nullptr;
    createDoublyLinkedList(&head, arr, n);
    cout << "Doubly Linked List: ";
    displayDoublyLinkedList(head);
    return 0;
}
