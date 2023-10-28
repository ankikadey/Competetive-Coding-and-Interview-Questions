#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &A) {
        int n = A.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > A[i + 1] && candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
            }
        }

        int minCandies = 0;
        for (int candy : candies) {
            minCandies += candy;
        }
        return minCandies;
    }
};

int main() {
    Solution solution;
    vector<int> A = {1, 2};
    cout << "Minimum candies: " << solution.candy(A) << endl;

    A = {1, 5, 2, 1};
    cout << "Minimum candies: " << solution.candy(A) << endl;

    return 0;
}
