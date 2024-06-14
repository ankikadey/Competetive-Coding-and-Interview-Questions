class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        # dp[i][j] := true if s[0..i) matches p[0..j)
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True

        def is_match(i, j):
            return j >= 0 and (p[j] == '?' or s[i] == p[j])

        for j in range(n):
            if p[j] == '*':
                dp[0][j + 1] = dp[0][j]

        for i in range(m):
            for j in range(n):
                if p[j] == '*':
                    match_empty = dp[i + 1][j]
                    match_some = dp[i][j + 1]
                    dp[i + 1][j + 1] = match_empty or match_some
                elif is_match(i, j):
                    dp[i + 1][j + 1] = dp[i][j]

        return dp[m][n]