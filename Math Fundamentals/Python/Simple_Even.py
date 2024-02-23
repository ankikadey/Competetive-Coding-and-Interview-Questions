def SimpleEvens(num):
    # Convert the number to a string and check if every digit is even
    return all(int(digit) % 2 == 0 for digit in str(num))

print(SimpleEvens(int(input())))