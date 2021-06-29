# Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

# There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the
# next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that
# pos is not passed as a parameter.

# Notice that you should not modify the linked list.

# Leetcode 142: https://leetcode.com/problems/linked-list-cycle-ii/
# Difficulty: Medium

# Solution: Same method as linked list cycle 1 to detect cycle. Realize that whenever they meet, if you reset one of the
# pointers and move them forward at the same speed, you will arrive at the beginning of the cycle.

def detectCycle(self, head: ListNode) -> ListNode:
    # Linked List Cycle 1
    slow = fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            break
    # Else no cycle so return None
    else:
        return None

    # Reset slow pointer and move both slow and fast forward at the same speed until they meet
    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next

    return slow

# Time Complexity: O(N)
# Space Complexity: O(1)
