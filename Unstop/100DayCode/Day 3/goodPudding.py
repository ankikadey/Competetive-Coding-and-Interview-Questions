def is_good_pudding(number):
    num_str = str(abs(number))  # Use abs() to ensure we're working with the absolute value
    first_reversal = int(num_str[::-1])
    second_reversal = int(str(first_reversal)[::-1])
    return str(second_reversal) == str(abs(number))  # Compare with the absolute value

N = int(input())
puddings = []
for _ in range(N):
    pudding = input().lstrip('0')  # Strip leading zeros
    puddings.append(int(pudding))

for pudding in puddings:
    print(1 if is_good_pudding(pudding) else 0)