import collections
from typing import List


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        count = collections.Counter(arr)
        occurences = set()

        for value in count.values():
            if value in occurences:
                return False
            occurences.add(value)

        return True
