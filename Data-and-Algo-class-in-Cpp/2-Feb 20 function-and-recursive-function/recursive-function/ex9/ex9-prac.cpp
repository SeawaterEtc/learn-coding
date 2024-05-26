// write cpp recursive to Calculate power of number. 

#include <iostream>

double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    } else if (exponent > 0) {
        return base * power(base, exponent - 1);
    } else {
        // Negative exponent: calculate reciprocal
        return 1.0 / power(base, -exponent);
    }
}

int main() {
    double base = 2.0;
    int exponent = 3;
    double result = power(base, exponent);
    std::cout << base << " raised to the power of " << exponent << " is " << result << std::endl;
    return 0;
}
