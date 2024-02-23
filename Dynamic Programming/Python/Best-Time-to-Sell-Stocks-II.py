# Say you have an array, A, for which the ith element is the price of a given stock on day i.

# Design an algorithm to find the maximum profit.

# You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

# However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution:
    def maxProfit(self, A):
        n = len(A)
        max_profit = 0

        for i in range(1, n):
            if A[i] > A[i - 1]:
                max_profit += A[i] - A[i - 1]

        return max_profit

# Example usage:
A1 = [1, 2, 3]
A2 = [5, 2, 10]

solution = Solution()
print(solution.maxProfit(A1))  # Output: 2
print(solution.maxProfit(A2))  # Output: 8
