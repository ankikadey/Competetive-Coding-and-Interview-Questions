#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
        {
            return s;
        }

        // Transform s to the format with '#' inserted.
        string t = "#";
        for (char c : s)
        {
            t += c;
            t += "#";
        }

        int n = t.size();
        vector<int> dp(n, 0);
        int center = 0, right = 0;
        int max_len = 1;
        string max_str = s.substr(0, 1);

        for (int i = 0; i < n; ++i)
        {
            if (i < right)
            {
                dp[i] = min(right - i, dp[2 * center - i]);
            }

            // Expand around the current center i
            while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < n && t[i - dp[i] - 1] == t[i + dp[i] + 1])
            {
                ++dp[i];
            }

            // Update the center and right boundary if the palindrome expanded past the right boundary
            if (i + dp[i] > right)
            {
                center = i;
                right = i + dp[i];
            }

            // Update the maximum length and corresponding string
            if (dp[i] > max_len)
            {
                max_len = dp[i];
                max_str = t.substr(i - dp[i], 2 * dp[i] + 1);
                // Remove the '#' characters to get the actual palindrome
                max_str.erase(remove(max_str.begin(), max_str.end(), '#'), max_str.end());
            }
        }

        return max_str;
    }
};