class Solution:
    def maximalRectangle(self, matrix):
        if not matrix:
            return 0

        ans = 0
        hist = [0] * len(matrix[0])

        for row in matrix:
            for i in range(len(row)):
                hist[i] = 0 if row[i] == '0' else hist[i] + 1
            ans = max(ans, self.largestRectangleArea(hist))

        return ans

    def largestRectangleArea(self, heights):
        ans = 0
        stack = []

        for i in range(len(heights) + 1):
            while stack and (i == len(heights) or heights[stack[-1]] > heights[i]):
                h = heights[stack.pop()]
                w = i if not stack else i - stack[-1] - 1
                ans = max(ans, h * w)
            stack.append(i)

        return ans

# Example usage
if __name__ == "__main__":
    # Example binary matrix
    matrix = [
        ['1', '0', '1', '0', '0'],
        ['1', '0', '1', '1', '1'],
        ['1', '1', '1', '1', '1'],
        ['1', '0', '0', '1', '0']
    ]

    sol = Solution()
    print("Maximal Rectangle Area:", sol.maximalRectangle(matrix))