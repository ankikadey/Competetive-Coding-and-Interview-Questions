from collections import deque

def wordLadder(begin, end, dict_words):
    if begin == end:
        return 0
    
    # Create a set from dict_words for faster lookup
    word_set = set(dict_words)
    
    # Initialize a queue for BFS
    queue = deque([(begin, 1)])  # (word, transformation sequence length)
    
    # Mark the begin word as visited
    visited = {begin}
    
    # Perform BFS
    while queue:
        word, length = queue.popleft()
        
        # Generate all possible next words by changing one character at a time
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                next_word = word[:i] + c + word[i+1:]
                
                # If next_word is end, return the transformation sequence length
                if next_word == end:
                    return length + 1  # Include transformation from begin to first transformed word
                
                # If next_word is in the dictionary and has not been visited yet, push it into the queue
                if next_word in word_set and next_word not in visited:
                    queue.append((next_word, length + 1))
                    visited.add(next_word)
    
    # If no transformation sequence is found, return -1
    return -1

# Input format
T = int(input())
for _ in range(T):
    begin = input().strip()
    end = input().strip()
    N = int(input())
    dict_words = input().strip().split()

    # Calculate and print the result for each test case
    result = word_ladder(begin, end, dict_words)
    print(result)