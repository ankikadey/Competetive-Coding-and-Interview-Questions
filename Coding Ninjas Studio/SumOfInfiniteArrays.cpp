#include <iostream>
#include <vector>
using namespace std;

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q)
{
    if (n == 0 || q == 0)
        return {};

    vector<long long> prefix(n + 1);
    vector<int> ans;
    prefix[0] = 0;
    int MOD = 1000000007; // The modulo value 10^9 + 7

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = (prefix[i - 1] + arr[i - 1]) % MOD; // Apply modulo here
    }

    for (int i = 0; i < q; i++)
    {
        long long l = queries[i][0], r = queries[i][1];
        long long leftSum = (((l - 1) / n) % MOD * prefix[n] + prefix[(l - 1) % n]) % MOD; // Apply modulo here
        long long rightSum = (((r / n) % MOD) * prefix[n] + prefix[r % n]) % MOD;          // Apply modulo here
        ans.push_back((rightSum - leftSum + MOD) % MOD);                                   // Ensure result is non-negative by adding MOD and applying modulo again
    }
    return ans;
}