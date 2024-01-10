def StringCalculate(s):
    # Replace double asterisks with Python exponentiation operator
    s = s.replace('**', '**')

    # Use eval() to evaluate the mathematical expression
    result = eval(s)

    return int(result)  # Convert result to integer (no decimal operations)

print(StringCalculate(input()))