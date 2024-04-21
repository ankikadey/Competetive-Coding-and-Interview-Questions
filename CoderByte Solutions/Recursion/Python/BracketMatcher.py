def BracketMatcher(input_str):
    stack = []

    for char in input_str:
        if char == '(':
            stack.append(char)
        elif char == ')':
            if not stack:
                return 0  # Unmatched closing bracket
            stack.pop()

    return 1 if not stack else 0  # Return 1 if the stack is empty (all brackets matched)

# Take input from the user
# try:
#     user_input = input()
#     print(BracketMatcher(user_input))
# except Exception as e:
#     print(f"Error: {e}")

print(BracketMatcher(input()))
