#include <iostream>

using namespace std;

void reverseArray(int arr[], int size) {
   int *left = arr;    // Pointer to the first element
   int *right = arr + size - 1; // Pointer to the last element

   while (left < right) {
       // Swap the elements pointed to by left and right
       int temp = *left;
       *left = *right;
       *right = temp;

       // Move the pointers towards each other
       left++;
       right--;
   }
}

int main() {
   int arr[] = {10, 20, 30, 40, 50};
   int size = sizeof(arr) / sizeof(arr[0]);

   cout << "Original array: ";
   for (int i = 0; i < size; i++) {
       cout << arr[i] << " ";
   }
   cout << endl;

   reverseArray(arr, size);

   cout << "Reversed array: ";
   for (int i = 0; i < size; i++) {
       cout << arr[i] << " ";
   }
   cout << endl;

   return 0;
}

