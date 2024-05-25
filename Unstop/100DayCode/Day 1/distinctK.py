def kth_unique_string(N, strings, k):
    unique_strings = {}
    unique_count = 0
    
    # Count occurrences of each string
    for string in strings:
        unique_strings[string] = unique_strings.get(string, 0) + 1
    
    # Find the kth unique string
    for string in strings:
        if unique_strings[string] == 1:
            unique_count += 1
            if unique_count == k:
                return string
    
    # If less than k unique strings found
    return ""

# Read inputs
N = int(input())
strings = [input() for _ in range(N)]
k = int(input())

# Find the kth unique string
result = kth_unique_string(N, strings, k)

# Print output
print(result)