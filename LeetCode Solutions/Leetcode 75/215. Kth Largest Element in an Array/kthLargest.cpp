#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), std::greater<int>());
        return nums[k - 1];
    }
};