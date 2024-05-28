#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calculateFinalScore(vector<string>& ops) {
    vector<int> scores;

    for (const string& op : ops) {
        if (op == "C") {
            if (!scores.empty()) {
                scores.pop_back();
            }
        } else if (op == "D") {
            if (!scores.empty()) {
                scores.push_back(2 * scores.back());
            }
        } else if (op == "+") {
            if (scores.size() >= 2) {
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
            }
        } else {
            scores.push_back(stoi(op));
        }
    }

    int sum = 0;
    for (int score : scores) {
        sum += score;
    }

    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<string> ops(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> ops[i];
    }

    int result = calculateFinalScore(ops);
    cout << result << endl;

    return 0;
}
