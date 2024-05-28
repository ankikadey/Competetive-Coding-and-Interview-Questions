class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def swapNodes(head, k):
    # Count the length of the linked list
    length = 0
    curr = head
    while curr:
        length += 1
        curr = curr.next

    # Find the kth node from the beginning
    kth_from_beginning = head
    for _ in range(k - 1):
        kth_from_beginning = kth_from_beginning.next

    # Find the kth node from the end
    kth_from_end = head
    for _ in range(length - k):
        kth_from_end = kth_from_end.next

    # Swap the values
    kth_from_beginning.val, kth_from_end.val = kth_from_end.val, kth_from_beginning.val

    return head

def printLinkedList(head):
    curr = head
    while curr:
        print(curr.val, end=" ")
        curr = curr.next
    print()

# Input
n = int(input())
values = list(map(int, input().split()))
k = int(input())

# Create the linked list
head = ListNode(values[0])
curr = head
for val in values[1:]:
    curr.next = ListNode(val)
    curr = curr.next

# Swap nodes
head = swapNodes(head, k)

# Output
printLinkedList(head)
