# Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the
# first two lists.

# Example 1:
# Input: l1 = [1,2,4], l2 = [1,3,4]
# Output: [1,1,2,3,4,4]

# Leetcode 21: https://leetcode.com/problems/merge-two-sorted-lists/
# Difficulty: Easy

# Solution: Iterate through both lists at the same time and build return list using the smaller of the values.

def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
    # Dummy head and current pointer to build linked list
    dummy = curr = ListNode(0)

    # While l1 and l2 exist
    while l1 and l2:
        # If l1.val is less than l2.val
        if l1.val < l2.val:
            # Set next to this node
            curr.next = l1
            l1 = l1.next
        # l2.val >= l1.val
        else:
            curr.next = l2
            l2 = l2.next
        # Always move curr forward
        curr = curr.next

    # Either l1 or l2 is done so set the remaining elements using whichever list still has elements
    curr.next = l1 or l2
    return dummy.next

# Time Complexity: O(N)
# Space Complexity: O(1)
