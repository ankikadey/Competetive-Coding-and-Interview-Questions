// Similar to Largest Rectangle in Histogram
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = 0;
        stack<int> stack;

        for (int i = 0; i <= nums.size(); ++i) {
            while (!stack.empty() &&
                (i == nums.size() || nums[stack.top()] > nums[i])) {
                const int h = nums[stack.top()];
                stack.pop();
                const int w = stack.empty() ? i : i - stack.top() - 1;
                if ((stack.empty() || stack.top() + 1 <= k) && i - 1 >= k)
                    ans = max(ans, h * w);
            }
            stack.push(i);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<int> nums = {1, 4, 3, 7, 4, 5};
    int k = 2;
    cout << "Maximum Score: " << sol.maximumScore(nums, k) << endl;

    return 0;
}
