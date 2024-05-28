def Palindromes(string, n):
    res = set()

    for i in range(n):
        for j in range(i+1, n+1):
            # Add length of substrings that are equal to reverse string to set
            if string[i:j] == string[i:j][::-1]:
                res.add(len(string[i:j]))
    return max(res)

# Driver code
n = int(input())
string = input()
print(Palindromes(string, n))
