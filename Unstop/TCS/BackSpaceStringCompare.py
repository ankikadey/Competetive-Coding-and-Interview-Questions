# Alice and Bob both are friends and are playing with each other.
# Alice receives a new typewriter and is very excited to type the words on it.
# He challenged Bob to write the same word as his on the typewriter.
# Both are kids and are making some mistakes in typing and are making use of the ‘#’ key on a typewriter to delete the last character printed on it.

# An empty text remains empty even after backspaces.

# Input Format
# The first line contains a string ‘Bob’ of Bob.
# The second line contains a string ‘Alice’  of Alice.

# Output Format
# The first line contains ‘YES’ if Alice is able to print the exact words as Bob , otherwise ‘NO’.

# Constraints
# 1 <= Bob.length, Alice.length <= 100000
# Bob and Alice only contain lowercase letters and '#' characters.

# Sample Testcase 0
# Testcase Input
# ab#c
# ad#c
# Testcase Output
# YES
# Explanation
# Here ,
# The actual typed string by Bob : ‘ac’
# The actual typed string by Alice : ‘ac’
# Hence , they matched.

# Sample Testcase 1
# Testcase Input
# a#c
# b
# Testcase Output
# NO
# Explanation
# Here ,
# The actual typed string by Bob : ‘c’
# The actual typed string by Alice : ‘b’
# Hence , they do not matched.

def compare_typing(bob, alice):
    def simulate_typing(s):
        typed = []
        for char in s:
            if char == '#':
                if typed:
                    typed.pop()
            else:
                typed.append(char)
        return ''.join(typed)
    
    bob_typed = simulate_typing(bob)
    alice_typed = simulate_typing(alice)
    
    return "YES" if bob_typed == alice_typed else "NO"

# Input reading
bob = input().strip()
alice = input().strip()
print(compare_typing(bob, alice))
