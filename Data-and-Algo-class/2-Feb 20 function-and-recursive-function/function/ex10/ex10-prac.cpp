// Write cpp for an atoi() function. 

#include <iostream>
#include <string>

int customAtoi(const std::string& str) {
    int result = 0;
    bool isNegative = false;
    size_t i = 0;

    // Handle negative sign
    if (str[i] == '-') {
        isNegative = true;
        i++;
    }

    // Convert characters to integer
    while (i < str.length()) {
        if (isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        } else {
            // Invalid character encountered
            std::cerr << "Error: Invalid input string\n";
            return 0;
        }
        i++;
    }

    // Apply negative sign if needed
    if (isNegative) {
        result = -result;
    }

    return result;
}

int main() {
    std::string inputStr = "12345"; // Replace with your desired input string
    int convertedValue = customAtoi(inputStr);

    std::cout << "String to be Converted: " << inputStr << std::endl;
    std::cout << "Converted to Integer: " << convertedValue << std::endl;

    return 0;
}
