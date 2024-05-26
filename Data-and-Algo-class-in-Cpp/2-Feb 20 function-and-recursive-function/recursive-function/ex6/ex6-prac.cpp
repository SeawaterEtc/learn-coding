// Write cpp recursive to Count the number of occurrences of a specific element in an array of integers. 
#include <iostream>
using namespace std;

int countOccurrences(int arr[], int low, int high, int target) {
    if (low > high) {
        return 0; // Base case: empty subarray
    }

    int mid = (low + high) / 2;
    int total = 0;

    if (arr[mid] == target) {
        total++; // Increment count if the element matches the target
    }

    // Recursively search both halves of the array
    total += countOccurrences(arr, low, mid - 1, target); // Left half
    total += countOccurrences(arr, mid + 1, high, target); // Right half

    return total;
}

int main() {
    int arr[] = {1, 2, 2, 3, 2, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int result = countOccurrences(arr, 0, n - 1, target);
    cout << "Occurrences of " << target << ": " << result << endl;

    return 0;
}
