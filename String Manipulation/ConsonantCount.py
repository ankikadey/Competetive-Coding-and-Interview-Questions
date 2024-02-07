def ConsonantCount(s):
    consonants = 'bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ'
    count = sum(1 for char in s if char in consonants)
    return count

print(ConsonantCount(input()))