#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool isAnagram(const string& s, const string& t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> charCount;

    // Count characters in string s
    for (char ch : s) {
        charCount[ch]++;
    }

    // Decrement character counts based on string t
    for (char ch : t) {
        if (charCount.find(ch) == charCount.end() || charCount[ch] == 0) {
            return false; // Character not found in s or count is already 0
        } else {
            charCount[ch]--;
        }
    }

    return true;
}

int main() {
    // Take input from the user
    string inputS;
    getline(cin, inputS);

    string inputT;
    getline(cin, inputT);

    // Check if the strings are anagrams
    cout << (isAnagram(inputS, inputT) ? "true" : "false") << endl;

    return 0;
}
