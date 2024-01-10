def ArrayRotation(arr):
    rotation_index = arr[0] % len(arr)
    rotated_array = arr[rotation_index:] + arr[:rotation_index]
    return ''.join(map(str, rotated_array))

print(ArrayRotation(list(map(int, input().split()))))