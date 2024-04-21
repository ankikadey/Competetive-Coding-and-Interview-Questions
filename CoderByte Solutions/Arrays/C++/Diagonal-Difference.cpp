#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int lrd = 0, rld = 0;

    for (int i = 0; i < arr.size(); ++i) {
        lrd += arr[i][i];
        rld += arr[i][arr.size() - i - 1];
    }

    return abs(rld - lrd);
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    int result = diagonalDifference(arr);

    cout << result << '\n';

    return 0;
}
