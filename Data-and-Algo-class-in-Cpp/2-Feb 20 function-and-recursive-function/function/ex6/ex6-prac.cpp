// Count the number of occurrences of a specific element in an array of integers. 
#include <iostream>

int main() {
    int arr[] = {5, 5, 5, 2, 2, 2, 2, 2, 9, 4};

    int target = 2; // Declare the target element

    // std::cout << "Enter the element you want to count: ";
    // std::cin >> target;

    int count = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        if (arr[i] == target) {
            ++count;
        }
    }

    std::cout << "The number of occurrences of " << target << " is: " << count << std::endl;

    return 0;
}
