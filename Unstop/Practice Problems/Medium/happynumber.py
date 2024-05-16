def sum_of_squares_of_digits(n):
    # Function to calculate the sum of squares of digits of a number
    total = 0
    while n > 0:
        digit = n % 10
        total += digit * digit
        n //= 10
    return total

def is_good_number(n):
    slow = n
    fast = n

    while True:
        slow = sum_of_squares_of_digits(slow)
        fast = sum_of_squares_of_digits(sum_of_squares_of_digits(fast))

        if fast == 1:
            return True
        if slow == fast:
            return False

# Input number
n = int(input("Enter the number: "))

# Check if it's a good number and print the result
print(is_good_number(n))
