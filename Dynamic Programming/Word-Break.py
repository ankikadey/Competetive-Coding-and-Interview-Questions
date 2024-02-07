# Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence of one or more dictionary words.


# Problem Constraints
# 1 <= len(A) <= 6500
# 1 <= len(B) <= 10000
# 1 <= len(B[i]) <= 20


# Input Format
# The first argument is a string, A.
# The second argument is an array of strings, B.


# Output Format
# Return 0 / 1 ( 0 for false, 1 for true ) for this problem.


# Example Input
# Input 1:
#  A = "myinterviewtrainer",
# B = ["trainer", "my", "interview"]
# Input 2:
# A = "a"
# B = ["aaa"]


# Example Output
# Output 1:
# 1
# Output 2:
# 0


class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, word_dict):
        stack = [1]
        for i in range (0, len(s)):
            stack.append(0)
            for j in range(i,-1,-1):
                if stack[j] and s[j:i+1] in word_dict:
                    stack[i+1] = 1
                    break
        return stack[len(s)]