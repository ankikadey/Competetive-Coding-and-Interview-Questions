#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max_books_on_shelf(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, 0); // Initialize dp array

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 1; // At least one book on the shelf
        for (int j = i - 1; j >= 1; --j)
        {
            if (heights[i - 1] > heights[j - 1])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end()); // Return the maximum value in dp array
}

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    cout << max_books_on_shelf(n, heights) << endl;

    return 0;
}
