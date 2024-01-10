def Consecutive(arr):
    arr.sort()  # Sort the array in ascending order
    min_integers_needed = 0

    for i in range(len(arr) - 1):
        difference = arr[i + 1] - arr[i] - 1
        min_integers_needed += difference

    return min_integers_needed

print(Consecutive(list(map(int, input().split()))))