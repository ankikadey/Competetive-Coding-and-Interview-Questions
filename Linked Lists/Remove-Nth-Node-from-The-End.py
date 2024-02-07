class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param A : head node of linked list
    # @param B : integer
    # @return the head node in the linked list
    def removeNthFromEnd(self, A, B):
        # Calculate the length of the linked list
        current = A
        length = 0
        while current:
            length += 1
            current = current.next
        
        # If B is greater than or equal to the length, remove the first node
        if B >= length:
            return A.next

        # Find the node to be removed
        target_index = length - B
        current = A
        for _ in range(target_index - 1):
            current = current.next

        # Remove the node
        current.next = current.next.next

        return A

# Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)

B = 2

solution = Solution()
result = solution.removeNthFromEnd(head, B)

# Output: 1 -> 2 -> 3 -> 5
while result:
    print(result.val, end=" -> ")
    result = result.next
