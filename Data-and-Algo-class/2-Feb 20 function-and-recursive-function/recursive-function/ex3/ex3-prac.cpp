// write cpp recursive function to Find max value in a given array.

#include <iostream>
using namespace std;

// Recursive function to find the maximum value in an array
int findMax(int arr[], int n) {
    // Base case: If there's only one element, return it
    if (n == 1) {
        return arr[0];
    }

    // Recursive case: Compare the first element with the maximum of the rest
    int restMax = findMax(arr + 1, n - 1);
    return max(arr[0], restMax);
}

int main() {
    int arr[] = {10, 5, 8, 50, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxValue = findMax(arr, n);
    cout << "Maximum value in the array: " << maxValue << endl;

    return 0;
}
