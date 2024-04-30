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