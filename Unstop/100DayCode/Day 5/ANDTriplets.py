def count_and_triplets(arr):
    n = len(arr)
    count = 0
    
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if arr[i] & arr[j] & arr[k] == 0:
                    count += 1
                    
    return count

# Example usage:
n = int(input())
arr = list(map(int, input().split()))
result = count_and_triplets(arr)
print(result)
