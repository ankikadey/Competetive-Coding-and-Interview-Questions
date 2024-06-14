#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix){
            if(matrix.empty())
                return 0;

            int ans = 0;
            vector<int> hist(matrix[0].size());

            //Iterate through each row in the matrix
            for (const vector<char>& row : matrix){
                //update histogram for each row
                for (int i = 0; i < row.size(); ++i)
                {
                    hist[i] = row[i] == '0' ? 0 : hist[i] + 1;
                }
                //calculate the largest rectangle area using the histogram of the current row.
                ans = max(ans, largestRectangleArea(hist));
            }

            return ans;
        }
    private:
        int largestRectangleArea(const vector<int>& heights){
            int ans = 0;
            stack<int> stack;

            //interate through each element in the heights array and calculate the largest area
            for (int i = 0; i <= heights.size(); ++i)
            {
                while (!stack.empty() && (i == heights.size() || heights[stack.top()] > heights[i]))
                {
                    //calculate the area of the rectangle with the current height
                    const int h = heights[stack.top()];
                    stack.pop();
                    const int w = stack.empty() ? i : i - stack.top() - 1;
                    ans = max(ans, h*w);
                }
                stack.push(i);
            }
            
            return ans;
        }
};

int main() {
    // Example binary matrix
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    Solution sol; // Create an instance of the Solution class

    // Call the maximalRectangle method and print the result
    cout << "Maximal Rectangle Area: " << sol.maximalRectangle(matrix) << endl;

    return 0;
}