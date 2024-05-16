def max_books_on_shelf(n, heights):
    dp = [0] * (n + 1)  # Initialize dp array
    dp[0] = 0  # Base case

    for i in range(1, n + 1):
        dp[i] = 1  # At least one book on the shelf
        for j in range(i - 1, 0, -1):
            if heights[i - 1] > heights[j - 1]:
                dp[i] = max(dp[i], dp[j] + 1)

    return max(dp)  # Return the maximum value in dp array

# Input number of books
n = int(input())

# Input heights of books
heights = list(map(int, input().split()))

print(max_books_on_shelf(n, heights))