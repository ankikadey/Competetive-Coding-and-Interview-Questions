#include <vector>
using namespace std;
class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        int l = 0, r = 0;
        long long sum = 0;

        while (r < n)
        {
            sum += arr[r];

            if (sum == s)
                return {l + 1, r + 1};

            while (sum > s && l < r)
            {
                sum -= arr[l];
                l++;
                if (sum == s)
                    return {l + 1, r + 1};
            }

            r++;
        }

        return {-1};
    }
};