// write c program that reverses the elements of an array using pointers

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tmp, size, i, j, *arr;

    printf("Enter size of array: ");
    scanf("%d", &size);

    arr = (int*)calloc(size, sizeof(int));

    printf("Enter elements in array: ");
    for (i = 0; i < size; i++)
        scanf("%d", arr + i);

    for (i = 0, j = size - 1; i < j; i++, j--) {
        tmp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = tmp;
    }

    printf("After reversing the array: ");
    for (i = 0; i < size; i++)
        printf("%d ", *(arr + i));

    free(arr); // Don't forget to free the allocated memory!

    return 0;
}
