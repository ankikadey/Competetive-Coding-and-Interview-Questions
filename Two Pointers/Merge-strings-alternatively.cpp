#include <iostream>
#include <string>

using namespace std;

string mergeStrings(string word1, string word2) {
    string result;
    int i = 0, j = 0;

    while (i < word1.length() && j < word2.length()) {
        result += word1[i++];
        result += word2[j++];
    }

    while (i < word1.length()) {
        result += word1[i++];
    }

    while (j < word2.length()) {
        result += word2[j++];
    }

    return result;
}

int main() {
    string word1, word2;

    // Input word1
    cin >> word1;

    // Input word2
    cin >> word2;

    // Output merged string
    cout << mergeStrings(word1, word2) << endl;

    return 0;
}
