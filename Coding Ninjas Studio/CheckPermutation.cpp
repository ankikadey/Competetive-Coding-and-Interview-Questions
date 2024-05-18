#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool arePermutations(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    unordered_map<char, int> charCount;
    
    for (char c : str1) {
        charCount[c]++;
    }
    
    for (char c : str2) {
        if (charCount[c] == 0) {
            return false;
        }
        charCount[c]--;
    }

    return true;
}

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;

    if (arePermutations(str1, str2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
