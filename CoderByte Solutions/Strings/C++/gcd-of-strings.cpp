/*For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.*/

#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

string gcdOfStrings(string str1, string str2) {
    int len1 = str1.length();
    int len2 = str2.length();

    int divisor = gcd(len1, len2);

    // Check if the common substring is a valid divisor
    string commonSubstring = str1.substr(0, divisor);
    string tempStr1, tempStr2;

    for (int i = 0; i < len1 / divisor; ++i) {
        tempStr1 += commonSubstring;
    }

    for (int i = 0; i < len2 / divisor; ++i) {
        tempStr2 += commonSubstring;
    }

    if (tempStr1 == str1 && tempStr2 == str2) {
        return commonSubstring;
    } else {
        return "";
    }
}

int main() {
    string str1, str2;

    // Input str1
    cin >> str1;

    // Input str2
    cin >> str2;

    // Output the largest string x that divides both str1 and str2
    string result = gcdOfStrings(str1, str2);
    if (result.empty()) {
        cout << "" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
