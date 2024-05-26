def reverse_string_from_last_occurrence(s, ch):
    # Find the index of the last occurrence of ch in s
    idx = s.rfind(ch)
    
    # If ch is not found in s, return s as it is
    if idx == -1:
        return s
    
    # Reverse the substring from idx to the end of the string
    reversed_substring = s[idx:][::-1]
    
    # Concatenate the non-reversed prefix and the reversed substring
    return s[:idx] + reversed_substring

# Input
s, ch = input().split()

# Output
print(reverse_string_from_last_occurrence(s, ch))
