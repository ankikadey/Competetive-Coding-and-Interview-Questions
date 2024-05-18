/* Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> result(nums.size());
    int left = 0;
    int right = nums.size() - 1;
    int index = nums.size() - 1;

    while (left <= right)
    {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare)
        {
            result[index--] = leftSquare;
            left++;
        }
        else
        {
            result[index--] = rightSquare;
            right--;
        }
    }
    return result;
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

    vector<int> result = sortedSquares(nums);

    cout << "Output: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
