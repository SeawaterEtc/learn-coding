// 5. Create an array of 5 integer elements. Use 2 pointers to propagate from left to right and right to left. 
// If the value is an odd, the pointer jump by one. 
// If the value is even, the pointer jumps by two.
// Show the array and address of each element.
// When pointers point to the same value, print the value.
// When pointers pass by each other, print the values and address both pointer pointed to.


#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr1 = arr;
    int *ptr2 = arr + 4;


    cout << *ptr1 << endl; 
    cout << *ptr2 << endl;


}
