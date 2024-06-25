from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        digtolett = ['', '', 'abc', 'def', 'ghi',
                     'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        res = []

        def dfs(i: int, path: List[chr]) -> None:
            if i == len(digits):
                res.append(''.join(path))
                return

            for letter in digtolett[ord(digits[i]) - ord('0')]:
                path.append(letter)
                dfs(i+1, path)
                path.pop()

        dfs(0, [])
        return res
