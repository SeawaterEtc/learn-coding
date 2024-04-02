#include <iostream>

using namespace std;

void multiplyArrayBy2(int arr[], int size) {
    int *ptr = arr;  // Pointer to the first element

    while (ptr < arr + size) {
        *ptr *= 2;  // Multiply the value pointed to by 2
        ptr++;      // Move to the next element
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    multiplyArrayBy2(arr, size);

    cout << "Array after multiplication: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
