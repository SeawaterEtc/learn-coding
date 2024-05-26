// write cpp to Calculate power of number. 

#include <iostream>

double calculatePower(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    double base = 2.0;
    int exponent = 10;
    double powerResult = calculatePower(base, exponent);
    std::cout << "Result: " << powerResult << std::endl;
    return 0;
}
