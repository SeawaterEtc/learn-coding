// 2. Write a program that finds the sum of all elements in an integer array using pointers

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]); 
    int *ptr = arr;
    int sum = 0;

    while (ptr < arr + size) {
        sum += *ptr;
        ptr++;
    }

    cout << "Sum of array elements: " << sum << endl;
    return 0;

}