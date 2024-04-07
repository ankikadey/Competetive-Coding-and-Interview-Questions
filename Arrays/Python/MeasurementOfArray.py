MOD = 1000000007

def calculate_measurement(n, arr):
    last_occurrence = {}
    measurement = 0
    
    for i in range(n):
        last_occurrence[arr[i]] = i
        
    for i in range(n):
        sanity = i + last_occurrence[arr[i]]
        measurement += sanity
        
    return measurement % MOD

# Input reading
n = int(input().strip())
arr = list(map(int, input().strip().split()))
print(calculate_measurement(n, arr))
