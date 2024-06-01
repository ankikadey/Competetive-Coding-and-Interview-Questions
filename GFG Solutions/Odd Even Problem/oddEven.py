from collections import Counter


class Solution:
    def oddEven(self, s: str) -> str:
        freq = Counter(s)

        x = 0
        y = 0

        for char, count in freq.items():
            # Get 1-based position in the alphabet
            position = ord(char) - ord('a') + 1

            if position % 2 == 0:  # Even position in alphabet
                if count % 2 == 0:  # Even frequency
                    x += 1
            else:  # Odd position in alphabet
                if count % 2 == 1:  # Odd frequency
                    y += 1

        # Step 4: Calculate the sum and determine if it's even or odd
        if (x + y) % 2 == 0:
            return "EVEN"
        else:
            return "ODD"
