def longestRepeatingSubsequence(st):
    n = len(st)
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if st[i - 1] == st[j - 1] and i != j:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[n][n]

# Test cases
test_cases = int(input())
for _ in range(test_cases):
    st = input()
    print(longestRepeatingSubsequence(st))
