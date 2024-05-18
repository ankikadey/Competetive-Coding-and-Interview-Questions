#include <iostream>
#include <string>

using namespace std;

void generateSubstrings(const string& str) {
    int n = str.length();
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            cout << str.substr(i, len) << endl;
        }
    }
}

int main() {
    string inputString;
    getline(cin, inputString);

    generateSubstrings(inputString);

    return 0;
}
