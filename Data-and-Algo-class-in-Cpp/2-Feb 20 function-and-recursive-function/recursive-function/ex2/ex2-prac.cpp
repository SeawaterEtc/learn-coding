// write cpp resursive function to Calculate Fibonacci F(0) = 0, F(1) = 1. The function F(n) = F(n - 1), F(n - 2)


#include <iostream>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n = 10; // Change this value to calculate F(n) for a different n
    std::cout << "F(" << n << ") = " << fibonacci(n) << std::endl;
    return 0;
}
