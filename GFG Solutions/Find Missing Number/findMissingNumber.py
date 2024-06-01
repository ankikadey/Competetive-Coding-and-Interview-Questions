class Solution:
    def MissingNumber(self, array, N):
        # Step 1: Calculate the expected sum of the first N natural numbers
        total_sum = N * (N + 1) // 2

        # Step 2: Calculate the sum of the elements in the array
        array_sum = sum(array)

        # Step 3: The missing number is the difference between the total sum and the array sum
        return total_sum - array_sum


solution = Solution()

array1 = [1, 2, 3, 5]
N1 = 5
print(solution.MissingNumber(array1, N1))  # Output: 4

array2 = [6, 1, 2, 8, 3, 4, 7, 10, 5]
N2 = 10
print(solution.MissingNumber(array2, N2))  # Output: 9
