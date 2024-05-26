def wordbreak(s, worddict):
    if not worddict:
        return False
    wordset = set(worddict)
    dp = [False] * (len(s) + 1)
    dp[0] = True

    for i in range(1, len(s) + 1):
        for j in range(i - 1, -1, -1):
            if dp[j]:
                word = s[j:i]
                if word in wordset:
                    dp[i] = True
                    break

    return dp[-1]

if __name__ == "__main__":
    s = input().strip()
    n = int(input())
    worddict = []
    for _ in range(n):
        worddict.append(input().strip())
    print("true" if wordbreak(s, worddict) else "false")
