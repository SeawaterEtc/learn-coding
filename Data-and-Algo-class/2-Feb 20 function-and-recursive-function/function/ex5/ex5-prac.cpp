// Check if a given string is a palindrome. Using few example to test the code in the main function. 

#include <iostream>
#include <string>
#include <algorithm> // For reverse

using namespace std;

bool isPalindrome(const string& str) {
    // Create a copy of the input string
    string copy = str;

    // Remove spaces and convert to lowercase
    copy.erase(remove_if(copy.begin(), copy.end(), ::isspace), copy.end());
    transform(copy.begin(), copy.end(), copy.begin(), ::tolower);

    // Create a reversed copy of the string
    string reversed = copy;
    reverse(reversed.begin(), reversed.end());

    // Check if the reversed copy is equal to the original
    return copy == reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    // getline(cin, input);

    if (isPalindrome(input)) {
        cout << "The input string is a palindrome." << endl;
    } else {
        cout << "The input string is not a palindrome." << endl;
    }

    // Example tests
    cout << "Example tests:" << endl;
    cout << "Is 'racecar' a palindrome? " << (isPalindrome("racecar") ? "Yes" : "No") << endl;
    cout << "Is 'ACECA' a palindrome? " << (isPalindrome("ACECA") ? "Yes" : "No") << endl;
    cout << "Is 'Hello' a palindrome? " << (isPalindrome("Hello") ? "Yes" : "No") << endl;
    return 0;
}
