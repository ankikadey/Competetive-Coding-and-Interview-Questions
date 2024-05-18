#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

string reverseWords(const string& str) {
    stringstream ss(str);
    stack<string> wordStack;
    string word;
    
    while (ss >> word) {
        wordStack.push(word);
    }
    
    string reversedString;
    while (!wordStack.empty()) {
        reversedString += wordStack.top() + " ";
        wordStack.pop();
    }
    
    // Remove the trailing space before returning the result.
    return reversedString.substr(0, reversedString.length() - 1);
}

int main() {
    string inputString;
    getline(cin, inputString);

    string reversedString = reverseWords(inputString);
    cout << reversedString << endl;

    return 0;
}
