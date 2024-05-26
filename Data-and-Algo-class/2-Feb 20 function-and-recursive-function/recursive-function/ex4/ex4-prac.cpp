// Write cpp recursive function to Reverse a given array.   

#include <iostream>
using namespace std;

// Recursive function to reverse an array
void reverseArray(int arr[], int start, int end) {
    if (start >= end)
        return; // Base case: when start index is greater than or equal to end index

    // Swap elements at start and end indices
    swap(arr[start], arr[end]);

    // Recur for the remaining subarray
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int arr[] = {5,4,3,2,1,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    reverseArray(arr, 0, n - 1);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
