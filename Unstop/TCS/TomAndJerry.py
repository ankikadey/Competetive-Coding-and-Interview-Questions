def find_cookie(stream, k):
    stream.sort(reverse=True)
    return stream[k - 1]

def main():
    n = int(input())
    k = int(input())
    stream = list(map(int, input().split()))

    cookie_position = find_cookie(stream, k)
    print(cookie_position)

if __name__ == "__main__":
    main()