// Write cpp recursive for an atoi() function. 

#include <iostream>

int customAtoi(const char* str, int index = 0, int result = 0) {
    // Base case: end of string or non-digit character
    if (str[index] == '\0' || !isdigit(str[index])) {
        return result;
    }

    // Convert the current character to an integer
    int digit = str[index] - '0';

    // Update the result
    result = result * 10 + digit;

    // Recurse to the next character
    return customAtoi(str, index + 1, result);
}

int main() {
    const char* input = "555467";
    int value = customAtoi(input);
    std::cout << "Converted value: " << value << std::endl;
    return 0;
}
