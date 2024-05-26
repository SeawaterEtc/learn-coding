// write cpp recursive for a case: if given two strings, copy one string to another. 

#include <iostream>

void copyString(const char* source, char* destination, int index = 0) {
    if (source[index] == '\0') {
        destination[index] = '\0'; // Null-terminate the destination string
        return;
    }
    destination[index] = source[index];
    copyString(source, destination, index + 1);
}

int main() {
    const char* sourceString = "Hello, world!";
    char destinationString[100]; // Make sure the destination buffer is large enough
    copyString(sourceString, destinationString);

    std::cout << "Source string: " << sourceString << std::endl;
    std::cout << "Copied string: " << destinationString << std::endl;

    return 0;
}
