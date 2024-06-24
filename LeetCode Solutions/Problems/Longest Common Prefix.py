from typing import List
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""

        # Assume the first string is the common prefix
        prefix = strs[0]

        for string in strs[1:]:
            # Reduce the prefix length until it matches the beginning of the current string
            while string[:len(prefix)] != prefix and prefix:
                prefix = prefix[:len(prefix)-1]

                # Early exit if there's no common prefix
                if not prefix:
                    return ""

        return prefix
