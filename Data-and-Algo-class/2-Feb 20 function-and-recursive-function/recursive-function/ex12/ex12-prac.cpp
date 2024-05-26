// write cpp to Merge two sorted arrays into a new sorted array. 

#include <iostream>

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]) {
    int i = 0, j = 0, k = 0;

    // Traverse both arrays and compare elements
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1 (if any)
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2 (if any)
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 2, 3, 5, 9};
    int arr2[] = {4, 6, 7, 8};


    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1 + n2]; // Auxiliary array to store merged elements

    mergeArrays(arr1, arr2, n1, n2, arr3);

    std::cout << "Merged sorted array: ";
    for (int i = 0; i < n1 + n2; ++i) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
