#include <iostream>
#include <string>

using namespace std;

string removeConsecutiveDuplicates(const string& str) {
    string result;
    char prevChar = '\0'; // Initialize with a null character to represent no previous character.

    for (char c : str) {
        if (c != prevChar) {
            result.push_back(c);
            prevChar = c;
        }
    }

    return result;
}

int main() {
    string inputString;
    getline(cin, inputString);

    string result = removeConsecutiveDuplicates(inputString);
    cout << result << endl;

    return 0;
}
