// Time Complexity: O(n)
#include <vector>
#include <numeric>  // For accumulate function
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Calculate the total sum of the elements to use as the initial rightSum
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        // Initialize leftSum to store the sum of the numbers to the left of the current index
        int leftSum = 0;

        // Traverse all elements in the array
        for (int idx = 0; idx < nums.size(); idx++) {
            // Subtract the current element from rightSum
            rightSum -= nums[idx];
            // Check if leftSum equals rightSum (indicating the pivot index)
            if (leftSum == rightSum)
                return idx;  // Return the pivot index if condition is met
            // Add the current element to leftSum
            leftSum += nums[idx];
        }

        // If no pivot index is found, return -1
        return -1;
    }
};
