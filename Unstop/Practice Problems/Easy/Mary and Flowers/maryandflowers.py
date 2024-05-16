def find_flowers(N, t, a):
    i, j = 0, N-1

    while i < j:
        total = a[i]+a[j]
        if total == t:
            return i, j
        elif total < t:
            i += 1
        else:
            j -= 1
    return None


N, t = map(int, input().split())
a = list(map(int, input().split()))

result = find_flowers(N, t, a)
if result:
    print(*result)
else:
    print("No valid pair found.")
