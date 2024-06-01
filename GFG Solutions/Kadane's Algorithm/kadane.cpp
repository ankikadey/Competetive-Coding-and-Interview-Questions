#include <climits>
class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {

        long long sum = INT_MIN;
        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            count += arr[i];
            if (count > sum)
                sum = count;
            if (count < 0)
                count = 0;
        }

        return sum;
    }
};