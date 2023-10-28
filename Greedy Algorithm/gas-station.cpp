#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
        int n = A.size();
        int total_tank = 0;
        int current_tank = 0;
        int starting_station = 0;

        for (int i = 0; i < n; i++) {
            total_tank += A[i] - B[i];
            current_tank += A[i] - B[i];
            if (current_tank < 0) {
                starting_station = i + 1;
                current_tank = 0;
            }
        }

        return (total_tank >= 0) ? starting_station : -1;
    }
};

int main() {
    Solution sol;
    vector<int> A = {1, 2};
    vector<int> B = {2, 1};
    int result = sol.canCompleteCircuit(A, B);
    cout << "Result: " << result << endl;
    return 0;
}