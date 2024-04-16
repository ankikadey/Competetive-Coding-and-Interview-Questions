# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = va
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0)
        curr = dummy
        carry = 0

        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            curr.next = ListNode(carry % 10)
            carry //= 10
            curr = curr.next

        return dummy.next

if __name__ == "__main__":
    # Creating linked lists l1 and l2
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    # Adding two numbers represented by linked lists l1 and l2
    sol = Solution()
    result = sol.addTwoNumbers(l1, l2)

    # Printing the result
    print("Result: ", end="")
    while result:
        print(result.val, end=" ")
        result = result.next
    print()
