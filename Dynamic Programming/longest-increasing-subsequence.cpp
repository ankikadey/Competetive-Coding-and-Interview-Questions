#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lis(const vector<int> &A) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }

        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    vector<int> A = {1, 2, 1, 5};
    cout << "Length of longest increasing subsequence: " << solution.lis(A) << endl;

    A = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout << "Length of longest increasing subsequence: " << solution.lis(A) << endl;

    return 0;
}
