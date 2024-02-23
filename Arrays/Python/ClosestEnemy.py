def ClosestEnemy(arr):
    # Find the position of 1 and 2 in the array
    position_1 = arr.index(1)
    position_2 = arr.index(2) if 2 in arr else -1

    # If there is no 2, return 0
    if position_2 == -1:
        return 0

    # Calculate the distance between positions
    distance = abs(position_1 - position_2)

    return distance

print(ClosestEnemy(list(map(int, input().split()))))