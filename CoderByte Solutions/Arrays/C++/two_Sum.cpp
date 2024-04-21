#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a map to store the numbers and their indices
        unordered_map<int, int> numIndices;
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement of the current number
            int complement = target - nums[i];
            // If the complement is found in the map, return the indices
            if (numIndices.find(complement) != numIndices.end()) {
                return {numIndices[complement], i};
            }
            // Otherwise, add the number and its index to the map
            numIndices[nums[i]] = i;
        }
        // Throw an exception if no solution is found
        throw invalid_argument("No two sum solution");
    }
};

int main() {
    Solution solution;
    // Test the algorithm with example inputs
    vector<int> nums1 = {2, 15, 11, 7};
    vector<int> result1 = solution.twoSum(nums1, 9);
    // Output the results
    cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << endl;  // Output: [0, 3]

    vector<int> nums2 = {3, 1, 4, 8, 5};
    vector<int> result2 = solution.twoSum(nums2, 9);
    cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl;  // Output: [1, 3]]

    vector<int> nums3 = {10, 20, 30, 40, 50};
    vector<int> result3 = solution.twoSum(nums3, 90);
    cout << "Output: [" << result3[0] << ", " << result3[1] << "]" << endl;  // Output: [3, 4]
}