/* Given an integer array nums, find the subarray with the largest sum, and return its sum. (Kadane's Algo)

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxSum = nums[0];
    int currSum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}   

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = maxSubArray(nums);

    cout << "Output: " << result << endl;
    return 0;
}