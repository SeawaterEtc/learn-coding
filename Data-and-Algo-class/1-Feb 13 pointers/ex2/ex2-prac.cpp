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