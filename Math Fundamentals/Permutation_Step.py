from itertools import permutations

def PermutationStep(num):
    # Convert the number to a list of digits
    digits = list(str(num))

    # Generate all permutations of the digits
    all_permutations = sorted(int(''.join(perm)) for perm in permutations(digits))

    # Find the next permutation greater than the given number
    for perm in all_permutations:
        if perm > num:
            return perm

    # If there is no greater permutation, return -1
    return -1

print(PermutationStep(int(input())))