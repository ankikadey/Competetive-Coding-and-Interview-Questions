class Solution:
    # @param A : list of list of integers
    # @return the same list modified
    def setZeroes(self, A):
        rows_to_zero = set()
        cols_to_zero = set()
        # Mark rows and columns to be set to 0
        for i in range(len(A)):
            for j in range(len(A[0])):
                if A[i][j] == 0:
                    rows_to_zero.add(i)
                    cols_to_zero.add(j)

        # Set rows to 0
        for row in rows_to_zero:
            for j in range(len(A[0])):
                A[row][j] = 0

        # Set columns to 0
        for col in cols_to_zero:
            for i in range(len(A)):
                A[i][col] = 0

        return A
