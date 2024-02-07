# Say you have an array, A, for which the ith element is the price of a given stock on day i.
# If you were only permitted to complete at most one transaction (i.e, buy one and sell one share of the stock),
# design an algorithm to find the maximum profit.

# Return the maximum possible profit.

class Solution:
    def maxProfit(self, A):
        n = len(A)
        if n <= 1:
            return 0

        min_price = A[0]
        max_profit = 0

        for i in range(1, n):
            min_price = min(min_price, A[i])
            max_profit = max(max_profit, A[i] - min_price)

        return max_profit

# Example usage:
A1 = [1, 2]
A2 = [1, 4, 5, 2, 4]

solution = Solution()
print(solution.maxProfit(A1))  # Output: 1
print(solution.maxProfit(A2))  # Output: 4