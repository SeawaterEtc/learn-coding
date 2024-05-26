// write c program that multiplies each element of an array by 2 using pointers 

#include <stdio.h>

#define SIZE 5

/* Function declarations */
void arrayInput(int arr[], int size);
void arrayPrint(int arr[], int size);
void arrayMultiply(int arr[], int size);


/* Function to input elements in an array from the user */
void arrayInput(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

/* Function to print elements in an array */
void arrayPrint(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to multiply each element in the array by 2 */
void arrayMultiply(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}


int main() {
    int myArray[SIZE];

    /* Input elements in the array */
    printf("Enter %d elements in the array:\n", SIZE);
    arrayInput(myArray, SIZE);

    // Multiply each element by 2
    arrayMultiply(myArray, SIZE);

    // Print the modified array
    printf("Modified array after multiplying each element by 2:\n");
    arrayPrint(myArray, SIZE);

    return 0;
}
