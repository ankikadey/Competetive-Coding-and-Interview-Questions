def check_ab_pattern(s):
    b_seen = False
    
    for box in s:
        if box == 'a' and b_seen:
            return "NO"
        elif box == 'b':
            b_seen = True
    
    return "YES"

# Input
s = input()

# Output
print(check_ab_pattern(s))
