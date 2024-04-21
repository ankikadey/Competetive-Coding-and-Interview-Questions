#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void miniMaxSum(vector<int> arr) {
    sort(arr.begin(), arr.end());
    long long maxsum = 0, minsum = 0;

    for (int i = 0; i < arr.size() - 1; ++i) {
        maxsum += arr[i];
    }

    for (int j = 1; j < arr.size(); ++j) {
        minsum += arr[j];
    }

    cout << maxsum << " " << minsum << endl;
}

int main() {
    vector<int> arr(5);

    for (int i = 0; i < 5; ++i) {
        cin >> arr[i];
    }

    miniMaxSum(arr);

    return 0;
}
