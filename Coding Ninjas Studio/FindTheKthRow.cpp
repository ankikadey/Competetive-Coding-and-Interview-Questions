#include <iostream>
#include <vector>

using namespace std;

int find_K(const vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int k = 0; k < n; ++k) {
        bool is_valid_row = true;
        bool is_valid_col = true;

        // Checking for valid row
        for (int j = 0; j < n; ++j) {
            if (j != k && matrix[k][j] != 0) {
                is_valid_row = false;
                break;
            }
        }

        // Checking for valid column
        for (int i = 0; i < n; ++i) {
            if (i != k && matrix[i][k] != 1) {
                is_valid_col = false;
                break;
            }
        }

        if (is_valid_row && is_valid_col) {
            return k;
        }
    }

    return -1;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the value of N: ";
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n, 0));

        cout << "Enter the matrix:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        int result = find_K(matrix);
        cout << result << endl;
    }

    return 0;
}
