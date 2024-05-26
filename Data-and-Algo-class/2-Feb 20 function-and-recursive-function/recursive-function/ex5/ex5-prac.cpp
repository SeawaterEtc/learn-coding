// Write cpp recursive function to check if a given string is a palindrome. Using few example to test the code in the main function. 

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

// Recursive function to check if a string is a palindrome
bool isPalRec(char str[], int s, int e) {
    if (s == e)
        return true; // Base case: single character is a palindrome

    if (str[s] != str[e])
        return false; // Characters don't match, not a palindrome

    if (s < e + 1)
        return isPalRec(str, s + 1, e - 1); // Recur for remaining substring

    return true;
}

bool isPalindrome(char str[]) {
    int n = strlen(str);
    if (n == 0)
        return true; // Empty string is a palindrome

    return isPalRec(str, 0, n - 1);
}

int main() {
    char str[] = "racecar"; // Example string
    if (isPalindrome(str))
        cout << "Yes, it's a palindrome.";
    else
        cout << "No, it's not a palindrome.";

    return 0;
}
