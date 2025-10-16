

#include <iostream>
#include <string>
#include <cctype> 
#include <cstring>
using namespace std;

// Function prototypes
void isPalindrome(string);
bool checkPalindrome(string, int, int);

/**
 * isPalindrome - Main function that checks if a string is a palindrome
 * @str: The string to check
 * 
 * This function uses a recursive helper function and displays the result.
 */
void isPalindrome(string str) {
    //changing string to ensure all characters are lower case
    //This program is not case-sensitive and will read 'K' and 'k' as the same
    string temp;
    for (char ch : str){
        temp += tolower(static_cast<unsigned char>(ch));
    }
    bool result = checkPalindrome(temp, 0, temp.length() - 1);
    
    if (result) {
        cout << "The string '" << str << "' is a Palindrome" << endl;
    } else {
        cout << "The string '" << str << "' is not a palindrome." << endl;
    }
}

/**
 * checkPalindrome - Recursive helper function to check palindrome
 * @str: The string to check
 * @left: Left index pointer
 * @right: Right index pointer
 * 
 * Returns: true if palindrome, false otherwise
 * 
 * Base cases:
 * - If left >= right, we've checked all characters (palindrome)
 * 
 * Recursive case:
 * - Compare characters at left and right positions
 * - If they match, recursively check the next pair
 * - If they don't match, it's not a palindrome
 */
bool checkPalindrome(string str, int left, int right) {
    // Base case: if pointers meet or cross, it's a palindrome
    if (left >= right) {
        return true;
    }
    
    // If characters don't match, not a palindrome
    if (str[left] != str[right]) {
        return false;
    }
    
    // Recursive case: check next pair of characters
    return checkPalindrome(str, left + 1, right - 1);
}

/**
 * main - Driver function
 * 
 * Prompts the user to enter strings and checks if they are palindromes
 * until the user decides to quit.
 */
int main() {
    string input;
    
    cout << "========================================" << endl;
    cout << "   Recursive Palindrome Checker" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // Run multiple test cases
    while (true) {
        // Prompt user for input
        cout << "Enter a string to test(q to quit): ";
        getline(cin, input);
        if (input == "q" || input == "Q"){
            break;
        }
        
        // Check and display result
        isPalindrome(input);
    }
    
    return 0;
}
