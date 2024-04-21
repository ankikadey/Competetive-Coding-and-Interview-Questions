# Ravi discovered that some strings read the same forwards and backwards, which are called palindromes.
# He noticed that every string he encountered has at least one palindromic substring.
# He wants to know how to find the longest palindromic substring in a given string.

# Can you help him determine the length of this longest palindromic substring?

# Input Format
# The first line contains n the length of the string
# The following line has s, the input string

# Output Format
# Print the length of the longest palindromic substring that is possible.

# Constraints
# 1<=n<=1000

# Sample Testcase 0
# Testcase Input
# 5
# abacc
# Testcase Output
# 3

def longest_palindromic_substring_length(s):
    n = len(s)
    max_length = 1
    for i in range(n):
        for j in range(i + 1, n):
            if s[i:j + 1] == s[i:j + 1][::-1]:
                max_length = max(max_length, j - i + 1)
    return max_length

# Input reading
n = int(input().strip())
s = input().strip()

# Calculate and print the length of the longest palindromic substring
print(longest_palindromic_substring_length(s))