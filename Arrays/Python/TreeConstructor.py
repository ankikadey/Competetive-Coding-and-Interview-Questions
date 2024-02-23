def TreeConstructor(strArr):
    child_count = {}
    parent_count = {}

    for pair in strArr:
        pair = pair[1:-1].split(',')
        child, parent = int(pair[0]), int(pair[1])

        child_count[child] = child_count.get(child, 0) + 1
        parent_count[parent] = parent_count.get(parent, 0) + 1

        if child_count[child] > 1 or parent_count[parent] > 2:
            return "false"

    return "true"

# Take input from the user
print(TreeConstructor(input()))
