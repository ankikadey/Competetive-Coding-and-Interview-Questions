def max_border(a):
    max_length = 0
    # Iterate over rows (i) and columns (j)
    for i in range(len(a)):
        count = 0
        for j in range(len(a[i])):  # Use len(a[i]) instead of len(a)
            if a[i][j] == '#':
                count += 1
        max_length = max(max_length, count)
    return max_length

# Input: Number of test cases
no = int(input())
while no != 0:
    m, n = map(int, input().split())
    a = []
    for _ in range(m):
        row = input().strip()
        a.append(list(row))
    result = max_border(a)
    print(result)
    no -= 1
