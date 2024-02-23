def CamelCase(s):
    words = ''.join([char.lower() if char.isalnum() else ' ' for char in s]).split()
    camel_case_str = words[0].lower() + ''.join(word.capitalize() for word in words[1:])
    return camel_case_str

print(CamelCase(input()))