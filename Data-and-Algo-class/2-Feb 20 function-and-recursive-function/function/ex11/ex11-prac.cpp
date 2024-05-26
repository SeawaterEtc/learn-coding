// write cpp for if given two strings, copy one string to another. 

#include <iostream>

void copyString(char* dest, const char* src) {
    while (*src) {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0'; // Null-terminate the destination string
}

int main() {
    const char* source = "Hello, world!";
    char destination[50]; // Make sure the destination buffer is large enough

    copyString(destination, source);

    std::cout << "Copied string: " << destination << std::endl;

    return 0;
}
