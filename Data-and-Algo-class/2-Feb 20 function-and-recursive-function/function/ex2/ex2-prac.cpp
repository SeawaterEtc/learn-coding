// Calculate Fibonacci F(0) = 0, F(1) = 1
// F(n) = F(n - 1), F(n - 2)


#include <iostream>
using namespace std;

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    srand(time(0));
    
    int lb = 1, ub = 10;

    int n = 10;
    // int n = rand() % (ub - lb + 1) + lb;

    // cout << "Enter a positive integer: ";
    // cin >> n;

    if (n < 0) {
        cout << "Invalid input. Please enter a non-negative integer.\n";
    } else {
        cout << "F(" << n << ") = " << fibonacci(n) << "\n";
    }
    return 0;
}
