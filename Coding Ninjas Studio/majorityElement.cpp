/* Given an array nums of size n, return the majority element.

 The majority element is the element that appears more than ⌊n / 2⌋ times.
 You may assume that the majority element always exists in the array.

 

 Example 1:

 Input: nums = [3,2,3]
 Output: 3
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    int majority = 0;
    
    for (int num : nums) {
        count[num]++;
        if (count[num] > nums.size() / 2) {
            majority = num;
            break;
        }
    }
    
    return majority;
}

int main() {
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    
    return 0;
}
