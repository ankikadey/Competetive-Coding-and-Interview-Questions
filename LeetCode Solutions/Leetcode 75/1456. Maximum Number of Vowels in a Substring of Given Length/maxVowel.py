class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        ans = 0
        maximum = 0
        kvowels = 'aeiou'
        for i, c in enumerate(s):
            if c in kvowels:
                maximum += 1
            if i >= k and s[i - k] in kvowels:
                maximum -= 1
            ans = max(ans, maximum)
        return ans

        