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
    cout << "Enter array size: "; 
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " Integers: ";
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    countEvenOddNumbers(arr, n);

    return 0;
}