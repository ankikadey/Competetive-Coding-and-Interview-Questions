#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordbreak(string s, unordered_set<string>& worddict) {
    if (worddict.empty()) return false;
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (dp[j]) {
                string word = s.substr(j, i - j);
                if (worddict.find(word) != worddict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[s.size()];
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    unordered_set<string> worddict;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        worddict.insert(str);
    }
    wordbreak(s, worddict) ? cout << "true" : cout << "false";
    return 0;
}
