def ASCIIConversion(s):
    result = []
    for char in s:
        if char == ' ':
            result.append(' ')
        else:
            result.append(str(ord(char)))

    return ''.join(result)

print(ASCIIConversion(input()))