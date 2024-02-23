def MinWindowSubstring(strArr):
    N, K = strArr[0], strArr[1]
    char_count = {}
    
    for char in K:
        char_count[char] = char_count.get(char, 0) + 1

    min_window = float('inf')
    min_window_str = ""

    left, right = 0, 0
    required_chars = len(char_count)

    while right < len(N):
        if N[right] in char_count:
            char_count[N[right]] -= 1
            if char_count[N[right]] == 0:
                required_chars -= 1

        while required_chars == 0:
            if right - left < min_window:
                min_window = right - left
                min_window_str = N[left:right + 1]

            if N[left] in char_count:
                char_count[N[left]] += 1
                if char_count[N[left]] > 0:
                    required_chars += 1

            left += 1

        right += 1

    return min_window_str

# Keep this function call here
print(MinWindowSubstring(input()))