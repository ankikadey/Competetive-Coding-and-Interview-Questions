#include <vector>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int curr, vector<int> &memo)
    {
        if (curr < 0)
            return 0;
        if (memo[curr] != INT_MIN)
            return memo[curr];
        int x = nums[curr] + solve(nums, curr - 2, memo);
        int y = solve(nums, curr - 1, memo);
        memo[curr] = max(x, y);
        return memo[curr];
    }

    int rob(vector<int> &nums)
    {
        vector<int> memo(nums.size(), INT_MIN);
        return solve(nums, nums.size() - 1, memo);
    }
};