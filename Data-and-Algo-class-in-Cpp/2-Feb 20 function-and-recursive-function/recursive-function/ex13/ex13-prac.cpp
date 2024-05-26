// Write cpp resursive to find the number of occurrences of a substring in a given string. 

#include <iostream>
using namespace std;

// Function to count occurrences of `str2` in `str1`
int countSubstring(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();

    // Base case: If the length of `str1` is less than `str2`, return 0
    if (n1 < n2)
        return 0;

    // Check if the substring `str2` is present at the beginning of `str1`
    if (str1.substr(0, n2) == str2)
        return countSubstring(str1.substr(1), str2) + 1;
    else
        return countSubstring(str1.substr(1), str2);
}

int main() {
    string str1 = "geeksforgeeks";
    string str2 = "geeks";

    cout << "Occurrences of \"" << str2 << "\" in \"" << str1 << "\": ";
    cout << countSubstring(str1, str2) << endl;

    str1 = "aaaaa";
    str2 = "aaa";
    cout << "Occurrences of \"" << str2 << "\" in \"" << str1 << "\": ";
    cout << countSubstring(str1, str2) << endl;

    return 0;
}
