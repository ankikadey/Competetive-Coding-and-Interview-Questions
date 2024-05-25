def largest_remainder(t, test_cases):
    results = []
    
    for l, r in test_cases:
        if l * 2 <= r:
            results.append(r % (r // 2 + 1))
        else:
            results.append(r % l)
    
    return results

# Input
t = int(input().strip())
test_cases = [tuple(map(int, input().strip().split())) for _ in range(t)]

# Output
for result in largest_remainder(t, test_cases):
    print(result)
