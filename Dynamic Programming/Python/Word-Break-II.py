# Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word.

# Return all such possible sentences.

# Note : Make sure the strings are sorted in your result.

# Input Format:

# The first argument is a string, A.
# The second argument is an array of strings, B.
# Output Format:

# Return a vector of strings representing the answer as described in the problem statement.
# Constraints:

# 1 <= len(A) <= 50
# 1 <= len(B) <= 25
# 1 <= len(B[i]) <= 20
# Examples:

# Input 1:
#     A = "b"
#     B = ["aabbb"]

# Output 1:
#     []

# Input 1:
#     A = "catsanddog",
#     B = ["cat", "cats", "and", "sand", "dog"]

# Output 1:
#     ["cat sand dog", "cats and dog"]

class Solution:
    # @param A : string
    # @param B : list of strings
    # @return a list of strings
    def wordBreak(self, A, B):
        word_set = set(B)
        memo = {}

        def word_break_helper(start):
            if start == len(A):
                return ['']

            if start in memo:
                return memo[start]

            sentences = []
            for end in range(start + 1, len(A) + 1):
                word = A[start:end]
                if word in word_set:
                    next_sentences = word_break_helper(end)
                    for sentence in next_sentences:
                        sentences.append((word + ' ' + sentence).strip())

            memo[start] = sentences
            return sentences

        result = word_break_helper(0)
        return sorted(result)
