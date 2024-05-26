// Write cpp to find the number of occurrences of a substring in a given string. 

#include <iostream>

int countSubstringOccurrences(const char* str, const char* substr) {
    int count = 0;
    int strLen = 0;
    int substrLen = 0;

    // Calculate the lengths of the input strings
    while (str[strLen] != '\0') {
        ++strLen;
    }
    while (substr[substrLen] != '\0') {
        ++substrLen;
    }

    // Iterate through the main string
    for (int i = 0; i <= strLen - substrLen; ++i) {
        bool found = true;
        for (int j = 0; j < substrLen; ++j) {
            if (str[i + j] != substr[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            ++count;
        }
    }

    return count;
}

int main() {
    const char* mainString = "cdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcd";
    const char* targetSubstring = "cd";

    int occurrences = countSubstringOccurrences(mainString, targetSubstring);
    std::cout << "Occurrences of \"" << targetSubstring << "\" in \"" << mainString << "\": " << occurrences << std::endl;

    return 0;
}
