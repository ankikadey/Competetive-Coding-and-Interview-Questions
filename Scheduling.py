def minDifficulty(taskdifficulty, d):
    n = len(taskdifficulty)
    
    # If the number of days is greater than the number of tasks or is less than 1,
    # it is impossible to schedule the tasks.
    if d > n or d < 1:
        return -1
    
     # dp[i][j] represents the minimum difficulty to complete the first i tasks in j days.
    dp = [[float('inf')] * (d + 1) for _ in range(n + 1)]
    dp[0][0] = 0
    
    for i in range(1, n+1):
        for k in range(1, d+1):
            max_difficulty = 0
            for j in range(i, 0, -1):
                max_difficulty = max(max_difficulty, taskdifficulty[j-1])
                dp[i][k] = min(dp[i][k], dp[j-1][k-1] + max_difficulty)
    return dp[n][d] if dp[n][d] != float('inf') else -1

n = int(input())
taskdifficulty = list(map(int, input().split()))
d = int(input())

print(minDifficulty(taskdifficulty, d))