#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int wordLadder(string begin, string end, vector<string> &dict) {
    if (begin == end) {
        return 0;
    }

    // Create a set from dict for faster lookup
    unordered_set<string> word_set(dict.begin(), dict.end());

    // Initialize a queue for BFS
    queue<pair<string, int>> q;  // (word, transformation sequence length)
    q.push({begin, 1});

    // Mark the begin word as visited
    unordered_set<string> visited = {begin};

    // Perform BFS
    while (!q.empty()) {
        string word = q.front().first;
        int length = q.front().second;
        q.pop();

        // Generate all possible next words by changing one character at a time
        for (int i = 0; i < word.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                string next_word = word;
                next_word[i] = c;

                // If next_word is end, return the transformation sequence length
                if (next_word == end) {
                    return length + 1; // Add 1 to include the transformation to the end word
                }

                // If next_word is in the dictionary and has not been visited yet, push it into the queue
                if (word_set.count(next_word) && !visited.count(next_word)) {
                    q.push({next_word, length + 1});
                    visited.insert(next_word);
                }
            }
        }
    }

    // If no transformation sequence is found, return -1
    return -1;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        string begin, end;
        int N;
        cin >> begin >> end >> N;

        vector<string> dict(N);
        for (int i = 0; i < N; ++i) {
            cin >> dict[i];
        }

        int result = wordLadder(begin, end, dict);
        cout << result << endl;
    }

    return 0;
}
