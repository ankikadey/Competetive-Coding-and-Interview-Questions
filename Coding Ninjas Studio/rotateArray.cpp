/* Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    if (k == 0)
    {
        return;
    }
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    rotate(nums, k);
    cout << "Output: [";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i];
        if (i < nums.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}

