// program that finds the maximum and minimum elements in a given array and displays their addresses
#include <iostream>
using namespace std;

void findMinMaxAddress(int arr[], int N) {
    int* minE = &arr[0];
    int* maxE = &arr[0];
    for (int i = 1; i < N; ++i) {
        if (arr[i] < *minE) {
            minE = &arr[i];
        }
        if (arr[i] > *maxE) {
            maxE = &arr[i];
        }
    }
    cout << "Minimum element: " << *minE << " (Address: " << minE << ")" << endl;
    cout << "Maximum element: " << *maxE << " (Address: " << maxE << ")" << endl;
}
int main() {
    int arr[] = { 1, 2, 4, -1 };
    int N = sizeof(arr) / sizeof(arr[0]);
    findMinMaxAddress(arr, N);
    return 0;
}
