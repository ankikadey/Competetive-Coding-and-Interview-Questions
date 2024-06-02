#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int numOfWays(int n, int m, int k)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, 0)));

    dp[0][0][0] = 1;

    for (int length = 1; length <= n; ++length)
    {
        for (int cost = 0; cost <= k; ++cost)
        {
            for (int max_val = 0; max_val <= m; ++max_val)
            {
                for (int val = 1; val <= m; ++val)
                {
                    if (val > max_val)
                    {
                        if (cost > 0)
                        {
                            dp[length][cost][val] = (dp[length][cost][val] + dp[length - 1][cost - 1][max_val]) % MOD;
                        }
                    }
                    else
                    {
                        dp[length][cost][max_val] = (dp[length][cost][max_val] + dp[length - 1][cost][max_val]) % MOD;
                    }
                }
            }
        }
    }

    int result = 0;
    for (int max_val = 1; max_val <= m; ++max_val)
    {
        result = (result + dp[n][k][max_val]) % MOD;
    }

    return result;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    cout << numOfWays(n, m, k) << endl;

    return 0;
}
