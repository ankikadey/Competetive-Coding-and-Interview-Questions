/* Given an integer array nums, find a subarray that has the largest product, and return the product.

    The test cases are generated so that the answer will fit in a 32-bit integer.

    Example 1:

    Input: nums = [2,3,-2,4]
    Output: 6
    Explanation: [2,3] has the largest product 6.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 0) {
        return 0;
    }
    
    int max_product = nums[0];
    int min_product = nums[0];
    int result = nums[0];
    
    for (int i = 1; i < n; i++) {
        int temp_max = max_product;
        int temp_min = min_product;
        
        max_product = max({nums[i], temp_max * nums[i], temp_min * nums[i]});
        min_product = min({nums[i], temp_max * nums[i], temp_min * nums[i]});
        
        result = max(result, max_product);
    }
    
    return result;
}

int main() {
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Output for Example 1: " << maxProduct(nums1) << endl;
    
    vector<int> nums2 = {-2, 0, -1};
    cout << "Output for Example 2: " << maxProduct(nums2) << endl;
    
    return 0;
}
