// Rahul has a unit test in school, but he woke up very late in the morning. 
// He has to go to school as soon as possible. 
// Rahul's house is situated at 0,0 index of integer matrix and his school is at n-1, m-1 index of the matrix. 
// You have to help Rahul to find the shortest route.
// You are provided with a matrix, in which the ith, jth value represents distance

// Input Format
// The first line of input should contain a single integer n -  representing a row of matrix.
// The second line of input should contain a single integer m -  representing column of matrix.
// The next line n lines contain m number each, jth number in ith line denotes the number that is written on cell arr[i][j]

// Output Format
// The output should be a single integer value

// Constraints
// M == grid.length
// N == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 10
// Sample Testcase 0
// Testcase Input
// 3
// 3
// 1
// 3
// 1
// 1
// 5
// 1
// 4
// 2
//
// Testcase Output
//
// Explanation
// Route 1 = [ 1 + 3 + 1 + 1 + 1]         ->       7
// Route 2 = [ 1 + 3 + 5 + 2 + 1]         ->      12
// Route 3 = [ 1 + 3 + 5 + 1 + 1]        ->      11
// Route 4 = [1 + 1 + 4 + 2 + 1]       ->       9
// Route 5 = [1 + 1 + 5 + 2 + 1]       ->      10
// Therefore 7 is minimum.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min_distance(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    // Initialize distances array with maximum values
    vector<vector<int>> distances(n, vector<int>(m, INT_MAX));
    
    // Base case: Rahul's house
    distances[0][0] = grid[0][0];
    
    // Iterate over each cell and update distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Check adjacent cells (up and left)
            if (i > 0) {
                distances[i][j] = min(distances[i][j], distances[i - 1][j] + grid[i][j]);
            }
            if (j > 0) {
                distances[i][j] = min(distances[i][j], distances[i][j - 1] + grid[i][j]);
            }
        }
    }
    
    // Return the minimum distance to reach school
    return distances[n - 1][m - 1];
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read the grid
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Calculate and print the minimum distance
    cout << min_distance(grid) << endl;

    return 0;
}
