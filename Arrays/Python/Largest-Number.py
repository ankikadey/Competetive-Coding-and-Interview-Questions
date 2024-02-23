# Given a list of non-negative integers, arrange them such that they form the largest number.
# Note: The result may be very large, so you need to return a string instead of an integer.


# Problem Constraints
# 1 <= |A| <= 105
# 0 <= Ai <= 109


# Input Format
# The first argument is an integer array A.


# Output Format
# Return a string representing the largest number formed


# Example Input
# A = [3, 30, 34, 5, 9]


# Example Output
# 9534330


# Example Explanation
# Largest possible number that can be formed is 9534330

from functools import cmp_to_key

class Solution:
    # Custom sorting function
    def largestNumber(self, A):
        # Convert numbers to strings for easier comparison
        A = list(map(str, A))

        # Define the comparison function for sorting
        def compare(x, y):
            return int(y + x) - int(x + y)

        # Sort the numbers using the custom comparison function
        A.sort(key=cmp_to_key(compare))

        # Handle the case where the list contains only zeros
        if A[0] == '0':
            return '0'

        # Concatenate the sorted strings to form the largest number
        result = ''.join(A)
        return result

# Example usage:
A = [3, 30, 34, 5, 9]
solution = Solution()
result = solution.largestNumber(A)
print(result)
