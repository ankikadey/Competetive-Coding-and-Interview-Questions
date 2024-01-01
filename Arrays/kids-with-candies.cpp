#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandies = *max_element(candies.begin(), candies.end());
    vector<bool> result;

    for (int i = 0; i < candies.size(); ++i) {
        result.push_back(candies[i] + extraCandies >= maxCandies);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> candies;
    for (int i = 0; i < n; ++i) {
        int candy;
        char comma;
        cin >> candy >> comma;
        candies.push_back(candy);
    }

    int extraCandies;
    cin >> extraCandies;

    vector<bool> result = kidsWithCandies(candies, extraCandies);

    // Output
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << (result[i] ? "true" : "false");
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
