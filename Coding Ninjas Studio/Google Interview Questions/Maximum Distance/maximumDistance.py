def maxDiff(a, n):
    max_diff = -1
    left = [0] * n
    right = [0] * n

    # Calculate left[i]: minimum index on the left such that A[left[i]] <= A[i]
    min_index = 0
    for i in range(n):
        if a[i] < a[min_index]:
            min_index = i
        left[i] = min_index

    # Calculate right[j]: maximum index on the right such that A[right[j]] >= A[j]
    max_index = n - 1
    for j in range(n - 1, -1, -1):
        if a[j] > a[max_index]:
            max_index = j
        right[j] = max_index

    # Calculate max difference
    i, j = 0, 0
    while i < n and j < n:
        if a[left[i]] <= a[right[j]]:
            max_diff = max(max_diff, right[j] - left[i])
            j += 1
        else:
            i += 1

    return max_diff

# Input handling
T = int(input().strip())

for _ in range(T):
    n = int(input().strip())
    a = list(map(int, input().strip().split()))

    # Calculate and print the maximum index difference
    print(maxDiff(a, n))