def findOrder(height, infront):
    N = len(height)
    result = []

    # Combine height and infront arrays into tuples
    people = [(h, i) for h, i in zip(height, infront)]

    # Sort people by height in descending order and then by infront count in ascending order
    people.sort(key=lambda x: (-x[0], x[1]))

    # Insert people into result list at the specified position
    for h, i in people:
        result.insert(i, h)

    return result

# Test cases
test_cases = int(input().strip())

for _ in range(test_cases):
    N = int(input().strip())
    Height = list(map(int, input().strip().split()))
    Infront = list(map(int, input().strip().split()))

    order = findOrder(Height, Infront)
    print(*order)
