# Implement wildcard pattern matching with support for '?' and '*' for strings A and B.
# '?' : Matches any single character.
# '*' : Matches any sequence of characters (including the empty sequence).
# The matching should cover the entire input string (not partial).


# Problem Constraints
# 1 <= |A|, |B| <= 9e4


# Input Format
# The first argument of input contains a string A.
# The second argument of input contains a string B.


# Output Format
# Return 0 or 1:
# => 0 : If the patterns do not match.
# => 1 : If the patterns match.

class Solution:
    # @param s : string
    # @param p : string
    # @return an integer
    def isMatch(self, s, p):
        # If the count of non-wildcard characters in p is greater than the length of s, return 0
        if len(p) - p.count('*') > len(s):
            return 0
        
        #initialize the DP array with the first element set to True
        DP = [True] + [False] * len(s)
        
        #iterate through the characters in p
        for c in p:
            if c == '*':
                for n in range(1, len(s) + 1):
                    DP[n] = DP[n - 1] or DP[n]
            else:
                # If the character is not '*', update the DP array based on the previous row
                for n in range(len(s) - 1, -1, -1):
                    DP[n + 1] = DP[n] and (c == s[n] or c == '?')
                
                # Update the first element of DP based on whether the current character is '*'
                DP[0] = DP[0] and c == '*'
                
        # Return 1 if the last element of DP is True, indicating a match
        return 1 if DP[-1] else 0