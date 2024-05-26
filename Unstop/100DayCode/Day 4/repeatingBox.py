from collections import Counter

n = int(input())
data = input()
arr = []

# Create hashmap of all values seen
for val in data.split():
    arr.append(int(val))
count = Counter(arr)

# If any count is n/2, it has been repeated exactly n times
for key, val in count.items():
    if val == n//2:
        print(key)
        break