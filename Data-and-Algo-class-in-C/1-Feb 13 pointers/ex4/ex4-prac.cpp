/*
write c program to create an array of 5 integer elements. Use 2 pointers to propagate from left to right and right to left. 
If the value is an odd, the pointer jump by one. 
If the value is even, the pointer jumps by two.
Show the array and address of each element.
When pointers point to the same value, print the value.
When pointers pass by each other, print the values and address both pointer pointed to.
*/

#include <stdio.h>

int main() {
    int arr[5] = {1, 3, 5, 7, 9}; // Initialize an array with 5 odd integer elements
    int *leftPtr = &arr[0];      // Pointer starting from the left (beginning of array)
    int *rightPtr = &arr[4];     // Pointer starting from the right (end of array)

    // Print the array and addresses of each element
    printf("Array elements and addresses:\n");
    for (int i = 0; i < 5; ++i) {
        printf("arr[%d] = %d (address: %p)\n", i, arr[i], &arr[i]);
    }

    // Traverse the array using the two pointers
    while (leftPtr <= rightPtr) {
        // Print the value when pointers point to the same element
        if (leftPtr == rightPtr) {
            printf("\nPointers meet at arr[%d] = %d\n", (int)(leftPtr - &arr[0]), *leftPtr);
        } else {
            // Print values and addresses when pointers pass by each other
            printf("\nLeft pointer (arr[%d]) = %d (address: %p)\n", (int)(leftPtr - &arr[0]), *leftPtr, leftPtr);
            printf("Right pointer (arr[%d]) = %d (address: %p)\n", (int)(rightPtr - &arr[0]), *rightPtr, rightPtr);
        }

        // Update pointers based on odd/even values
        if (*leftPtr % 2 == 0) {
            leftPtr += 2; // Jump by two if even
        } else {
            leftPtr += 1; // Jump by one if odd
        }

        if (*rightPtr % 2 == 0) {
            rightPtr -= 2; // Jump by two if even
        } else {
            rightPtr -= 1; // Jump by one if odd
        }
    }

    return 0;
}
