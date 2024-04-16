class Solution:
    def maximumScore(self, nums, k):
        ans = 0
        stack = []

        for i in range(len(nums) + 1):
            while stack and (i == len(nums) or nums[stack[-1]] > nums[i]):
                h = nums[stack.pop()]
                w = i if not stack else i - stack[-1] - 1
                if (not stack or stack[-1] + 1 <= k) and i - 1 >= k:
                    ans = max(ans, h * w)
            stack.append(i)

        return ans

if __name__ == "__main__":
    sol = Solution()

    # Example usage
    nums = [1, 4, 3, 7, 4, 5]
    k = 2
    print("Maximum Score:", sol.maximumScore(nums, k))
