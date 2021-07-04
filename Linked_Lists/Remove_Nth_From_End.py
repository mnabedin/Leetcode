# Given the head of a linked list, remove the nth node
# from the end of the list and return its head.

# Example 1:
# Input: head = [1,2,3,4,5], n = 2
# Output: [1,2,3,5]

# Leetcode 19: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
# Difficulty: Medium

# Solution: Use a dummyHead keep a distance of n between slow and fast pointers. Then break the list.

def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
    dummyHead = ListNode(0)
    dummyHead.next = head
    slow = fast = dummyHead

    # Distance of n between slow and fast pointers starting from dummyHead. Eg for n = 2:
    # DH -> 1 -> 2 -> 3 -> 4 -> 5
    #  S         F
    for _ in range(n):
        fast = fast.next

    # DH -> 1 -> 2 -> 3 -> 4 -> 5
    #                 S         F
    while fast and fast.next:
        slow = slow.next
        fast = fast.next

    # Remove the Nth node
    slow.next = slow.next.next

    return dummyHead.next

# Time Complexity: O(N)
# Space Complexity: O(1)
