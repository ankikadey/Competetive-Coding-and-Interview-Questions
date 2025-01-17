def rotateArray(arr: list, k: int) -> list:
    n = len(arr)
    k = k%n
    
    temp=[]
    for i in range(k):
        temp.append(arr[i])
    
    for j in range(k,n):
        arr[j-k] = arr[j]
    
    for i in range(len(temp)):
        arr[n-k+i] = temp[i]
    
    return arr