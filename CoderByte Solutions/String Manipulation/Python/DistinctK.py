def kth_unique_string(strings, k):
    unique_strings = set()

    for string in strings:
        sorted_string = ''.join(sorted(string))
        unique_strings.add((sorted_string, string))

    sorted_unique_strings = sorted(unique_strings)

    if len(sorted_unique_strings) >= k:
        return sorted_unique_strings[k - 1][1]  # Return the original string
    else:
        return ""

# Input
n = int(input())
strings = [input().strip() for _ in range(n)]
k = int(input())

# Output
result = kth_unique_string(strings, k)
print(result)
