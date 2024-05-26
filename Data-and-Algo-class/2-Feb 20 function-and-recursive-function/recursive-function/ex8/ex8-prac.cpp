// write cpp recursive to Convert decimal number to binary. 
#include <iostream>
using namespace std;

// Recursive function to convert decimal to binary
void decToBinary(int decimal_number) {
    if (decimal_number == 0)
        return; // Base case: when the decimal number is 0, stop recursion
    else {
        // Recursively divide the decimal number by 2
        decToBinary(decimal_number / 2);
        // Print the remainder (binary digit) at each step
        cout << decimal_number % 2;
    }
}

int main() {
    int decimal_number = 11; // Example: convert decimal 10 to binary
    decToBinary(decimal_number);
    return 0;
}
