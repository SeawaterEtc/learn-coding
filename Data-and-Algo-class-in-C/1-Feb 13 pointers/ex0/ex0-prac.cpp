// write c program to Create an array of 5 integer elements. Create pointer ptr1 that points to the 3rd element of the array. Modify the value pointed by ptr1 by multiplying it by 10. Show the array value.

#include <stdio.h>

int main() {
    // Create an array of 5 integer elements
    int arr[5] = {1, 2, 3, 4, 5};

    // Create a pointer ptr1 that points to the 3rd element of the array
    int *ptr1 = &arr[2];

    // Modify the value pointed by ptr1 by multiplying it by 10
    *ptr1 *= 10;

    // Show the array values
    printf("Array values after modification:\n");
    for (int i = 0; i < 5; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
