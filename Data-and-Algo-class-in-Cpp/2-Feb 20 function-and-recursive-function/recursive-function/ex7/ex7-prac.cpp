// Write cpp recursive to Count the number of digits of a given number. 

#include <iostream>
using namespace std;

int countDigits(long long int num) {
    if (num == 0) {
        return 1; // Single digit
    } else {
        return 1 + countDigits(num / 10);
    }
}

int main() {
    long long int number = 123143513546432;
    cout << "Number of digits: " << countDigits(number) << endl;
    return 0;
}
