# Read the input values
n, k = map(int, input().split())
original_string = input().strip()

# Reverse the string
reversed_string = original_string[::-1]

# Get the kth character (1-based index, so we use k-1)
kth_character = reversed_string[k-1]

# Print the kth character
print(kth_character)