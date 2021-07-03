# Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even
# indices, and return the reordered list.

# The first node is considered odd, and the second node is even, and so on.

# Note that the relative order inside both the even and odd groups should remain as it was in the input.

# You must solve the problem in O(1) extra space complexity and O(n) time complexity.

# Example 1:
# Input: head = [1,2,3,4,5]
# Output: [1,3,5,2,4]

# Leetcode 328: https://leetcode.com/problems/odd-even-linked-list/
# Difficulty: Medium

# Solution: Use two pointers to build odd and even lists and then connect the odd list to the even one.

def oddEvenList(self, head: ListNode) -> ListNode:
    # Return head if there's only one node
    if not head or not head.next:
        return head

    # The first node is odd and the second is even. evenHead is the head of the new even list.
    odd = head
    even = evenHead = head.next

    # Even pointer will reach the end first so while even and even.next exists
    while even and even.next:
        # Next of even will be odd so set the next pointer of odd to that, and move odd forward
        odd.next = even.next
        odd = odd.next
        # Do the same for even
        even.next = odd.next
        even = even.next

    # Connect odd to even list
    odd.next = evenHead

    return head

# Time Complexity: O(N)
# Space Complexity: O(1)