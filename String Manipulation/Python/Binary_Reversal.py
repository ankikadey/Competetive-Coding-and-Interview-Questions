def BinaryReversal(str):
    # Step 1: Convert the integer to binary and remove the '0b' prefix
    binary_str = bin(int(str))[2:]

    # Step 2: Pad the binary string to the nearest multiple of 8 and reverse it
    padded_binary_str = binary_str.rjust((len(binary_str) + 7) // 8 * 8, '0')
    reversed_binary_str = padded_binary_str[::-1]

    # Step 3: Convert the reversed binary string to decimal
    decimal_result = int(reversed_binary_str, 2)

    return decimal_result

print(BinaryReversal(input()))