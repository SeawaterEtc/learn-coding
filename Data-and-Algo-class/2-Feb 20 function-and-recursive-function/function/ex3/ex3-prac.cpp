// Find max value in a given array.

#include <iostream>
using namespace std;

int main() {
    int n = 5; // Number of elements in the array
    float arr[5] = {1, 7, 3, 4, 5}; // Array to store the elements
    // Initialize max with the first element
    float max = arr[0];
    // Find the maximum element
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Largest element in the array: " << max << endl;

    return 0;
}
