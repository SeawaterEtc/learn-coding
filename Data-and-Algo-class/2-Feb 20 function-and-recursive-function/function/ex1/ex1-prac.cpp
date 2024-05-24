// write cpp for Write a program that asks user for an integer number and find the sum of all natural numbers up to that input number: sum(n) = 1 + 2 + 3 + … + n

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    cout << "Q1: write cpp for Write a program that asks user for an integer number and find the sum of all natural numbers up to that input number: sum(n) = 1 + 2 + 3 + … + n. The number is randomized between 1-100: " << endl;

    srand((time(nullptr))); // need this before using rand() 

    int lb = 1, ub = 100;

    int n = rand() % (ub - lb + 1) + lb;

    int sum = n * (n + 1) / 2;

    cout << ">> Answer1: Sum of natural numbers up to " << n << " is: " << sum << endl;

    return 0;
}