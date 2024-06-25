from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# class Solution:
    # def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    #     if not list1 or not list2:
    #         return list1 if list1 else list2
    #     if list1.val > list2.val:
    #         list1, list2 = list2, list1
    #     list1.next = self.mergeTwoLists(list1.next, list2)
    #     return list1

# Using Dummy List


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        cur = dummy

        while list1 and list2:
            if list1.val > list2.val:
                cur.next = list2
                list2 = list2.next
            else:
                cur.next = list1
                list1 = list1.next

            cur = cur.next

        if list1:
            cur.next = list1
        else:
            cur.next = list2

        return dummy.next
