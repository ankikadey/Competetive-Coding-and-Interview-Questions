def PalindromicSubstring(s):
    def is_palindrome(sub):
        return sub == sub[::-1]

    longest_palindrome = ""
    for i in range(len(s)):
        for j in range(i + 2, len(s) + 1):
            substring = s[i:j]
            if is_palindrome(substring) and len(substring) > len(longest_palindrome):
                longest_palindrome = substring

    return longest_palindrome if longest_palindrome else "none"

print(PalindromicSubstring(input()))