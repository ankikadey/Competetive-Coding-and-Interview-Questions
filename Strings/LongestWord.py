import re

def LongestWord(sen):
    words = re.findall(r'\b\w+\b', sen)
    longest_word = max(words, key=len)
    return longest_word

print(LongestWord(input()))