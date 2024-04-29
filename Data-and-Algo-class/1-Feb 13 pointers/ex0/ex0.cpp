// 1. Create an array of 5 integer elements. Create pointer ptr1 that points to the 3rd element of the array. Modify the value pointed by ptr1 by multiplying it by 10. Show the array value.

#include <iostream>

using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // create the arr int arr[5] = {&0, &1, &2, &3, &4}
    int *ptr1 = &arr[2]; // create a pointer to point to address 2

    cout << "Original array value: "; 
    for (int i=0; i<5; ++i) {
        cout << arr[i] << " "; 
    } // print out the array
    cout << endl;

    // modify the array
    *ptr1 *= 10;

    cout << "Modified array value: "; 
    for (int i=0; i<5; ++i) {
        cout << arr[i] << " "; 
    } // print out the array
    cout << endl;


}