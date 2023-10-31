#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    int isPalindrome(string A) {
        // Remove spaces and special characters and convert to lowercase
        string modifiedString = "";
        for (int i = 0; i < A.length(); i++) {
            if (isalnum(A[i])) {
                modifiedString += tolower(A[i]);
            }
        }

        // Check if modifiedString is a palindrome
        int left = 0;
        int right = modifiedString.length() - 1;
        while (left < right) {
            if (modifiedString[left] != modifiedString[right]) {
                return 0;
            }
            left++;
            right--;
        }
        return 1;
    }
};

int main() {
    Solution sol;
    string input1 = "A man, a plan, a canal: Panama";
    string input2 = "race a car";
    cout << "Input 1: " << input1 << ", Is Palindrome: " << sol.isPalindrome(input1) << endl;
    cout << "Input 2: " << input2 << ", Is Palindrome: " << sol.isPalindrome(input2) << endl;
    return 0;
}
