def anagrams(A):
    anagram_groups = {}
    result = []

    for i, word in enumerate(A, 1):
        # Sort the word to get its unique representation
        sorted_word = ''.join(sorted(word))

        # Check if the sorted word is already in the hash map
        if sorted_word in anagram_groups:
            anagram_groups[sorted_word].append(i)
        else:
            anagram_groups[sorted_word] = [i]

    # Add the anagram groups to the result
    for group in anagram_groups.values():
        result.append(group)

    return result

# Example usage:
strings = ["cat", "dog", "tac", "god", "act"]
output = anagrams(strings)
print(output)
