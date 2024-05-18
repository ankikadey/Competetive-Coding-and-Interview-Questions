#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s) {
    vector<vector<int>> result;
    unordered_set<int> seen;

    for (int i = 0; i < arr.size(); i++) {
        int target = s - arr[i];
        
        if (seen.find(target) != seen.end()) {
            vector<int> pair = {min(arr[i], target), max(arr[i], target)};
            result.push_back(pair);
        }
        
        seen.insert(arr[i]);
    }

    sort(result.begin(), result.end());

    return result;
}

int main() {
    vector<int> arr = {2, -3, 3, 3, -2};
    int sum = 0;

    vector<vector<int>> pairs = pairSum(arr, sum);

    for (const auto &pair : pairs) {
        cout << pair[0] << " " << pair[1] << endl;
    }

    return 0;
}
