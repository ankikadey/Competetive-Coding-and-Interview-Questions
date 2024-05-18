#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string reverseEachWord(const string& str) {
    stringstream ss(str);
    string word, reversedStr;
    
    while (ss >> word) {
        reverse(word.begin(), word.end());
        reversedStr += word + " ";
    }
    
    // Remove the trailing space before returning the result.
    return reversedStr.substr(0, reversedStr.length() - 1);
}

int main() {
    string inputString;
    getline(cin, inputString);

    string reversedWordsString = reverseEachWord(inputString);
    cout << reversedWordsString << endl;

    return 0;
}
