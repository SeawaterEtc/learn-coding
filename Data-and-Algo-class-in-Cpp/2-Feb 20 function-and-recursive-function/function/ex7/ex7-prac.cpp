// Count the number of digits of a given number. 

 
#include <iostream>

// Generic solution for counting digits in any integer type
template <class T>
int numDigits(T number) {
    int digits = 0;
    if (number < 0)
        digits = 1; // Remove this line if '-' doesn't count as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

int main() {
    int num = 12345; // Replace with your desired number
    int digitCount = numDigits(num);
    std::cout << "Number of digits in " << num << ": " << digitCount << std::endl;
    return 0;
}
