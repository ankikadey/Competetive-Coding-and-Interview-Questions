def calculate_final_score(ops):
    scores = []
    
    for op in ops:
        if op == "C":
            if scores:
                scores.pop()
        elif op == "D":
            if scores:
                scores.append(2 * scores[-1])
        elif op == "+":
            if len(scores) >= 2:
                scores.append(scores[-1] + scores[-2])
        else:
            scores.append(int(op))
    
    return sum(scores)

# Reading input
n = int(input().strip())
ops = input().strip().split()

# Calculating and printing the final score
result = calculate_final_score(ops)
print(result)
