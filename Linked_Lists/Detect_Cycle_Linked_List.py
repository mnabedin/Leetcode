# Given head, the head of a linked list, determine if the linked list has a cycle in it.

# There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following
# the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note
# that pos is not passed as a parameter.

# Return true if there is a cycle in the linked list. Otherwise, return false.

# Leetcode 141: https://leetcode.com/problems/linked-list-cycle/
# Difficulty: Easy

# Solution: Use slow and fast pointers. If they ever meet, there's a cycle else no cycle.

def hasCycle(self, head: ListNode) -> bool:
    if not head or not head.next:
        return False

    slow = fast = head

    # While fast and fast.next exists
    while fast and fast.next:
        # Move slow pointer once and fast twice. If there's a cycle, fast and slow pointers are guaranteed to meet.
        slow = slow.next
        fast = fast.next.next

        # If they meet, there's a cycle
        if slow == fast:
            return True

    # We reached the end of the linked list so no cycle
    return False

# Time Complexity: O(N)
# Space Complexity: O(1)
