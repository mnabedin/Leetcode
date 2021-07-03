# You are given the head of a singly linked-list. The list can be represented as:
# L0 → L1 → … → Ln - 1 → Ln

# Reorder the list to be on the following form:
# L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
# You may not modify the values in the list's nodes. Only nodes themselves may be changed.

# Example 2:
# Input: head = [1,2,3,4,5]
# Output: [1,5,2,4,3]

# Leetcode 143: https://leetcode.com/problems/reorder-list/
# Difficulty: Medium

# Solution: Break the list into two parts. Reverse the second part and merge the lists.

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: ListNode) -> None:
        # Nothing to do if head doesn't or if there is only one node.
        if not head or not head.next:
            return

        # Slow -> head of second list. Prev -> tail of first list. Fast -> tail of second list.
        slow = fast = prev = head

        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next

        # Break the first list from the rest of the list.
        prev.next = None

        # l1 and l2 are the heads of the first and second lists respectively
        l2 = self.reverseLinkedList(slow)
        l1 = head
        self.mergeLinkedList(l1, l2)

    def mergeLinkedList(self, l1, l2):
        while l2:
            # Temp pointers
            temp1, temp2 = l1.next, l2.next
            # Merge l1 with l2
            l1.next = l2

            # Break out if we ever reach a point where l1.next does not exist
            if not temp1:
                break

            # Merge l2 with l1
            l2.next = temp1
            # Move l1 and l2 forward
            l1, l2 = temp1, temp2

    def reverseLinkedList(self, head):
        prev = None
        curr = head

        while curr:
            nextTemp = curr.next
            curr.next = prev
            prev = curr
            curr = nextTemp

        return prev

# Time Complexity: O(N)
# Space Complexity: O(1)
