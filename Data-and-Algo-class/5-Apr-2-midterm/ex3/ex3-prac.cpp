// 2 Write a program to count the number of even and odd numbers in an array. Your program must have function is Even Number allowing to check if input number is even or odd. The function isEvenNumber returns true if the input number is even and false otherwise.

#include <iostream>
using namespace std;

bool isEvenNumber(int num) {
    return num % 2 == 0;
}


void countEvenOddNumbers(int arr[], int n) {
    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < n; ++i) {
        if (isEvenNumber(arr[i])) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    cout << "Even numbers: " << evenCount << endl;
    cout << "Odd numbers: " << oddCount << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    countEvenOddNumbers(arr, n);

    return 0;
}
