#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();
        
        for (int i = 0; i < n; ++i) {
            while (1 <= A[i] && A[i] <= n && A[A[i] - 1] != A[i]) {
                swap(A[A[i] - 1], A[i]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<int> input1 = {1, 2, 0};
    vector<int> input2 = {3, 4, -1, 1};
    vector<int> input3 = {-8, -7, -6};

    cout << "Output 1: " << sol.firstMissingPositive(input1) << endl;
    cout << "Output 2: " << sol.firstMissingPositive(input2) << endl;
    cout << "Output 3: " << sol.firstMissingPositive(input3) << endl;

    return 0;
}
