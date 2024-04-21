class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of list of integers
    def combinationSum(self, A, B):
        def generate_combinations(candidates, target, start, current_combination, result):
            if target == 0:
                result.append(current_combination.copy())
                return

            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:
                    continue  # Skip duplicates to avoid duplicate combinations

                if candidates[i] > target:
                    break  # No need to continue if the current candidate is greater than the remaining target

                current_combination.append(candidates[i])
                generate_combinations(candidates, target - candidates[i], i + 1, current_combination, result)
                current_combination.pop()

        A.sort()  # Sort the candidates to handle non-descending order
        result = []
        generate_combinations(A, B, 0, [], result)
        return result