// correct this code

#include <iostream>
using namespace std;

void swapNumbers(int a, int b) {
    int temp = a;
    b = temp;
    a = b;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    cout << num1 << " " << num2 << endl;
    swapNumbers(*num1, &num2);
    cout << num1 << " " << num2 << endl;
    return 0;
}
