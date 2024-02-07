# def BracketCombinations(num):
#     def generate_combinations(current, left, right):
#         if left == 0 and right == 0:
#             combinations.append(current)
#             return
#         if left > 0:
#             generate_combinations(current + '(', left - 1, right)
#         if right > left:
#             generate_combinations(current + ')', left, right - 1)

#     combinations = []
#     generate_combinations('', num, num)
#     return len(combinations)

# # Take input from the user
# try:
#     input_num = int(input())
#     if input_num < 0:
#         raise ValueError("Please enter a non-negative integer.")
# except ValueError as e:
#     print(f"Error: {e}")
# else:
#     print(BracketCombinations(input_num))

from math import factorial

def BracketCombinations(num):
  return int(factorial(2 * num) / (factorial(num + 1) * factorial(num)))

# keep this function call here 
input_num = int(input())
print(BracketCombinations(input_num))