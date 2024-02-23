# Import the Counter class from the collections module
from collections import Counter

# Input: Number of songs in Bob's playlist
n = int(input())

# Input: List of singers associated with each song (only consider the first 'n' elements)
a = list(map(int, input().split()))[:n]

# Create a Counter object to count the occurrences of each singer
c = Counter(a)

# Find the maximum count (number of songs) for any singer
max_count = max(c.values())

# Count the number of singers with the maximum count
num_favorite_singers = list(c.values()).count(max_count)

# Print the result
print(num_favorite_singers)