/*
5. Create an array of 5 integer elements. Use 2 pointers to propagate from left to right and right to left. 
If the value is an odd, the pointer jump by one. 
If the value is even, the pointer jumps by two.
Show the array and address of each element.
When pointers point to the same value, print the value.
When pointers pass by each other, print the values and address both pointer pointed to.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // int n; // Number of elements in the array
    //cout << "Enter the number of elements: ";
    //cin >> n;
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5}; // Create an array of n integer elements

    // Initialize the array (you can modify this part as needed)
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1; // Example: Initialize with consecutive values
    }

    cout << "Original array: ";
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " "; 
    }
    cout << endl; 

    // Initialize pointers
    int leftPtr = 0;
    int rightPtr = n - 1;

    cout << "Traversing through array: " << endl;

    // Traverse the array
    while (leftPtr <= rightPtr) {
        // Print left pointer value and address
        cout << "Left Pointer: arr[" << leftPtr << "] = " << arr[leftPtr]
                  << " (Address: " << &arr[leftPtr] << ")" << endl;

        // Print right pointer value and address
        cout << "Right Pointer: arr[" << rightPtr << "] = " << arr[rightPtr]
                  << " (Address: " << &arr[rightPtr] << ")" << endl;

        // Check if pointers point to the same value
        if (leftPtr == rightPtr) {
            cout << "Pointers meet! Value: " << arr[leftPtr] << endl;
        }

        // Update pointers based on value parity
        if (arr[leftPtr] % 2 == 0) {
            leftPtr += 2; // Even value, jump by two
        } else {
            leftPtr += 1; // Odd value, jump by one
        }

        if (arr[rightPtr] % 2 == 0) {
            rightPtr -= 2; // Even value, jump by two
        } else {
            rightPtr -= 1; // Odd value, jump by one
        }
    }

    return 0;
}
