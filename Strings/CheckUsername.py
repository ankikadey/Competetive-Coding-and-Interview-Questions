def CodelandUsernameValidation(username):
    # Rule 1: Check length
    if 4 <= len(username) <= 25:
        # Rule 2: Check if it starts with a letter
        if username[0].isalpha():
            # Rule 3: Check if it contains only letters, numbers, and underscore
            if all(char.isalnum() or char == '_' for char in username[1:-1]):
                # Rule 4: Check if it does not end with an underscore
                if username[-1] != '_':
                    return "true"

    return "false"

print(CodelandUsernameValidation(input()))