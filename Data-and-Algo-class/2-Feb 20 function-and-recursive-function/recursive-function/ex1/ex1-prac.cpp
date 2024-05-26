// write cpp recursive functions for Write a program that asks user for an integer number and find the sum of all natural numbers up to that input number: sum(n) = 1 + 2 + 3 + … + n

#include <iostream>

using namespace std;

// Recursive function to compute the sum of natural numbers
int sum(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sum(n - 1);
    }
}

int main() {
    int num = 100;
    std::cout << "Enter a positive integer: ";
    // std::cin >> num;

    if (num <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
    } else {
        int result = sum(num);
        std::cout << "Sum of natural numbers up to " << num << " is: " << result << std::endl;
    }

    return 0;
}
