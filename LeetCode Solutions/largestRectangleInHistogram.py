class Solution:
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

if __name__ == "__main__":
    sol = Solution()

    # Example usage
    heights = [2, 1, 5, 6, 2, 3]
    print("Largest Rectangle Area:", sol.largestRectangleArea(heights))
