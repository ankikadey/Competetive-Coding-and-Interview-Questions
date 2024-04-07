def find_flower_indexes(N, t, flowers):
    # Use two pointers technique
    left, right = 0, N - 1

    while left < right:
        total = flowers[left] + flowers[right]
        if total == t:
            return left, right
        elif total < t:
            left += 1
        else:
            right -= 1

    return None, None

# Read inputs
N, t = map(int, input().split())
flowers = list(map(int, input().split()))

# Find indexes of flowers to collect
index1, index2 = find_flower_indexes(N, t, flowers)

# Print output
print(index1, index2)
