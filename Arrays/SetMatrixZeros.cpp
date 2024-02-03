#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows_to_zero;
        unordered_set<int> cols_to_zero;
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rows_to_zero.insert(i);
                    cols_to_zero.insert(j);
                }
            }
        }
        
        for (auto row : rows_to_zero) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[row][j] = 0;
            }
        }
        
        for (auto col : cols_to_zero) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][col] = 0;
            }
        }
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<vector<int>> input_matrix1 = {
        {1, 0, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    vector<vector<int>> input_matrix2 = {
        {1, 0, 1},
        {1, 1, 1},
        {1, 0, 1}
    };

    sol.setZeroes(input_matrix1);
    sol.setZeroes(input_matrix2);

    cout << "Output 1:" << endl;
    for (const auto& row : input_matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "Output 2:" << endl;
    for (const auto& row : input_matrix2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
