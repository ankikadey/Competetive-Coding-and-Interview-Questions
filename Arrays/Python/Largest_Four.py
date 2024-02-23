def LargestFour(arr):
    # Sort the array in descending order
    arr.sort(reverse=True)

    # Return the sum of the four largest elements or the sum of all elements if less than four
    return sum(arr[:4])

print(list(map(int, input().split())))